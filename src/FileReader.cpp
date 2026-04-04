//
// Created by hell0ve on 03.04.2026.
//
#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <limits>

std::optional<std::string> FileReader::readLines(const std::string &filename, std::size_t currentLine) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        throw(std::runtime_error("Could not find file: " + filename));
    }

    for (int i = 1; i < currentLine; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (file.eof()) return std::nullopt;
    }
    std::string line;
    std::getline(file, line);
    file.close();
    return line;
}
