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

Token* parseParenthesisedToken(int&, const std::string&);
Token* parseDecimalToken(int&, const std::string&);
Token* parseToken(int&, const std::string&);

int eval(const std::string);
void parseWhitespace(int&, const std::string&);
void checkBounds(int&, const std::string&);
void check(int&, const std::string&);

class Token {

public:
	virtual int evaluate() = 0;

	virtual ~Token() {
	}
};

class ParenthesiseToken: public Token {

	const std::string evalInput;

public:
	ParenthesiseToken(const std::string evalInput) :
			evalInput(evalInput) {
	}

	virtual int evaluate() override {
		return eval(evalInput);
	}
	virtual ~ParenthesiseToken() {
	}
};

int eval(const std::string evalInput) {

	return 1;
}

// Iterate over whitespace.
void parseWhitespace(int &itr, const std::string &evalInput) {

	while (evalInput[itr] == ' ' || evalInput[itr] == '\t'
			|| evalInput[itr] == '\n') {
		checkBounds(itr, evalInput);
		itr++;
	}
}

// Check current position is still within bounds of input string.
void checkBounds(int &itr, const std::string &evalInput) {

	if (evalInput.length() <= (typeof(evalInput.length())) itr)
		return;
	else
		throw std::runtime_error("Out of bounds.");
}

// Check all possible disabilities at once.
void check(int &itr, const std::string &evalInput) {
	parseWhitespace(itr, evalInput);
	checkBounds(itr, evalInput);

}

//Any number of operator and operand pairs.
inline Token* parseParenthesisedToken(int &itr, const std::string &evalInput) {
	check(itr, evalInput);

	// Capture the location of opening and closing parenthesise.
	int prths = 1, prthsStartPos = itr;

	// Iterate through all parenthesise to find matching pairs.
	while (prths) {
		itr++;
		parseWhitespace(itr, evalInput);

		(evalInput[itr] == '(') ? prths++ :
		(evalInput[itr] == ')') ? prths-- : 1;
	}
	return new ParenthesiseToken(
			evalInput.substr(prthsStartPos, itr - prthsStartPos));
}

inline Token* parseToken(int &itr, const std::string &evalInput) {
	return nullptr;
}

inline Token* parseDecimalToken(int &itr, const std::string &evalInput) {
	return nullptr;
}

inline Token* parseOperands(int &itr, const std::string &evalInput) {
	return nullptr;
}

inline Token* parseOperator(int &itr, const std::string &evalInput) {
	return nullptr;
}

void parse(std::string evalInput) {

	std::vector<Token*> tokens;

	// Save the position within the evalInput string.
	int itr { };

	check(itr, evalInput);

	switch (evalInput[0]) {

	case '(':
		tokens.push_back(parseParenthesisedToken(itr, evalInput));
		break;

	case '.':
		tokens.push_back(parseDecimalToken(itr, evalInput));
		break;

	case '0' ... '9':
		tokens.push_back(parseToken(itr, evalInput));
		break;

	default:
		;

		//TODO Error - Invalid token
	}
}
}

int main() {

	return 0;
}
