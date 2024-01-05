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

#include "node.h"
#include <string>
using namespace std;
Define_Module(Node);
int count = 1;
void Node::initialize()
{
    // TODO - Generated method body

    int nodeId = getIndex();
    cMessage * msg = new cMessage("hi");
    EV << "Starting Node " << nodeId << endl;
    if(nodeId == 0)
    send(msg, "port$o", nodeId);
}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    int nodeId = getIndex();
//    EV << "Starting Node " << nodeId << endl;
    EV << "Node " << nodeId << " received message: " << msg->getName() << endl;

       // Check if the special message has completed the ring
       if (strcmp(msg->getName(), "hi") == 0 && nodeId == 0) {
           // The special message has completed the ring and returned to Node 0

           EV << "Ring Length: " << count << endl;
           delete msg;  // Delete the message since it has completed the ring
           return;
       }

       // Forward the message to the next node in the ring
//       int nextGateIndex = (msg->getArrivalGate()->getIndex() + 1) % gateSize("port");
       int nextGateIndex = (msg->getArrivalGate()->getIndex() + 1) ;
       count++;
       EV << "next: " <<nextGateIndex << endl;
       send(msg, "port$o",nextGateIndex);




}
