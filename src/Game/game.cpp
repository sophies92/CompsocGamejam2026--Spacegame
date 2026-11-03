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

#include "game.h"

SpaceQuest::Game::Game()
{
    CreateLocations();
    CreateShips();


    currentLocation = allLocations.at("New London");
    currentShip = allShips.at("Spider");

    RunGameloop();
}

SpaceQuest::Game::~Game()
{
}

void SpaceQuest::Game::SetGamestate(SpaceQuest::Gamestate newState)
{
    gamestate = newState;
}

void SpaceQuest::Game::PrintText(std::string textToPrint)
{
    for(int i = 0; i < textToPrint.length(); i++)
    {
        std::cout << textToPrint.at(i);
        std::flush(std::cout);
        usleep(TEXT_DELAY * 1000);
    }
    usleep(TEXT_DELAY *1000);
}

void SpaceQuest::Game::ClearScreen()
{
    std::cout << "\e[1;1H\e[2J";
}

char SpaceQuest::Game::GetCinInput()
{
    char c;
    std::cin >> c;
    return(c);
}

void SpaceQuest::Game::CreateLocations()
{
    SpaceQuest::MapLocation *newLondonLocation = new SpaceQuest::MapLocation(
        "New London",
        "Welcome to New London", 
        SpaceQuest::LocationType::PLANET, 
        SpaceQuest::EconomyType::MANUFACTURING,
        true,
        true,
        true
    );
    allLocations.emplace("New London", newLondonLocation);

    SpaceQuest::MapLocation *kentResearchLocation = new SpaceQuest::MapLocation(
        "Kent Research Station",
        "This was the first research station established after the Earth was evacuated.",
        SpaceQuest::LocationType::STATION,
        SpaceQuest::EconomyType::RESEARCH,
        true,
        false,
        false
    );
    allLocations.emplace("Kent Research Station", kentResearchLocation);
}

void SpaceQuest::Game::CreateShips()
{
    SpaceQuest::Ship *spiderShip = new SpaceQuest::Ship(
        "Spider",
        "A small ship formerly used by the navy for training new pilots.",
        30,
        30,
        2,
        2,
        3,
        std::vector<SpaceQuest::Cargo>()
    );
    allShips.emplace("Spider", spiderShip);
}

