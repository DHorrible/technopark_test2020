#include "Row.h"

const std::string& Row::at(size_t i) const {
	if (i > this->size()) {
		throw RowOutOfRangeException();
	}
	return (const std::string&)vals[i];
}

std::string& Row::operator[](size_t i) {
	if (i > this->size()) {
		throw RowOutOfRangeException();
	}
	return (std::string&)vals[i];
}

Row& Row::set(size_t i, const std::string& val) {
	if (i > this->size()) {
		throw RowOutOfRangeException();
	}
	this->vals[i] = val;
	return *this;
}

std::string Row::get_raw() const {
	std::string raw("");
	if (this->vals.size() > 0) {
		raw += this->vals[0];
		for (size_t i(1); i < this->vals.size(); i++) {
			raw += '\t' + this->vals[i];
		}
	}
	return std::move(raw);
}

Row& Row::from_raw(const std::string& raw) {
	this->vals = split(raw);
	return *this;
}

size_t Row::size() const {
	return this->vals.size();
}

Row::Iterator Row::begin() {
	if (!this->size()) {
		throw RowOutOfRangeException();
	}
	return Row::Iterator(&this->vals[0]);
}

Row::Iterator Row::end() {
	if (!this->size()) {
		throw RowOutOfRangeException();
	}
	return Row::Iterator(&this->vals[0] + this->vals.size());
}

Row& Row::clear() {
	this->vals.clear();
	return *this;
}

Row::Row(std::string raw) 
	: vals(split(raw)) 
{}

std::istream& operator>>(std::istream& in, Row& row) {
	std::string raw;
	std::getline(in, raw);
	row.from_raw(raw);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Row& row) {
	std::cout << "{ ";
	if (row.vals.size() > 0) {
		std::cout << row.vals[0];
		for (size_t i(1); i < row.vals.size(); i++) {
			std::cout << ", " << row.vals[i];
		}
	}
	std::cout << " }";
	return out;
}

Row::Iterator::Iterator(std::string* ptr) 
	: ptr(ptr)
{}

Row::Iterator Row::Iterator::operator+ (int n) const {
	return Row::Iterator(this->ptr + n);
}

Row::Iterator Row::Iterator::operator- (int n) const {
	return Row::Iterator(this->ptr - n);
}

Row::Iterator& Row::Iterator::operator-- () {
	--ptr;
	return *this;
}

Row::Iterator& Row::Iterator::operator++ () {
	++ptr;
	return *this;
}

Row::Iterator Row::Iterator::operator-- (int) {
	auto ret = *this;
	this->ptr--;
	return ret;
}

Row::Iterator Row::Iterator::operator++ (int) {
	auto ret = *this;
	this->ptr++;
	return ret;
}

bool Row::Iterator::operator!= (const Iterator& it) const {
	return ptr != it.ptr;
}

bool Row::Iterator::operator== (const Iterator& it) const {
	return ptr == it.ptr;
}

std::string& Row::Iterator::operator* () const {
	return *(this->ptr);
}

const char* RowOutOfRangeException::what() const throw () {
	return "Out of range";
}