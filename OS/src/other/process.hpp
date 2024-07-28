#include <iostream>
#include <chrono>
#include <atomic>
#include "Core/base/print.h"
#include "Core/experimental/process.h"

extern void commandsZone(); // from os_main.cpp
extern std::atomic<int> atomicI;
extern bool work;

void counterMov();
process processNew("main", counterMov);

void startProcess() {
    processNew.createThread("notmain", commandsZone);
    processNew.startThread("main");
    processNew.startThread("notmain");
}

void counterMov() {
    for (int i = 0; i <= 2024; i++) {
        atomicI = i;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));

        if (!work) break;

        if (i == 2024) {
            print(print::colors::blue, "GOOD JOB\n");
            print(print::colors::green, "Thread id: ");
            std::cout << processNew.getThread("main")->get_id() << '\n';
            print(print::colors::aqua, "NRC Process name: main\n");
        }
    }
}