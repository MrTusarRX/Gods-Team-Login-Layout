# User Login System

This repository showcases a user login system implemented using Java, C++, and PHP. The application validates user credentials to ensure the entered username and password are correct. A floating menu feature, controlled by C++ logic, is also included. The floating menu becomes accessible only after a successful login.

---

## Features

1. **User Login Validation**:
   - Ensures secure and accurate username and password verification.
   - Implements logic using Java, C++, and PHP for cross-platform efficiency.

2. **Floating Menu Logic**:
   - Controlled using C++ for efficient logic handling.
   - Accessible only after a successful login.
   - Prevents unauthorized access to menu options.

3. **Cross-Language Workflow**:
   - **Java**: Handles the front-end logic and Android APK layout.
   - **C++**: Manages high-performance validation tasks and floating menu logic.
   - **PHP**: Connects to the server for backend processing.

---

## APK Layout

Below are screenshots of the APK's layout:

### Login Screen
![Login Screen](./img/layout.jpg)

### Success Message
![Success Screen](path/to/success_screen_screenshot.png)

### Floating Menu (Accessible After Login)
![Floating Menu](path/to/floating_menu_screenshot.png)

*Note: Replace `path/to/` with the actual paths to your screenshots in the repository.*

---

## How It Works

### Login Process
1. The user enters their **username** and **password** on the login screen.
2. The application sends the credentials to the server.
3. The C++ module verifies the credentials by interacting with a secure database.
4. The server responds:
   - **Correct credentials**: A success message is displayed, and the user is logged in.
   - **Incorrect credentials**: An error message prompts the user to re-enter the details.

### Floating Menu Logic
1. After a successful login, the floating menu is enabled.
2. The C++ logic ensures the menu remains inaccessible unless the user is logged in.
3. The floating menu allows users to perform additional actions based on their access level.

---

## Getting Started

### Prerequisites
- Android Studio for running the APK.
- A backend server configured with PHP and a database for credential verification.
- C++ compiler for handling validation and floating menu logic.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/your-repo-name.git
