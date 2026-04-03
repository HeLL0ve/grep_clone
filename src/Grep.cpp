//
// Created by hell0ve on 03.04.2026.
//
#include "Grep.h"

#include <algorithm>
#include <cctype>
#include <regex>
#include <stdexcept>

std::vector<std::string> Grep::search(const std::string &mode, const std::vector<std::string> &lines, const std::string &pattern, const std::string &flag) {
    std::vector<std::string> result;
    const bool ignoreCase = flag == "ignore-case";
    const bool showLineNumber = flag == "line-number";

    if (!flag.empty() && !ignoreCase && !showLineNumber) {
        throw std::runtime_error("Unknown flag: " + flag);
    }

    auto formatMatch = [showLineNumber](std::size_t lineIndex, const std::string& line) {
        if (!showLineNumber) {
            return line;
        }
        return std::to_string(lineIndex + 1) + ": " + line;
    };

    if (mode.empty()) {
        std::string normalizedPattern = pattern;
        if (ignoreCase) {
            std::transform(
                normalizedPattern.begin(),
                normalizedPattern.end(),
                normalizedPattern.begin(),
                [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); }
            );
        }

        for (std::size_t i = 0; i < lines.size(); ++i) {
            std::string normalizedLine = lines[i];
            if (ignoreCase) {
                std::transform(
                    normalizedLine.begin(),
                    normalizedLine.end(),
                    normalizedLine.begin(),
                    [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); }
                );
            }

            if (normalizedLine.find(normalizedPattern) != std::string::npos) {
                result.push_back(formatMatch(i, lines[i]));
            }
        }
    } else if (mode == "regex") {
        const auto regexFlags = ignoreCase
            ? std::regex_constants::ECMAScript | std::regex_constants::icase
            : std::regex_constants::ECMAScript;
        std::regex r(pattern, regexFlags);
        for (std::size_t i = 0; i < lines.size(); ++i) {
            if (std::regex_search(lines[i], r)) {
                result.push_back(formatMatch(i, lines[i]));
            }
        }
    } else {
        throw std::runtime_error("Please correctly enter mode");
    }
    return result;
}
