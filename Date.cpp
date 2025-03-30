#include "Date.h"
#include <iostream>

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

Date::~Date() {}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::PrintDate() const {
    std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
}