#include <iostream>
#include <string>

void process();
int getInt(char temp);

using namespace std;

string input; 
int sum = 0;

// Answer: 17085

int main(){
    while (true)
        process();
    return 0;
}

/*
    234234234234278
//*/

void process(){
    //iterate through 
    input = "";
    cin >> input;

    int max = 0;
    int max2 = 0;

    for( int i = 0; i < input.length(); i++){
        int curr = getInt(input[i]);
        if( curr > max && i + 1 < input.length()){
            max = curr;
            max2 = 0;
        }
        else if ( curr > max2)
            max2 = curr;
    }

    cout << max << max2 << endl;

    max = (max * 10) + max2;
    cout << max << endl;

    sum = sum + max;
    cout << sum << endl;
}

int getInt(char temp){
    int val = int(temp);
    val = val - 48;
    return val;
}