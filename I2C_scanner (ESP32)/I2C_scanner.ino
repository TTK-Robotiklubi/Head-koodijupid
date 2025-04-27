#include <Wire.h>
 
void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
}
 
void loop() {
 // pinMode(15, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(16, OUTPUT);

  //LOW -ei tuvasta, HIGH- tuvastab
  //digitalWrite(15,LOW);  //siia panna VL53L1X (0x29)"XSHUT", et tuvastaks neid.
  digitalWrite(2,HIGH);  //siia panna VL53L1X (0x29)"XSHUT", et tuvastaks neid.
  digitalWrite(0,LOW);  //siia panna VL53L1X (0x29)"XSHUT", et tuvastaks neid. 
  digitalWrite(4,LOW);  //siia panna VL53L1X (0x29)"XSHUT", et tuvastaks neid.
  //LOW -tuvastab, HIGH-ei tuvasta (panna otse gnd, ei sega teisi andureid adresseerimisel?)
  digitalWrite(16,LOW); //siia panna Me Color Sensor V1 (0x38) "S2", et tuvastaks teda (VAJAB LEVEL SHIFTERIT, ET ANDUR "HIGH"-GA VÄLJA LÜLITADA. 3.3V ON IKKA GND ANDURI JAOKS) 

  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
      nDevices++;
    }
    else if (error==4) {
      Serial.print("Unknow error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("done\n");
  }
  delay(5000);          
}