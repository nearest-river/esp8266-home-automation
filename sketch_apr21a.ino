// please replace these three values with your own. or i'll cry cry, womp womp
#define BLYNK_TEMPLATE_ID "TMPL3eaGnM1IY"
#define BLYNK_TEMPLATE_NAME "automation"
#define BLYNK_AUTH_TOKEN "xxYrPdMyleve5WMA30OkfhL8nTZZsePZ"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Please replace the value of `BAUD_RATE` with yout own, it might not be same as mine.
// You'll possibly find it on the back of your cutie. If you can't contact me, Saul Goodman avocado at embedded sys.
#define BAUD_RATE 9600
#define OUTPUT_STATUS(OUT) (OUT)?"on":"off"
#define INIT_DURATION 10000

// dont forget to put your own wifi ssid (i.e. just the name of the wifi/hotspot, in my case it's `kakashi`)
const static char* const WIFI_SSID="<your wifi/hotspot ssid>";
const static char* const WIFI_PASS="<your password>"; // if you can't understand this one. go curse yourself.

typedef enum {
  D2=4,
  D1=5,
  D6=12,
  D5=14
} GPIOPin;


void setup() {
  // Initializing the serial
  Serial.begin(BAUD_RATE);
  delay(INIT_DURATION); // you could remove the delay if you wanted.
  printf("Initialized the serial with baud-rate %u\n",BAUD_RATE);

  // an array of pins. if you need to add more outputs, update it.
  const static GPIOPin PINS[4]={ D2,D1,D6,D5 };
  const static size_t LEN=sizeof(PINS)/sizeof(GPIOPin);
  for(size_t i=0;i<LEN;i++) {
    pinMode(PINS[i],OUTPUT);
    digitalWrite(PINS[i],0); // zero means low. just everyday regular boolean.

    printf("Initialized GPIO-%u\n",PINS[i]);
  }

  Blynk.begin(BLYNK_AUTH_TOKEN,WIFI_SSID,WIFI_PASS);
  printf("Connected to wifi: %s\n",WIFI_SSID);
  printf("Finished initialization.\n");
  // you're smart enough to understand print statements.
}

// Button0 handler
void BlynkWidgetWrite0(BlynkReq& _req,const BlynkParam& query) {
  // just setting the gpio pin output.
  bool out=(bool)query.asInt();
  digitalWrite(D2,out);
  printf("Turned GPIO-%u %s.\n",D2,OUTPUT_STATUS(out));
}

// Button1 handler
void BlynkWidgetWrite1(BlynkReq& _req,const BlynkParam& query) {
  bool out=(bool)query.asInt();
  digitalWrite(D1,out);
  printf("Turned GPIO-%u %s.\n",D1,OUTPUT_STATUS(out));
}

// Button2 handler
void BlynkWidgetWrite2(BlynkReq& _req,const BlynkParam& query) {
  bool out=(bool)query.asInt();
  digitalWrite(D6,out);
  printf("Turned GPIO-%u %s.\n",D6,OUTPUT_STATUS(out));
}

// Button3 handler
void BlynkWidgetWrite3(BlynkReq& _req,const BlynkParam& query) {
  bool out=(bool)query.asInt();
  digitalWrite(D5,out);
  printf("Turned GPIO-%u %s.\n",D5,OUTPUT_STATUS(out));
}


void loop() {
  // According to the documentation of Blynk, it seems to me that it's running some kind of event loop.
  // I couldn't find the source code so I can't say for sure what it exactly does,
  // and Im too lazy to read the assembly output.
  // Just dont mess with it.
  Blynk.run();
}










