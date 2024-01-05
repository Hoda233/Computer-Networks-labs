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

#include "player1.h"
#include <string>
using namespace std;
Define_Module(Player1);

void Player1::initialize()
{
    // TODO - Generated method body
    EV<<"Player 1 chose "<<par("num").intValue()<<endl;
    cMessage *msg = new cMessage("send one guess at  time !");
    send(msg,"out");
}

void Player1::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    string message = msg->getName();
    EV<<"Player 1 received: "<<message<<endl;
    int num = par("num").intValue();

//    int guess = stoi(message);
    int guess;
    sscanf(msg->getName(), "%d", &guess);

    EV<<"num , guess: "<<num<<" , "<<guess<<endl;
    if(num == guess) {
        msg->setName("correct guess");
        EV<<"Player 1 send :"<<msg->getName()<<endl;
        send(msg,"out");

    }
    else {
        msg->setName("wrong guess");
        EV<<"Player 1 send :"<<msg->getName()<<endl;
        send(msg,"out");

    }


}
