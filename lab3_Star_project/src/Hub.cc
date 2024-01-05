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

#include "Hub.h"

Define_Module(Hub);

void Hub::initialize()
{
    // TODO - Generated method body
    scheduleAt(0, new cMessage(""));
}

void Hub::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->isSelfMessage()){ // message is from the hub -> start or interval is finished

        int n = getParentModule()->par("N");
        int m = int(uniform(0,n));

        EV<<m<<endl;

        cMessage * msg_to_node = new cMessage("Hello from Hub");
        send(msg_to_node, "ports$o", m);

    }else{ // message is from a node -> wait a random interval

        double interval=  exponential(2.0);
        EV<<interval<<endl;
        scheduleAt(simTime() + interval, new cMessage(""));

    }
}
