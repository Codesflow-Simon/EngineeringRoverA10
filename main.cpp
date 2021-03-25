int incomingByte = 0; // for incoming serial data
bool a = false;
bool b = false;

void setup() {
	Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
	#define cutoutOne 4
  	#define driveAOne 5
  	#define driveBOne 3
  	pinMode(cutoutOne, OUTPUT);
  	pinMode(driveAOne, OUTPUT);
  	pinMode(driveBOne, OUTPUT);
  
  	#define cutoutTwo 8
  	#define driveATwo 10
  	#define driveBTwo 11
  	pinMode(cutoutTwo, OUTPUT);
  	pinMode(driveATwo, OUTPUT);
  	pinMode(driveBTwo, OUTPUT);
  
  	digitalWrite(cutoutOne, HIGH);
 	digitalWrite(cutoutTwo, HIGH);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
	Serial.println(incomingByte);
    drive(incomingByte);
  }
}

void drive(int direction) {
  	int dirOne, dirTwo;
    switch (direction) {
    	case 115:
      		dirOne = 115;
            dirTwo = 115;
            break;
      	case 102:
      		dirOne = 102;
            dirTwo = 102;
            break;
      	case 98:
      		dirOne = 98;
            dirTwo = 98;
            break;
     	case 108:
      		dirOne = 102;
            dirTwo = 98;
            break;
      	case 114:
      		dirOne = 98;
            dirTwo = 102;
            break;
    }
  	for (int i=1; i<3; i++){
      	int driveA, driveB, dir;
      	if (i == 1) {driveA = driveAOne; driveB = driveBOne; dir=dirOne;}
      	else {driveA = driveATwo; driveB = driveBTwo; dir=dirTwo;}
      	Serial.println(driveA);
      	Serial.println(driveB);
      	Serial.println(dir);
        if (dir==115){
    		digitalWrite(driveA, LOW);
            digitalWrite(driveB, LOW);
        }
      	else if (dir==102) {
    		digitalWrite(driveA, HIGH);
            digitalWrite(driveB, LOW);
        }
     	else if (dir==98){
    		digitalWrite(driveA, LOW);
            digitalWrite(driveB, HIGH);
         }
 	 }
}
           
