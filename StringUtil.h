#pragma once
#include<cstring>
class StringUtil {
public:
    static char* copyString( char* source) {
        char* dest = new char[strlen(source) + 1];
        strcpy(dest, source);
        return dest;
    }

    static void deleteString(char* str) {
        delete[] str;
    }

    static int stringLength(const char* str) {
        return strlen(str);
    }

    static int stringCompare(const char* str1, const char* str2) {
        return strcmp(str1, str2);
    }

    // Add more string manipulation functions as needed
};
