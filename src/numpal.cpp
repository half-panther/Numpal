#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

namespace pal {
class Token;

void calculate(std::string calculatable) {

}

Token parseParenthesisedToken();
Token parseDecimal();
Token parseToken();

void parse(std::string input) {

	std::vector tokens;

	switch (input[0]) {

	case '(':
		tokens.push_back(parseParenthesisedToken());
		break;

	case '.':
		tokens.push_back(parseDecimal());
		break;

	case '0' ... '9':
		tokens.push_back(parseToken());
		break;

	default:

		//TODO error - Invalid token

	}

}

inline Token parseParenthesisedToken() {

	return "";
}

inline Token parseDecimal() {

	return "";
}

inline Token parseToken() {

	return "";
}
}

int main() {

	pal::calculate("4 + 2 + 6  s");

	return 0;
}

