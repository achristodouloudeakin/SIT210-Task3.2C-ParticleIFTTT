int led1 = D7; // The on-board LED
int led2 = A5; // The Red LED

// Variable Assignments for the Photoresistor segments
int photoresistor = A0;
int analog_value;

void setup()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(photoresistor, INPUT);
    Particle.variable("light",&analog_value, INT);
}

void loop()
{
    // Turn ON the LEDs
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);

    analog_value = analogRead(photoresistor);
    String light = String(analog_value);
    Particle.publish("light", light, PRIVATE);

    delay(3000);

    // Turn OFF the LED
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);

    delay(1,797,000);
}