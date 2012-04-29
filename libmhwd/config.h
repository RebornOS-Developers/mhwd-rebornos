/*
 *  mhwd - Manjaro Hardware Detection
 *
 *  Copyright (C) 2007 Free Software Foundation, Inc.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "string.hpp"

using namespace std;


namespace mhwd {
    class Config
    {
    public:
        Config(string path);
        bool operator==(const Config& compare);

        bool isValid() { return configValid; }
        string getName() { return name; }
        string getInfo() { return info; }
        bool getIsFreeDriver() { return freedriver; }
        int getPriority() { return priority; }

        struct IDsGroup {
            vector<string> classIDs, vendorIDs, deviceIDs;
        };

        vector<IDsGroup> getIDsGroups() { return IDs; }

    private:
        string path, name, info;
        vector<IDsGroup> IDs;
        bool configValid, freedriver;
        int priority;

        bool readConfig(const Vita::string path);
        vector<string> getIDs(Vita::string str);
        inline void addNewIDsGroup();
        Vita::string getRightPath(Vita::string str);
    };
}

#endif // CONFIG_H