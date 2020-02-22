#include "Row.h"

void print_row(Row& row) {
	for (size_t i(0); i < row.size(); i++) {
		std::cout << "std::cout << row[" << i << "]: " << row[i] << std::endl;
		std::cout << "std::cout << row.at(" << i << "): " << row.at(i) << std::endl;
	}
}

void log_info(const std::string& s) {
	std::cout << "INFO: " << s << std::endl;
}

int main() {
	std::string input;
	Row row;

	while (std::getline(std::cin, input)) {
		log_info("Let's print more");
		row = Row(input);
		std::cout << "std::cout << row: " << row << std::endl;
		log_info("Print raw");
		std::cout << row.get_raw() << std::endl;
		print_row(row);
		if (row.size() > 0) {
			log_info("Set (row.set) the first value 'is_temp_value_for_set'");
			row.set(0, "is_temp_value_for_set");
			print_row(row);
			log_info("Set (row.[]) the first value 'is_temp_value_for_brackets'");
			row[0] = "is_temp_value_for_brackets";
			print_row(row);
		}
		log_info("foreach start");
		for (const auto& t : row) {
			std::cout << t << std::endl;
		}
		std::cout << "row.clear: " << row.clear() << std::endl;
	}

	return 0;
}