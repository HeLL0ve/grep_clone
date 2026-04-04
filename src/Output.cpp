//
// Created by hell0ve on 04.04.2026.
//
#include "Output.h"

#include <fstream>
#include <iostream>
#include <ostream>

void Output::pushCLI(const std::string& line) {
    std::cout << line << std::endl;
}
void Output::pushFile(const std::vector <std::string>& lines, const std::string& file_name) {
    std::ofstream file(file_name, std::ios::app);
    if (file.is_open()) {
        for (const auto& line : lines) {
            file << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Problem opening output file" << std::endl;
        throw(std::runtime_error("Problem opening output file"));
    }
}
