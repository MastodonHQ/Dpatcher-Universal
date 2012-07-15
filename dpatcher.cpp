/*
################################################################################
# This file is part of dpatcher.                                               #
#                                                                              #
#    dpatcher is free software: you can redistribute it and/or modify          #
#    it under the terms of the GNU General Public License as published by      #
#    the Free Software Foundation, either version 3 of the License, or         #
#    (at your option) any later version.                                       #
#                                                                              #
#    Foobar is distributed in the hope that it will be useful,                 #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of            #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             #
#    GNU General Public License for more details.                              #
#                                                                              #   
#   You should have received a copy of the GNU General Public License          #
#   along with dpatcher. If not, see <http://www.gnu.org/licenses/>.           #
################################################################################
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


int main(int argc,char ** argv){
/*if(argc<=1){
cout<<"What am I operating on thin air? Give me a file damn it preferably your save.dats they taste like cookies :D.\n";
exit(0);
}
*/
//else{
fstream destinia;
destinia.open("test.dat",fstream::in | fstream::out | fstream::binary);
unsigned int d;

cout<<"Beginning Patch Mode.\n";
cout<<"Patching Level/Exp.\n";

destinia.seekg(0x16);
d=destinia.get();
cout<<"Value at 0x16 before patch:\n";
cout<<"Decimal:"<<d<<"\n";
cout<<"Hexidecimal:"<<hex<<d<<"\n";
cout<<"\nNow Patching..."<<endl;

destinia.seekp(0x16);
destinia.put(0xFF);

destinia.seekg(0x16);
d=destinia.get();
cout<<"Value at 0x16 after patch:\n";
cout<<"Decimal:"<<d<<"\n";
cout<<"Hexidecimal:"<<hex<<d<<endl;

destinia.seekg(0x4A);
d=destinia.get();
cout<<"Value at 0x4A before patch:\n";
cout<<"Decimal:"<<d<<"\n";
cout<<"Hexidecimal:"<<hex<<d<<"\n";

destinia.seekg(0x4B);
d=destinia.get();
cout<<"Value at 0x4B before patch:\n";
cout<<"Decimal:"<<d<<"\n";
cout<<"Hexidecimal:"<<hex<<d<<"\n";

cout<<"\nNow Patching Stat Points...\n";

destinia.seekp(0x4A);
destinia.put(0x0F);

destinia.seekp(0x4B);
destinia.put(0x27);

destinia.seekg(0x4A);
d=destinia.get();
cout<<"Value at 0x4A after patch:\n";
cout<<"Decimal:"<<d<<"\n";
cout<<"Hexidecimal:"<<hex<<d<<"\n";

destinia.seekg(0x4B);
d=destinia.get();
cout<<"Value at 0x4B after patch:\n";
cout<<"Decimal:"<<d<<"\n";
cout<<"Hexidecimal:"<<hex<<d<<"\n";
destinia.close();
//}
return 0;
}
