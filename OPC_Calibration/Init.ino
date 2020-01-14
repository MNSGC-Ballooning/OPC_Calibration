void initSD(){
  pinMode(chipSelect, OUTPUT);                                          //initialize SD card
  
  while (!SD.begin(chipSelect)) {                                       //power LED will blink if no card is inserted
    Serial.println("No SD");
    delay(500);
    SDcard = false;
  }
  SDcard = true;

  for (int i = 0; i < 100; i++) {                                       //Flight Log Name Cration
    Fname = String("Log" + String(i / 10) + String(i % 10) + ".csv");
    if (!SD.exists(Fname.c_str())) {
      openlog();
      break;
    }
  }
  
  Serial.println("Log created: " + Fname);

  String Header = Plan.CSVHeader();
  file.println(Header);                                                //Set up Flight log format
  Serial.println("Log header added");                            

  closelog();
}

void initOPCs() {                                                       //Sets up serial and initializes the OPCs
  PMS_SERIAL.begin(9600);
  Plan.initOPC();
  Serial.println("Plantower Initialized");
}
