#pragma once
#include "User.h" // Include User.h for User class
#include "Post.h" // Include Post.h for Post class

class Page {
private:
    char* uniqueID;
    User* actualOwner;
    char* title;
    Post** sharedPosts;
    int postsCount;
    int totalLikes;

public:
    Page(const char* ID, User* owner, const char* pageTitle);
    ~Page();

    void ViewPostsByUser(Post& post);
    void changeOwner(User& newOwner);
    void addPost(Post& newPost);
    char* getTitle() {
        return title;
    }
    Post** getPosts() {
        return sharedPosts;
    }
    int getPostCount() {
        return postsCount;
    }
    char* getID() {
        return uniqueID;
    }
        
};
