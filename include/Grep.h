//
// Created by hell0ve on 03.04.2026.
//

#ifndef GREP_CLONE_GREP_H
#define GREP_CLONE_GREP_H
#include <string>

#include "Options.h"

class Grep {
public:
    static bool search(
        const std::string& line,
        const std::string& pattern,
        const Options& options
    );
};
#endif //GREP_CLONE_GREP_H