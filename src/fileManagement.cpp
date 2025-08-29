#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>

#include "../headers/fileManagement.h"

namespace FileManagement {

    std::shared_ptr<Directory> createFilesystem() {

        auto root = std::make_shared<Directory>();
        root->name = "/";

        auto logs = std::make_shared<Directory>();
        logs->name = "logs";
        logs->parent = root.get();

        File f1;
        f1.name = "radio_traffic_01.txt";
        f1.contents = "[14:02] Routine radio chatter...\n";

        logs->files.push_back(f1);
        root->subdirs.push_back(logs);

        return root;
    }

    // Searches for [TAGS] within .txt files
    std::string readFileTag(const std::string& filename, const std::string& tag) {

        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Sorry, the file you were looking for wasn't found" <<
            std::endl;
            return "";
        }

        std::ostringstream buffer;
        buffer << file.rdbuf();
        std::string content = buffer.str();

        // Search pattern [TAG]
        std::string searchPattern = "[" + tag + "]";

        // Find position of tag
        size_t pos = content.find(searchPattern);
        if (pos == std::string::npos) {
            return ""; // Tag not found
        }

        // Move position to just after the tag
        pos += searchPattern.length();

        size_t startQuote = content.find('"', pos);
        if (startQuote == std::string::npos) {
            return "";
        }

        size_t endQuote = content.find('"', startQuote + 1);
        if (endQuote == std::string::npos) {
            return "";
        }

        std::string rawString = content.substr(startQuote + 1, endQuote - startQuote - 1);

        return rawString;
    }
}
