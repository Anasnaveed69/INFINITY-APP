#include "SocialNetworkingApp.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

User* currentUser = nullptr;

SocialNetworkingApp::SocialNetworkingApp()
    : users(nullptr), userCount(0), pages(nullptr), pageCount(0),
    posts(nullptr), postCount(0), comments(nullptr), commentCount(0) {}

SocialNetworkingApp::~SocialNetworkingApp() {
    for (int i = 0; i < userCount; ++i) delete users[i];
    delete[] users;
    for (int i = 0; i < pageCount; ++i) delete pages[i];
    delete[] pages;
    for (int i = 0; i < postCount; ++i) delete posts[i];
    delete[] posts;
    for (int i = 0; i < commentCount; ++i) delete comments[i];
    delete[] comments;
}

void SocialNetworkingApp::run() {
    loadUsers("User.txt");
    loadPages("Pages.txt");
    loadPosts("Posts.txt");
    loadComments("Comments.txt");

    setCurrentUser();

    viewHome(currentUser);

    likePost();

    viewLikedPeople();

    commentOnPost();

    viewPost();

    shareMemory();

    viewTimeline();

    viewFriendList();

    viewPage();

    displayMenu();
}

void SocialNetworkingApp::end() {
    // Save user data to a file
    saveUsers("User.txt");
    // Save page data to a file
    savePages("Pages.txt");
    // Save post data to a file
    savePosts("Posts.txt");
    // Save comment data to a file
    saveComments("Comments.txt");

    std::cout << "Data saved successfully. Exiting the application." << std::endl;
}
void SocialNetworkingApp::saveUsers(const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Write the number of users
    file << userCount << std::endl;

    // Write user data to the file
    for (int i = 0; i < userCount; ++i) {
        file << users[i]->getID() << " " << users[i]->getFirstName() << " " << users[i]->getLastName() << std::endl;
    }

    file.close();
}

void SocialNetworkingApp::savePages(const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Write the number of pages
    file << pageCount << std::endl;

    // Write page data to the file
    for (int i = 0; i < pageCount; ++i) {
        file << pages[i]->getID() << " " << pages[i]->getTitle() << std::endl;
    }

    file.close();
}

void SocialNetworkingApp::savePosts(const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Write the number of posts
    file << postCount << std::endl;

    // Write post data to the file
    for (int i = 0; i < postCount; ++i) {
        file << posts[i]->getUniqueID() << " " << posts[i]->getDescription() << std::endl;
    }

    file.close();
}

void SocialNetworkingApp::saveComments(const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Write the number of comments
    file << commentCount << std::endl;

    // Write comment data to the file
    for (int i = 0; i < commentCount; ++i) {
        // Get user IDs associated with the comment
        char** userIDs = comments[i]->getUserIDs();

        // Write user IDs to the file
        for (int j = 0; userIDs[j] != nullptr; ++j) {
            file << userIDs[j] << " ";
        }

        // Write post ID, user ID, and comment text to the file
        file << comments[i]->getPostID() << " " << comments[i]->getUserIDs() << " " << comments[i]->getComment() << std::endl;
    }

    file.close();
}



void SocialNetworkingApp::loadUsers(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    int count;
    file >> count;
    users = new User * [count];

    for (int i = 0; i < count; ++i) {
        char* ID = new char[10];
        char* firstName = new char[50];
        char* lastName = new char[50];
        file >> ID >> firstName >> lastName;
        users[i] = new User(ID, firstName, lastName);
        delete[] ID;
        delete[] firstName;
        delete[] lastName;
    }

    userCount = count;
}

void SocialNetworkingApp::loadPages(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    int count;
    file >> count;
    pages = new Page * [count];

    for (int i = 0; i < count; ++i) {
        char* ID = new char[10];
        char* pageTitle = new char[50];
        file >> ID >> pageTitle;
        pages[i] = new Page(ID, nullptr, pageTitle); // Set owner as nullptr for now
        delete[] ID;
        delete[] pageTitle;
    }

    pageCount = count;
}


void SocialNetworkingApp::loadPosts(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    int count;
    file >> count;
    posts = new Post * [count];

    for (int i = 0; i < count; ++i) {
        char* ID = new char[10];
        char* desc = new char[100];
        file >> ID >> desc;
        posts[i] = new Post(ID, desc);
        delete[] ID;
        delete[] desc;
    }

    postCount = count;
}

