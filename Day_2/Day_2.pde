String input = "";

int sum = 0;

//1548245443 wrong
//927663391 wrong

void setup(){
    testInput();
    //realInput();
    process(input);
    println(sum);
}

void process( String data ){
    String buffer = "";
    for(int i = 0; i < data.length(); i++){
        //iterate through the characters of the data set
        char curr = data.charAt(i);

        if(curr != ',')
            buffer = buffer + curr; //if the current char isnt a comma, add it to the current buffer
        else{
            //Buffer currently has one whole segment 
            //println(buffer);
            int min = 0;
            int max = 0;
            String Val = "";

            for(int j = 0; j < buffer.length(); j++){
                //iterate through current partition of the dataset xx-zz
                curr = buffer.charAt(j);
                if(curr != '-'){
                    Val = Val + curr;
                    if(j + 1 == buffer.length()){
                        max = int(Val);
                        //println(max);
                    }
                }
                else{
                    min = int(Val);
                    //print(min +",");
                    Val = "";
                }
            }
            buffer = ""; // clear buffer
            // we now have the starting value of the range and the ending value
            range(min,max);
        }
    }
}

void range(int min, int max){
    //now that we have two integers we need to check them and all in between for flaws
    for( int i = min; i <= max; i++){
        String curr = str(i);
        int temp = curr.length();
        if( odd(temp) == false){
            //if the current number has an even number of digits
            String firstHalf = curr.substring(0, temp/2);
            String secondHalf = curr.substring(temp/2, temp);
            //split the string down the middle and compare the two substrings 
            if(firstHalf.equals(secondHalf)){
                //if they are the same then we have an invalid
                println(curr + " is invalid");
                sum = sum + i;
            }
        }

    }
}

boolean odd(int value) {
  if (value % 2 == 0) {
    return false;
  }
  return true;
}
