struct DisplayPorts {
  int a = 3;
  int b = 4;
  int c = 6;
  int d = 7;
  int e = 8;
  int f = 9;
  int g = 10;
  int dp = 5;
} display1;

void printNumber(int n);

void displayControl(struct DisplayPorts dp, int conf[] );

void setup() {
  pinMode(13, OUTPUT);
  
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  
  pinMode(3T);
  
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(10,INPUT);
  pinMode(5,INPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  //for(int i=0; i<10;i++ ){
  //  printNunber(i);
  //	delay(1000);
  //}
  int A=digitalRead(5), B=digitalRead(10), C=digitalRead(12), D=digitalRead(13);
  A=false;B=false;C=true;D=false;
  int out[8];
  out[0] = !((!A&&C)||(B&&C)||(C&&!D)||(!A&&B&&C)||(A&&!D)||(A&&!B&&!C));
  out[1] = !((!A&&!C&&!D)||(!B&&!C)||(A&&!C&&D)||(!A&&!B)||(!A&&C&&D)||(!B&&C&&!D)); 
  out[2] = !((!A&&!C)||(!A&&D)||(B)||(!B&&!C&&D));
  out[3] = !((!A&&!D)||(!B&&C&&D)||(B&&!C)||(!C&&!D)||(B&&!D)||(A&&!C));
  out[4] = !((C&&!D)||(!A&&!B&&!D)||(A&&B)||(A&&C)||(A&&D));
  out[5] = !((!C&&!D)||(A&&!B)||(A&&C)||(!A&&B&&C)||(B&&!D));
  out[6] = !((C&&!D)||(A&&!B)||(!A&&B&&!C)||(A&&D)||(!B&&C));
  out[7] = 1;
  displayControl(display1, out);
}

void printNumber(int n) {
  switch (n) {
    case 0: {
      int confDisplay[8] = {0,0,0,0,0,0,1,1};
      displayControl(display1, confDisplay);
      break;
    }
    
    case 1: {
      int confDisplay[8] = {1,0,0,1,1,1,1,1};
      displayControl(display1, confDisplay);
      break;
    }
    
    case 2: {
      int confDisplay[8] = {0,0,1,0,0,1,0,1};
      displayControl(display1, confDisplay);
      break;
    }
    
    case 3: {
      int confDisplay[8] = {0,0,0,0,1,1,0,1};
      displayControl(display1, confDisplay);
      break;
    }
    
    case 4: {
      int confDisplay[8] = {1,0,0,1,1,0,0,1};
      displayControl(display1, confDisplay);
      break;
    }
    
    case 5: {
      int confDisplay[8] = {0,1,0,0,1,0,0,1};
      displayControl(display1, confDisplay);
      break;
    }
    
    case 6: {
      int confDisplay[8] = {0,1,0,0,0,0,0,1};
      displayControl(display1, confDisplay);
      break;
    }
    
    case 7: {
      int confDisplay[8] = {0,0,0,1,1,1,1,1};
      displayControl(display1, confDisplay);
      break;
    }
    
    case 8: {
      int confDisplay[8] = {0,0,0,0,0,0,0,1};
      displayControl(display1, confDisplay);
      break;
    }
    
    case 9: {
      int confDisplay[8] = {0,0,0,0,1,0,0,1};
      displayControl(display1, confDisplay);
      break;
    }
    
    default: {
      int confDisplay[8] = {1,1,1,1,1,1,1,1};
      displayControl(display1, confDisplay);
      break;
    }  
  }
}

void displayControl(struct DisplayPorts dp, int conf[] ){
  digitalWrite(dp.a,conf[0]);
  digitalWrite(dp.b,conf[1]);
  digitalWrite(dp.c,conf[2]);
  digitalWrite(dp.d,conf[3]);
  digitalWrite(dp.e,conf[4]);
  digitalWrite(dp.f,conf[5]);
  digitalWrite(dp.g,conf[6]);
  digitalWrite(dp.dp,conf[7]);
}