#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "WIFI NETWORK";
const char* password = "WIFI PASSWORD";

//MQTT Server
const char* mqtt_server = "MQTT Server-IP";

const int dataled = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(dataled, OUTPUT);
  digitalWrite(dataled, LOW);

  /*Serial.begin(115200);
  Serial.println("MQTT Mailboxsensor");
  Serial.println("Connecting WIFI");  //*/
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    //Serial.print(".");
  }
  //Serial.println("WiFi connected.");

  client.setServer(mqtt_server, 1883);
  client.connect("Mailboxsensor");

  client.publish("briefkasten/sensor", "1");
  
  client.loop();

  delay(1000);

  //Serial.println("Starting Deep Sleep ...");
  digitalWrite(dataled, HIGH);  
  ESP.deepSleep(0); //Infinite Deep-Sleep
}

void loop() {
}
