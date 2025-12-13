#include <iostream>
#include <string>

using namespace std;

void process();
int finish(string curr, string prev);
void checkPrev(string& prev, string curr, int& viable);

bool isRoll(string array, int pos){
    if( array[pos] == '@')
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

int main(){

    process();

    return 0;
}

void process(){
    int viable = 0;
    string prev, curr, next;
    
    cin >> prev;
    cin >> curr;

    checkPrev(prev, curr, viable);
   
    //cout << "viables found " << viable << endl;

    while(true){
        
        cin >> next;
        //************ */

        for(int i = 0; i < curr.length(); i++){
            if(isRoll(curr,i)){
                int count = 0;
                count += countRolls(prev,i);
                count += countRolls(curr,i);
                count--;
                count += countRolls(next,i);
                if( count < limit){
                    viable++;
                    curr[i] = 'x';
                    i = 0;
                    
                    //checkPrev(prev, viable); // doesnt work right because it treats rolls as viable which arent because it doesnt have the context of the roll previous to previous
                    //cout << "viable found" << endl;
                }
                //cout << "____________" << endl;
            }

        }
        cout << "found viable spots: " << viable << endl;
        //************ */
        prev = curr;
        curr = next;
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
                    viable++; //cout << "viable found" << endl;
                    prev[i] = 'x';
                    i = 0;
                }
            }
            /*else
                cout << "not a roll" << endl;
            */
        }
}