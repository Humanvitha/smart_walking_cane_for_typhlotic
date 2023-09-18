const int trigPin1=9;
const int trigPin2=8;
const int echoPin1=10;
const int echoPin2=12;
const int buzzer=11;
int UltraSensor1,UltraSensor2,distance;
long duration;
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop()
{
  someSensor(trigPin1,echoPin1);
  UltraSensor1=distance;
  delay(100);
  someSensor(trigPin2,echoPin2);
  UltraSensor2=distance;
  if(UltraSensor1 <=75 or UltraSensor2 >75)
  {
      digitalWrite(buzzer,HIGH);
  }
  else
  {
      digitalWrite(buzzer,LOW);
  }
  Serial.print("distance1:");
  Serial.println(UltraSensor1);
  Serial.print("distance2:");
  Serial.println(UltraSensor2);
}
void someSensor(int trigPin,int echoPin)
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*(0.034/2);
 
}
