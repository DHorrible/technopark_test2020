#include "utility.h"

std::vector<std::string> split(const std::string& s, char separator) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream token_stream(s);
	while (std::getline(token_stream, token, separator)) {
		tokens.emplace_back(token);
	}
	return tokens;
}