int oct[3][12] = {
    {131,139,147,156,165,175,185,196,208,220,233,247},
    {262,277,294,311,330,349,370,392,415,440,466,494},
    {523,554,587,622,659,698,740,784,831,880,932,988}
};
byte low, high;
#define sori 3
void setup() {
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  pinMode(sori,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 int btn=analogRead(A2);
 eum=getbutton(btn);
 println(eum);
 dong(eum)
 delay(1000);
 } 

int getbutton(int val) {
 if(val>1000)eum=0;
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
 else return 123123; 
}
void dong(eum) {
  if(eum<12)
    tone(sori,oct[1+high-low][eum],500);
  else if(eum==12) low=low^1;
  else if(eum==13) high=high^1;
  else if(eum==14) rec();
  else if(eum==15) playe();
  if(high==1&&low==1) {
  high=0; low=0;
 }
}


void rec() {
  digitalWrite(5,HIGH);                 // 녹음 중....
  delay(10000);                           // 10초 동안 녹음 중 
  digitalWrite(5,LOW);
  Serial.println("끝");
}

void playe() {
  digitalWrite(4,HIGH);               // 재생 중.
  delay(10000);
  digitalWrite(4,LOW);
}
