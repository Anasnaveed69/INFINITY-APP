#include "Activity.h"
#include <cstring>

Activity::Activity(int t, const char* v) : type(t), value(nullptr) {
    value = new char[StringUtil::stringLength(v) + 1];
    value = StringUtil::copyString(v);
}

Activity::~Activity() {
    delete[] value;
}

int Activity::getType() const {
    return type;
}

const char* Activity::getValue() const {
    return value;
}

void Activity::PrintActivity() const {
    std::cout << "Activity Type: " << type << ", Value: " << value << std::endl;
}
