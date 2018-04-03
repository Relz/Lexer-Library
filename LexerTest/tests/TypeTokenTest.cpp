#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(type_token, determining_if_stay_alone)
{
	ExpectTokens("Integer", { Token::TYPE });
	ExpectTokens("Float", { Token::TYPE });
	ExpectTokens("String", { Token::TYPE });
	ExpectTokens("Void", { Token::TYPE });
	ExpectTokens("Array", { Token::TYPE });
}

TEST(type_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" Integer ", { Token::TYPE });
	ExpectTokens(";Integer;", { Token::SEMICOLON, Token::TYPE, Token::SEMICOLON });

	ExpectTokens(" Float ", { Token::TYPE });
	ExpectTokens(";Float;", { Token::SEMICOLON, Token::TYPE, Token::SEMICOLON });

	ExpectTokens(" String ", { Token::TYPE });
	ExpectTokens(";String;", { Token::SEMICOLON, Token::TYPE, Token::SEMICOLON });

	ExpectTokens(" Void ", { Token::TYPE });
	ExpectTokens(";Void;", { Token::SEMICOLON, Token::TYPE, Token::SEMICOLON });

	ExpectTokens(" Array ", { Token::TYPE });
	ExpectTokens(";Array;", { Token::SEMICOLON, Token::TYPE, Token::SEMICOLON });
}

TEST(type_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("Integer;", { Token::TYPE, Token::SEMICOLON });
	ExpectTokens(";Integer", { Token::SEMICOLON, Token::TYPE });

	ExpectTokens("Float;", { Token::TYPE, Token::SEMICOLON });
	ExpectTokens(";Float", { Token::SEMICOLON, Token::TYPE });

	ExpectTokens("String;", { Token::TYPE, Token::SEMICOLON });
	ExpectTokens(";String", { Token::SEMICOLON, Token::TYPE });

	ExpectTokens("Void;", { Token::TYPE, Token::SEMICOLON });
	ExpectTokens(";Void", { Token::SEMICOLON, Token::TYPE });

	ExpectTokens("Array;", { Token::TYPE, Token::SEMICOLON });
	ExpectTokens(";Array", { Token::SEMICOLON, Token::TYPE });
}

TEST(type_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1Integer1", { Token::UNKNOWN });
	ExpectTokens("1Integer1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1Integer1", { Token::UNKNOWN });
	ExpectTokens("1.1Integer1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1Integer1", { Token::UNKNOWN });
	ExpectTokens("1Integer1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });

	ExpectTokens("1Float1", { Token::UNKNOWN });
	ExpectTokens("1Float1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1Float1", { Token::UNKNOWN });
	ExpectTokens("1.1Float1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1Float1", { Token::UNKNOWN });
	ExpectTokens("1Float1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });

	ExpectTokens("1String1", { Token::UNKNOWN });
	ExpectTokens("1String1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1String1", { Token::UNKNOWN });
	ExpectTokens("1.1String1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1String1", { Token::UNKNOWN });
	ExpectTokens("1String1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });

	ExpectTokens("1Void1", { Token::UNKNOWN });
	ExpectTokens("1Void1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1Void1", { Token::UNKNOWN });
	ExpectTokens("1.1Void1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1Void1", { Token::UNKNOWN });
	ExpectTokens("1Void1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });

	ExpectTokens("1Array1", { Token::UNKNOWN });
	ExpectTokens("1Array1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1Array1", { Token::UNKNOWN });
	ExpectTokens("1.1Array1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1Array1", { Token::UNKNOWN });
	ExpectTokens("1Array1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(type_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"Integer\"", { Token::STRING_LITERAL });
	ExpectTokens("\" Integer \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1Integer1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";Integer;\"", { Token::STRING_LITERAL });

	ExpectTokens("\"Float\"", { Token::STRING_LITERAL });
	ExpectTokens("\" Float \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1Float1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";Float;\"", { Token::STRING_LITERAL });

	ExpectTokens("\"String\"", { Token::STRING_LITERAL });
	ExpectTokens("\" String \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1String1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";String;\"", { Token::STRING_LITERAL });

	ExpectTokens("\"Void\"", { Token::STRING_LITERAL });
	ExpectTokens("\" Void \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1Void1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";Void;\"", { Token::STRING_LITERAL });

	ExpectTokens("\"Array\"", { Token::STRING_LITERAL });
	ExpectTokens("\" Array \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1Array1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";Array;\"", { Token::STRING_LITERAL });
}

TEST(type_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//Integer", { });
	ExpectTokens("// Integer ", { });
	ExpectTokens("//1Integer1", { });
	ExpectTokens("//;Integer;", { });
	ExpectTokens("/*Integer*/", { });
	ExpectTokens("/* Integer */", { });
	ExpectTokens("/*1Integer1*/", { });
	ExpectTokens("/*;Integer;*/", { });
	ExpectTokens("/*Integer", { });
	ExpectTokens("/* Integer ", { });
	ExpectTokens("/*1Integer1", { });
	ExpectTokens("/*;Integer;", { });

	ExpectTokens("//Integer", { });
	ExpectTokens("// Float ", { });
	ExpectTokens("//1Float1", { });
	ExpectTokens("//;Float;", { });
	ExpectTokens("/*Float*/", { });
	ExpectTokens("/* Float */", { });
	ExpectTokens("/*1Float1*/", { });
	ExpectTokens("/*;Float;*/", { });
	ExpectTokens("/*Float", { });
	ExpectTokens("/* Float ", { });
	ExpectTokens("/*1Float1", { });
	ExpectTokens("/*;Float;", { });

	ExpectTokens("//String", { });
	ExpectTokens("// String ", { });
	ExpectTokens("//1String1", { });
	ExpectTokens("//;String;", { });
	ExpectTokens("/*String*/", { });
	ExpectTokens("/* String */", { });
	ExpectTokens("/*1String1*/", { });
	ExpectTokens("/*;String;*/", { });
	ExpectTokens("/*String", { });
	ExpectTokens("/* String ", { });
	ExpectTokens("/*1String1", { });
	ExpectTokens("/*;String;", { });

	ExpectTokens("//Void", { });
	ExpectTokens("// Void ", { });
	ExpectTokens("//1Void1", { });
	ExpectTokens("//;Void;", { });
	ExpectTokens("/*Void*/", { });
	ExpectTokens("/* Void */", { });
	ExpectTokens("/*1Void1*/", { });
	ExpectTokens("/*;Void;*/", { });
	ExpectTokens("/*Void", { });
	ExpectTokens("/* Void ", { });
	ExpectTokens("/*1Void1", { });
	ExpectTokens("/*;Void;", { });

	ExpectTokens("//Array", { });
	ExpectTokens("// Array ", { });
	ExpectTokens("//1Array1", { });
	ExpectTokens("//;Array;", { });
	ExpectTokens("/*Array*/", { });
	ExpectTokens("/* Array */", { });
	ExpectTokens("/*1Array1*/", { });
	ExpectTokens("/*;Array;*/", { });
	ExpectTokens("/*Array", { });
	ExpectTokens("/* Array ", { });
	ExpectTokens("/*1Array1", { });
	ExpectTokens("/*;Array;", { });
}