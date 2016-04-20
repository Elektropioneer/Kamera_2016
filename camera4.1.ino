#include <SPI.h>
#include <Pixy.h>

Pixy pixy;
uint16_t blocks;
int i,n,pos[7],j,x,y,sig,ser,stg,scn;
int tol = 30;
void purple_get_position()
{
  //sig 1 = purple, sig 2 = white, sig 3 = green

    if(x > 71 - tol && x < 71 + tol && y > 68 - tol && y < 68 + tol){
        pos[1] = sig;
             Serial.print(sig);
    }
    else if(x > 177 - tol && x < 177 + tol && y > 109 - tol && y < 109 + tol){
        pos[2] = sig;
             Serial.print(sig);
    }
    else if(x > 278 - tol && x < 278 + tol && y > 168 - tol && y < 168 + tol){
        pos[3] = sig;
             Serial.print(sig);
    }
    else if(x > 237 - tol && x < 237 + tol && y > 88 - tol && y < 88 + tol){
        pos[4] = sig;
              Serial.print(sig);
    }

}
void get_combination()
{

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  
  if(pos[1] == 3 && pos[2] == 1){
        Serial.println("Kombinacija 1");
        digitalWrite(2, HIGH);
        }

    if(pos[1] == 1 && pos[2] == 1){
        Serial.println("Kombinacija 2");
        digitalWrite(3, HIGH);
        }

    if(pos[1] == 1 && pos[3] == 1 && pos[4] == 2){
        Serial.println("Kombinacija 3");
        digitalWrite(4, HIGH);
        }

    if(pos[1] == 2 && pos[3] == 1 && pos[4] == 2){
        Serial.println("Kombinacija 4");
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        }

    if(pos[3] == 1 && pos[4] == 3){
        Serial.println("Kombinacija 5");
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        }
}
void setup()
{
  Serial.begin(9600);
  Serial.print("Starting");

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  pinMode(5, INPUT);

  pixy.init();
}
void loop()
{
  if(digitalRead(5))
  {
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
  
          
          
          
          purple_get_position();
          
          
              
          
          
        }
        get_combination();
      }
    }
  }
  else
  {

  }
}
