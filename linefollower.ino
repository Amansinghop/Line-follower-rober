// Moters pin
#define ENA 10
#define IN1 A2
#define IN2 A3
#define IN3 A4
#define IN4 A5
#define ENB 11
// Ir sensore pins
int irSensore[8]={2,3,4,5,6,7,8,9};
int sensoreData[8];

void setup() {
  // Moters pin IO
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  for(int i=0;i<8;i++){
    pinMode(irSensore[i],INPUT);
  }

  Serial.begin(9600);
  
}
  



void loop() {
  // reading IRsensore
  for(int i=0;i<8;i++){
    sensoreData[i]=digitalRead(irSensore[i]);
    Serial.print(sensoreData[i]);
    Serial.print(" ");
    
  }
  Serial.println();
  //Basic Line follower Logic
  //0,1,2,3,4,5,6,7 index for
  //2,3,4,5,6,7,8,9 Pin Nos
  //1,2,3,4,5,6,7,8 chanels of IR SENSORE
  if(sensoreData[3]==0||sensoreData[4]==0){
    moveForward(150);
    
  }
   else if((sensoreData[3]==0 && sensoreData[4]==0)&&(sensoreData[2]==0&&sensoreData[5]==0)){
    moveForward(120);
    
  }
   else if((sensoreData[3]==0 && sensoreData[4]==0)&&(sensoreData[2]==0&&sensoreData[5]==0)&&(sensoreData[1]==0&&sensoreData[6]==0)){
    moveForward(80);
    
  }
  else if( (sensoreData[3]==0||sensoreData[4]==0)&&(sensoreData[2]==1&& sensoreData[5]==0)){
    forwardLeft1();
    
  }
   else if((sensoreData[3]==0||sensoreData[4]==0)&&(sensoreData[2]==1&& sensoreData[5]==0)&&(sensoreData[1]==1&& sensoreData[6]==0)){
    forwardLeft2();
    
  }
   else if( (sensoreData[3]==0||sensoreData[4]==0)&&(sensoreData[2]==0&& sensoreData[5]==1)){
    forwardRight1();
    
  }
   else if((sensoreData[3]==0||sensoreData[4]==0)&&(sensoreData[2]==0&& sensoreData[5]==1)&&(sensoreData[1]==0&& sensoreData[6]==1)){
    forwardRight2();
    
  }
  else if(sensoreData[0]==0&&sensoreData[1]==0&&sensoreData[2]==0){
    turnLeft();
  }
   else if(sensoreData[0]==0&&sensoreData[1]==0){
    turnLeft();
  }
   else if(sensoreData[0]==0){
    turnLeft();
  }
  else if(sensoreData[5]==0&&sensoreData[6]==0&&sensoreData[7]==0){
    turnRight();
  }
  else if(sensoreData[6]==0&&sensoreData[7]==0){
    turnRight();
  }
  else if(sensoreData[7]==0){
    turnRight();
  }
  else{
    stopMotors();
  }


  delay(500);




  

}
void moveForward(int s){
  analogWrite(ENA,s);
  analogWrite(ENB,s);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
}
void forwardLeft1(){
  analogWrite(ENA,150);
  analogWrite(ENB,125);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
}
void forwardLeft2(){
  analogWrite(ENA,150);
  analogWrite(ENB,100);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
}
void forwardLeft3(){
  analogWrite(ENA,150);
  analogWrite(ENB,75);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
}
void forwardRight1(){
  analogWrite(ENA,125);
  analogWrite(ENB,150);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
}
void forwardRight2(){
  analogWrite(ENA,100);
  analogWrite(ENB,150);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
}
void forwardRight3(){
  analogWrite(ENA,75);
  analogWrite(ENB,150);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
}
void turnLeft(){
  analogWrite(ENA,100);
  analogWrite(ENB,100);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void turnRight(){
  analogWrite(ENA,100);
  analogWrite(ENB,100);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void stopMotors(){
   digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
