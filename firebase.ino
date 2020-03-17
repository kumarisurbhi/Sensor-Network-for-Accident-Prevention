#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>

#define FIREBASE_HOST "priorfire1.firebaseio.com"
#define FIREBASE_AUTH "zh2rOSto8AyL93NLdl3N2GVxQQK1VNcIVWdSyBU1"
#define WIFI_SSID "le"
#define WIFI_PASSWORD "hellohello1234"



void setup() {
  // put your setup code here, to run once:
  pinMode(D1, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to:");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 // Firebase.set("Node", 0);
}

int n = 0;
void loop() {
  // put your main code here, to run repeatedly:
  n = Firebase.getInt("Node");
 if(Firebase.failed()){
      Serial.print("failed");
      Serial.println(Firebase.error());
      return;
      delay(100);
    }
 else{
  if(n == 1){
    Serial.println("LED on");
    digitalWrite(D1, HIGH);
    return;
    delay(100);
    
  }

  else{
    Serial.println("LED OFF");
    digitalWrite(D1, LOW);
    delay(100);
  }
 }
  
}
