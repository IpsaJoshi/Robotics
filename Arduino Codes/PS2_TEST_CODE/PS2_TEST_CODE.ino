 /*========================================JOYSTICK CONFIG===========================================*/
#include <PS2X_lib.h>                        /* PS2 Controller Library */
PS2X ps2x;                                   /* create PS2 Controller Class*/
byte Type = 0;
byte vibrate = 0;
int RX=0,RY=0,LX=0,LY=0;

int Jx,Jy,Jlx,Jly;

#define Joy_left_x ps2x.Analog(PSS_LX) 
#define Joy_left_y ps2x.Analog(PSS_LY)
#define Joy_right_x ps2x.Analog(PSS_RX)
#define Joy_right_y ps2x.Analog(PSS_RY)
#define  key_up ps2x.Button(PSB_PAD_UP)
#define  key_down ps2x.Button(PSB_PAD_DOWN)
#define  key_left ps2x.Button(PSB_PAD_LEFT)
#define  key_right ps2x.Button(PSB_PAD_RIGHT)
#define key_l1 ps2x.Button(PSB_L1)
#define key_r1 ps2x.Button(PSB_R1)
#define key_l2 ps2x.Button(PSB_L2)
#define key_r2 ps2x.Button(PSB_R2) 
#define key_triangle ps2x.Button(PSB_GREEN)
#define key_circle ps2x.Button(PSB_RED)
#define key_x ps2x.Button(PSB_BLUE)
#define key_square ps2x.Button(PSB_PINK) 
#define key_select ps2x.Button(PSB_SELECT)
#define key_start ps2x.Button(PSB_START) 
/*==========================================================================================================================*/

/*===========================================SETUP======================================*/
void setup() 
{
   ps2x.config_gamepad(52,51,53 ,50, true, true); /* setup pins and settings:  GamePad(sck(clock), mosi(command), ss(attention), miso(data), Pressures?, Rumble?) check for error*/
   Type = ps2x.readType();                       /* Reading type of the PS2 Ccontroller */
   
   Serial.begin(115200);
}
void loop()
{
      ps2x.read_gamepad(false, vibrate);
 /*     Serial.print("key_down==");
      Serial.print(key_down);
      Serial.print("key_up ");
      Serial.print(key_up);
      Serial.print("key_left== ");
      Serial.print(key_left);
      Serial.print("key_right== ");
      Serial.println(key_right);
/*      Serial.print("key_X== ");
      Serial.println(key_x);
      Serial.print("key_circle== ");
      Serial.print(key_circle);
      Serial.print("key_triangele== ");
      Serial.print(key_triangle);
      Serial.print("key_start== ");
      Serial.print(key_start);
      Serial.print("key_circle== ");
      Serial.print(key_circle);
      Serial.print("key_select==");
      Serial.print(key_select);
      Serial.print("key_square== ");
      Serial.println(key_square);*/
 /*     Serial.print("key_r1== ");
      Serial.print(key_r1);
      Serial.print("key_l1== ");
      Serial.print(key_l1);
      Serial.print("key_l2");
      Serial.print(key_l2);
      Serial.print("key_r2 ");
      Serial.print(key_r2);*/
      Serial.print(" x==");
      Serial.print(Joy_left_x);
      Serial.print(" y==");
      Serial.print(Joy_left_y);
      Serial.print("   right_x == ");
      Serial.print(Joy_right_x );
      Serial.print("  right_y == ");
      Serial.println(Joy_right_y );
}
