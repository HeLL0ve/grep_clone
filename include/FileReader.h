//
// Created by hell0ve on 03.04.2026.
//

#ifndef GREP_CLONE_FILEREADER_H
#define GREP_CLONE_FILEREADER_H
#include <optional>
#include <string>

class FileReader {
public:
    static std::optional<std::string> readLines(
        const std::string& filename,
        std::size_t currentLine
        );
};
#endif //GREP_CLONE_FILEREADER_H