#define trigPin 12     
#define echoPin 13      
#define led 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 7
#define buzzer 11
 
int sound = 250;
 
 
void setup() {
  Serial.begin (9600);        
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);    
  pinMode(led, OUTPUT);       
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
}
 
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);       
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration/2) / 29.1;   
 
  if (distance <= 60) {      
    digitalWrite(led, HIGH); 
    sound = 250;
}
  else {
    digitalWrite(led,LOW);  
  }
  if (distance < 50) {
      digitalWrite(led2, HIGH);
      sound = 260;
}
  else {
      digitalWrite(led2, LOW);
  }
  if (distance < 40) {
      digitalWrite(led3, HIGH);
      sound = 270;
} 
  else {
    digitalWrite(led3, LOW);
  }
  if (distance < 30) {
    digitalWrite(led4, HIGH);
    sound = 280;
}
  else {
    digitalWrite(led4,LOW);
  }
  if (distance < 20) {
    digitalWrite(led5, HIGH);
    sound = 290;
}
  else {
    digitalWrite(led5,LOW);
  }
  if (distance < 10) {
    digitalWrite(led6, HIGH);
    sound = 300;
}
  else {
    digitalWrite(led6,LOW);
  }
 
  if (distance > 30 || distance <= 0){
    Serial.println("***");
    noTone(buzzer);
  }
  else {
    Serial.print(distance); 
    Serial.println(" cm");  
    tone(buzzer, sound);    
   
  }
  delay(500); 
}
