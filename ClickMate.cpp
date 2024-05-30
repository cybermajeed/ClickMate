#include <iostream>
#include <windows.h>
#include <conio.h>

int main()
{
    bool isLeftClick;
    std::cout << "Choose Mouse Type: \n";
    std::cout << "\t1. Left-click \n";
    std::cout << "\t2. Right-click \n";
    std::cout << "-> ";
    isLeftClick = std::cin.get() == '1';
    std::cout << (isLeftClick ? "Left" : "Right") << "-click chosen.\n";
    //
    INPUT inp{0};
    inp.type = INPUT_MOUSE;
    inp.mi.dx = 0;
    inp.mi.dy = 0;
    auto mouseDown = isLeftClick ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_RIGHTDOWN;
    auto mouseUp = isLeftClick ? MOUSEEVENTF_LEFTUP : MOUSEEVENTF_RIGHTUP;
    bool clickEnabled = 0;
    //
    std::cout << "Press ALT + C to Turn On/Off...\n";
    while (true)
    {
        if (GetKeyState(VK_MENU) < 0 && GetKeyState(0x43) < 0) // ALT + C
        {
            Sleep(800);
            clickEnabled = !clickEnabled; // turn on/off autoclicker
        }
        if (clickEnabled)
        {
            // start mouse click
            inp.mi.dwFlags = mouseDown;
            SendInput(1, &inp, sizeof(INPUT));
            inp.mi.dwFlags = mouseUp;
            SendInput(1, &inp, sizeof(INPUT));
            Sleep(50);
        }
    }
    getch();
}