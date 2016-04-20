#include <SPI.h>
#include <Pixy.h>


///////////////////////////////
//   SETTINGS FOR CAMERA     //
///////////////////////////////

#define tolerancija          30
#define camera_0_pin          2
#define camera_1_pin          3
#define camera_2_pin          4
#define side_pin              5     

///////////////////////////////
//     PURPLE SIDE COORD     //
///////////////////////////////
#define p_first_x            71
#define p_first_y            68

#define p_second_x           177
#define p_second_y           109

#define p_third_x            278
#define p_third_y            168

#define p_fourth_x           237  
#define p_fourth_y           88

///////////////////////////////
//      GREEN SIDE COORD     //
///////////////////////////////
#define g_first_x            71
#define g_first_y            68

#define g_second_x           177
#define g_second_y           109

#define g_third_x            278
#define g_third_y            168

#define g_fourth_x           237  
#define g_fourth_y           88

////////////////////////////////

Pixy pixy;
uint16_t blocks;
int i,n,pos[7],j,x,y,sig,ser,stg,scn;
int tol = tolerancija;

void get_x_y_position()
{
  Serial.println(x);
  Serial.println(y);
  Serial.println(sig);
  Serial.print("\n");
  Serial.print("\n"); 
}
void purple_get_position()
{
  //sig 1 = purple, sig 2 = white, sig 3 = green

    if(x > p_first_x - tol && x < p_first_x+ tol && y > p_first_y - tol && y < p_first_y + tol){
        pos[1] = sig;
             Serial.print(sig);
    }
    else if(x > p_second_x - tol && x < p_second_x + tol && y > p_second_y - tol && y < p_second_y + tol){
        pos[2] = sig;
             Serial.print(sig);
    }
    else if(x > p_third_x  - tol && x < p_third_x  + tol && y > p_third_y  - tol && y < p_third_y  + tol){
        pos[3] = sig;
             Serial.print(sig);
    }
    else if(x > p_fourth_x - tol && x < p_fourth_x + tol && y > p_fourth_y - tol && y < p_fourth_y + tol){
        pos[4] = sig;
              Serial.print(sig);
    }

}
void green_get_position()
{
  //sig 1 = purple, sig 2 = white, sig 3 = green

    if(x > g_first_x - tol && x < g_first_x+ tol && y > g_first_y - tol && y < g_first_y + tol){
        pos[1] = sig;
             Serial.print(sig);
    }
    else if(x > g_second_x - tol && x < g_second_x + tol && y > g_second_y - tol && y < g_second_y + tol){
        pos[2] = sig;
             Serial.print(sig);
    }
    else if(x > g_third_x  - tol && x < g_third_x  + tol && y > g_third_y  - tol && y < g_third_y  + tol){
        pos[3] = sig;
             Serial.print(sig);
    }
    else if(x > g_fourth_x - tol && x < g_fourth_x + tol && y > g_fourth_y - tol && y < g_fourth_y + tol){
        pos[4] = sig;
              Serial.print(sig);
    }

}
void get_combination()
{

  digitalWrite(camera_0_pin, LOW);
  digitalWrite(camera_1_pin, LOW);
  digitalWrite(camera_2_pin, LOW);
  
  if(pos[1] == 3 && pos[2] == 1){
        Serial.println("Kombinacija 1");
        digitalWrite(camera_0_pin, HIGH);
        }

    if(pos[1] == 1 && pos[2] == 1){
        Serial.println("Kombinacija 2");
        digitalWrite(camera_1_pin, HIGH);
        }

    if(pos[1] == 1 && pos[3] == 1 && pos[4] == 2){
        Serial.println("Kombinacija 3");
        digitalWrite(camera_2_pin, HIGH);
        }

    if(pos[1] == 2 && pos[3] == 1 && pos[4] == 2){
        Serial.println("Kombinacija 4");
        digitalWrite(camera_0_pin, HIGH);
        digitalWrite(camera_1_pin, HIGH);
        }

    if(pos[3] == 1 && pos[4] == 3){
        Serial.println("Kombinacija 5");
        digitalWrite(camera_1_pin, HIGH);
        digitalWrite(camera_2_pin, HIGH);
        }
        
    Serial.println("Did not find anything");
}
void setup()
{
  Serial.begin(9600);
  Serial.print("Starting");

  pinMode(camera_0_pin, OUTPUT);
  pinMode(camera_1_pin, OUTPUT);
  pinMode(camera_2_pin, OUTPUT);
  
  pinMode(side_pin, INPUT);

  Serial.println("Ports are set");

  pixy.init();
  Serial.println("Pixy is set");
}
void loop()
{
  if(digitalRead(side_pin))
  {

    Serial.println("P");
    
    blocks = pixy.getBlocks();
    if(blocks)
    {
      i++;
  
      if(i%10 == 0)
      {
        for(n=0;n<7;n++)
        {
          pos[n] = 0;
        }
        for(j=0;j<blocks;j++)
        {
          x = pixy.blocks[j].x;
          y = pixy.blocks[j].y;
          sig = pixy.blocks[j].signature;
  
          
          
          get_x_y_position();
          //purple_get_position();
          
          
              
          
          
        }
        get_combination();
      }
    }
  }
  else
  {
    Serial.println("G");
    
    blocks = pixy.getBlocks();
    
    if(blocks)
    {
      i++;
  
      if(i%10 == 0)
      {
        for(n=0;n<7;n++)
        {
          pos[n] = 0;
        }
        for(j=0;j<blocks;j++)
        {
          x = pixy.blocks[j].x;
          y = pixy.blocks[j].y;
          sig = pixy.blocks[j].signature;
  
          
          
          get_x_y_position();
          //green_get_position();
          
          
              
          
          
        }
        get_combination();
      }
    }
  }
}
