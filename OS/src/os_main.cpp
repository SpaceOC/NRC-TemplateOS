#include <iostream>
#include <map>
#include <string>
#include "other/commands.hpp"

bool work = true;

void commandsZone() {
    handlerCommands HC;
    while(work) {
        print("Enter: ");
        std::string userInputResult;
        while (!(std::cin >> std::ws)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        getline(std::cin, userInputResult);
        HC.sendCommand(userInputResult);
    }
}

void OS() {
    addCommands();
    commandsZone();
}