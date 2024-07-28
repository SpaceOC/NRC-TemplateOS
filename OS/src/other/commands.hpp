#include <iostream>
#include <vector>
#include <map>
#include "Core/base/print.h"
#include "Core/base/command/handler_commands.h"
#include "Core/base/data/file_manager.h"

extern bool work;

// Да, я взял код counter.cpp прямиком из SpaceDOS и немного ... переписал... переделал.... 
void counter() {
    int a, b = 0;
    print("Min number: ");

    while(!(std::cin >> a)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        print("Min number: ");
    } 

    a--;
    print("Max number: ");

    while(!(std::cin >> b)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        print("Max number: ");
    }
    
    if (a > b) {
        print(print::colors::red, "The minimum number cannot be greater than the maximum number!!!\n");
        return;
    }

    if (b >= 1000000 || b <= -1000000) {
        std::string yourChoice;
        print(print::colors::yellow, "Attention! This number is huge and it will take a long time to finish working with such a number. Do you want to continue? (Y/N) \t");
        std::cin >> yourChoice;
        if (yourChoice == "N") {
            return;
        }
    }
    std::cout << "----------------------------------------------------------" << std::endl;
    fileManager FM;
    FM.createFolder("Texts");
    FM.createFile("Texts/counter.txt");
    // "Ладно, и так сойдёт" :skull: :cold_face:
    auto file = FM.getFileOfstream("Texts/counter.txt", std::ios::out);

    if (file) {
        while (a != b) {
            a++;
            std::cout << a << '\n';
            file << a << '\n';
        }
        file.close();
    } else {
        print(print::colors::red, "Error!\n");
        return;
    }

    print("----------------------------------------------------------\n");
    print(print::colors::green, "It's done! The file is saved in the Texts folder under the name \"counter.txt\"\n");
    std::string yourChoice;
    print("Exit? (Y/N) \t");
    std::cin >> yourChoice;
    if (yourChoice == "N") { counter(); } 
    else { return; }
}

void bye() {
    work = false;
}

void hi() {
    srand(static_cast<unsigned int>(time(0)));
    std::vector<std::string> messages = {"hi", "HII", "hello :D", "hiiiiii"};
    print(messages[rand() % (messages.size() - 1)] + '\n');
}

void addCommands() {
    handlerCommands hc;
    hc.addCommand("counter", "No description", counter);
    hc.addCommand("hi", "hiii!", hi);
    hc.addCommand("exit", "exit", bye);
}