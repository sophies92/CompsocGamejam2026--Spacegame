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
 #include <vector>
 #include "../Cargo/cargo.h"

 #pragma once

 namespace SpaceQuest
 {
    class Ship
    {
    private:
        std::string shipName;
        std::string shipDescription;
        int maxHP;
        int currentHP;
        int maxFuel;
        int currentFuel;
        int maxCargo;
        std::vector<SpaceQuest::Cargo> currentCargo;

    public:
        Ship(std::string shipName,
        std::string shipDescription,
        int maxHP,
        int currentHP,
        int maxFuel,
        int currentFuel,
        int maxCargo,
        std::vector<SpaceQuest::Cargo> currentCargo);
        ~Ship();

        std::string GetShipName();
        std::string GetShipDescription();
        int GetMaxHP();
        int GetCurrentHP();
        int GetMaxFuel();
        int GetCurrentFuel();
        int GetMaxCargo();
        int GetCurrentCargoCount();
    };
 }