#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#define STD_SEPARATOR '\t'

std::vector<std::string> split(const std::string& s, char delimiter = STD_SEPARATOR);
