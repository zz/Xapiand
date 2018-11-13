/*
 * Copyright (C) 2015-2018 Dubalu LLC. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

#include <atomic>    // for std::atomic_bool
#include <memory>    // for shared_ptr
#include <string>    // for string

#include "worker.h"  // for Worker


constexpr int CONN_TCP_NODELAY      = 1;
constexpr int CONN_TCP_DEFER_ACCEPT = 2;


// Values in seconds.
constexpr double idle_timeout = 60;
constexpr double active_timeout = 15;


// Base class for configuration data for TCP.
class TCP {
	void _check_backlog(int tcp_backlog);

protected:
	int port;
	int sock;
	std::atomic_bool closed;

	int flags;

	std::string description;

	void bind(int tries);

	void close();

public:
	TCP(int port_, std::string description_, int tries_, int flags_);
	virtual ~TCP();

	static int connect(int sock_, const std::string& hostname, const std::string& servname);
	int accept();

	virtual std::string getDescription() const noexcept = 0;
};


// Base class for configuration data for TCP.
class BaseTCP : public TCP, public Worker {
protected:
	void shutdown_impl(long long asap, long long now) override;
	void destroy_impl() override;

public:
	BaseTCP(const std::shared_ptr<Worker>& parent_, ev::loop_ref* ev_loop_, unsigned int ev_flags_, int port_, std::string description_, int tries_, int flags_);
	~BaseTCP();
};
