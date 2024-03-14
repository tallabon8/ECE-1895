int clockSynchronizationOutput = 9;
int playerOneWinLossRead = 5;
int playerTwoWinLossRead = 6;
int gameActiveOutput = 2;
int gameChoiceOutput = 3;    // pin for game choice output
int gameChoice = 0;          //Value from 0-3: 0 = no active game, 1 = knife game, 2 = draw down, 3 pick your poison
int gameChoiceCount = 0;     // Count indicating how many times the output went high
int playerOneLifeCount = 3;  // Life count for player 1
int playerTwoLifeCount = 3;  // Life count for player 2
int gameStart = 1;           // Pin mapping for game start input
bool gameActive = false;     // Current state of whether overall game is active
int pwmCenterControl = 10;

int count;

void setup() {
  //pinMode(lossOutput, OUTPUT);
  pinMode(gameChoiceOutput, OUTPUT);
  pinMode(gameStart, INPUT_PULLUP);
  pinMode(playerOneWinLossRead, INPUT);
  pinMode(playerTwoWinLossRead, INPUT);
  pinMode(gameActiveOutput, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  if (digitalRead(gameStart) == LOW) {
    gameActive = true;
    digitalWrite(gameActiveOutput, HIGH);
  }
  if (gameChoice == 0) {
    delay(25);
    gameChoice = random(1, 3);
    //designate l
  }
  while (gameActive == true) {

    Serial.write("Game Choice: " + gameChoice);
    // Serial.println("Game Choice: " gameChoice);
    while (gameChoice != 0) {
      //Initiallly when game is activated counts up to random value
      if (gameChoiceCount <= 3) {
        gameChoiceCount++;
      }
      //Synchonized clock pulse
      digitalWrite(clockSynchronizationOutput, LOW);
      delay(5);
      digitalWrite(clockSynchronizationOutput, HIGH);
      //If the gameChoiceCount equals the game choice it the gameChoiceOutput will be set to high
      //If the gameChoiceCount doesnt equal the game choice it will be low


      if (count == gameChoice) {
        digitalWrite(gameChoiceOutput, HIGH);
        // Serial.println("H + H");
        Serial.write("H + H");
      } else {
        digitalWrite(gameChoiceOutput, LOW);
        // Serial.println("H + L");
        Serial.write("H + L");
      }
      if (digitalRead(playerOneWinLossRead) == LOW || digitalRead(playerTwoWinLossRead) == LOW) {
        gameChoice = 0;
        if (digitalRead(playerOneWinLossRead) == LOW) {
          playerOneLifeCount--;
          //  Serial.println("Player One Life Count: "PlayerOneLifeCount);
          Serial.write("Player One Life Count: " + playerOneLifeCount);
        }
        if (digitalRead(playerOneWinLossRead) == LOW) {
          playerOneLifeCount--;
          // Serial.println("Player Two Life Count: "PlayerTwoLifeCount);
          Serial.write("Player Two Life Count: " + playerTwoLifeCount);
        }
        if (playerOneLifeCount == 0 || playerTwoLifeCount == 0) {
          gameActive == false;
        }
      }
    }
  }
}
