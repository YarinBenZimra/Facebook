# Facebook Social Network System

Welcome to **Facebook Social Network System**! This is a comprehensive project simulating the functionality of a social networking platform. The application includes features like user and fan page management, status updates, and relationships, built with advanced C++ principles including STL, inheritance, polymorphism, and file handling. 

---

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation and Setup](#installation-and-setup)
- [How to Use](#how-to-use)
- [File I/O and Data Preservation](#file-io-and-data-preservation)
- [Design and Implementation](#design-and-implementation)
- [Notes](#notes)

---

## Project Overview

This project, developed during a C++ course, is a demonstration of object-oriented design principles and advanced C++ concepts. The system mimics a social network where:

- Users can connect with friends and follow fan pages.
- Status updates can include text, images, or videos.
- Data is persisted across sessions using file I/O.

---

## Features

1. **User and Fan Page Management**:
   - Add friends and fan pages.
   - Display the members and fans associated with entities.

2. **Statuses**:
   - Post and view statuses containing text, images, or videos.
   - Support for multimedia statuses with appropriate display methods.

3. **Relationships**:
   - Mutual friendships between users.
   - Users can like fan pages.

4. **Polymorphism and Inheritance**:
   - Unified handling of diverse statuses and entities.

5. **File Handling**:
   - Save and load the system's state for data preservation.

6. **Custom Operators**:
   - `+=` for adding friends or fans.
   - `>` for comparing entities by the number of connections.
   - `==` for comparing statuses based on content.

---

## Prerequisites

Ensure you have the following installed:

- **C++ Compiler**: Any compiler supporting C++11 or later.
- **Git**: For cloning the repository.

---

You're correct that `./FacebookApp` would refer to an executable file that doesn't exist until we explicitly create it. I’ll update the **Installation and Setup** section accordingly to clarify the process, ensuring the instructions reflect how the project can be built and run from the `.sln` file or via manual compilation without assuming any default executable name.

---

## Installation and Setup

### Step 1: Clone the Repository

Start by cloning the repository from GitHub:

```bash
git clone https://github.com/YarinBenZimra/Facebook.git
```

### Step 2: Open and Build the Project

#### Option 1: Using Visual Studio (Recommended)

1. **Navigate to the project directory**:
   ```bash
   cd Facebook
   ```

2. **Open the `.sln` file**:
   - Double-click `Facebook.sln` in the `Facebook` folder to open the project in Visual Studio.

3. **Build the Solution**:
   - In Visual Studio, go to the **Build** menu and select **Build Solution** (or press `Ctrl + Shift + B`).

4. **Run the Application**:
   - After a successful build, press `F5` to run the program or select **Start Debugging** from the **Debug** menu.
   - The program will launch in the console window.

#### Option 2: Without Visual Studio (Using Command Line)

If you don't have Visual Studio installed, you can compile and run the project using a C++ compiler like `g++`:

1. **Navigate to the project directory**:
   ```bash
   cd Facebook/Facebook
   ```

2. **Compile the project**:
   Compile the `.cpp` files into an executable. Use the following command to generate an executable file (e.g., `FacebookApp`):
   ```bash
   g++ -std=c++11 -o FacebookApp *.cpp
   ```

3. **Run the application**:
   Once the compilation is complete, run the program with:
   ```bash
   ./FacebookApp
   ```

If your compiler doesn't support `g++`, ensure you use an equivalent compiler that supports C++11 or later standards.

---

### Step 3: Running the Application

Upon starting the application, a menu-driven interface will appear in the console. Use the numbered options to interact with the system, which includes adding friends, posting statuses, and viewing timelines.

---

This updated section should now eliminate confusion and provides a clearer explanation for both Visual Studio users and those relying on manual compilation. Let me know if there are other concerns!

## How to Use

Upon launching, a menu-driven interface allows you to interact with the system. Predefined data is loaded at the start, including users, fan pages, and statuses. You can:

1. Add friends or fan pages.
2. Post statuses to users or fan pages.
3. View recent statuses of friends.
4. Link or remove relationships.
5. Save and exit the system.

---

## File I/O and Data Preservation

- The system saves all data (users, fan pages, statuses) into a file upon exit.
- Data is reloaded on startup, ensuring continuity across sessions.
- File format is structured for easy parsing and debugging.

---

## Design and Implementation

### Class Hierarchy
- **Entity**: Base class for `User` and `FanPage`.
- **User**: Inherits from `Entity`; maintains friends and liked pages.
- **FanPage**: Inherits from `Entity`; maintains a list of fans.
- **Status**: Base class for `TextStatus`, `ImageStatus`, and `VideoStatus`.

### Key Design Decisions
1. **Polymorphism**: Virtual methods for displaying statuses allow dynamic behavior.
2. **STL Usage**: Vectors replace manual arrays for dynamic data management.
3. **Memory Management**: Smart pointers or well-defined destructors ensure no memory leaks.

---

## Notes

- **Exception Handling**: Robust error handling ensures invalid input doesn't crash the system.
- **Extensibility**: The modular design allows for future features, such as new status types or additional relationships.

---


Feel free to explore, run, and extend the project. Contributions are welcome! 🎉
