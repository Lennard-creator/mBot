//--------agreements----------
/*
engine speed in 1/s
wheel diameter in mm
delta in mm
*/
//--------notes-----------
/*
-change direction also for bot
*/
#include <math.h>

//---------------------------------mat functins---------------------------------
float deg_to_rad(float deg){
  return deg*(PI/180);
}
float rad_to_deg(float rad){
  return rad*(180/PI);
}


//---------------------------------bot/movement functions---------------------------------

void changeDirection(vec2 &direction, float phi) {
  float x_new = direction.x * cos(phi) - direction.y * sin(phi);
  float y_new = direction.x * sin(phi) + direction.y * cos(phi);
  direction.x = x_new;
  direction.y = y_new;

}

 void move(int pins[2][3], vec2 &coord, vec2 &direction, float delta, float engine_speed, float wheel_diameter){ //[FL, FR, BL, BR]
  coord.x += delta * direction.x;
  coord.y += delta * direction.y;
  float t_sec = delta / (2 * PI * engine_speed * (wheel_diameter / 2));
  unsigned long t_ms = (unsigned long)(t_sec * 1000);

  for(int i = 0; i < 2; i++){
    digitalWrite(pins[i][0], HIGH);  // vorwärts
    digitalWrite(pins[i][1], LOW);   // rückwärts aus
  }

  delay(t_ms);

  for(int i = 0; i < 2; i++){
    digitalWrite(pins[i][0], LOW);
    digitalWrite(pins[i][1], LOW);
  }
  
}

bool checkCircumnavigation(){}
void addPosition()

//---------------------------------bot/sensoric functions---------------------------------
bool checkRim(){}



//---------------------------------variables---------------------------------
int i = 0; //--> indicies for direction changes
int j = 0; //--> -..-
int engine_speed = 150;
struct vec2 {float x; float y}; 
vec2 coord;//coordinates
vec2 dir; //direction
coord.x = 0;
coord.y = 0;
dir.x = 0;
dir.y = 0;
int engineFront[2][3] = {{0,0,0}, {0,0,0}}; // engineleft[vorwärts,rückwärts, speed], engineright[...] - pin
int lightSensor = A0; //Pin
int lightSensorValue = 0;


void setup() {

  pinMode(engineFront[0][0], OUTPUT); //forward
  pinMode(engineFront[0][1], OUTPUT); //backward
  pinMode(engineFront[0][2], OUTPUT); //speed

  pinMode(engineFront[1][0], OUTPUT);
  pinMode(engineFront[1][1], OUTPUT);
  pinMode(engineFront[1][2], OUTPUT); 

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}
