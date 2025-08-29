#include <iostream>
#include <string>
#include "../headers/consoleFormat.h"

#include <sys/ioctl.h>
#include <unistd.h>

namespace ConsoleFormatting {

    std::string wrap(const std::string& wrapInput) {

        std::string output;
        size_t linelength = 0;
        size_t columnWidth = getConsoleWidth();

        for (size_t i = 0; i < wrapInput.length(); i++) {

            char c = wrapInput[i]; // The current character we're iterating through
            output += c; // Append the current character to the result
            linelength++; // Keep track of how many characters we've iterated through

            if (linelength >= columnWidth) { // If we reach 80 characters...

                if (c == ' ') {

                    output.back() = '\n'; // Replace the last character in output with a newline
                    linelength = 0;

                } else {

                    size_t lastSpace = output.rfind(' ');

                    if (lastSpace != std::string::npos) {

                        output[lastSpace] = '\n';
                        linelength = output.length() - lastSpace - 1;
                    }
                }
            }
        }

        return output;
    }

    int getConsoleWidth() {
        struct winsize w;

        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
            return w.ws_col;
        }

        return 80; // Return 80 as default if no other value found
    }

    // Yes, I know there's a better way to do this, no I don't want to do it
    // right now
    std::string colorize(const std::string& text) {

        std::string result = text;

        size_t pos;
        while((pos = result.find("<red>")) != std::string::npos) {

            result.replace(pos, 5, "\033[31;1m");
        }

        while((pos = result.find("</red>")) != std::string::npos) {

            result.replace(pos, 6, "\033[0m");
        }

        while((pos = result.find("<cyan>")) != std::string::npos) {

            result.replace(pos, 6, "\033[36;1m");
        }

        while((pos = result.find("</cyan>")) != std::string::npos) {

            result.replace(pos, 7, "\033[0m");
        }

        return result;
    }
}
