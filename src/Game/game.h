/*
 *   Space Quest
 *   Copyright (C) 2026  Sophie Short
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <string>
#include <iostream>
#include <unistd.h>
#include <map>
#include "Map/mapLocation.h"
#include "Ship/ship.h"
#include "Cargo/cargo.h"

#pragma once

namespace SpaceQuest
{
#define TEXT_DELAY 100

enum Gamestate
{
    INTRO,
    MAIN_MENU,
    SHIP_MENU,
    PLANET_MENU,
    STATION_MENU,
    SPACE_MENU,
    STAR_MENU,
    ASTEROID_MENU,
    MARKET_MENU,
    SHIPMARKET_MENU,
    OUTFITTING_MENU,
    EXPLORE_MENU
};

class Game
{
private:
    std::map<std::string, SpaceQuest::Ship *> allShips;
    std::map<std::string, SpaceQuest::MapLocation *> allLocations;

    Gamestate gamestate = SpaceQuest::Gamestate::MAIN_MENU;
    SpaceQuest::MapLocation *currentLocation;
    SpaceQuest::Ship *currentShip;

    SpaceQuest::MapLocation *destination;
    int destinationDistanceRemaining;

public:
    Game();
    ~Game();

private:
    void SetGamestate(SpaceQuest::Gamestate newState);
    void PrintText(std::string textToPrint);
    void ClearScreen();
    char GetCinInput();
    void CreateLocations();
    void CreateShips();
    void RunGameloop();
};
}