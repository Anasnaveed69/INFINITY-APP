#pragma once
#include <iostream>

class Comment {
private:
    char* comment;
    char** userIDs; // Array to store user IDs associated with the comment
    char* postID; // Variable to store the post ID associated with the comment

public:
    Comment(const char* text);
    ~Comment();

    void printComment();
    char* getComment();
    void setUserIDs(char** ids);
    char** getUserIDs();
    void setPostID(const char* id);
    char* getPostID();
};
