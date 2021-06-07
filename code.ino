int oct[3][12] = {
    {131,139,147,156,165,175,185,196,208,220,233,247},
    {262,277,294,311,330,349,370,392,415,440,466,494},
    {523,554,587,622,659,698,740,784,831,880,932,988}
};
byte low, high, onoff;
#define sori 3
void setup() {
  pinMode(6,OUTPUT); //녹음
  pinMode(7,OUTPUT); //재생
  pinMode(sori,OUTPUT);
  //Serial.begin(9600);
}

void loop() {
 int btn=analogRead(A3);
 int eum=getbutton(btn);
 //Serial.println(eum);
 dong(eum);
 
 //**************************************************
 delay(1000);
 } 

 int getbutton(int val) {
 if(val>1000)return 0;
 else if(val>900)return 1;
 else if(val>820)return 2;
 else if(val>750)return 3;
 else if(val>660)return 4;
 else if(val>620)return 5;
 else if(val>585)return 6;
 else if(val>540)return 7;
 else if(val>500)return 8;
 else if(val>475)return 9;
 else if(val>455)return 10;
 else if(val>425)return 11;
 else if(val>370)return 12; 
 else if(val>300)return 13;
 else if(val>260)return 14;
 else if(val>200)return 15;
 else return 16; 
}

int dong(int eum) {
  if(eum<12)
    tone(sori,oct[1+high-low][eum],500);
  else if(eum==12) low=low^1;
  else if(eum==13) high=high^1;
  else if(eum==14) {
    delay(3000);
    tone(sori,622,500);
    digitalWrite(6,1);
    digitalWrite(6,0);
  }
  else if(eum==15) {
    onoff=onoff^1;
    digitalWrite(7,onoff);
  }
  if(high==1&&low==1) {
  high=0; low=0;
 }
}
