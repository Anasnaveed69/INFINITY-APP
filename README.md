# Social Network Application with GUI

## Table of Contents
1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Phases of Development](#phases-of-development)
4. [Execution Flow](#execution-flow)
5. [Folder Structure](#folder-structure)
6. [Setup Instructions](#setup-instructions)
7. [Usage](#usage)
8. [Contributing](#contributing)
9. [License](#license)

---

## Project Overview

The **Social Network Application** is a desktop-based graphical user interface (GUI) application designed to simulate a simplified version of a social media platform. It allows users to interact with posts, pages, friends, and memories in a structured and object-oriented manner. The application emphasizes clean design, separation of concerns, and adherence to best practices in Object-Oriented Programming (OOP).

This project is divided into two phases:
1. **Phase I - Project Design**: UML class diagram creation.
2. **Phase II - Development**: Implementation of the application with all required functionalities.

---

## Features

### Core Functionalities
- **Set Current User**: Allows the user to set themselves as the current user of the application.
- **View Home**: Displays posts from friends and liked pages shared in the last 24 hours.
- **Like a Post**: Enables users to like posts (up to 10 likes per post).
- **View Liked List**: Displays the list of users who have liked a specific post.
- **Comment on a Post**: Allows users to comment on posts (up to 10 comments per post).
- **View a Post**: Displays the post along with its comments.
- **Share a Memory**: Allows users to share memories by referencing an original post.
- **View User’s Profile**: Displays the user's name and their timeline posts.
- **View Friend List**: Displays the list of friends for a specific user.
- **View Page**: Displays all posts shared by a specific page.

### Additional Features
- **Activity Posts**: Posts can include activities such as feelings, thoughts, celebrations, etc.
- **Memory Posts**: Special type of post that references an original post.
- **Dynamic Memory Allocation**: All arrays are dynamically allocated to optimize memory usage.
- **Persistent Data Storage**: User and page information is stored in `.txt` files for persistence.

---

## Phases of Development

### Phase I: Project Design
- **UML Class Diagram**:
  - Created using tools like StarUML or Draw.io.
  - Includes all major classes, their attributes, methods, and relationships.
  - Excludes getters, setters, and constructors for clarity.

### Phase II: Development
- **Implementation**:
  - Full development of the application with all required functionalities.
  - Proper folder structuring and modular codebase.
  - Adherence to OOP principles and best practices.

---

## Execution Flow

1. **Entry Point**:
   - The application starts with the `SocialNetworkApp::Run()` function in the `main()` method.
   - Responsibilities are delegated to appropriate classes for separation of concerns.

2. **Manager/App Class**:
   - Acts as the master/driver class for the application.
   - Handles user input and delegates tasks to other classes.

3. **Dynamic Memory Management**:
   - Arrays are dynamically allocated and deallocated to ensure efficient memory usage.

4. **Persistence**:
   - User and page information is stored in `.txt` files for runtime persistence.

---

## Folder Structure

```
SocialNetworkApp/
├── src/
│   ├── App.cpp          // Main application logic
│   ├── App.h            // Header file for App class
│   ├── User.cpp         // User class implementation
│   ├── User.h           // Header file for User class
│   ├── Page.cpp         // Page class implementation
│   ├── Page.h           // Header file for Page class
│   ├── Post.cpp         // Post class implementation
│   ├── Post.h           // Header file for Post class
│   ├── Comment.cpp      // Comment class implementation
│   ├── Comment.h        // Header file for Comment class
│   ├── Memory.cpp       // Memory class implementation
│   ├── Memory.h         // Header file for Memory class
├── data/
│   ├── users.txt        // Stores user IDs and names
│   ├── pages.txt        // Stores page IDs and titles
├── assets/
│   ├── gui/             // GUI-related files (if applicable)
├── docs/
│   ├── uml_diagram.png  // UML class diagram
├── Makefile             // Build script (if applicable)
├── README.md            // This file
└── LICENSE              // License file
```

---

## Setup Instructions

### Prerequisites
- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., GCC or Clang).
- **Build Tools**: Install `make` or any build system if required.
- **GUI Library**: If using a GUI library (e.g., Qt), install it and configure the environment.

### Steps to Run
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/SocialNetworkApp.git
   cd SocialNetworkApp
   ```

2. **Install Dependencies**:
   - If using external libraries, install them using your package manager or follow the library's documentation.

3. **Compile the Code**:
   ```bash
   make
   ```

4. **Run the Application**:
   ```bash
   ./SocialNetworkApp
   ```

---

## Usage

1. **Set Current User**:
   ```plaintext
   Command: Set current user "u7"
   Abdullah Nadeem successfully set as Current User
   ```

2. **View Home**:
   ```plaintext
   Command: View Home
   Abdullah Nadeem – Home Page
   ```

3. **Like a Post**:
   ```plaintext
   Command: LikePost(post5)
   ```

4. **View Liked List**:
   ```plaintext
   Command: ViewLikedList(post5)
   Post Liked By: U2 – Amna Akram, P1 – Food Fusion, U3 – Waheed Khan, U4 – Burhan Tahir, u7 – Abdullah Nadeem
   ```

5. **Comment on a Post**:
   ```plaintext
   Command: PostComment(post4, "Good Luck for your Result")
   ```

6. **View a Post**:
   ```plaintext
   Command: ViewPost(post4)
   --- Ali Ahmed shared “Waiting for Result”
   Abdullah Nadeem wrote: “Good Luck for your Result”
   ```

7. **Share a Memory**:
   ```plaintext
   Command: ShareMemory(post10, “Never thought I will be specialist in this field...”)
   ```

---

## Contributing

We welcome contributions from the community! To contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeatureName`).
3. Commit your changes (`git commit -m "Add YourCommitMessage"`).
4. Push to the branch (`git push origin feature/YourFeatureName`).
5. Open a pull request.

---

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.
