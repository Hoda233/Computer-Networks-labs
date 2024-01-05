//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "coordinator.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
Define_Module(Coordinator);

void Coordinator::initialize()
{

    // a2ra el file
    std::ifstream inputFile("E:/fourth year/projects/networks/Data_Link_Layer_Protocols_Simulation/code/coordinator.txt");

    // Check if the file is open
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
    }
    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);

        std::string nodeId, startingTime;

        // Read the two values from the line
        if (iss >> nodeId >> startingTime)
        {
            // Process the values as needed
            EV << nodeId << "   " << startingTime << endl;
            MyMessage_Base *newMesg = new MyMessage_Base(nodeId.c_str());
            newMesg->setFrame_type('3');
//            newMesg->setKind(3); // for start messaging
            scheduleAt(simTime() + std::stod(startingTime), newMesg);
        }
        else
        {
            std::cerr << "Error reading values from the line: " << line << std::endl;
        }
    }

    inputFile.close();
}

void Coordinator::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    MyMessage_Base *mmsg = check_and_cast<MyMessage_Base *>(msg);
    send(mmsg, "out", std::stoi(mmsg->getName()));
}
