#include <iostream>
#include <windows.h>

using namespace std;

//const int VK_F1 = 0x70; // Virtual-Key code for F1
//const int MOUSEEVENTF_LEFTDOWN = 0x02;
//const int MOUSEEVENTF_LEFTUP = 0x04;

void PressF1AndClick()
{
    // Simulate F1 key press
    keybd_event(VK_F1, 0, 0, 0); // Press down F1
    keybd_event(VK_F1, 0, KEYEVENTF_KEYUP, 0); // Release F1

    // Simulate mouse left button click
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

int main()
{
    cout << "Program running... Press and hold F1 for auto F1 press and mouse click. Press ESC to exit." << endl;

    while (true)
    {
        if (GetAsyncKeyState(VK_F1) & 0x8000) // Check if F1 is pressed
            {
            PressF1AndClick();
            //cout << "F1 key pressed and mouse clicked" << endl;
            //Sleep(500); // Delay to prevent too rapid firing
            }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // Check if ESC is pressed
            {
            break;
            }

        // Sleep(100); // Sleep to reduce CPU usage
    }

    cout << "Program terminated." << endl;
    return 0;
}
