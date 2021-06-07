#define REC 6
#define PLAYE 7
void setup() {
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
}


void loop() {
  if(digitalRead(REC)==1)rec();
  if(digitalRead(PLAYE)==1) playe();

}


void rec() {
  digitalWrite(5,HIGH);                 // 녹음 중....
  delay(10000);                           // 10초 동안 녹음 중 
  digitalWrite(5,LOW);
}

void playe() {
  while(digitalRead(PLAYE)!=0){
  digitalWrite(4,HIGH); 
  
  
  
  // 재생 중.
  digitalWrite(4,LOW);}
}
