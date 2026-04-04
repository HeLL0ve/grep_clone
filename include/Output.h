//
// Created by hell0ve on 04.04.2026.
//

#ifndef GREP_CLONE_OUTPUT_H
#define GREP_CLONE_OUTPUT_H
#include <string>
#include <vector>

class Output {
public:
    static void push(
        const std::string& line,
        const std::string& resultFile,
        const std::vector<std::string>& flag
        );
};
#endif //GREP_CLONE_OUTPUT_H