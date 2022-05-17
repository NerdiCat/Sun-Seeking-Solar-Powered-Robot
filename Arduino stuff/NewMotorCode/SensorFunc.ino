bool gonnaFall(){
  uint8_t range = lox2.readRange();
  uint8_t status = lox2.readRangeStatus();

  if (status == VL6180X_ERROR_NONE && range<100) {
    return false;
  }
  else return true;
  delay(25);
}

bool gonnaCrash(){
  uint8_t range = lox1.readRange();
  uint8_t status = lox1.readRangeStatus();

  if (range<100) {
    return true;
  }
  else return false;
  delay(50);
}
