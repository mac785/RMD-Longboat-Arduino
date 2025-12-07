int xPin = A1;
int yPin = A2;
int buttonPin = A0;
int buttonState = 0;

int motor1pin1 = 13;
int motor1pin2 = 12;

int motor2pin1 = 11;
int motor2pin2 = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);
  buttonState = digitalRead(buttonPin);

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  // Motor
  analogWrite(5, 255); //motor 1 motorvalue - 0-255
  analogWrite(6, 255); //motor 2 motorvalue - 0-255

  if(yValue > 900 && yValue <= 1023 && xValue > 450 && xValue < 550) {
      Moveright();
  } else 
      if (yValue >= 0 && yValue < 100 && xValue > 450 && xValue < 550) {
        Moveleft();
      } else
           if (xValue >= 0 && xValue < 100 && yValue > 450 && yValue < 550) {
            Movebackward(); 
           } else
              if(xValue > 900 && xValue <= 1023 && yValue > 450 && yValue < 550) {
                Moveforward();
              } else {
                Stopmotors();
              }


}

void Moveforward() {
  Serial.println("Forward");
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(100);
}

void Movebackward() {
  Serial.println("Backwards");
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(100);
}

void Moveright() {
  Serial.println("Left");
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(100);
}

void Moveleft() {
  Serial.println("Right");
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(100);
}

void Stopmotors() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}
