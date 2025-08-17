#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <iostream>
#include <string>
#include <vector>

namespace GameWorld {

    struct Location {
        std::string name;
        std::string description;
        std::vector<Item> items;
        std::vector<NPC> npcs;
        bool isBlocked = false;
    };

    struct Item {
        std::string name;
        std::string description;
        int quantity;
        bool isEquippable = false;
        bool isMoveable false; // Whether or not the item is stationary
        std::function<void(Player&)> onUse;

    };

    struct GameCharacter {
        std::string name;
        std::string description;
        Location* currentLocation;
        std::vector<Item> inventory;
        bool isInteractable = true;
        std::function<void(GameCharacter&)> interact;

        virtual void interact(GameCharacter& character) {

            if (interact) {
                interact(character);
            } else {
                // DEBUG
                std::cout << "You just tried to interact with a character that "
                "doesn't have an interact() function set!" << std::endl;
            }

            virtual ~GameCharacter() = default;
        }
    };

    struct Player : GameCharacter {
        /*
        Player specific traits here, right now I can't think of any
        */
    }

    void use(Player& player) {

        if (onUse) {
            onUse(player);
        } else {
            std::cout << "You can't use that!" << std::endl;
        }
    }
}

#endif
