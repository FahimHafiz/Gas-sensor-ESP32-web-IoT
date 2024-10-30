#include <WiFi.h>
#include <HTTPClient.h>

// Pin connected to the MQ-2 sensor
const int sensorPin = 13;
// Define the load resistance value (in ohms) used in the circuit
#define RL 10 //Load resistance
#define m -0.263 //Calculated Slope
#define b 0.42 //Calculated intercept
#define Ro 20 // Resistance on fresh air

String URL = "http://10.10.113.41/gas_sensor_esp32/gas_sensor_php.php";
const char* ssid = "UIU-Faculty-Staff";
const char* password = "UIU#9876";
int ppm_val = 3000;
void setup() {
  Serial.begin(115200);
  Serial.println("MQ2 warming up!");
  delay(20000); // allow the MQ2 to warm up
  pinMode(sensorPin, INPUT);
  //set the resolution to 12 bits (0-4095)
  analogReadResolution(12);
  connectWiFi();
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


  // ppm_val = ppm;

  if(WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  String postData = "ppm_val=" + String(ppm_val);
  HTTPClient http;
  http.begin(URL);
  http.addHeader("Content-Type", "application/x- w-form-urlencoded");
  int httpCode = http.POST(postData);
  String payload = http.getString();
  Serial.print("URL : "); Serial.println(URL);
  Serial.print("Data: "); Serial.println(postData);
  Serial.print("httpCode: "); Serial.println(httpCode);
  Serial.print("payload : "); Serial.println(payload);
  Serial.println("--------------------------------------------------");
  delay(5000);
}


void connectWiFi() {
  WiFi.mode(WIFI_OFF);
  delay(1000);
  //This line hides the viewing of ESP as wifi hotspot
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() == WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.print("connected to : "); Serial.println(ssid);
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}

