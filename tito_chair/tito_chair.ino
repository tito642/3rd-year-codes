// ---------------------------------------------------------------------------
// Example NewPing library sketch that pings 3 sensors 20 times a second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define SONAR_NUM 2      // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
int x ;

const int buzzer = 9;
NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(4, 5, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(6, 7, MAX_DISTANCE), 
 
};

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
pinMode(buzzer, OUTPUT);

}

void loop() { 
  x= sonar[1].ping_cm()-sonar[0].ping_cm();
  
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through each sensor and display results.
    delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    Serial.print(i);
    Serial.print("=");
    Serial.print(sonar[i].ping_cm());
    Serial.print("cm ");
    
    
  }
  Serial.println(   );
  Serial.print("x");
    Serial.print("=");
    Serial.print(x);
    Serial.print("    ");

if (x <8)
        { // Enter the Distance
digitalWrite(buzzer, LOW);


}
else{
digitalWrite(buzzer, HIGH);

}

    
}
