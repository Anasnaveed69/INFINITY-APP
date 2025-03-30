#pragma once

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int d, int m, int y);
    ~Date();

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void PrintDate() const;
    void setDay(int d) {
        day = d;
    }

    void setMonth(int m) {
        month = m;
    }

    void setYear(int y) {
        year = y;
    }

};