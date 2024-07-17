#include <iostream>
extern void Init();
extern void OOBE();
extern void OS();
extern void fixNOW();

int main() {
    fixNOW();
    Init();
    std::cout << "Welcome to <Your pseudo-OS name>!" << '\n';
    OOBE();
    OS();
    return 0;
}