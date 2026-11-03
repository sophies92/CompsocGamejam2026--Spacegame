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

 #pragma once

 namespace SpaceQuest
 {
    enum LocationType
    {
        PLANET,
        STATION,
        ASTEROID,
        STAR,
        SPACE
    };

    enum EconomyType
    {
        MANUFACTURING,
        MINING,
        MILITARY,
        AGRICULTURE,
        TOURISM,
        RESEARCH,
        SERVICE
    };

    class MapLocation
    {
    private:
        std::string locationName;
        std::string locationDescription;
        SpaceQuest::LocationType locationType;
        SpaceQuest::EconomyType economyType;
        bool hasMarket;
        bool hasShipyard;
        bool hasOutfitting;

    public:
        MapLocation(std::string locationName, std::string locationDescription, SpaceQuest::LocationType locationType, SpaceQuest::EconomyType economyType, bool hasMarket, bool hasShipyard, bool hasOutfitting);
        ~MapLocation();

        std::string GetName();
        std::string GetDescription();
        SpaceQuest::LocationType GetLocationType();
        SpaceQuest::EconomyType GetEconomyType();
        std::string GetEconomyTypeString();
        bool GetHasMarket();
        bool GetHasShipyard();
        bool GetHasOutfitting();
    };
 }