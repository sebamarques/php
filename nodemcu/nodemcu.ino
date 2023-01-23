//----------------------------------------Include the NodeMCU ESP8266 Library
//----------------------------------------see here: https://www.youtube.com/watch?v=8jMr94B8iN0 to add NodeMCU ESP8266 library and board
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
//----------------------------------------

int led = 5;

//----------------------------------------SSID and Password of your WiFi router.

//----------------------------------------

//----------------------------------------Web Server address / IPv4
// If using IPv4, press Windows key + R then type cmd, then type ipconfig (If using Windows OS).
const char *host = "http://192.168.1.34";
//----------------------------------------

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500);

  WiFi.mode(WIFI_STA);
  Serial.println("");
    
  pinMode(led,OUTPUT);
  delay(500);

  
  //----------------------------------------Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    
  }
  //----------------------------------------
  Serial.println("");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  //----------------------------------------
}

void loop() {
  // put your main code here, to run repeatedly:
  HTTPClient http; //--> Declare object of class HTTPClient

  //----------------------------------------Getting Data from MySQL Database
  String GetAddress, LinkGet, getData;
  int id = 0; //--> ID in Database
  GetAddress = "NodeMCU_Get_Database/GetData.php"; 
  LinkGet = host + GetAddress; //--> Make a Specify request destination
  getData = "ID=" + String(id);
  Serial.println("----------------Connect to Server-----------------");
  Serial.println("Get LED Status from Server or Database");
  Serial.print("Request Link : ");
  Serial.println(LinkGet);
  http.begin(LinkGet); //--> Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
  int httpCodeGet = http.POST(getData); //--> Send the request
  String payloadGet = http.getString(); //--> Get the response payload from server
  Serial.print("Response Code : "); //--> If Response Code = 200 means Successful connection, if -1 means connection failed. For more information see here : https://en.wikipedia.org/wiki/List_of_HTTP_status_codes
  Serial.println(httpCodeGet); //--> Print HTTP return code
  Serial.print("Returned data from Server : ");
  Serial.println(payloadGet); //--> Print request response payload

  if (payloadGet == "1") {
    digitalWrite(LED_D8, HIGH); //--> Turn off Led
  }
  if (payloadGet == "0") {
    digitalWrite(LED_D8, LOW); //--> Turn off Led
  }
  //----------------------------------------
  
  Serial.println("----------------Closing Connection----------------");
  http.end(); //--> Close connection
  Serial.println();
  Serial.println("Please wait 5 seconds for the next connection.");
  Serial.println();
  delay(5000); //--> GET Data at every 5 seconds
}
