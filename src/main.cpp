#include <iostream>
#include <sstream>
#include "FileReader.h"

struct Command {
    std::string command;
    std::string pattern;
    std::string file;
    std::string resultFile;
    std::vector<std::string> flags;
};
std::vector<std::string> tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::string current;
    bool inQuotes = false;
    bool resultFile = false;
    for (char c : input) {
        if (c == '"') {
            inQuotes = !inQuotes;
        }else if (c == ' ' && !inQuotes) {
            if (!current.empty()) {
                if (resultFile) {
                    tokens.push_back(">" + current);
                    resultFile = false;
                }else {
                    tokens.push_back(current);
                }
                current.clear();
            }
        }else if (c == '>'&& !inQuotes) {
            resultFile = true;
        }else {
            current.push_back(c);
        }
    }
    if (!current.empty()) {
        if (resultFile) {
            tokens.push_back(">" + current);
        } else {
            tokens.push_back(current);
        }
    }
    return tokens;
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
        if (token.starts_with("--")) {
            cmd.flags.push_back(token);
            if (token == "--help") {
                return cmd;
            }
        }
    }
    for (auto& token : tokens) {
        if (token.starts_with('>')) {
            cmd.resultFile = token.substr(1);
            break;
        }
    }
    for (auto& token : tokens) {
        if (!token.starts_with("--") && token != cmd.command && token != cmd.resultFile) {
            cmd.pattern = token;
            break;
        }
    }
    for (auto& token : tokens) {
        if (!token.starts_with("--") && token != cmd.pattern && token != cmd.command && token != cmd.resultFile) {
            cmd.file = token;
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
bool helpCommand(const Command& cmd) {
    for (auto& token : cmd.flags) {
        if (token=="--help") {
            std::cout << "Help" <<std::endl;
            return true;
        }
    }
    return false;
}
int main() {
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
            if (helpCommand(cmd)) {
                continue;
            }

            FileReader::readLines(cmd.file, cmd.pattern, cmd.resultFile, cmd.flags);
            std::cout<<"End of the search"<<std::endl;
        }catch (std::exception& e) {
            std::cout<<e.what()<<std::endl;
        }

    }
    return 0;
}