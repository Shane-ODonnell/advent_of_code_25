#include <iostream>
#include <string>

void process();
int getInt(char temp);
long long ipow(long long val, int p);

using namespace std;

string input; 
long long sum = 0;

// Answer: 17085

void println(string input){
    cout << input << endl;
}

void printArray( int array[], int l){
    for(int i = 0; i < l; i++){
        cout << array[i];
    }
    cout << endl;
}

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
    const int s = 12;
    int max[s];

    for (int i = 0; i < s; i++){
        max[i] = 0;
    }

    for( int i = 0; i < input.length(); i++){
        int curr = getInt(input[i]);
        
        for( int j = 0; j < s; j++){
            
            if(curr > max[j] && input.length() - i >= s - j ){ //the remaining digits are enough to fill the remaining slots
                
                max[j] = curr;
                for(int it = j+1; it < s; it++){
                    max[it] = 0;
                }
                j = s;
            }

        }
        
    }

    printArray(max,s);
    
    long long val = 0;

    for(int i = 0; i < s; i++){
        val = val + max[s -1 - i]*ipow(10,i);
        //cout << "on loop number " << i << " val is = " << val << endl;
    }
    
    sum = sum + val;
    cout << "sum is: " << sum << endl;
}

long long ipow(long long val, int p){
    long long ans = val;
    if( p == 0)
        return 1;
    else if (p == 1)
        return val;
    p--;
    
    for(int i = 0; i < p; i++){
        ans = ans * val;
    }

    return ans;
}

int getInt(char temp){
    int val = int(temp);
    val = val - 48;
    return val;
}

// correct answer 169408143086082 lets goooo