#include "User.h"
#include <iostream>

User::User(const char* ID, const char* fName, const char* lName)
    : uniqueID(nullptr), 
      firstName(nullptr), 
      lastName(nullptr), 
      friendList(nullptr), 
      likedPagesList(nullptr), 
      postByUser(nullptr), 
      friendsCount(0), 
      likedPagesCount(0), 
      totalSharePagesCount(0), 
      userTimeline(nullptr),
      timelineSize(0) {
    uniqueID = StringUtil::copyString(ID);
    firstName = StringUtil::copyString(fName);
    lastName = StringUtil::copyString(lName);
}

User::~User() {
    StringUtil::deleteString(uniqueID);
    StringUtil::deleteString(firstName);
    StringUtil::deleteString(lastName);
    // Delete other dynamically allocated memory
}

void User::addFriendsInList(User* friendId) {
    if (friendsCount == 0) {
        friendList = new User*[1];
    } else {
        User** temp = new User*[friendsCount + 1];
        for (int i = 0; i < friendsCount; ++i) {
            temp[i] = friendList[i];
        }
        delete[] friendList;
        friendList = temp;
    }
    friendList[friendsCount++] = friendId;
}

void User::addLikePagesInList(Page* pageId) {
    if (likedPagesCount == 0) {
        likedPagesList = new Page*[1];
    } else {
        Page** temp = new Page*[likedPagesCount + 1];
        for (int i = 0; i < likedPagesCount; ++i) {
            temp[i] = likedPagesList[i];
        }
        delete[] likedPagesList;
        likedPagesList = temp;
    }
    likedPagesList[likedPagesCount++] = pageId;
}

void User::commentOnPostByUser(Post& post) {
    // Implementation logic here
    std::cout << "Commented on post: " << post.getDescription() << std::endl;
}

void User::Posting(Page& page, Post post) {
    // Implementation logic here
    std::cout << "Posted on page: " << page.getTitle() << " - " << post.getDescription() << std::endl;
}

void User::printFriendList() {
    std::cout << "Friend List of " << firstName << " " << lastName << ":\n";
    for (int i = 0; i < friendsCount; ++i) {
        std::cout << friendList[i]->uniqueID << " - " << friendList[i]->firstName << " " << friendList[i]->lastName << std::endl;
    }
}

void User::printLikedPages() {
    std::cout << "Liked Pages of " << firstName << " " << lastName << ":\n";
    for (int i = 0; i < likedPagesCount; ++i) {
        std::cout << likedPagesList[i]->getTitle() << std::endl;
    }
}

void User::printTimeline() {
    std::cout << "Timeline of " << firstName << " " << lastName << ":\n";
    for (int i = 0; i < timelineSize; ++i) {
        std::cout << userTimeline[i]->getDescription() << " - ";
        std::cout << userTimeline[i]->getSharedDate().getDay() << "/";
        std::cout << userTimeline[i]->getSharedDate().getMonth() << "/";
        std::cout << userTimeline[i]->getSharedDate().getYear() << std::endl;
    }
}
