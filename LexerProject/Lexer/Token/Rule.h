#ifndef TOKEN_RULE_H
#define TOKEN_RULE_H

#include <set>

namespace
{
	class Rule
	{
	public:
		static bool IsLetter(char ch)
		{
			return UPPERCASE_LETTERS.find(ch) != UPPERCASE_LETTERS.end()
				|| LOWERCASE_LETTERS.find(ch) != LOWERCASE_LETTERS.end();
		}

		static bool IsIdentifier(std::string const& str)
		{
			if (
				str.empty()
				||
				(
					!IsLetter(str.front())
					&& !IsIdentifierSpecialCharacter(str.front())
				)
			)
			{
				return false;
			}
			for (size_t i = 1; i < str.length(); ++i)
			{
				if (
					!Rule::IsLetter(str.at(i))
					&& !Rule::IsDigit(str.at(i))
					&& !IsIdentifierSpecialCharacter(str.front())
				)
				{
					return false;
				}
			}
			return true;
		}

		static bool IsDigit(char ch, size_t numberSystem = Constant::Number::DEFAULT_SYSTEM)
		{
			if (numberSystem == Constant::Number::DEFAULT_SYSTEM)
			{
				return DIGITS.find(ch) != DIGITS.end();
			}

			std::set<char> availableSymbols;
			size_t i = 0;
			for (char digit : DIGITS)
			{
				if (i == numberSystem)
				{
					break;
				}
				availableSymbols.emplace(digit);
				++i;
			}
			for (char uppercaseLetter : UPPERCASE_LETTERS)
			{
				if (i == numberSystem)
				{
					break;
				}
				availableSymbols.emplace(uppercaseLetter);
				++i;
			}
			return availableSymbols.find(ch) != availableSymbols.end();
		}

		static bool IsInteger(
			std::string const& str,
			size_t fromIndex,
			size_t & failIndex,
			std::string & goodString,
			size_t system = Constant::Number::DEFAULT_SYSTEM
		)
		{
			if (str.empty())
			{
				return true;
			}
			size_t i = fromIndex;
			for (i; i < str.length(); ++i)
			{
				if (!Rule::IsDigit(str.at(i), system))
				{
					failIndex = i;
					goodString = str.substr(fromIndex, i - fromIndex);
					return false;
				}
			}
			return true;
		}

	private:
		static bool IsIdentifierSpecialCharacter(char ch)
		{
			return IDENTIFIER_SPECIAL_CHARACTERS.find(ch) != IDENTIFIER_SPECIAL_CHARACTERS.end();
		}

		static std::set<char> const UPPERCASE_LETTERS;
		static std::set<char> const LOWERCASE_LETTERS;
		static std::set<char> const DIGITS;
		static std::set<char> const IDENTIFIER_SPECIAL_CHARACTERS;
	};
}

std::set<char> const Rule::UPPERCASE_LETTERS
{
	'A',
	'B',
	'C',
	'D',
	'E',
	'F',
	'G',
	'H',
	'I',
	'J',
	'K',
	'L',
	'M',
	'N',
	'O',
	'P',
	'Q',
	'R',
	'S',
	'T',
	'U',
	'V',
	'W',
	'X',
	'Y',
	'Z'
};

std::set<char> const Rule::LOWERCASE_LETTERS
{
	'a',
	'b',
	'c',
	'd',
	'e',
	'f',
	'g',
	'h',
	'i',
	'j',
	'k',
	'l',
	'm',
	'n',
	'o',
	'p',
	'q',
	'r',
	's',
	't',
	'u',
	'v',
	'w',
	'x',
	'y',
	'z'
};

std::set<char> const Rule::DIGITS
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9'
};

std::set<char> const Rule::IDENTIFIER_SPECIAL_CHARACTERS = {
	Constant::Separator::UNDERSCORE_CHARACTER,
	'-'
};

#endif //TOKEN_RULE_H