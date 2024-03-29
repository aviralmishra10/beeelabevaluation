#define trigPin 12
#define echoPin 11
int Buzzer = 8; 
int ledPin= 6; 
int duration, distance; 

void setup() {
        Serial.begin (9600); 

        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
        pinMode(Buzzer, OUTPUT);
        pinMode(ledPin, OUTPUT);
}

void loop() {

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
  if (distance >= 30) 
        {
        Serial.println("no object detected");
        digitalWrite(Buzzer,LOW);
        digitalWrite(ledPin,LOW);
        }
  else {
    digitalWrite(Buzzer,LOW);
        Serial.println("object detected \n");
        Serial.print("distance= ");              
        Serial.print(distance);
        digitalWrite(Buzzer,HIGH);
        digitalWrite(ledPin,HIGH);
    delay(200);
    digitalWrite(Buzzer,LOW);
    digitalWrite(ledPin,LOW);
    delay(200);
  }
}
