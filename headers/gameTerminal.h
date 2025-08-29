#ifndef GAME_TERMINAL_H
#define GAME_TERMINAL_H

#include "../headers/fileManagement.h"

namespace GameTerminal {

    // Functions handling ls, cd, and cat
    void listDirectory(FileManagement::Directory* dir);
    FileManagement::Directory* changeDirectory(FileManagement::Directory* current,
        const std::string& name);
    void catFile(FileManagement::Directory* dir, const std::string& name);
    void runTerminal();
}

#endif
