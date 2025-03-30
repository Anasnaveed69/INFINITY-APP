# INFINITY-APP

Social Network Application with GUI
Table of Contents
Project Overview
Features
Phases of Development
Execution Flow
Folder Structure
Setup Instructions
Usage
Contributing
License
Project Overview
The Social Network Application is a desktop-based graphical user interface (GUI) application designed to simulate a simplified version of a social media platform. It allows users to interact with posts, pages, friends, and memories in a structured and object-oriented manner. The application emphasizes clean design, separation of concerns, and adherence to best practices in Object-Oriented Programming (OOP).

This project is divided into two phases:

Phase I - Project Design : UML class diagram creation.
Phase II - Development : Implementation of the application with all required functionalities.
Features
Core Functionalities
Set Current User :
Allows the user to set themselves as the current user of the application.
View Home :
Displays posts from friends and liked pages shared in the last 24 hours.
Like a Post :
Enables users to like posts (up to 10 likes per post).
View Liked List :
Displays the list of users who have liked a specific post.
Comment on a Post :
Allows users to comment on posts (up to 10 comments per post).
View a Post :
Displays the post along with its comments.
Share a Memory :
Allows users to share memories by referencing an original post.
View User’s Profile :
Displays the user's name and their timeline posts.
View Friend List :
Displays the list of friends for a specific user.
View Page :
Displays all posts shared by a specific page.
Additional Features
Activity Posts : Posts can include activities such as feelings, thoughts, celebrations, etc.
Memory Posts : Special type of post that references an original post.
Dynamic Memory Allocation : All arrays are dynamically allocated to optimize memory usage.
Persistent Data Storage : User and page information is stored in .txt files for persistence.
Phases of Development
Phase I: Project Design
UML Class Diagram :
Created using tools like StarUML or Draw.io.
Includes all major classes, their attributes, methods, and relationships.
Excludes getters, setters, and constructors for clarity.
Phase II: Development
Implementation :
Full development of the application with all required functionalities.
Proper folder structuring and modular codebase.
Adherence to OOP principles and best practices.
Execution Flow
Entry Point :
The application starts with the SocialNetworkApp::Run() function in the main() method.
Responsibilities are delegated to appropriate classes for separation of concerns.
Manager/App Class :
Acts as the master/driver class for the application.
Handles user input and delegates tasks to other classes.
Dynamic Memory Management :
Arrays are dynamically allocated and deallocated to ensure efficient memory usage.
Persistence :
User and page information is stored in .txt files for runtime persistence.
