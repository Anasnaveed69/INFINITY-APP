#include "Comment.h"
#include <iostream>
#include <cstring>


Comment::Comment(const char* text) {
    comment = new char[strlen(text) + 1];
    strcpy(comment, text);
    postID = nullptr;
    userIDs = nullptr;
}

Comment::~Comment() {
    delete[] comment;
    if (postID)
        delete[] postID;
    if (userIDs) {
        for (int i = 0; userIDs[i] != nullptr; ++i) {
            delete[] userIDs[i];
        }
        delete[] userIDs;
    }
}

void Comment::printComment() {
    std::cout << "Comment: " << comment << std::endl;
}

char* Comment::getComment() {
    return comment;
}

void Comment::setUserIDs(char** ids) {
    int count = 0;
    // Count the number of user IDs
    while (ids[count] != nullptr) {
        ++count;
    }
    // Allocate memory for user IDs
    userIDs = new char* [count + 1];
    // Copy user IDs
    for (int i = 0; i < count; ++i) {
        userIDs[i] = new char[strlen(ids[i]) + 1];
        strcpy(userIDs[i], ids[i]);
    }
    // Set the last element of the array to nullptr to mark the end
    userIDs[count] = nullptr;
}

char** Comment::getUserIDs() {
    return userIDs;
}

void Comment::setPostID(const char* id) {
    postID = new char[strlen(id) + 1];
    strcpy(postID, id);
}

char* Comment::getPostID() {
    return postID;
}

