#pragma once
#include "Page.h"
#include "Post.h"

#include "StringUtil.h" // Include StringUtil.h for string manipulation functions

class User {
private:
    char* uniqueID;
    char* firstName;
    char* lastName;
    User** friendList;
    Page** likedPagesList;
    Post** postByUser;
    int friendsCount;
    int likedPagesCount;
    int totalSharePagesCount;
    Post** userTimeline;
    int timelineSize;

public:
    User(const char* ID, const char* fName, const char* lName);
    ~User();

    void addFriendsInList(User* friendId);
    void addLikePagesInList(Page* pageId);
    void commentOnPostByUser(Post& post);
    void Posting(Page& page, Post post);
    void printFriendList();
    void printLikedPages();
    void printTimeline();
    char* getFirstName() {
        return firstName;
    }
    char* getLastName() {
        return lastName;
    }
    char* getID() {
        return uniqueID;
    }
    int getLikeCount() {
        return likedPagesCount;
    }
    Post** getPosts() {
        return postByUser;
    }
    User** getFriendList() {
        return friendList;
    }
    int getFriendCount() {
        return friendsCount;
    }
};
