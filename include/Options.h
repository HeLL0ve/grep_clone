//
// Created by hell0ve on 04.04.2026.
//

#ifndef GREP_CLONE_OPTIONS_H
#define GREP_CLONE_OPTIONS_H
#include <stdexcept>
#include <string>
#include <vector>

struct Options {
    bool ignoreCase = false;
    bool lineNumber = false;
    bool regex = false;
    bool cliOutput = true;
    bool fileOutput = false;

    Options(const std::vector<std::string> &flags, const std::string &resultFile) {
        if (!flags.empty()) {
            for (const auto& flag : flags) {
                if (flag == "--ignore-case") {
                    this->ignoreCase = true;
                }else if (flag == "--regex") {
                    this->regex = true;
                }else if (flag == "--line-number") {
                    this->lineNumber = true;
                }else if (flag == "--no-cmd") {
                    this->cliOutput = false;
                }else {
                    throw std::runtime_error("Unknown flag: " + flag);
                }
            }
        }
        if (!resultFile.empty()) {
            this->fileOutput = true;
        }
    }
};
#endif //GREP_CLONE_OPTIONS_H