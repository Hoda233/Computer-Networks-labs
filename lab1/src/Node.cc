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

#include "Node.h"
#include <string> // Include the string header file
using namespace std;
Define_Module(Node);
int text_tic=0;
int text_toc=1;

void Node::initialize()
{
    // TODO - Generated method body

    if(strcmp(getName(),"Tic")==0)
    {
        std::string text1 = "Tic_";
//        int text2 = 0;
        std::string text = text1+std::to_string(text_tic);
        cMessage * msg = new cMessage(text.c_str());
        send(msg,"out");
    }

}



//void Node::handleMessage(cMessage *msg)
//{
//    // TODO - Generated method body
//    if (msg->isSelfMessage()) {
//            std::string message = msg->getName();
//
//            if (message == "Tic_0") {
//                cMessage* ticMsg = new cMessage("Tic_0");
//                send(ticMsg, "out");
//            }
//            else if (message.substr(0, 4) == "Toc_") {
//                int sequenceNumber = std::stoi(message.substr(4));
//
//                if (sequenceNumber < 9) {
//                    std::string responseMessage;
//                    if (sequenceNumber % 2 == 0) {
//                        responseMessage = "Tic_" + std::to_string(sequenceNumber + 1);
//                    }
//                    else {
//                        responseMessage = "Toc_" + std::to_string(sequenceNumber + 1);
//                    }
//
//                    cMessage* response = new cMessage(responseMessage.c_str());
//                    send(response, "out");
//                }
//            }
//        }
//
//        delete msg;
//}


void Node::handleMessage(cMessage *msg)
{
    static uint32_t count = 1;
    if(count<=9)
    {
    if(strcmp(getName(), "Tic") == 0)
        {

                cMessage* msg;

                string temp = "Tic_" + to_string(count);
                msg = new cMessage(temp.c_str());
                count++;

                send(msg, "out");
        }
    else if(strcmp(getName(), "Toc") == 0) {
        cMessage* msg;
        if(count != 0) {
            string temp = "Toc_" + to_string(count);
            msg = new cMessage(temp.c_str());
            count++;
        }
        send(msg, "out");

    }
    }
}



//void Node::handleMessage(cMessage *msg)
//
//{
//if(text_tic < 9)
//
//{
//    if (msg->isSelfMessage()) {
//    if(strcmp(getName(),"Tic")==0)
//       {
//
//           std::string text1 = "Tic_";
//           int text2 = 2;
//           std::string text = text1+std::to_string(text_tic);
//           cMessage * msg = new cMessage(text.c_str());
//           send(msg,"out");
//           text_tic++;
//
//       }
//    else {
//        std::string text1 = "Toc_";
//                  int text2 = 1;
//                  std::string text = text1+std::to_string(text_tic);
//                  cMessage * msg = new cMessage(text.c_str());
//                  send(msg,"out");
//                  text_tic++;
//
//    }
//
//    send(msg,"out"); //(msg,output gate)
//      EV<<"Resending Message "<<endl;
//    }
//
//}
//}

