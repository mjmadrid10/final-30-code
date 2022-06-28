Code for Arduino Traffic light!

int red = 10;

int yellow = 9;

int green = 8;

void setup(){

    pinMode(red, OUTPUT);
    
    pinMode(yellow, OUTPUT);
    
    pinMode(green, OUTPUT);
    
}

void loop(){

    changeLights();
    
    delay(15000);
    
}

void changeLights(){

    // green off, yellow on for 3 seconds
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(3000);
    // turn off yellow, then turn red on for 5 seconds
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(5000);
    //yellow on for 2 seconds 
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    delay(2000);
    // turn off red and yellow, then turn on green
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    delay(3000);
}











Code for Arduino Clap Switch!


int Sensor = A0;


int clap = 0;

long detection_range_start = 0;

long detection_range = 0;

boolean status_lights = false;

void setup() {

pinMode(Sensor, INPUT);

pinMode(13,OUTPUT);

}

void loop() {

int status_sensor = digitalRead(Sensor);

if (status_sensor == 0)

{

if (clap == 0)

{

detection_range_start = detection_range = millis();

clap++;

}

else if (clap > 0 && millis()-detection_range >= 50)

{

detection_range = millis();

clap++;

}

}

if (millis()-detection_range_start >= 400)

{

if (clap == 2)

{

if (!status_lights)

{

status_lights = true;

digitalWrite(13, HIGH);

}

else if (status_lights)

{

status_lights = false;

digitalWrite(13, LOW);

}

}

clap = 0;

}

}
