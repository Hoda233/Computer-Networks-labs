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
   const char *s= msg->getName();
   string text_message = "";
    string cppString(s);
    EV<<"Received message "<<cppString<<endl;
    vector<bitset<8> > vec;
    for (size_t i = 0; i < cppString.length(); i += 8) {
            string chunk;
            chunk = cppString.substr(i, 8);
            vec.push_back(bitset<8>(chunk));

        }
    cout<<"hello we are now in receiver: "<<endl;
    bitset<8> receiver_parity=bitset<8>(0);
    bitset<8> sender_parity=bitset<8>(0);
    for(vector<bitset<8> >::iterator it=vec.begin();it!=vec.end();++it)

                {
        if(it != prev(vec.end())){
            receiver_parity=receiver_parity^*it;
        }
        else {
            sender_parity = *it;
        }
                    cout<<*it<<endl;
                }
    cout<<"sender parity: "<<sender_parity<<" , "<<"receiver parity: "<<receiver_parity<<endl;

    if(sender_parity!=receiver_parity) {
        cout<<"there is an error in the message!"<<endl;
    }
    else {
        for(vector<bitset<8> >::iterator it=vec.begin()+1;it!=vec.end();++it)

                        {
                if(it != prev(vec.end())){
                    text_message = text_message + (char)(*it).to_ulong() ;
                }


                        }
        cout<<"the text message is: "<<text_message<<endl;
    }


    send(msg,"out");
}
