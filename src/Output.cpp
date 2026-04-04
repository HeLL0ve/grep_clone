//
// Created by hell0ve on 04.04.2026.
//
#include "Output.h"

#include <fstream>
#include <iostream>
#include <ostream>

struct OutputOptions {
    bool cmd = true;
    bool file = false;
};
OutputOptions outputOptions(const std::string &resultFile, const std::vector<std::string> &flags) {
    OutputOptions o;
    if (!resultFile.empty()) {
        o.file = true;
    }
    for (auto& flag : flags) {
        if (flag == "--no-cmd") {
            o.cmd = false;
        }
    }
    return o;
};

void Output::push(const std::string &line, const std::string &resultFile, const std::vector<std::string> &flags) {
    try {
        OutputOptions o = outputOptions(resultFile, flags);
        if (o.cmd) {
            std::cout << line << std::endl;
        }
        if (o.file) {
            std::ofstream file(resultFile, std::ios::app);

            if (file.is_open()) {
                file << line << std::endl;
                file.close();
            } else {
                throw(std::runtime_error("Problem opening output file"));
            }
        }
    }catch (std::exception &e) {
        std::cout<<e.what()<<std::endl;
    }
}
