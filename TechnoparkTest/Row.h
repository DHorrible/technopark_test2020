#pragma once

#include "utility.h"

class Row {
private:
	std::vector<std::string> vals;
public:
	class Iterator;

	const std::string& at(size_t i) const;
	std::string& operator[](size_t i);
	Row& set(size_t i, const std::string& val);

	std::string get_raw() const;
	Row& from_raw(const std::string& raw);

	size_t size() const;
	
	Iterator begin();
	Iterator end();

	Row& clear();

	friend std::istream& operator>>(std::istream& in, Row& row);
	friend std::ostream& operator<<(std::ostream& out, const Row& row);

	explicit Row(std::string raw = "");

	class Iterator {
	private:
		std::string* ptr;
	public:
		Iterator(std::string* ptr);

		Iterator operator+ (int n) const;
		Iterator operator- (int n) const;

		Iterator& operator-- ();
		Iterator& operator++ ();
		Iterator operator-- (int);
		Iterator operator++ (int);

		bool operator!= (const Iterator& it) const;
		bool operator== (const Iterator& it) const;
		std::string& operator* () const;
	};
};

class RowOutOfRangeException : public std::exception {
	const char* what() const throw ();
};
