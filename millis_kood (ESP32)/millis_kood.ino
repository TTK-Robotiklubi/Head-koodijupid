


void loop() {
    digitalWrite(LED_PIN, LED_status);
    if (millis() - time_now > period){
        //wait approx. [period] ms
        time_now = millis();
        LED_status =!LED_status;
        Serial.print(time_now);
        Serial.println(" millisekundit on möödunud käivitamisest");
        Serial.print(LED_status);
        Serial.println(" on hetkel LED_status");
    }
}