#pragma once
#include <iostream>
#include"StringUtil.h"

class Activity {
private:
    int type;
    char* value;

public:
    Activity(int t, const char* v);
    ~Activity();

    int getType() const;
    const char* getValue() const;

    void PrintActivity() const;
};