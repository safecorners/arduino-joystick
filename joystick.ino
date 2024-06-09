const int VRX_PIN = A0 ;
const int VRY_PIN = A1 ;
const int SW_PIN = A2 ;

void setup() {

    pinMode(SW_PIN, INPUT_PULLUP);
    
    Serial.begin(9600);
    Serial.println("Joystick Ready. format: (VRX, VRY, SW)");
}

void loop() {
    int VRX = analogRead(VRX_PIN);
    int VRY = analogRead(VRY_PIN);
    int SW = digitalRead(SW_PIN);
    if (Serial.available()) {
        char command = Serial.read();
        if (command == 's') {
            sendSensingValues(VRX, VRY, SW);
        }
    }
}

void sendSensingValues(int VRX, int VRY, int SW) {
    char buffer[50];
    sprintf(buffer, "(%d, %d, %d)", VRX, VRY, SW);
    Serial.println(buffer);
    Serial.flush();
}