void SocialNetworkingApp::loadComments(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    int count;
    file >> count;
    comments = new Comment * [count];

    for (int i = 0; i < count; ++i) {
        char* ID = new char[10];
        char* postID = new char[10];
        char* userID = new char[10];
        char* commentText = new char[100];
        file >> ID >> postID >> userID >> commentText;
        comments[i] = new Comment(commentText);
        delete[] ID;
        delete[] postID;
        delete[] userID;
        delete[] commentText;
    }

    commentCount = count;
}



void SocialNetworkingApp::displayMenu() {
    std::cout << "Main Menu:" << std::endl;
    std::cout << "1. View Friend List" << std::endl;
    std::cout << "2. View Liked Pages" << std::endl;
    std::cout << "3. View Home" << std::endl;
    std::cout << "9. Quit" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    handleUserInput(choice);
}

void SocialNetworkingApp::handleUserInput(int choice) {
    switch (choice) {
    case 1:
        viewFriendList();
        break;
    case 2:
        viewLikedPeople();
        break;
    case 3:
        viewHome(currentUser);
        break;
    case 9:
        end();
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
    }
}

void SocialNetworkingApp::setCurrentUser() {
    std::string userID;
    std::cout << "Enter your user ID: ";
    std::cin >> userID;

    for (int i = 0; i < userCount; ++i) {
        if (strcmp(users[i]->getID(), userID.c_str()) == 0) {
            currentUser = users[i];
            std::cout << "Welcome, " << currentUser->getFirstName() << " " << currentUser->getLastName() << "!" << std::endl;
            return;
        }
    }

    std::cout << "User not found!" << std::endl;
}

void SocialNetworkingApp::viewHome(User* user) {
    std::cout << "Home of " << user->getFirstName() << " " << user->getLastName() << ":" << std::endl;
    std::time_t currentTime = std::time(nullptr);
    // Implement viewing posts of friends and liked pages within last 24 hours
}

