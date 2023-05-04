// Copyright (c) 2023 Damitha Fernando <damitha.fernando@outlook.com>
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Some dummy tests to check if gtest is working

#include <gtest/gtest.h>

TEST(DummyTests, SomeTestThatPass) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(DummyTests, SomeOtherTestThatFail) {
    EXPECT_NE(2,3);
}
