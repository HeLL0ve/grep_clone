#include <iostream>
#include <sstream>
#include "FileReader.h"
#include "Grep.h"
struct Command {
    std::string command;
    std::string pattern;
    std::string file;
    std::vector<std::string> flags;
};
std::vector<std::string> tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::string current;
    bool inQuotes = false;
    for (char c : input) {
        if (c == '"') {
            inQuotes = !inQuotes;
        }else if (c == ' ' && !inQuotes) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
        }else {
            current.push_back(c);
        }
    }
    if (current.empty()) {
        tokens.push_back(current);
    }
}
Command parseCommand(const std::string& input) {
    Command cmd;
    auto tokens = tokenize(input);
    if (tokens.empty()) {
        throw std::runtime_error("Please enter command");
    }
    cmd.command = tokens[0];
    if (cmd.command != "search") {
        throw std::runtime_error("Please enter command");
    }
    for (auto& token : tokens) {
        if (token.starts_with('--')) {
            cmd.flags.push_back(token);
        }
    }
    for (auto token = tokens.rbegin(); token != tokens.rend(); ++token) {
        if (!token->starts_with('--')) {
            cmd.file = *token;
            break;
        }
    }
    for (auto& token : tokens) {
        if (!token.starts_with('--') && token != cmd.file && token != cmd.command) {
            cmd.pattern = token;
            break;
        }
    }
    if (cmd.pattern.empty()) {
        throw std::runtime_error("Please enter pattern");
    }
    if (cmd.file.empty()) {
        throw std::runtime_error("Please enter file");
    }
    return cmd;
}
int main() {
    std::vector<std::string> result;
    std::vector<std::string> lines;
    FileReader reader;
    Grep grep;
    std::string command_line;


    while (true) {
        try {
            if (!std::getline(std::cin, command_line)) {
                break;
            }
            if (command_line.empty()) {
                throw std::runtime_error("Please enter command");
            }
            auto cmd = parseCommand(command_line);


            lines = reader.readLines(cmd.file);
            result = grep.search(mode, lines, pattern, flag);
            for (auto& line : result) {
                std::cout << line << std::endl;
            }
            std::cout << std::endl;
        }catch (std::exception& e) {
            std::cout<<e.what()<<std::endl;
        }


    }
    return 0;
}