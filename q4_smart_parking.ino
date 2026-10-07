/**
 * purpose: smart parking indicator. an ultrasonic sensor measure the distance
 * to a vehicle. if it is within threshold, the red LED and buzer turn on.
 * otherwise the green LED is on.
 */

 const int triggerPin = 9;
 const int echoPin = 10;
 const int greenLED = 4;
 const int redLED = 5;
 const int buzzer = 6;

 const int THRESHOLD_CM = 50;

 void setup() {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
 }

 long measureDistanceCM() {

    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    return duration * 0.034 /2;
 }

 void loop() {
    long distance = measureDistanceCM();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= THRESHOLD_CM) {
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        tone(buzzer, 1000);
    } else {
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        noTone(buzzer);
    }

    delay(200);
 }