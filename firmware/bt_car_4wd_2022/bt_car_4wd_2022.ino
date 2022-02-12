/*
*         __                __     _______________  _______  _______   
  _______/  |______ _______|  | __/   __   \   _  \ \   _  \ \   _  \  
 /  ___/\   __\__  \\_  __ \  |/ /\____    /  /_\  \/  /_\  \/  /_\  \ 
 \___ \  |  |  / __ \|  | \/    <    /    /\  \_/   \  \_/   \  \_/   \
/____  > |__| (____  /__|  |__|_ \  /____/  \_____  /\_____  /\_____  /
     \/            \/           \/                \/       \/       \/ 
*-----------------------------------------------------------------------
*Arduino Automatic Wire Cutter.    
*coded by Saliya Ruchiranga.   
*2022-01-29.   
*stark9000@gmail.com.   
*/

#include <SoftwareSerial.h>
SoftwareSerial BTS(2, 3); // RX, TX

char command = 'S';

int vel = 127;
char det;
char determinant;

int IN_1 = 9;
int IN_2 = 10;
int IN_3 = 11;
int IN_4 = 12;

void setup() {
  Serial.begin(9600);
  BTS.begin(9600);
  
  Serial.print("init");

  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
}

void loop() {
  //Forward();
  //Backward();
  //Tright();
  //Tleft();
  det = check();

  while (det == 'F')   // F, move forward
  {
    Serial.println("F");
    Forward();
    det = check();
  }

  while (det == 'B')   // B, move back
  {
    Serial.println("B");
    Backward();
    det = check();
  }

  while (det == 'L')   // L, turn left
  {
    Serial.println("L");
    Tleft();
    det = check();
  }

  while (det == 'R')   // R, turn right
  {
    Serial.println("R");
    Tright();
    det = check();
  }

  while (det == 'S')   // S, stop
  {
    Serial.println("S");
    Stop();
    det = check();
  }

  //---------------------Toggle switch code------------------//
  while (det == 'W') {
    det = check();
  }
  while (det == 'w') {
    det = check();
  }

  while (det == 'U') {
    det = check();
  }
  while (det == 'u') {
    det = check();
  }

  while (det == 'V') {
    det = check();
  }
  while (det == 'v') {
    det = check();
  }

}

void Forward() {
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  digitalWrite(IN_2, HIGH); //right forward
  digitalWrite(IN_1, HIGH);//left forward
}

void Backward() {
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_3, HIGH); //right backward
  digitalWrite(IN_4, HIGH);//left backward
}

void Stop() {
  analogWrite(IN_1, LOW);
  analogWrite(IN_2, LOW);
  analogWrite(IN_3, LOW);
  analogWrite(IN_4, LOW);
}

void Tright() {
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_4, LOW);
  digitalWrite(IN_1, HIGH);//left forward
  digitalWrite(IN_3, HIGH); //right backward
}

void Tleft() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_2, HIGH); //right forward
  digitalWrite(IN_4, HIGH);//left backward
}

int check()
{ if (BTS.available() > 0) {
    command = BTS.read();
    //Serial.print(command);
    if (command == 'F') {
      determinant = 'F';
    }
    else if (command == 'B') {
      determinant = 'B';
    } else if (command == 'L') {
      determinant = 'L';
    }
    else if (command == 'R') {
      determinant = 'R';
    } else if (command == 'I') {
      determinant = 'I';
    }
    else if (command == 'J') {
      determinant = 'J';
    } else if (command == 'G') {
      determinant = 'G';
    }
    else if (command == 'H') {
      determinant = 'H';
    } else if (command == 'S') {
      determinant = 'S';
    }
    else if (command == '0') {
      vel = 255;
    } else if (command == '1') {
      vel = 245;
    }
    else if (command == '2') {
      vel = 220;
    } else if (command == '3') {
      vel = 210;
    }
    else if (command == '4') {
      vel = 185;
    } else if (command == '5') {
      vel = 165;
    }
    else if (command == '6') {
      vel = 145;
    } else if (command == '7') {
      vel = 125;
    }
    else if (command == '8') {
      vel = 120;
    } else if (command == '9') {
      vel = 80;
    }
    else if (command == 'q') {
      vel = 40;
    }
    else if (command == 'U') {
      determinant = 'U';
    } else if (command == 'u') {
      determinant = 'u';
    }
    else if (command == 'W') {
      determinant = 'W';
    } else if (command == 'w') {
      determinant = 'w';
    }

  } return determinant;
}
