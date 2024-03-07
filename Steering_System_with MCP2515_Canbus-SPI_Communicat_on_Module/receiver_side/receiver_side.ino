#include <SPI.h>
#include <mcp2515.h>
#include <Servo.h>
Servo myServo;

struct can_frame canMsg;

MCP2515 mcp2515(10);

void setup() {
  Serial.begin(9600);
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
myServo.attach(3);
}

void loop()

{

  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)
  {

    int x = canMsg.data[0];
    
    

    
    myServo.write(x);
    

    
    
  }
}