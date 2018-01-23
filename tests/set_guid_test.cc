/*
 * Copyright (C) 2015-2018 deipi.com LLC and contributors. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "test_guid.h"

#include "gtest/gtest.h"


TEST(GUIDTest, Generator) {
	EXPECT_EQ(test_generator_guid(), 0);
}


TEST(GUIDTest, Constructor) {
	EXPECT_EQ(test_constructor_guid(), 0);
}


TEST(GUIDTest, Special) {
	EXPECT_EQ(test_special_guids(), 0);
}


TEST(GUIDTest, Condensed) {
	EXPECT_EQ(test_condensed_guids(), 0);
}


TEST(GUIDTest, Compacted) {
	EXPECT_EQ(test_compacted_guids(), 0);
}


TEST(GUIDTest, Expanded) {
	EXPECT_EQ(test_expanded_guids(), 0);
}


TEST(GUIDTest, Several) {
	EXPECT_EQ(test_several_guids(), 0);
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
