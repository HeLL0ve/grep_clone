//
// Created by hell0ve on 04.04.2026.
//

#include "CommandExecutor.h"

#include <iostream>

#include "Command.h"
#include "Options.h"
#include "FileReader.h"
#include "Grep.h"
#include "Output.h"

int CommandExecutor::execute(const Command &cmd) {
    const Options opt(cmd.flags, cmd.resultFile);
    int currentLine = 1;
    std::vector<std::string> lines;
    while (true) {
        auto line = FileReader::readLines(cmd.file, currentLine);
        if (line != std::nullopt) {
            if (Grep::search(*line, cmd.pattern, opt)) {
                std::string str = *line;
                if (opt.lineNumber) {
                    str = std::to_string(currentLine) + ": " + *line;
                }if (opt.cliOutput) {
                    Output::pushCLI(str);
                }
                lines.push_back(str);
            }
        }else {
            break;
        }
        currentLine++;
    }
    if (lines.empty()) {
        return 1;
    }
    if (opt.fileOutput) {
        Output::pushFile(lines, cmd.resultFile);
    }
    return 0;
}
