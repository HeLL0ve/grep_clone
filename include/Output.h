//
// Created by hell0ve on 04.04.2026.
//

#ifndef GREP_CLONE_OUTPUT_H
#define GREP_CLONE_OUTPUT_H
#include <string>
#include <vector>

class Output {
public:
    static void pushCLI(const std::string& line);
    static void pushFile(
        const std::vector<std::string>& lines,
        const std::string& file_name
        );
};
#endif //GREP_CLONE_OUTPUT_H