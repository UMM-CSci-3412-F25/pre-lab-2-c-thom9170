#include <gtest/gtest.h>
#include "check_whitespace.h"

// function to help with repeated task
#define STRIP_FREE(s) do { if ((s)[0] != '\0') free((void*)(s)); } while(0)

// Strip tests
TEST(strip, EmptyString) {
    const char *s = strip("");
    ASSERT_STREQ("", s);
    STRIP_FREE(s);
}

TEST(strip, NoWhitespace) {
    const char *s = strip("frog");
    ASSERT_STREQ("frog", s);
    STRIP_FREE(s);
}

TEST(strip, WhitespaceOnFront) {
    const char *s = strip("   frog");
    ASSERT_STREQ("frog", s);
    STRIP_FREE(s);
}

TEST(strip, WhitespaceOnBack) {
    const char *s = strip("frog   ");
    ASSERT_STREQ("frog", s);
    STRIP_FREE(s);
}

TEST(strip, WhitespaceOnBothEnds) {
    const char *s = strip("  frog   ");
    ASSERT_STREQ("frog", s);
    STRIP_FREE(s);
}

// is_clean tests
TEST(is_clean, EmptyString) {
    ASSERT_TRUE(is_clean(""));
}

TEST(is_clean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("University of Minnesota Morris   "));
}

TEST(is_clean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris   "));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
