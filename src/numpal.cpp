#include <stdexcept>
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

bool checkAll(int &itr, std::string &evalInput);
void parseWhiteSpace(int &itr, std::string &evalInput);
bool checkBounds(int &itr, std::string &evalInput);

struct Token {

};

void eval(std::string input) {
}

// Check all disabilities
bool check(int &itr, std::string &evalInput) {

	parseWhiteSpace(itr, evalInput);
	return checkBounds(itr, evalInput);
}

// Iterate over whitespace.
void parseWhiteSpace(int &itr, std::string &evalInput) {

	while (evalInput[itr] == ' ' || evalInput[itr] == '\t' || evalInput[itr] == '\n' )
		itr++;
}

// Check current position is still within bounds of input string.
bool checkBounds(int &itr, std::string &evalInput) {

	if (evalInput.length() <= itr)
		return false;
	else
		throw std::runtime_error("Out of bounds.");
}

//Any number of operator and operand pairs.
inline Token parseParenthesisedToken(int &itr, const std::string &evalInput) {

	// Capture the location of opening and closing parenthesise.
	int prths = 1, prthsStartPos = itr, prthsEndPos { };

	// Iterate through all parenthesise to find matching pairs.
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

