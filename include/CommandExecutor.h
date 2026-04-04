//
// Created by hell0ve on 04.04.2026.
//

#ifndef GREP_CLONE_COMMANDEXECUTOR_H
#define GREP_CLONE_COMMANDEXECUTOR_H
#include "Command.h"

class CommandExecutor {
public:
    static int execute(const Command& cmd);
};
#endif //GREP_CLONE_COMMANDEXECUTOR_H