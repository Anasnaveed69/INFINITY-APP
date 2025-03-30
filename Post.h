#pragma once
#include "User.h" // Include User.h for User class
#include "Page.h" // Include Page.h for Page class
#include"Comment.h"
#include"Date.h"
#include"Memory.h"
class Post {
private:
    char* UniqueID;
    char* Description;
    int PostLikesCount;
    User** LikedBy;
    int LikedByCount;
    Date SharedDate;
    Comment** PostComments;
    int TotalCommentsCount;
    Page* PostPage;
    Memory*memories;
    int memoryCount;

public:
   
    Post(const char* id, const char* desc);
    ~Post();

    // Getters
    char* getUniqueID() const;
    char* getDescription() const;
    int getPostLikesCount() const;
    User** getLikedBy() const;
    int getLikedByCount() const;
    Date getSharedDate() const;
    Comment** getPostComments() const;
    int getTotalCommentsCount() const;
    Page* getPostPage() const;

    // Setters
    void setUniqueID(const char* id);
    void setDescription(const char* desc);
    void setPostLikesCount(int likesCount);
    void setLikedBy(User** likedBy);
    void setLikedByCount(int likedByCount);
    void setSharedDate(Date date);
    void setPostComments(Comment** comments);
    void setTotalCommentsCount(int commentsCount);
    void setPostPage(Page* page);

    // Other methods
    void SetDate(int day, int month, int year);
    void AddaLike();
    void AddaComment(char* commentText);
    void PrintComments();
    void PrintDate();
    void PrintPost();
    

    Memory* getMemories() const;
   
};