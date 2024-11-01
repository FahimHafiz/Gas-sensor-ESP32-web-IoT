// Pin connected to the MQ-2 sensor
const int sensorPin = 13;
// Define the load resistance value (in ohms) used in the circuit
#define RL 10 //Load resistance
#define m -0.263 //Calculated Slope
#define b 0.42 //Calculated intercept

#define Ro 20 // Resistance on fresh air
void setup() {
  Serial.begin(115200);
  Serial.println("MQ2 warming up!");
  delay(20000); // allow the MQ2 to warm up
  pinMode(sensorPin, INPUT);
}

void loop() {
  float VRL; //Voltage drop across the MQ sensor
  float Rs; //Sensor resistance at gas concentration
  float ratio; //Define variable for ratio
  float sensorValue = analogRead(sensorPin);
  //Serial.println(sensorValue);
  VRL = sensorValue * (5.0/1023.0); //Measure the voltage drop and convert to 0-5V
  Rs = ((5.0*RL)/VRL)-RL; //Use formula to get Rs value
  ratio = Rs/Ro; // find ratio Rs/Ro
  float ppm = pow(10, ((log10(ratio)-b)/m)); //use formula to calculate ppm
  Serial.print("PPM: ");
  Serial.println(ppm);
}

