//
// Created by hell0ve on 04.04.2026.
//
#include <iostream>
#include <ostream>
#include <ranges>
#include "Command.h"
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
void helpCommand() {
    std::cout
        << "cgrep help\n"
        << "\n"
        << "Usage:\n"
        << "  search \"<pattern>\" <file> [flags] [>output_file]\n"
        << "\n"
        << "Flags:\n"
        << "  --help         Show this help message\n"
        << "  --ignore-case  Case-insensitive search\n"
        << "  --regex        Treat pattern as a regular expression\n"
        << "  --line-number  Prefix matched lines with line numbers\n"
        << "  --no-cmd       Do not print matches to console\n"
        << "\n"
        << "Output redirection:\n"
        << "  >output_file   Write matched lines to a file\n"
        << "                 Console output remains enabled unless --no-cmd is used\n"
        << "\n"
        << "Examples:\n"
        << "  search \"error\" logs.txt\n"
        << "  search \"error\" logs.txt --ignore-case\n"
        << "  search \"^WARN.*timeout$\" logs.txt --regex --line-number\n"
        << "  search \"error\" logs.txt >result.txt\n"
        << "  search \"error\" logs.txt --no-cmd >result.txt\n";
}
Command::Command(const std::string& input) {
    auto tokens = tokenize(input);
    if (tokens.empty()) {
        throw std::runtime_error("Please enter command");
    }
    this->command = tokens[0];
    if (this->command != "search") {
        throw std::runtime_error("Please enter command");
    }
    for (const auto& token : tokens) {
        if (token.starts_with("--")) {
            this->flags.push_back(token);
            if (token == "--help") {
                helpCommand();
                this->help = true;
                return;
            }
        }
    }
    for (auto& token : tokens) {
        if (token.starts_with(">")) {
            this->resultFile = token.substr(1);
            token = this->resultFile;
            break;
        }
    }
    for (const auto& token : tokens) {
        if (!token.starts_with("--") && token != this->command && token != this->resultFile) {
            this->pattern = token;
            break;
        }
    }
    for (auto & token : std::ranges::reverse_view(tokens)) {
        if (!token.starts_with("--") && token != this->pattern && token != this->command && token != this->resultFile) {
            this->file = token;
            break;
        }
    }
    if (this->pattern.empty()) {
        throw std::runtime_error("Please enter pattern");
    }
    if (this->file.empty()) {
        throw std::runtime_error("Please enter file");
    }
}
