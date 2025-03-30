#include "Post.h"
#include <iostream>
#include <cstring>

Post::Post(const char* id, const char* desc)
    : UniqueID(nullptr),
    Description(nullptr),
    PostLikesCount(0),
    LikedBy(nullptr),
    LikedByCount(0),
    PostComments(nullptr),
    TotalCommentsCount(0),
    PostPage(nullptr){
    UniqueID = StringUtil::copyString(id);
    Description = StringUtil::copyString(desc);
}
Post::~Post() {
    delete[] UniqueID;
    delete[] Description;
    delete[] LikedBy;
    delete[] PostComments;
}


// Getters
char* Post::getUniqueID() const {
    return UniqueID;
}

char* Post::getDescription() const {
    return Description;
}

int Post::getPostLikesCount() const {
    return PostLikesCount;
}

User** Post::getLikedBy() const {
    return LikedBy;
}

int Post::getLikedByCount() const {
    return LikedByCount;
}

Date Post::getSharedDate() const {
    return SharedDate;
}

Comment** Post::getPostComments() const {
    return PostComments;
}

int Post::getTotalCommentsCount() const {
    return TotalCommentsCount;
}

Page* Post::getPostPage() const {
    return PostPage;
}

// Setters
void Post::setUniqueID(const char* id) {
    UniqueID = StringUtil::copyString(id);
}

void Post::setDescription(const char* desc) {
    Description = StringUtil::copyString(desc);
}

void Post::setPostLikesCount(int likesCount) {
    PostLikesCount = likesCount;
}

void Post::setLikedBy(User** likedBy) {
    LikedBy = likedBy;
}

void Post::setLikedByCount(int likedByCount) {
    LikedByCount = likedByCount;
}

void Post::setSharedDate(Date date) {
    SharedDate = date;
}

void Post::setPostComments(Comment** comments) {
    PostComments = comments;
}

void Post::setTotalCommentsCount(int commentsCount) {
    TotalCommentsCount = commentsCount;
}

void Post::setPostPage(Page* page) {
    PostPage = page;
}

// Other methods
void Post::SetDate(int day, int month, int year) {
    SharedDate.setDay(day);
    SharedDate.setMonth(month);
    SharedDate.setYear(year);
}


void Post::AddaLike() {
    ++PostLikesCount;
}

void Post::AddaComment(char* commentText) {
    if (TotalCommentsCount == 0) {
        PostComments = new Comment * [1];
    }
    else {
        Comment** temp = new Comment * [TotalCommentsCount + 1];
        for (int i = 0; i < TotalCommentsCount; ++i) {
            temp[i] = PostComments[i];
        }
        delete[] PostComments;
        PostComments = temp;
    }
    PostComments[TotalCommentsCount++] = new Comment(commentText);
}

void Post::PrintComments() {
    std::cout << "Comments on Post: " << Description << std::endl;
    for (int i = 0; i < TotalCommentsCount; ++i) {
        std::cout << "Comment " << i + 1 << ": " << PostComments[i]->getComment() << std::endl;
    }
}

void Post::PrintDate() {
    std::cout << "Shared Date: " << SharedDate.getDay() << "/" << SharedDate.getMonth() << "/" << SharedDate.getYear() << std::endl;
}

void Post::PrintPost() {
    std::cout << "Post ID: " << UniqueID << std::endl;
    std::cout << "Description: " << Description << std::endl;
    std::cout << "Likes: " << PostLikesCount << std::endl;
    std::cout << "Shared Date: " << SharedDate.getDay() << "/" << SharedDate.getMonth() << "/" << SharedDate.getYear() << std::endl;
}
Memory*Post::getMemories() const {
    return memories;
}



