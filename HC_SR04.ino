/*
  HC-SR04
*/
 
#define  TRIG  12 
#define  ECHO  11
#define  DELAY 1000
 
void setup()
{
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT); 
  Serial.begin(9600);    
}
 
void loop()
{
  digitalWrite(TRIG, LOW);                  
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
 
  long time_us = pulseIn(ECHO, HIGH);
  long dist_mm = time_us * 0.17;       // 0.34 / 2
 
  Serial.println("-----------------");  
  Serial.print("Time(us) : ");
  Serial.println(time_us);
  Serial.print("Distance(mm) : "); 
  Serial.print(dist_mm);
  Serial.println(" mm");
  Serial.println("-----------------");
  
  delay(DELAY);
}
