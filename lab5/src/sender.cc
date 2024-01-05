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

#include "sender.h"
# include "MyMessage_m.h"
#include <iostream>
using namespace std;

Define_Module(Sender);

void Sender::initialize()
{
    // TODO - Generated method body

    scheduleAt(0, new cMessage(""));
}

void Sender::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    // define the message
    MyMessage_Base * my_msg = new MyMessage_Base();

    // ----------------------------- Payload part -----------------------------

    string word;
    cout<<"Enter the message: "<<endl;
    cin>>word;
    cout<<"Your message: "<<word<<endl;

//    my_msg->setM_Payload(word.c_str());
//    cout<<"Payload: "<<my_msg->getM_Payload()<<endl;

    // ----------------------------- Header part -----------------------------

    int char_count = word.length() + 2;
    cout<<"Char count: "<<char_count<<endl;

    bitset<8> char_count_bits = bitset<8> (char_count);
    cout<<"Char count: "<< char_count_bits <<endl;

    my_msg->setM_Header((char)char_count_bits.to_ulong());

    cout<<"Header: "<<my_msg->getM_Header()<<endl;

    // ----------------------------- Trailer part -----------------------------

    vector<bitset<8> > vec;

    vec.push_back(char_count);

    for (char c : word) {
       vec.push_back(bitset<8>(c));
    }

    bitset<8> parity=bitset<8>(0);
    for(vector<bitset<8> >::iterator it=vec.begin();it!=vec.end();++it)
    {
       parity=parity^*it;
    }
    cout<<"parity: "<<parity<<endl;

    my_msg->setM_Trailer((char) parity.to_ulong());

    cout<<"Trailer: "<<my_msg->getM_Trailer()<<endl;

    vec.push_back(parity);

    // ----------------------------- Type part -----------------------------

    my_msg->setM_Type(2);

    cout<<"Type: "<<my_msg->getM_Type()<<endl;

    // ------------------------------ Payload part with error ----------------------------

       // probability of error
       volatile float error_rate = uniform(0,1);
       cout<<"no error probability "<<error_rate *100<<"%"<<endl;

       if (error_rate < 0.5)
       {
           EV<< "adding error"<<endl;
           cout<<"Adding error"<<endl;

           // choose random bit in the payload to flip
           int bitErrorPosition = int(uniform(0, word.length() * 8));
           cout<<"bit Error Position: "<< bitErrorPosition <<endl;

           // convert to string of bits
           string old_word = "";
           string new_word = "";

           cout<<"Word before: "<<word<<endl;
           for (char c : word) {
                old_word = old_word + bitset<8> (c).to_string();
                new_word = new_word + bitset<8> (c).to_string();
           }
           cout<<"Word before: "<<old_word<<endl;

           // flip the bit chosen
           new_word[bitErrorPosition] = new_word[bitErrorPosition] == '0' ? '1' : '0';

           cout<<"Word after : "<<new_word<<endl;

           // convert to string of chars
           string new_payload = "";
           for (size_t i = 0; i < new_word.length(); i += 8)
           {
              string chunk = new_word.substr(i, 8);
              new_payload = new_payload + (char)bitset<8>(chunk).to_ulong();
           }
           cout<<"Word after : "<<new_payload<<endl;

           my_msg->setM_Payload(new_payload.c_str());
           cout<<"Payload: "<<my_msg->getM_Payload()<<endl;

       }
       else{
           cout<<"No error"<<endl;
           my_msg->setM_Payload(word.c_str());
           cout<<"Payload: "<<my_msg->getM_Payload()<<endl;
       }

    // -----------------------------------------------------------------------------------
    EV<<"Sender: "<<endl;
    EV<<my_msg<<endl;
    EV<<"Header (char): "<<my_msg->getM_Header()<<" Header (bits): "<<bitset<8>(my_msg->getM_Header())<<" Header (ulong): "<<(bitset<8>(my_msg->getM_Header())).to_ulong()<<endl;
    EV<<"Payload: "<<my_msg->getM_Payload()<<endl;
    EV<<"Trailer (char): "<<my_msg->getM_Trailer()<<" Trailer (bits): "<<bitset<8>(my_msg->getM_Trailer())<<" Trailer (ulong): "<<(bitset<8>(my_msg->getM_Trailer())).to_ulong()<<endl;
    EV<<"Type: "<<my_msg->getM_Type()<<endl;

    send(my_msg,"out");


}



























