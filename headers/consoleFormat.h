#ifndef CONSOLE_FORMAT_H
#define CONSOLE_FORMAT_H

#include <string>
#include <vector>

namespace ConsoleFormatting
{
    std::string wrap(const std::string& wrapInput);
    int getConsoleWidth();
    std::string colorize(const std::string& text);
}

#endif
