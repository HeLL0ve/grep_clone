//
// Created by hell0ve on 03.04.2026.
//
#include "Grep.h"

#include <algorithm>
#include <cctype>
#include <regex>
#include <stdexcept>

std::string normalizedMatch(std::string line) {
    std::ranges::transform(line, line.begin(), [](unsigned char ch) {return static_cast<char>(std::tolower(ch));});
    return line;
}


bool Grep::search(const std::string &line, const std::string& pattern, const Options &options) {
    if (!options.regex) {
        std::string normalizedPattern = pattern;
        std::string normalizedLine = line;
        if (options.ignoreCase) {
            normalizedPattern = normalizedMatch(normalizedPattern);
            normalizedLine = normalizedMatch(normalizedLine);
        }
        if (normalizedLine.find(normalizedPattern) != std::string::npos) {
            return true;
        }
        return false;
    }
    try {
        const auto regexFlags = options.ignoreCase
                                    ? std::regex_constants::ECMAScript | std::regex_constants::icase
                                    : std::regex_constants::ECMAScript;
        std::regex r(pattern, regexFlags);
        if (std::regex_search(line, r)) {
            return true;
        }
        return false;
    }catch (const std::regex_error& e) {
        throw;
    }




}
