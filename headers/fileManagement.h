#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

namespace FileManagement {

    struct File {
        std::string name;
        std::string contents;
    };

    struct Directory {
        std::string name;
        std::vector<File> files;
        std::vector<std::shared_ptr<Directory>> subdirs;
        Directory* parent = nullptr; // for cd ../
    };

    std::shared_ptr<Directory> createFilesystem();
    std::string readFileTag(const std::string& filename, const std::string& tag);
}

#endif
