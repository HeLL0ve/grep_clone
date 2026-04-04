//
// Created by hell0ve on 03.04.2026.
//

#ifndef GREP_CLONE_FILEREADER_H
#define GREP_CLONE_FILEREADER_H
#include <string>
#include <vector>

class FileReader {
public:
    static void readLines(
        const std::string& filename,
        const std::string& pattern,
        const std::string& resultFile,
        const std::vector<std::string>& flags
        );
};
#endif //GREP_CLONE_FILEREADER_H