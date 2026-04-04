//
// Created by hell0ve on 03.04.2026.
//

#ifndef GREP_CLONE_GREP_H
#define GREP_CLONE_GREP_H
#include <string>
#include <vector>

class Grep {
public:
    static std::string search(
        const std::string& line,
        const int& lineNumber,
        const std::string& pattern,
        const std::vector<std::string>& flags
    );
};
#endif //GREP_CLONE_GREP_H