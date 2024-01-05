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

#include "player2.h"
#include <string>
using namespace std;
Define_Module(Player2);

void Player2::initialize()
{
    // TODO - Generated method body

}

void Player2::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    string message = msg->getName();
    EV<<"Player 2 received: "<<message<<endl;
//EV<<message.find("send") <<" "<< message.find("wrong")<<endl;
    if(message.find("send")!= std::string::npos ||  message.find("wrong")!= std::string::npos) {

        int guess = par("guess").intValue();
        char g[256];
        sprintf(g, "%lld", guess);
        msg->setName(g);

        EV<<"Player 2 send :"<<g<<endl;
        send(msg,"out");
    }
    else {
        cancelAndDelete(msg);
    }

}
