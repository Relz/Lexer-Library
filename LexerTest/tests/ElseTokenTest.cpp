#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(else_token, determining_if_stay_alone)
{
	ExpectTokens("else", { Token::ELSE });
}

TEST(else_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" else ", { Token::ELSE });
	ExpectTokens(";else;", { Token::SEMICOLON, Token::ELSE, Token::SEMICOLON });
}

TEST(else_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("else;", { Token::ELSE, Token::SEMICOLON });
	ExpectTokens(";else", { Token::SEMICOLON, Token::ELSE });
}

TEST(else_token, not_determining_if_between_numbers)
{
	ExpectTokens("1else1", { Token::UNKNOWN });
	ExpectTokens("1else1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1else1", { Token::UNKNOWN });
	ExpectTokens("1.1else1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1E+1else1", { Token::UNKNOWN });
	ExpectTokens("1else1E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(else_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"else\"", { Token::STRING_LITERAL });
	ExpectTokens("\" else \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1else1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";else;\"", { Token::STRING_LITERAL });
}

TEST(else_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//else", { });
	ExpectTokens("// else ", { });
	ExpectTokens("//1else1", { });
	ExpectTokens("//;else;", { });
	ExpectTokens("/*else*/", { });
	ExpectTokens("/* else */", { });
	ExpectTokens("/*1else1*/", { });
	ExpectTokens("/*;else;*/", { });
	ExpectTokens("/*else", { });
	ExpectTokens("/* else ", { });
	ExpectTokens("/*1else1", { });
	ExpectTokens("/*;else;", { });
}