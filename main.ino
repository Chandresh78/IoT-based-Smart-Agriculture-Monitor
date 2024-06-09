#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const char* ssid = "Enter your Wifi name";
const char* password = "Enter your Wifi password";
WiFiClient client;
unsigned long myChannelNumber = 354734;
const char * myWriteAPIKey = "JBNXNMFKVWQJ1NNV";
uint8_t temperature, humidity;
float sensor_output = 0;
float percent_water = 0;
int state=1;
void setup()
{
Serial.begin(115200);
dht.begin();
delay(10);
// Connect to WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
// Print the IP address
Serial.println(WiFi.localIP());
ThingSpeak.begin(client);
}
void loop()
{
//static boolean data_state = false;
temperature = dht.readTemperature();
humidity = dht.readHumidity();
Serial.print("Temperature Value is :");
Serial.print(temperature);
Serial.println("C");
Serial.print("Humidity Value is :");
Serial.print(humidity);
Serial.println("%");
sensor_output = analogRead(A0); //Read sensor data from A0 pin
percent_water = map(sensor_output,550,10,0,100); //In dry soil, we get serial value of 550, and in the wet soil, it drops to 10. 550 —> 0% water & 10 —> 100% water
Serial.println("Reading value from sensor…");
Serial.println("Percentage of water in the soil is:");
Serial.print(percent_water);
Serial.print("%");
// Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
// pieces of information in a channel. Here, we write to field 1.
if (state==1) {
ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);
state = state+1;
Serial.println(state);
Serial.println("Channel 1 transmitted");
}
else if ( state == 2){
ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);
state=state+1;
Serial.println(state);
Serial.println("Channel 2 transmitted");
}
else {
ThingSpeak.writeField(myChannelNumber, 3, percent_water, myWriteAPIKey);
Serial.println(state);
Serial.println("channel 3 transmitted");
state = 1;
}
Serial.println(state);
delay(30000);
}
