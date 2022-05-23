/******************************************************************************
  Title: Qwiic Switch Wireless Attempt Counter
  File: Qwiic_Switch_Wireless_Attempt_Counter.ino
  Created: May 22, 2022
  https://github.com/milador/Qwiic-Switch-Wireless-Attempt-Counter

******************************************************************************/

#include <Wire.h>
#include "SparkFun_TCA9534.h"
#include <M5StickC.h>
    
#define LOG Serial

TCA9534 inputModule;            //Input
TCA9534 outputModule;           //Output 


#define INPUT_ADDR               0x27
#define OUTPUT_ADDR              0x26

#define NUM_SWITCH 2                   //Switch A and B
#define UPDATE_SWITCH_DELAY 200        //100ms
#define BUTTON_DEBOUNCE_DELAY 200      //200ms

bool inputPinMode[NUM_SWITCH] = {GPIO_IN, GPIO_IN};
bool outputPinMode[NUM_SWITCH] = {GPIO_OUT, GPIO_OUT};

String switchConnectionMessage;        //Qwiic modules connection state message 

bool switchStatus[NUM_SWITCH];              //Switch A and B status

int moduleConnectionState;

//Session data struct
typedef struct {
  String sessionTitle;
  unsigned long sessionCountA;
  unsigned long sessionCountB;
} sessionType;

int pageNumber = 0;


sessionType sessionAttempt;                //Array of sessions 

String sessionString;                      //Session string data
                                
void setup() {
  
  LOG.begin(115200);

  M5.begin();

  initData();                                 //Initialize data

  showIntro();                                //Show intro page

  Wire.begin();

  while (1) { //Both input and output modules are successfully detected 
    if (inputModule.begin(Wire,INPUT_ADDR) == true && outputModule.begin(Wire,OUTPUT_ADDR) == true ) {
      switchConnectionMessage = "Success: Qwiic Modules are detected";
      LOG.println(switchConnectionMessage);
      moduleConnectionState = 1;
      break;
    } else {
      switchConnectionMessage = "Error: Qwiic Modules are not detected";
      LOG.println(switchConnectionMessage);
      moduleConnectionState = 0;
      delay(3000);
    }
  }
  inputModule.pinMode(inputPinMode);
  outputModule.pinMode(outputPinMode);

  showSession();                                 //Show session page

}


/*** Show Intro Page***/
void showIntro() {

  pageNumber = 0;                                  //Set intro page number 

  M5.Lcd.setRotation(3);

  M5.Lcd.fillScreen(WHITE);
  delay(200);
  M5.Lcd.fillScreen(RED);
  delay(200);
  M5.Lcd.fillScreen(GREEN);
  delay(200);
  M5.Lcd.fillScreen(BLUE);
  delay(200);
  M5.Lcd.fillScreen(BLACK);
  
  M5.Lcd.setTextColor(WHITE);

  M5.Lcd.setTextSize(2);                        
  M5.Lcd.drawCentreString("Milador.ca",80,20,2);

  M5.Lcd.setTextSize(1);
  M5.Lcd.drawCentreString("Switch Attempt Counter",80,50,1);

  delay(3000);
}


/*** Show Session Page***/
void showSession(){


  pageNumber = 1;

  //Session title
  M5.Lcd.setRotation(0);
  M5.Lcd.fillScreen(BLACK);                      //Black background                   
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.drawCentreString(sessionAttempt.sessionTitle,40,2,2);
  
  //Session switch A attempt count
  M5.Lcd.drawRect(5, 20, 70, 45, BLUE); 
  M5.Lcd.setTextSize(2);                        
  M5.Lcd.setTextColor(BLUE);
  M5.Lcd.setCursor(13, 25);
  M5.Lcd.printf("SW A");
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(40, 42);
  M5.Lcd.drawCentreString((String)sessionAttempt.sessionCountA,40,42,1);

  //Session switch B attempt count
  M5.Lcd.drawRect(5, 75, 70, 45, RED);       
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setCursor(13, 80);
  M5.Lcd.printf("SW B");
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(40, 102);
  M5.Lcd.drawCentreString((String)sessionAttempt.sessionCountB,40,102,1);

  //I2C connection text
  showConnection(moduleConnectionState);

  //Reset button text
  M5.Lcd.drawRect(1, 145, 79, 15, ORANGE);
  M5.Lcd.setCursor(2, 155);
  M5.Lcd.setTextColor(ORANGE);                           // Select the font
  M5.Lcd.setTextSize(1);
  M5.Lcd.drawCentreString("Reset",40,150,1);
}
/*** Show Qwiic modules connection state***/
void showConnection(int code) {

  M5.Lcd.setRotation(0);
  M5.Lcd.drawRect(1, 128, 79, 15, BLUE);
  M5.Lcd.setCursor(2, 133);
  M5.Lcd.setTextColor(WHITE);                           // Select the font
  M5.Lcd.setTextSize(1);
  //Display connection status based on code
  if(code==0){
    switchConnectionMessage = "Error: No I2C";
    LOG.println(switchConnectionMessage);
    M5.Lcd.drawCentreString(switchConnectionMessage,2,133,1);// Display connection state
  } else if(code==1){
    switchConnectionMessage = "Success: I2C";
    LOG.println(switchConnectionMessage);
    M5.Lcd.drawCentreString(switchConnectionMessage,2,133,1);// Display connection state
  }
    
}

/*** Initialize Session Data***/
void initData() {
    sessionAttempt.sessionTitle = "Session";
    sessionAttempt.sessionCountA = 0;
    sessionAttempt.sessionCountB = 0;
}

/*** Initialize Session Data***/
void resetSessionData() {
  sessionAttempt.sessionTitle = "Session";
  sessionAttempt.sessionCountA = 0;
  sessionAttempt.sessionCountB = 0;
}


/***Main Loop***/
void loop() {
  //Perform input action based on page number 
  switch (pageNumber) {
    case 0:
      introLoop();
      break;
    case 1:
      sessionLoop();
      break;
    default:
      // statements
      break;
  }

  delay(UPDATE_SWITCH_DELAY);
}

/***Intro Page Loop***/
void introLoop() {

}


/***Session Page Loop***/
void sessionLoop() {
  //Reset session 
  M5.update();
  
  if (M5.BtnA.wasReleased()) {
    resetSessionData();
    showSession();
  } 

  //Switch A input and output 
  switchStatus[0] = !inputModule.digitalRead(0);
  outputModule.digitalWrite(0, switchStatus[0]);

  //Switch B input and output 
  switchStatus[1] = !inputModule.digitalRead(1);
  outputModule.digitalWrite(1, switchStatus[1]);
  
  if(switchStatus[0]) { //Increment switch A count
    ++sessionAttempt.sessionCountA;
    showSession();
  };
  if(switchStatus[1]) { //Increment switch B count
    ++sessionAttempt.sessionCountB;
    showSession();
  };
}