void SocialNetworkingApp::likePost() {
    char postID[10];
    std::cout << "Enter the ID of the post you want to like: ";
    std::cin >> postID;

    // Find the post
    Post* post = nullptr;
    for (int i = 0; i < postCount; ++i) {
        bool found = true;
        for (int j = 0; j < 10; ++j) {
            if (posts[i]->getUniqueID()[j] != postID[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            post = posts[i];
            break;
        }
    }

    if (post) {
        // Check if the post can be liked
        if (post->getPostLikesCount() < 10) {
            // Like the post
            post->AddaLike();
            std::cout << "Post liked successfully!" << std::endl;
        }
        else {
            std::cout << "Sorry, this post has reached the maximum number of likes." << std::endl;
        }
    }
    else {
        std::cout << "Post not found!" << std::endl;
    }
}

void SocialNetworkingApp::viewLikedPeople() {
    char postID[10];
    std::cout << "Enter the ID of the post you want to view likes for: ";
    std::cin >> postID;

    // Find the post
    Post* post = nullptr;
    for (int i = 0; i < postCount; ++i) {
        bool found = true;
        for (int j = 0; j < 10; ++j) {
            if (posts[i]->getUniqueID()[j] != postID[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            post = posts[i];
            break;
        }
    }

    if (post) {
        // Get the users who liked the post
        User** likedBy = post->getLikedBy();
        int likedByCount = post->getLikedByCount();

        if (likedByCount > 0) {
            std::cout << "People who liked the post:" << std::endl;
            for (int i = 0; i < likedByCount; ++i) {
                std::cout << likedBy[i]->getFirstName() << " " << likedBy[i]->getLastName() << std::endl;
            }
        }
        else {
            std::cout << "No one has liked this post yet." << std::endl;
        }
    }
    else {
        std::cout << "Post not found!" << std::endl;
    }
}


void SocialNetworkingApp::commentOnPost() {
    char postID[10];
    std::cout << "Enter the ID of the post you want to comment on: ";
    std::cin >> postID;

    // Find the post
    Post* post = nullptr;
    for (int i = 0; i < postCount; ++i) {
        bool found = true;
        for (int j = 0; j < 10; ++j) {
            if (posts[i]->getUniqueID()[j] != postID[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            post = posts[i];
            break;
        }
    }

    if (post) {
        // Get comment text
        char commentText[100];
        std::cout << "Enter your comment: ";
        std::cin.ignore(); // Ignore previous newline character
        std::cin.getline(commentText, 100);

        // Add the comment to the post
        post->AddaComment(commentText);

        std::cout << "Comment added successfully!" << std::endl;
    }
    else {
        std::cout << "Post not found!" << std::endl;
    }
}


void SocialNetworkingApp::viewPost() {
    char postID[10];
    std::cout << "Enter the ID of the post you want to view: ";
    std::cin >> postID;

    // Find the post
    Post* post = nullptr;
    for (int i = 0; i < postCount; ++i) {
        bool found = true;
        for (int j = 0; j < 10; ++j) {
            if (posts[i]->getUniqueID()[j] != postID[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            post = posts[i];
            break;
        }
    }

    if (post) {
        // Display post details
        post->PrintPost();

        // Display post comments
        post->PrintComments();
    }
    else {
        std::cout << "Post not found!" << std::endl;
    }
}


void SocialNetworkingApp::shareMemory() {
    char postID[10];
    char memoryText[100];

    std::cout << "Enter the ID of the post you want to attach the memory to: ";
    std::cin >> postID;

    // Find the post
    Post* post = nullptr;
    for (int i = 0; i < postCount; ++i) {
        if (strcmp(posts[i]->getUniqueID(), postID) == 0) {
            post = posts[i];
            break;
        }
    }

    if (!post) {
        std::cout << "Post not found!" << std::endl;
        return;
    }

    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter the text of the memory: ";
    std::cin.getline(memoryText, 100);

    // Create a new memory object with the specified post as reference
    Memory* memory = new Memory(post, memoryText);

    // Add the memory to the post
    memory->addMemory(memory);

    std::cout << "Memory shared successfully!" << std::endl;
}



void SocialNetworkingApp::viewTimeline() {
    // Check if a current user is set
    if (!currentUser) {
        std::cout << "No current user set. Please set a user first." << std::endl;
        return;
    }

    // Display user's name
    std::cout << "Timeline of " << currentUser->getFirstName() << " " << currentUser->getLastName() << ":" << std::endl;

    // Get the array of posts from the current user
    Post** userPosts = currentUser->getPosts();

    // Iterate through the current user's posts and display them
    for (int i = 0; i < currentUser->getLikeCount(); ++i) {
        Post* post = userPosts[i];
        std::cout << "Post ID: " << post->getUniqueID() << std::endl;
        std::cout << "Description: " << post->getDescription() << std::endl;
        std::cout << "Shared Date: " << post->getSharedDate().getDay() << "/" << post->getSharedDate().getMonth() << "/" << post->getSharedDate().getYear() << std::endl;
        std::cout << "Likes: " << post->getPostLikesCount() << std::endl;
        std::cout << "Comments: " << post->getTotalCommentsCount() << std::endl;
        std::cout << std::endl;
    }
}


void SocialNetworkingApp::viewFriendList() {
    // Check if a current user is set
    if (!currentUser) {
        std::cout << "No current user set. Please set a user first." << std::endl;
        return;
    }

    // Display user's friend list
    std::cout << "Friend List of " << currentUser->getFirstName() << " " << currentUser->getLastName() << ":" << std::endl;

    // Get the array of friends from the current user
    User** friendList = currentUser->getFriendList();

    // Iterate through the friend list and display each friend's details
    for (int i = 0; i < currentUser->getFriendCount(); ++i) {
        User* friendUser = friendList[i];
        std::cout << "Friend ID: " << friendUser->getID() << std::endl;
        std::cout << "Name: " << friendUser->getFirstName() << " " << friendUser->getLastName() << std::endl;
        std::cout << std::endl;
    }
}

void SocialNetworkingApp::viewPage() {
    // Check if a current user is set
    if (!currentUser) {
        std::cout << "No current user set. Please set a user first." << std::endl;
        return;
    }

    // Ask for the page ID
    std::string pageID;
    std::cout << "Enter the ID of the page you want to view: ";
    std::cin >> pageID;

    // Find the page
    Page* page = nullptr;
    for (int i = 0; i < pageCount; ++i) {
        if (strcmp(pages[i]->getID(), pageID.c_str()) == 0) {
            page = pages[i];
            break;
        }
    }

    if (!page) {
        std::cout << "Page not found!" << std::endl;
        return;
    }

    // Display page's posts
    std::cout << "Posts on Page '" << page->getTitle() << "':" << std::endl;

    // Get the array of posts from the page
    Post** posts = page->getPosts();

    // Iterate through the posts and display each post's details
    for (int i = 0; i < page->getPostCount(); ++i) {
        Post* post = posts[i];
        std::cout << "Post ID: " << post->getUniqueID() << std::endl;
        std::cout << "Description: " << post->getDescription() << std::endl;
        std::cout << "Shared Date: " << post->getSharedDate().getDay() << "/" << post->getSharedDate().getMonth() << "/" << post->getSharedDate().getYear() << std::endl;
        std::cout << "Likes: " << post->getPostLikesCount() << std::endl;
        std::cout << "Comments: " << post->getTotalCommentsCount() << std::endl;
        std::cout << std::endl;
    }
}
