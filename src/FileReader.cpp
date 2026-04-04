//
// Created by hell0ve on 03.04.2026.
//
#include "FileReader.h"
#include "Grep.h"
#include "Output.h"
#include <fstream>
#include <iostream>
#include <memory>

void FileReader::readLines(const std::string &filename, const std::string& pattern, const std::string& fileResult,const std::vector<std::string>& flags) {
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw(std::runtime_error("Could not find file: " + filename));
        }
        std::string line;
        int counter = 1;
        int counterLines = 0;
        while (std::getline(file, line)) {
            std::string searchedLine = Grep::search(line, counter, pattern, flags);
            if (!searchedLine.empty()) {
                Output::push(searchedLine, fileResult, flags);
                counterLines++;
            }
            counter++;
        }
        if (counterLines == 0) {
            std::cout << "Nothing found" << std::endl;
        }
        file.close();
    }catch (std::exception& e) {
        std::cout << "Error while reading file: " << e.what() << std::endl;
    }
}
