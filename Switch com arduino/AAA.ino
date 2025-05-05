#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {0XDE, 0xAD, 0xBE, 0xEF, 0X01};
IPAdress ip (192,168,1,54);
EthernetServer server (5000);
const int LED = 8;
void setup() {
  pinMode(LED,OUTPUT);
  Ethernet.begin(mac,ip);
  server.begin();
  
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    String cmd = client.readStringUntil('\n');
    cmd.trim();
    if (cmd == "ligar"){
      digitalWrite(LED,HIGH);
    }
    else if (cmd == "desligar") {
      digitalWrite(LED,LOW);

    }
    client.println("OK\n");
    client.stop();
  }
  
}
