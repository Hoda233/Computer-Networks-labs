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

#include "receiver.h"
# include "MyMessage_m.h"
#include <iostream>
using namespace std;

Define_Module(Receiver);

void Receiver::initialize()
{
    // TODO - Generated method body
}

void Receiver::handleMessage(cMessage *msg)
{
    // TODO - Generated method body


     // cast the received message
     MyMessage_Base * my_msg = check_and_cast<MyMessage_Base *>(msg);

//     EV<<"Receiver: "<<endl;
//     EV<<my_msg<<endl;
//     EV<<"Header (char): "<<my_msg->getM_Header()<<" Header (bits): "<<bitset<8>(my_msg->getM_Header())<<" Header (ulong): "<<(bitset<8>(my_msg->getM_Header())).to_ulong()<<endl;
//     EV<<"Payload: "<<my_msg->getM_Payload()<<endl;
//     EV<<"Trailer (char): "<<my_msg->getM_Trailer()<<" Trailer (bits): "<<bitset<8>(my_msg->getM_Trailer())<<" Trailer (ulong): "<<(bitset<8>(my_msg->getM_Trailer())).to_ulong()<<endl;
//     EV<<"Type: "<<my_msg->getM_Type()<<endl;


     // vector of bits for the whole message
     vector<bitset<8> > vec;

     vec.push_back(bitset<8>(my_msg->getM_Header()));

     for (char c : string(my_msg->getM_Payload()))
     {
         vec.push_back(bitset<8>(c));
     }

     vec.push_back(bitset<8>(my_msg->getM_Trailer()));

     // check the parity
     bitset<8> receiver_parity=bitset<8>(0);
     bitset<8> sender_parity  =bitset<8>(0);
     for(vector<bitset<8> >::iterator it=vec.begin();it!=vec.end();++it)
     {
          if(it != prev(vec.end()))
          {
               receiver_parity=receiver_parity^*it;
          }
          else
          {
               sender_parity = *it;
          }
      }
      cout<<"Sender Parity: "<<sender_parity<<" , "<<"Receiver Parity: "<<receiver_parity<<endl;


      // define the message

      MyMessage_Base * my_msg2 = new MyMessage_Base();

      // compare and send to the sender ACK/NotACK
      if(sender_parity != receiver_parity)
      {
           cout<<"There is an ERROR in the message!"<<endl;
           my_msg2->setM_Type(0);
      }
      else
      {
           cout<<"The original message is \""<<my_msg->getM_Payload()<<"\""<<endl;
           my_msg2->setM_Type(1);
      }

      // -----------------------------------------------------------------------------------

      my_msg2->setM_Header(0);
      my_msg->setM_Payload("");
      my_msg2->setM_Trailer(0);

      EV<<"Receiver: "<<endl;
      EV<<my_msg2<<endl;
      EV<<"Header (char): "<<my_msg2->getM_Header()<<" Header (bits): "<<bitset<8>(my_msg2->getM_Header())<<" Header (ulong): "<<(bitset<8>(my_msg2->getM_Header())).to_ulong()<<endl;
      EV<<"Payload: "<<my_msg2->getM_Payload()<<endl;
      EV<<"Trailer (char): "<<my_msg2->getM_Trailer()<<" Trailer (bits): "<<bitset<8>(my_msg2->getM_Trailer())<<" Trailer (ulong): "<<(bitset<8>(my_msg2->getM_Trailer())).to_ulong()<<endl;
      EV<<"Type: "<<my_msg2->getM_Type()<<endl;
      send(my_msg2,"out");


}
