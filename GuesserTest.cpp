/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


TEST(GuesserTest, attemptsReset_test)
{
  Guesser object("Secret");
  object.match("Secrex");
  object.match("Secrex");
  object.match("Secret");
  ASSERT_EQ( object.remaining(), 3 );
}

TEST(GuesserTest, attemptsNoReset_test)
{
  Guesser object("Secret");
  object.match("Secrex");
  object.match("Secrex");
  object.match("Secrex");
  object.match("Secret");
  ASSERT_EQ( object.remaining(), 0 );
}

TEST(GuesserTest, attemptsDec_test)
{
  Guesser object("Secret");
  object.match("Secre");
  ASSERT_EQ( object.remaining(), 2 );
}

TEST(GuesserTest, attemptsDec_test1)
{
  Guesser object("Secret");
  object.match("Secre");
  object.match("Secre");
  ASSERT_EQ( object.remaining(), 1 );
}

TEST(GuesserTest, attemptsDec_test2)
{
  Guesser object("Secret");
  object.match("Secre");
  object.match("Secre");
  object.match("Secre");
  ASSERT_EQ( object.remaining(), 0 );
}

TEST(GuesserTest, attemptsDec_test3)
{
  Guesser object("Secret");
  object.match("Secre");
  object.match("Secre");
  object.match("Secre");
  object.match("Secre");
  ASSERT_EQ( object.remaining(), 0 );
}

TEST(GuesserTest, matchWrong_test)
{
  Guesser object("Secret");
  ASSERT_EQ( object.match("wrong"), false );
}

TEST(GuesserTest, matchCase_test)
{
  Guesser object("Secret");
  ASSERT_EQ( object.match("secret"), false );
}

TEST(GuesserTest, matchLock_test)
{
  Guesser object("Secret");
  object.match("secret");
  object.match("secret");
  object.match("secret");
  ASSERT_EQ( object.match("Secret"), false );
}

TEST(GuesserTest, matchLock_test1)
{
  Guesser object("Secret");
  object.match("wrong");
  ASSERT_EQ( object.match("Secret"), false );
}

TEST(GuesserTest, match_test)
{
  Guesser object("Secret");
  ASSERT_EQ( object.match("Secret"), true );
}

TEST(GuesserTest, matchLock_test2)
{
  Guesser object("Secret");
  object.match("Sec");
  ASSERT_EQ( object.match("Secret"), false );
}

TEST(GuesserTest, matchTrunc_test)
{
  Guesser object("1 2 3 4 5 6 7 8 9 1011121314151617181920");
  ASSERT_EQ( object.match("1 2 3 4 5 6 7 8 9 10111213141516"), true );
}

TEST(GuesserTest, matchTrunc_test1)
{
  Guesser object("1 2 3 4 5 6 7 8 9 1011121314151617181920");
  ASSERT_EQ( object.match("1 2 3 4 5 6 7 8 9 1011121314151617181920"), false );
}

TEST(GuesserTest, matchEmpty_test)
{
  Guesser object("");
  ASSERT_EQ( object.match("hhhhh"), false );
}

TEST(GuesserTest, matchEmpty_test1)
{
  Guesser object("");
  ASSERT_EQ( object.match(""), true );
}