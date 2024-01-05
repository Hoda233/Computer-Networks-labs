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
#include <iostream>
using namespace std;

Define_Module(Sender);

void Sender::initialize()
{
    // TODO - Generated method body
    scheduleAt(simTime()+5,new cMessage(""));

}

void Sender::handleMessage(cMessage *msg)
{
    cout<<"hello we are now in sender: "<<endl;
    // TODO - Generated method body
       string frame="";
       string word;
       cout<<"enter the message !"<<endl;
       cin>>word;
       cout<<"you enterd: "<<word<<endl;

        int char_count = word.length()+2;
        bitset<8> parity=bitset<8>(0);
       vector<bitset<8> > vec;
       vec.push_back(char_count);
       for (char c : word) {
           vec.push_back(bitset<8>(c));
          }

        for(vector<bitset<8> >::iterator it=vec.begin();it!=vec.end();++it)

        { parity=parity^*it;
//            cout<<*it<<" ";
        }
        cout<<endl;
        vec.push_back(parity);
        cout<<"messgae before error: "<<endl;
        for(vector<bitset<8> >::iterator it=vec.begin();it!=vec.end();++it)

              {
                  frame= frame + (*it).to_string();
                  cout<<*it<<endl;
              }
        cout<<endl;
//        cout <<"message before error as string: "<<frame<<endl;

        //error
        volatile float error_rate=uniform(0,1);
        cout<<"no error probability "<<error_rate *100<<"%"<<endl;

        if (error_rate < 0.5) {
               int bitErrorPosition = int(uniform(0, char_count*8));
               frame[bitErrorPosition] = frame[bitErrorPosition] == '0' ? '1' : '0';

                cout<<" bit Error Position: "<< bitErrorPosition<<endl;
//                cout <<"message with error: "<<frame<<endl;
                cout <<"message with error: "<<endl;
                for (size_t i = 0; i < frame.length(); i += 8) {
                            string chunk;
                            chunk = frame.substr(i, 8);
                           cout<<chunk<<endl;

                        }
           }
        else {
            cout<<" there will be no error the message will be the same "<<endl;
        }


       msg= new cMessage(frame.c_str());
       send(msg,"out");
}
