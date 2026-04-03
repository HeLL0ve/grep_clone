//
// Created by hell0ve on 03.04.2026.
//

#ifndef GREP_CLONE_FILEREADER_H
#define GREP_CLONE_FILEREADER_H
#include <string>
#include <vector>

class FileReader {
public:
    std::vector<std::string> readLines(const std::string& filename);
};
#endif //GREP_CLONE_FILEREADER_H