void SpaceQuest::Game::RunGameloop()
{
    while(true)
    {
        char c;
        switch (gamestate)
        {
            case SpaceQuest::Gamestate::MAIN_MENU:
                ClearScreen();
                PrintText("SpaceQuest\n");
                PrintText("\n");
                PrintText("1 - New Game\n");
                PrintText("Q - Quit\n");

                while(c = GetCinInput())
                {
                    switch(c)
                    {
                        case '1':
                            ClearScreen();
                            SetGamestate(SpaceQuest::Gamestate::INTRO);
                        break;

                        case 'q':
                        case 'Q':
                            ClearScreen();
                            PrintText("Exiting...");
                            ClearScreen();
                            return;
                        break;
                    }
                    break;
                }
            break; // End MAIN_MENU

            case SpaceQuest::Gamestate::INTRO:
                ClearScreen();
                PrintText("Ding! Ding! Ding!\n");
                PrintText("You've won a raffle!\n");
                PrintText("You won...\n");
                PrintText("...\n");
                PrintText("A spaceship!\n");
                PrintText("It's a little beat up and lacking in firepower, but this could be your chance to earn your fortune!\n");
                sleep(1);
                PrintText("If you survive...\n");
                sleep(3);

                SetGamestate(SpaceQuest::Gamestate::PLANET_MENU);
            break; // End INTRO

            case SpaceQuest::Gamestate::PLANET_MENU:
                ClearScreen();
                PrintText("Current Planet: ");
                PrintText(currentLocation->GetName() + "\n");
                PrintText(currentLocation->GetDescription() + "\n");
                PrintText("Economy Type: ");
                PrintText(currentLocation->GetEconomyTypeString());
                PrintText("\n");
                PrintText("\n");

                PrintText("1 - Market\n");
                PrintText("2 - Shipyard\n");
                PrintText("3 - Outfitting\n");
                PrintText("4 - Enter Ship\n");
                PrintText("5 - Explore\n");

                c = GetCinInput();
                switch(c)
                {
                    case '1':
                        if(currentLocation->GetHasMarket())
                        {
                            ClearScreen();
                            SetGamestate(SpaceQuest::Gamestate::MARKET_MENU);
                        }
                        else
                        {
                            ClearScreen();
                            PrintText("No market present!");
                        }
                    break;

                    case '2':
                        if(currentLocation->GetHasShipyard())
                        {
                            ClearScreen();
                            SetGamestate(SpaceQuest::Gamestate::SHIPMARKET_MENU);
                        }
                        else
                        {
                            ClearScreen();
                            PrintText("No shipyard present!");
                        }
                    break;

                    case '3':
                        if(currentLocation->GetHasOutfitting())
                        {
                            ClearScreen();
                            SetGamestate(SpaceQuest::Gamestate::OUTFITTING_MENU);
                        }
                        else
                        {
                            ClearScreen();
                            PrintText("No outfitters present!");
                        }
                    break;

                    case '4':
                        ClearScreen();
                        SetGamestate(SpaceQuest::Gamestate::SHIP_MENU);
                    break;

                    case '5':
                        ClearScreen();
                        SetGamestate(SpaceQuest::Gamestate::EXPLORE_MENU);
                    break;
                }
            break; // End PLANET_MENU

            case SpaceQuest::Gamestate::STATION_MENU:
                ClearScreen();
                PrintText("Current Station: ");
                PrintText(currentLocation->GetName() + "\n");
                PrintText(currentLocation->GetDescription() + "\n");
                PrintText("Economy Type: ");
                PrintText("ECONOMY TYPE\n");
                PrintText("\n");

                PrintText("1 - Market\n");
                PrintText("2 - Shipyard\n");
                PrintText("3 - Outfitting\n");
                PrintText("4 - Enter Ship\n");
                PrintText("5 - Explore\n");

                c = GetCinInput();
                switch(c)
                {
                    case '1':
                        if(currentLocation->GetHasMarket())
                        {
                            SetGamestate(SpaceQuest::Gamestate::MARKET_MENU);
                        }
                        else
                        {
                            ClearScreen();
                            PrintText("No market present!");
                        }
                    break;

                    case '2':
                        if(currentLocation->GetHasShipyard())
                        {
                            SetGamestate(SpaceQuest::Gamestate::SHIPMARKET_MENU);
                        }
                        else
                        {
                            ClearScreen();
                            PrintText("No shipyard present!");
                        }
                    break;

                    case '3':
                        if(currentLocation->GetHasOutfitting())
                        {
                            SetGamestate(SpaceQuest::Gamestate::OUTFITTING_MENU);
                        }
                        else
                        {
                            ClearScreen();
                            PrintText("No outfitters present!");
                        }
                    break;

                    case '4':
                        SetGamestate(SpaceQuest::Gamestate::SHIP_MENU);
                    break;

                    case '5':
                        SetGamestate(SpaceQuest::Gamestate::EXPLORE_MENU);
                    break;
                }
            break; // End STATION_MENU

            case SpaceQuest::Gamestate::SHIP_MENU:
                ClearScreen();
                PrintText("Current Ship: ");
                PrintText(currentShip->GetShipName());
                PrintText("\n");
                PrintText(currentShip->GetShipDescription());
                PrintText("\n");
                PrintText("HP: ");
                PrintText(std::to_string(currentShip->GetCurrentHP()));
                PrintText("/");
                PrintText(std::to_string(currentShip->GetMaxHP()));
                PrintText("\n");
                PrintText("Fuel: ");
                PrintText(std::to_string(currentShip->GetCurrentFuel()));
                PrintText("/");
                PrintText(std::to_string(currentShip->GetMaxFuel()));
                PrintText("\n");
                PrintText("Cargo: ");
                PrintText(std::to_string(currentShip->GetCurrentCargoCount()));
                PrintText("/");
                PrintText(std::to_string(currentShip->GetMaxCargo()));
                PrintText("\n");
                PrintText("\n");
                PrintText("1 - Select Target and Launch\n");
                PrintText("2 - Exit Ship\n");
                PrintText("9 - Repair\n");
                PrintText("0 - Refuel\n");

                c = GetCinInput();
                switch(c)
                {
                    case '1':
                        ClearScreen();
                    break;

                    case '2':
                        ClearScreen();
                        switch(currentLocation->GetLocationType())
                        {
                            case SpaceQuest::LocationType::ASTEROID:
                                SetGamestate(SpaceQuest::Gamestate::ASTEROID_MENU);
                            break;

                            case SpaceQuest::LocationType::PLANET:
                                SetGamestate(SpaceQuest::Gamestate::PLANET_MENU);
                            break;

                            case SpaceQuest::LocationType::SPACE:
                                SetGamestate(SpaceQuest::Gamestate::SPACE_MENU);
                            break;

                            case SpaceQuest::LocationType::STAR:
                                SetGamestate(SpaceQuest::Gamestate::STAR_MENU);
                            break;

                            case SpaceQuest::LocationType::STATION:
                                SetGamestate(SpaceQuest::Gamestate::STATION_MENU);
                            break;
                        }
                    break;

                    case '9':
                        
                    break;

                    case '0':

                    break;
                }
            break; // End SHIP_MENU

            case SpaceQuest::Gamestate::SPACE_MENU:

            break; // End SPACE_MENU
        } // End Switch
    }
}