Social Network Application (INFINITY-APP)  With GUI
<br>
Table of Contents
<br>
1.Project Overview
<br>
2.Features
<br>
3.Phases of Development
<br>
4.Execution Flow
<br>
5.Folder Structure
<br>
6.Setup Instructions
<br>
7.Usage
<br>
8.Contributing
<br>
1.Project Overview
<br>
The Social Network Application is a desktop-based graphical user interface (GUI) application designed to simulate a simplified version of a social media platform. It allows users to interact with posts, pages, friends, and memories in a structured and object-oriented manner. The application emphasizes clean design, separation of concerns, and adherence to best practices in Object-Oriented Programming (OOP).
This project is divided into two phases:
<br>
Phase I - Project Design : UML class diagram creation.
<br>
Phase II - Development : Implementation of the application with all required functionalities.
<br>
2.Features
<br>
Core Functionalities
<br>
Set Current User :
<br>
Allows the user to set themselves as the current user of the application.
<br>
View Home :
<br>
Displays posts from friends and liked pages shared in the last 24 hours.
<br>
Like a Post :
<br>
Enables users to like posts (up to 10 likes per post).
<br>
View Liked List :
<br>
Displays the list of users who have liked a specific post.
<br>
Comment on a Post :
<br>
Allows users to comment on posts (up to 10 comments per post).
<br>
View a Post :
<br>
Displays the post along with its comments.
<br>
Share a Memory :
<br>
Allows users to share memories by referencing an original post.
<br>
View User’s Profile :
<br>
Displays the user's name and their timeline posts.
<br>
View Friend List :
<br>
Displays the list of friends for a specific user.
<br>
View Page :
<br>
Displays all posts shared by a specific page.
<br>
Additional Features
<br>
Activity Posts : Posts can include activities such as feelings, thoughts, celebrations, etc.
<br>
Memory Posts : Special type of post that references an original post.
<br>
Dynamic Memory Allocation : All arrays are dynamically allocated to optimize memory usage.
<br>
Persistent Data Storage : User and page information is stored in .txt files for persistence.
<br>
<br>
Phases of Development
<br>
Phase I: Project Design
<br>
UML Class Diagram :
<br>
Created using tools like StarUML or Draw.io.
Includes all major classes, their attributes, methods, and relationships.
Excludes getters, setters, and constructors for clarity.
<br>
Phase II: Development
<br>
Implementation :
<br>
Full development of the application with all required functionalities.
<br>
Proper folder structuring and modular codebase.
<br>
Adherence to OOP principles and best practices.
<br>
Execution Flow
<br>
Entry Point :
<br>
The application starts with the SocialNetworkApp::Run() function in the main() method.
Responsibilities are delegated to appropriate classes for separation of concerns.
<br>
Manager/App Class :
<br>
Acts as the master/driver class for the application.
Handles user input and delegates tasks to other classes.
<br>
Dynamic Memory Management :
<br>
Arrays are dynamically allocated and deallocated to ensure efficient memory usage.
<br>
Persistence :
<br>
User and page information is stored in .txt files for runtime persistence.
<br>

Setup Instructions
<br>
Prerequisites
<br>
C++ Compiler : Ensure you have a C++ compiler installed (e.g., GCC or Clang).
<br>
Build Tools : Install make or any build system if required.
<br>
GUI Library : If using a GUI library (e.g., Qt), install it and configure the environment.
<br>
