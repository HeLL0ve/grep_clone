#include <iostream>
#include "Command.h"
#include "CommandExecutor.h"

int main() {
    std::string command_line;
    while (true) {
        try {
            if (!std::getline(std::cin, command_line)) {
                break;
            }
            if (command_line.empty()) {
                throw std::runtime_error("Please enter command");
            }
            auto cmd = Command(command_line);
            if (cmd.help) {
                continue;
            }
            switch (CommandExecutor::execute(cmd)) {
                case 0:
                    std::cout<<"End of the search"<<std::endl;
                    break;
                case 1:
                    std::cout<<"Nothing found"<<std::endl;
                    break;
                default: std::cout<<"Program end with bug"<<std::endl;
            }
        }catch (std::exception& e) {
            std::cout<<e.what()<<std::endl;
        }
    }
    return 0;
}