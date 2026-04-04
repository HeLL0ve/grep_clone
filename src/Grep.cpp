//
// Created by hell0ve on 03.04.2026.
//
#include "Grep.h"

#include <algorithm>
#include <cctype>
#include <regex>
#include <stdexcept>
struct Options {
    bool ignoreCase = false;
    bool lineNumber = false;
    bool regex = false;
};
Options convertToOptions(const std::vector<std::string> &flags) {
    Options options;
    if (!flags.empty()) {
        for (const auto& flag : flags) {
            if (flag == "--ignore-case") {
                options.ignoreCase = true;
            }else if (flag == "--regex") {
                options.regex = true;
            }else if (flag == "--line-number") {
                options.lineNumber = true;
            }else if (flag == "--no-cmd") {
            }else {
                throw std::runtime_error("Unknown flag: " + flag);
            }
        }
    }
    return options;
}

std::string Grep::search(const std::string &line, const int& lineNumber, const std::string &pattern, const std::vector<std::string> &flags) {
    Options opt = convertToOptions(flags);

    auto formatMatch = [opt](std::size_t lineIndex, const std::string& line) {
        if (!opt.lineNumber) {
            return line;
        }
        return std::to_string(lineIndex) + ": " + line;
    };
    auto normalizedMatch = [opt](std::string& lin) {
        if (!opt.ignoreCase) {
            return lin;
        }
        std::ranges::transform(lin, lin.begin(), [](unsigned char ch) {return static_cast<char>(std::tolower(ch));});
        return lin;
    };

    if (!opt.regex) {
        std::string normalizedPattern = pattern;
        normalizedPattern = normalizedMatch(normalizedPattern);

        std::string normalizedLine = line;
        normalizedLine = normalizedMatch(normalizedLine);

        if (normalizedLine.find(normalizedPattern) != std::string::npos) {
            return formatMatch(lineNumber, line);
        }else {
            return "";
        }
    }else{
        try {
            const auto regexFlags = opt.ignoreCase
            ? std::regex_constants::grep | std::regex_constants::icase
            : std::regex_constants::grep;
            std::regex r(pattern, regexFlags);
            if (std::regex_search(line, r)) {
                return formatMatch(lineNumber, line);
            }else {
                return "";
            }
        }catch (const std::regex_error& e) {
            throw std::runtime_error("Invalid regex pattern: " + std::string(e.what()));
        }
    }
}
