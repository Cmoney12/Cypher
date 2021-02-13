#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printList(const vector<char> &message) {
    for(auto i: message) {
        cout << i;
    }
}

int main(int argc, char **argv) {

    char myCh;
    int myInt = 1;
    string string1;

    vector<int> keyList;
    vector<char> letters;
    vector<int> positions;
    vector<char> decode;

    while(myInt != 0 && keyList.size() <= 99) {
        cin >> myInt;
        keyList.push_back(myInt);
        if(cin.fail()) {
            cout << "fail";
        }
    }
    keyList.pop_back();

    //the only way i could get it to not break the loop on the first go
    //cin.ignore();
    //cin.clear();
    string line;
    string garbage;
    while(cin.get(myCh)) {

        if(myCh =='\n') {
            continue;
        }
        letters.push_back(myCh);
    }
    /**while(getline(cin, line)) {
        if (line.empty() || cin.fail()) {
            break;
        }
        istringstream iss(line);
        while(iss>>myCh) {
            letters.push_back(myCh);
        }
    }
    for(auto i: letters) {
        cout << i;

    }**/
    cout << endl;

    int sizeNeeded = letters.size() - keyList.size();

   //make a list then char position then add the new shift amount
   //which is keylist + letter for first
   // then do char position left then then cpl + 32
   // append those to keylist vector
   //iterate over that
   int x;
   int shiftAmount;
   for(int i = 0; i != sizeNeeded; i++) {
       x = letters.at(i) - 32;
       int w = (x - keyList.at(i)) % 95;
       w = w + (w < 0 ? 95: 0);
       positions.push_back(w);

       if(i==0){
           shiftAmount = keyList.at(i) + letters.at(i);
       }
       else {
           shiftAmount = keyList.at(i) + positions.at(i-1) +32;
       }
       keyList.push_back(shiftAmount);
   }
   //doing the whole decoding and appending them to
   for(int i = 0; i != letters.size(); i++) {
       x = letters.at(i) - 32;
       int w = (x - keyList.at(i)) % 95;
       char z = w + (w < 0 ? 95: 0) + 32;
       decode.push_back(z);
   }
   printList(decode);
}

//gcc -o program myprogram.cpp
