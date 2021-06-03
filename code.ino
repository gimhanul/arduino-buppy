int oct[3][12] = {
    {131,139,147,156,165,175,185,196,208,220,233,247},
    {262,277,294,311,330,349,370,392,415,440,466,494},
    {523,554,587,622,659,698,740,784,831,880,932,988}
};

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
 Serial.println(get_button(btn));
 delay(1000);
 } 

int get_button(int val) {
 if(val>1000){
  tone(3,262,500);
  return 1;
 }
 else if(val>900){
  tone(3,294,500);
  return 2;
 }
 else if(val>820){
  tone(3,329.6,500);
  return 3;
 }
 else if(val>750)
   return 4;
 else if(val>660)
   return 5;
 else if(val>620)
   return 6;
 else if(val>585)
   return 7;
 else if(val>540)
   return 8;
 else if(val>500)
   return 9;
 else if(val>475)
   return 10;
 else if(val>455)
   return 11;
 else if(val>425)
   return 12;
 else if(val>370)
   return 13;
 else if(val>300)
   return 14;
 else if(val>260) {
  digitalWrite(5,HIGH);                 // 녹음 중....
  delay(10000);                           // 10초 동안 녹음 중 
  digitalWrite(5,LOW);
  Serial.println("끝");
  return 15;
 }
 else if(val>200) {
  digitalWrite(4,HIGH);               // 재생 중.
  delay(10000);
  digitalWrite(4,LOW);
  return 16;
 }
 else
   return 0; 
}
