boolean logOpen = false;
void openlog() {                                                  //Open flight log
  if (!logOpen&&SDcard) {
    //add .c_str() next to Fname
    file = SD.open(Fname.c_str(), FILE_WRITE);
    logOpen = true;
  }
}
void closelog() {                                                 //Close flight log
  if (logOpen&&SDcard) {
    file.close();
    logOpen = false;
  }
}
