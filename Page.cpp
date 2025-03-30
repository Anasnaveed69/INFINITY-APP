#include "Page.h"
#include <iostream>

Page::Page(const char* ID, User* owner, const char* pageTitle)
    : uniqueID(nullptr),
    actualOwner(owner),
    title(nullptr),
    sharedPosts(nullptr),
    postsCount(0),
    totalLikes(0) {
    uniqueID = StringUtil::copyString(ID);
    title = StringUtil::copyString(pageTitle);
}

Page::~Page() {
    StringUtil::deleteString(uniqueID);
    StringUtil::deleteString(title);
    // Delete sharedPosts array and its elements
    if (sharedPosts != nullptr) {
        for (int i = 0; i < postsCount; ++i) {
            delete sharedPosts[i];
        }
        delete[] sharedPosts;
    }
}

void Page::ViewPostsByUser(Post& post) {
    std::cout << "Viewing post: " << post.getDescription() << std::endl;
}

void Page::changeOwner(User& newOwner) {
    actualOwner = &newOwner;
    std::cout << "Owner of the page changed to: " << newOwner.getFirstName() << " " << newOwner.getLastName() << std::endl;
}

void Page::addPost(Post& newPost) {
    if (sharedPosts == nullptr) {
        sharedPosts = new Post * [1];
    }
    else {
        Post** temp = new Post * [postsCount + 1];
        for (int i = 0; i < postsCount; ++i) {
            temp[i] = sharedPosts[i];
        }
        delete[] sharedPosts;
        sharedPosts = temp;
    }
    sharedPosts[postsCount++] = &newPost;
    std::cout << "New post added to the page: " << newPost.getDescription() << std::endl;
}
