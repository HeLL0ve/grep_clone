//
// Created by hell0ve on 04.04.2026.
//

#ifndef GREP_CLONE_COMMAND_H
#define GREP_CLONE_COMMAND_H
#include <string>
#include <vector>

struct Command {
    std::string command;
    std::string pattern;
    std::string file;
    std::string resultFile;
    std::vector<std::string> flags;
    Command(const std::string& input);
    bool help = false;
};
#endif //GREP_CLONE_COMMAND_H