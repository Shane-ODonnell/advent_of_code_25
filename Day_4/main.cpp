#include <iostream>
#include <string>

using namespace std;

void process();
int finish(string curr, string prev);
void checkPrev(string& prev, string curr, int& viable);
void substring(string& target, string reference, int start);
void printInput(string input);

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
char sentinal = '!';
char goCommand = '?';

int main(){

    process();
    while(true);
    return 0;
}

bool done = false;

void process(){
    string prev, curr, next;
    string input, buffer = "";
    int viable = 0;
    int l = 0;
   
    cout << "reading inputs till " << goCommand << endl;
    cin >> input;

    l = input.length();
    prev = input;
    curr = input; // intialize length

    input = input + sentinal; //sentinal control

    while(buffer[0] != goCommand){
        cin >> buffer;
        input += buffer + sentinal;
    }
    //Input is fully stored now

    substring(prev, input, 0);
    substring(curr, input, l);
    checkPrev(prev, curr, viable);

    int row = 2;

    while(true){
        
        substring(next, input, row*l);
        row++;

        for(int i = 0; i < curr.length(); i++){
            if(isRoll(curr,i)){
                int count = 0;
                count += countRolls(prev,i);
                count += countRolls(curr,i);
                count--;
                count += countRolls(next,i);
                if( count < limit){
                    viable++;
                }
            }

        }
        cout << "found viable spots: " << viable << endl;

        prev = curr;
        curr = next;

        if(done){
            //cout << input << endl;
            printInput(input);
            break;
        }
        //
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
                    //prev[i] = 'x';
                    //i = 0;
                }
            }
        }
}

void substring(string& target, string reference, int start ){
    int ir = start;
    int it = 0;
    if(reference.length() > ir)
        if(reference[ir] == sentinal)
            ir++;
    else 
        done = true;
    while(reference[ir] != sentinal && ir < reference.length()){
        target[it] = reference[ir];
        it++;
        ir++;
    }
    
}

void printInput(string input){
    for( int i = 0; i < input.length(); i++){
        char curr = input[i];
        if(curr == sentinal)
            cout << endl;
        else
            cout << curr;
    }

}