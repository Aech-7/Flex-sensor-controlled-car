const int motor1IN1 = 2; 
const int motor1IN2 = 3; 
const int motor2IN1 = 4; 
const int motor2IN2 = 5; 
const int motor1Enable = 6; 
const int motor2Enable = 7; 

const int flexPin = A0;

void setup() {
  pinMode(motor1IN1, OUTPUT);
  pinMode(motor1IN2, OUTPUT);
  pinMode(motor2IN1, OUTPUT);
  pinMode(motor2IN2, OUTPUT);
  pinMode(motor1Enable, OUTPUT); 
  pinMode(motor2Enable, OUTPUT); 

  digitalWrite(motor1Enable, HIGH); 
  digitalWrite(motor2Enable, HIGH); 

  Serial.begin(9600);
}

void loop() {
  int flexValue = analogRead(flexPin);
  Serial.println(flexValue); 

  int motorSpeed;

  if (flexValue < 220) { 
    motorSpeed = map(flexValue, 70, 220, 255, 0); 
    digitalWrite(motor1IN1, LOW);
    digitalWrite(motor1IN2, HIGH);
    digitalWrite(motor2IN1, LOW);
    digitalWrite(motor2IN2, HIGH);
    Serial.println("Moving Forward");
  } else if (flexValue > 220) { 
    motorSpeed = map(flexValue, 220, 350, 0, 255);
    digitalWrite(motor1IN1, HIGH);
    digitalWrite(motor1IN2, LOW);
    digitalWrite(motor2IN1, HIGH);
    digitalWrite(motor2IN2, LOW);
    Serial.println("Moving Backward");
  } else {
    //
    motorSpeed = 0;
    digitalWrite(motor1IN1, LOW);
    digitalWrite(motor1IN2, LOW);
    digitalWrite(motor2IN1, LOW);
    digitalWrite(motor2IN2, LOW);
    Serial.println("Stopped");
  }

  analogWrite(motor1Enable, motorSpeed);
  analogWrite(motor2Enable, motorSpeed);

  delay(100); 
}
