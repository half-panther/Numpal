#include <string>
#include <vector>

/*
 * Possible input examples
 *
 * 4 * 8 + 2
 * 89 + (67 - 2) / 73
 *
 *(((((3)))
 *
 *
 *
 */

namespace pal {
class Token;

Token parseParenthesisedToken(int&, const std::string &evalInput);
Token parseDecimalToken(int &itr, const std::string &evalInput);
Token parseToken(int &itr, const std::string &evalInput);

struct Token {

};

void eval(std::string input) {
}

//Any number of operator and operand pairs.
inline Token parseParenthesisedToken(int &itr, const std::string &evalInput) {
	int prths = 1, prthsStartPos = itr, prthsEndPos { };

	while (prths) {
		itr++;

		(evalInput[itr] == '(') ? prths++ :
		(evalInput[itr] == ')') ? prths-- : 1;
	}
	prthsEndPos = itr;

	return Token { };
}

inline Token parseDecimalToken(int &itr, const std::string &evalInput) {
	return Token { };
}

inline Token parseToken(int &itr, const std::string &evalInput) {
	return Token { };
}

void parse(std::string input) {

	std::vector<Token> tokens;
	int itr { };

	switch (input[0]) {

	case '(':
		tokens.push_back(parseParenthesisedToken(itr, input));
		break;

	case '.':
		tokens.push_back(parseDecimalToken(itr, input));
		break;

	case '0' ... '9':
		tokens.push_back(parseToken(itr, input));
		break;

	default:
		;

		//TODO Error - Invalid token
	}
}
}

