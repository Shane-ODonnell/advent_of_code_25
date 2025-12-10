String input = "";
int val = 50;
int max = 99;
int min = 0;
int password = 0;


void setup() {
  println(val);
  testInput();
  realIntput();
  process(input);
  println( "Password is: " + password);
}


void adjust(int amount, int m) {
  int i = 0;

  while (i < amount) {
    val = val + m;
    i++;

    if ( val > max) {
      val = min;
      m = 1;
    } else if ( val < min) {
      val = max;
      m = -1;
    }
  }

  println(val);
  if ( val == 0) {
    password++;
  }
}

void process(String data) {
  int m = 0;
  String buffer = "";
  boolean first = true;

  for (int i = 0; i < data.length(); i++) {
    char curr = data.charAt(i);
    
    if ( digit(curr) == false) {
      if ( curr == 'R' || curr == 'L') {

        if (first)
          first = false;
        else {
          int amount = int(buffer);
          adjust(amount, m);
        }

        if ( curr == 'R') {
          m = 1;
        } else {
          m = -1;
        }
        buffer = ""; // clear buffer
      }
    } else {
      buffer = buffer + curr;
    }

    if( i + 1 >= data.length()){
      adjust( int(buffer),m);
    }
  }
}

boolean digit(char c) {
  if ( 47 < int(c) && int(c) <= 57 )
    return true;
  return false;
}
