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

 #include "mapLocation.h"

SpaceQuest::MapLocation::MapLocation(std::string locationName, std::string locationDescription, SpaceQuest::LocationType locationType, SpaceQuest::EconomyType economyType, bool hasMarket, bool hasShipyard, bool hasOutfitting)
{
    this->locationName = locationName;
    this->locationDescription = locationDescription;
    this->locationType = locationType;
    this->economyType = economyType;
    this->hasMarket = hasMarket;
    this->hasShipyard = hasShipyard;
    this->hasOutfitting = hasOutfitting;
}

SpaceQuest::MapLocation::~MapLocation()
{
}

std::string SpaceQuest::MapLocation::GetName()
{
    return(locationName);
}

std::string SpaceQuest::MapLocation::GetDescription()
{
    return(locationDescription);
}

SpaceQuest::LocationType SpaceQuest::MapLocation::GetLocationType()
{
    return(locationType);
}

SpaceQuest::EconomyType SpaceQuest::MapLocation::GetEconomyType()
{
    return(economyType);
}

std::string SpaceQuest::MapLocation::GetEconomyTypeString()
{
    switch(GetEconomyType())
    {
        case SpaceQuest::EconomyType::AGRICULTURE:
            return("Agriculture");

        case SpaceQuest::EconomyType::MANUFACTURING:
            return("Manufacturing");

        case SpaceQuest::EconomyType::MILITARY:
            return("Military");

        case SpaceQuest::EconomyType::MINING:
            return("Mining");

        case SpaceQuest::EconomyType::RESEARCH:
            return("Research");

        case SpaceQuest::EconomyType::SERVICE:
            return("Service");

        case SpaceQuest::EconomyType::TOURISM:
            return("Tourism");
    }
    return("ECONOMY_TYPE");
}

bool SpaceQuest::MapLocation::GetHasMarket()
{
    return(hasMarket);
}

bool SpaceQuest::MapLocation::GetHasShipyard()
{
    return(hasShipyard);
}

bool SpaceQuest::MapLocation::GetHasOutfitting()
{
    return(hasOutfitting);
}
