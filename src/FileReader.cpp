//
// Created by hell0ve on 03.04.2026.
//
#include "FileReader.h"

#include <fstream>
#include <iostream>

std::vector<std::string> FileReader::readLines(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw(std::runtime_error("Could not find file: " + filename));
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    if (lines.empty()) {
        throw std::runtime_error("File empty");
    }
    file.close();
    return lines;
}
