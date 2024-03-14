
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
int gameChoiceRead = 0;
int gameActiveRead = 9;
int clockSynchronizationRead = 8;
int playerWinLossOutput = 12;
int knifeInput[5] = { 1, 2, 3, 4, 5 };
// knifeInput[0]=1;
// knifeInput[1]=2;
// knifeInput[2]=3;
// knifeInput[3]=4;
// knifeInput[4]=5;
int count;
int gameChoice;
int gc1 = 7;
int gc2 = 13;
int gc3 = 11;

bool gameActive = false;
//int hallSensorRead;
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(gameChoiceRead, INPUT);
  pinMode(gameActiveRead, INPUT);
  pinMode(clockSynchronizationRead, INPUT);
  pinMode(playerWinLossOutput, OUTPUT);
  pinMode(gc1, OUTPUT);
  pinMode(gc2, OUTPUT);
  pinMode(gc3, OUTPUT);
  pinMode(knifeInput[0], INPUT_PULLUP);
  pinMode(knifeInput[1], INPUT_PULLUP);
  pinMode(knifeInput[2], INPUT_PULLUP);
  pinMode(knifeInput[3], INPUT_PULLUP);
  pinMode(knifeInput[4], INPUT_PULLUP);
}


// the loop function runs over and over again forever
void loop() {
  count = 0;

  if (digitalRead(gameActiveRead) == HIGH) {
    if (digitalRead(clockSynchronizationRead) == HIGH) {
      count++;
      if (digitalRead(gameChoiceRead) == HIGH) {
        gameChoice = count;
        count = 0;
      }
    }
  }


  while (gameChoice == 1 && digitalRead(gameActiveRead) == HIGH) {
    digitalWrite(gc1, HIGH);
    delay(250);
    digitalWrite(gc1, LOW);
    while (digitalRead(gameChoiceRead) == LOW) {
      if (digitalRead(knifeInput[5] == LOW)) {
        digitalWrite(playerWinLossOutput, HIGH);
      } else {
        if (digitalRead(knifeInput[count]) == LOW) {
          count++;
          if (count >= 4) {
            count = 0;
          }
        }
        if ((digitalRead(knifeInput[0] == LOW && count != 0)) || (digitalRead(knifeInput[1] == LOW && count != 1)) || (digitalRead(knifeInput[2] == LOW && count != 2)) || (digitalRead(knifeInput[3] == LOW && count != 3)) || (digitalRead(knifeInput[4] == LOW && count != 4)) || (digitalRead(knifeInput[5]))) {
          digitalWrite(playerWinLossOutput, HIGH);
        }
      }
    }
  }
  if (gameChoice = 2) {
    digitalWrite(gc2, HIGH);
    delay(250);
    digitalWrite(gc2, LOW);
  }
  if (gameChoice = 3) {
    digitalWrite(gc3, HIGH);
    delay(250);
    digitalWrite(gc3, LOW);
  }
}
