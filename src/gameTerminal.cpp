#include <iostream>
#include <string>

#include "../headers/gameTerminal.h"
#include "../headers/fileManagement.h"

namespace GameTerminal {

    void listDirectory(FileManagement::Directory* dir) {

        // For every subdirectory within the current directory, cout DIRECTORY/
        // then insert a linebreak so output looks like this:
        // DIRECTORY/
        // LOGS/
        // ETC/
        for (auto& d : dir->subdirs) {
            std::cout << d->name << "/" << std::endl;
        }

        for (auto& f : dir->files) {
            std::cout << f.name << std::endl;
        }
    }

    FileManagement::Directory* changeDirectory(FileManagement::Directory* current,
    const std::string& name) {

        // If the directory to be changed into is ".." then return the current
        // directory's parent if one exists, else, iterate through all subdirs
        // until the names match, then return that directory
        if (name == ".." && current->parent) {
            return current->parent;
        }

        for (auto& d : current->subdirs) {
            if (d->name == name) {
                return d.get();
            }
        }

        std::cout << "No such directory" << std::endl;
        return current;
    }

    void catFile(FileManagement::Directory* dir, const std::string& name) {

        // For every file in the current directory, if the file is equal to the
        // given argument, cout the contents of that file.
        for (auto& f : dir->files) {
            if (f.name == name) {
                std::cout << f.contents << std::endl;
                return;
            }
        }

        std::cout << "No such file" << std::endl;
    }

    void runTerminal() {

        // DEBUG
        std::cout << "Running runTerminal()!" << std::endl;

        auto root = FileManagement::createFilesystem();
        FileManagement::Directory* current = root.get();

        std::string cmd;
        while (true) {

            std::cout << current->name << "$ ";
            // What's the difference between std::getline() and std::cin?
            std::getline(std::cin, cmd);

            // What does std::string.rfind() do?
            if (cmd == "ls") {
                GameTerminal::listDirectory(current);
            } else if (cmd.rfind("cd ", 0) == 0) {
                std::string dirname = cmd.substr(3);
                current = GameTerminal::changeDirectory(current, dirname);
            } else if (cmd.rfind("cat ", 0) == 0) {
                std::string filename = cmd.substr(4);
                GameTerminal::catFile(current, filename);
            } else if (cmd == "help") {
                std::cout << "This command doesn't do anything at the moment" <<
                std::endl;
                // I'd like to have a file in the game terminal that contains a
                // list of all the commands, and help just runs cat path/to/file.txt
            } else if (cmd == "exit") {
                break;
            } else {
                std::cout << "Unknown command" << std::endl;
            }
        }
    }
}
