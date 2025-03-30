#include "User.h"
#include "Page.h"
#include "Post.h"
#include "Comment.h"
#include"Memory.h"

class SocialNetworkingApp {
public:
    SocialNetworkingApp();
    ~SocialNetworkingApp();

    void run();
    void end();

private:
    User** users;
    int userCount;
    Page** pages;
    int pageCount;
    Post** posts;
    int postCount;
    Comment** comments;
    int commentCount;

    void loadUsers(const char* filename);
    void loadPages(const char* filename);
    void loadPosts(const char* filename);
    void loadComments(const char* filename);
    void saveUsers(const char* filename);
    void savePages(const char* filename);
    void saveComments(const char* filename);
    void savePosts(const char* filename);
    void displayMenu();
    void handleUserInput(int choice);

    void setCurrentUser();
    void viewHome(User* user);
    void likePost();
    void viewLikedPeople();
    void commentOnPost();
    void viewPost();
    void shareMemory();
    void viewTimeline();
    void viewFriendList();
    void viewPage();

};