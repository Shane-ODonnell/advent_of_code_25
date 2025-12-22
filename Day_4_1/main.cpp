#include <iostream>
#include <string>

using namespace std;

void process();
void substring(string& target, string reference, int start);
void checkPrev(string& prev, string curr, int& viable);
void checkCurr(string& curr, string prev, string next, int& viable);
char sentinal = '!';
void printAll(string& full){
    for(int i = 0; i < full.length(); i++ ){
        char current = full[i];
        if(current == sentinal){
            cout << endl;
        }
        else {
            cout << full[i];
            if(current == 'x')
                full[i] = '.';
        }
    }
};

bool isRoll(string array, int pos){
    if( array[pos] == '@' || array[pos] == 'x')
        return true;
    return false;
}

int countRolls(string array, int pos){
    //cout << " checking the area sorrounding spot " << pos << endl;
    int count = 0;
    for(int i = pos - 1; i <= pos + 1; i++){
        if((0 <= i && i <= array.length()) && isRoll(array, i)){
            count++;
            //cout << " " << i << " has a roll, increasing count ";
            //cout << array[i] << endl;
        }
    }
    //cout << " rolls found: " << count << endl;
    return count;
}

const int limit = 4;
bool fin = false;
bool nothingDone = true;

int main(){

    process();

    return 0;
}

void process(){
    int viable = 0;
    string prev, curr, next, full;
    
    cin >> prev;
    cin >> curr;

    int l = prev.length();

    
    checkPrev(prev, curr, viable);
    
    //cout << "viables found " << viable << endl;
    bool done = false;
    while(true){
        
        cin >> next;
        if(next[0] == sentinal){
            done = true;
        }
        //************ */

        checkCurr(curr, prev, next, viable);
        
        //cout << "0 found viable spots: " << viable << endl;
        //************ */
        full += prev + sentinal;

        if(done){
            full+= curr + sentinal;
            full += next + sentinal;
            break;
        }

        prev = curr;
        curr = next;
    }

    cout << "1 found viable spots: " << viable << endl;
    //at this point everything is working, the correct amount of rolls have been found and 
    //following this all the 'x'es have been placed properly and are about to be printed properly

    printAll(full);

    //**************************************************** */
    printAll(full);
    //**************************************************** */

    cout << "all exes and rolls printed" << endl; 
    // code working perfectly to this point, all exes removed from puzzle

    substring(prev, full, 0);
    substring(curr, full, l);
    int row = 2;
    substring(next, full, 2*l);
    row++;

    cout << prev << endl;
    cout << curr << endl;
    cout << next << endl;

    string fullTemp;

    while(true){
        
        checkCurr(curr, prev, next, viable);
        
        //cout << "2 found viable spots: " << viable << endl;
        if ( viable == 25 ){
            while(true);
        }
        fullTemp += prev + sentinal;

        prev = curr;
        curr = next;
        substring(next, full, row*l);
        cout << next << endl;
        row++;

        if(fin){
            fullTemp += curr + sentinal;
            fullTemp += next + sentinal;
            for(int i = 0; i < full.length(); i++ ){
                char current = full[i];
                if(current == sentinal){
                    cout << endl;
                }
                else {
                    cout << full[i];
                    if(current == 'x')
                        full[i] = '.';
                }
            }


            substring(prev, full, 0);
            substring(curr, full, l);
            row = 2;
            if(nothingDone)
                break;
            nothingDone = true;
            fin = false;
            full = fullTemp;
            cout << "3found viable spots: " << viable << endl;
        }

    }

    cout << "4found viable spots: " << viable << endl;



}

void substring(string& target, string reference, int start ){
    int ir = start;
    int it = 0;
    if(reference.length() > ir){
        if(reference[ir] == sentinal){
            ir++;
        }
        else {
            //fin = true; // TO DO change back
        }
    }
    while(reference[ir] != sentinal && ir < reference.length()){
        target[it] = reference[ir];
        it++;
        ir++;
    }
    
}

void checkPrev(string& prev, string curr, int& viable){
    for(int i = 0; i < prev.length(); i++){
        if(isRoll(prev,i)){
            //cout << "spot " << i << " has a roll" << endl;
            int count = 0;
            count+= countRolls(prev,i);
            count--;
            count+= countRolls(curr,i);
            if( count < limit){
                viable++;
                prev[i] = 'x';
            }
        }
    }
}

void checkCurr(string& curr, string prev, string next, int& viable){
    for(int i = 0; i < curr.length(); i++){
        if(isRoll(curr,i)){
            int count = 0;
            count += countRolls(prev,i);
            count += countRolls(curr,i);
            count--;
            count += countRolls(next,i);
            if( count < limit){
                viable++;
                if(viable > 30)
                    while(true);        //Pause here to inspect whats going on
                nothingDone = false;
                curr[i] = 'x';
            }
        }

    }
}