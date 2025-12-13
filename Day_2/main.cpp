#include <iostream>
#include <string>

void process();
using namespace std;

long long sum = 0;

int main(){
    while (true)
        process();
    return 0;
}

void process(){
    string data;
    cin >> data;
    string buffer = "";

    for(int i = 0; i < data.length(); i++){
        char curr = data[i];

        if(curr != ',')
            buffer = buffer + curr; //if the current char isnt a comma, add it to the current buffer
        else{
            long min = 0;
            long max = 0;
            string Val = "";

            for(int j = 0; j < buffer.length(); j++){
                curr = buffer[j];
                 



            }





        }







        
    }









}