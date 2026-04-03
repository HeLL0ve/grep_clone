#include <iostream>
#include <sstream>
#include "FileReader.h"
#include "Grep.h"

int main() {
    std::vector<std::string> result;
    std::vector<std::string> lines;
    FileReader reader;
    Grep grep;
    std::string command_line;
    std::string command, mode, pattern, file, flag;

    while (true) {
        try {
            if (!std::getline(std::cin, command_line)) {
                break;
            }
            if (command_line.empty()) {
                throw std::runtime_error("Please enter command");
            }
            std::stringstream ss(command_line);
            ss >> command;
            if (command_line.find("--") < command_line.find('"')) {
                ss.ignore(256, '-');
                getline(ss, mode, ' ');
                if (!mode.empty()) {
                    mode.erase(mode.begin());
                }
            }
            ss.ignore(256, '"');
            getline(ss, pattern, '"');
            ss>>file;
            if (command_line.find_last_of("--") > command_line.find_last_of('"')) {
                ss.ignore(256, '-');
                getline(ss, flag, ' ');
                if (!flag.empty()) {
                    flag.erase(flag.begin());
                }
            }
            if (command.empty() || pattern.empty() || file.empty() || command != "search") {
                throw std::runtime_error("Please correctly enter command");
            }
            lines = reader.readLines(file);
            result = grep.search(mode, lines, pattern, flag);
            for (auto& line : result) {
                std::cout << line << std::endl;
            }
            std::cout << std::endl;
        }catch (std::exception& e) {
            std::cout<<e.what()<<std::endl;
        }


    }
    return 0;
}