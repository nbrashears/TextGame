/*
*******************************************************************************
                                    TO DO
*******************************************************************************

 - This game is gonna be near unplayable if there isn't some sort of system
that autocompletes commands when you press tab, just like a Linux terminal
would

 - Make it so that directories can be referred to by their name "dir" or by
the actual directory "dir/" so that when I run "cd ../" it doesn't return
"Unknown command"

 - Need a dev-file containing all of the ingame files on each separate ingame computer system
For example:
ComputerOne:
    root/
      logs/
        text.txt
        readme.txt
      programs/
        radioScanner
        radioInstructions.txt
And I need a system that can read this file and parse it into File objects and
Directory Objects and use those to populate in-game terminals.

 - A character-by-character typing system would be pretty cool and immersive.
Just make sure it's fast so it doesn't slow down gameplay

 - Find out how to change text color for certain words or characters to improve
readability and make it look more interesting

*/

#include <iostream>
#include <string>

#include "../headers/consoleFormat.h"
#include "../headers/fileManagement.h"
#include "../headers/gameTerminal.h"

using namespace std;

int main() {

    std::string CMDFilepath = "../files/gameCmds.txt";

    // DEBUG
    std::cout << "Now running main()!\nUse HELP to view a list of commands" <<
    std::endl;

    std::string userCmd;
    while (true) {

        std::getline(std::cin, userCmd);

        // Right now only HELP and EXIT work
        if (userCmd == "help") {
            std::cout << ConsoleFormatting::colorize(FileManagement::readFileTag("files/gameCmds.txt",
            userCmd)) << std::endl;
        } else if (userCmd == "exit") {
            break;
        } else {

            /*
            For every command, convert userCmd to lowercase and check if it's
            equal. If so, this means they just missed the case, and output:
            "Did you mean help instead of HELP? Remember, commands are case
            sensitive, to a computer, h and H are different symbols and will
            be treated as such." Obviously don't use such a long winded error
            message but you get the idea.

            In order to do this, I need:
             - A list of commands to iterate through
                - The Linux terminal handles this by storing all of its
                commands in a folder, /bin/, that contains bash scripts that
                simply get run if their name is typed into the terminal. This
                would be a very interesting way of doing that in-game, but also
                leagues more complex than a simple else if () statement for
                every command
            */

            // At some point, change it so that it only outputs the "use HELP'
            // part after a couple unknown commands
            std::cout << "Unknown command, try again. To view a list of "
            "commands, use HELP" << std::endl;
        }
    }

    return 0;
}
