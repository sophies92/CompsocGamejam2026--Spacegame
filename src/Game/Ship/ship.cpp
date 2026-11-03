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

 #include "ship.h"

SpaceQuest::Ship::Ship(std::string shipName,
        std::string shipDescription,
        int maxHP,
        int currentHP,
        int maxFuel,
        int currentFuel,
        int maxCargo,
        std::vector<SpaceQuest::Cargo> currentCargo)
{
    this->shipName = shipName;
    this->shipDescription = shipDescription;
    this->maxHP = maxHP;
    this->currentHP = currentHP;
    this->maxFuel = maxFuel;
    this->currentFuel = currentFuel;
    this->maxCargo = maxCargo;
    this->currentCargo = currentCargo;
}

SpaceQuest::Ship::~Ship()
{
}

std::string SpaceQuest::Ship::GetShipName()
{
    return(shipName);
}

std::string SpaceQuest::Ship::GetShipDescription()
{
    return(shipDescription);
}

int SpaceQuest::Ship::GetMaxHP()
{
    return(maxHP);
}

int SpaceQuest::Ship::GetCurrentHP()
{
    return(currentHP);
}

int SpaceQuest::Ship::GetMaxFuel()
{
    return(maxFuel);
}

int SpaceQuest::Ship::GetCurrentFuel()
{
    return(currentFuel);
}

int SpaceQuest::Ship::GetMaxCargo()
{
    return(maxCargo);
}

int SpaceQuest::Ship::GetCurrentCargoCount()
{
    return(currentCargo.size());
}
