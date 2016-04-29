# Camera_Elektropioneer

Hardware

    The camera we are using is the PixyMon camera
    For communication with the camera we are using an arduino nano. But any arduino can be used. We haven't tested it with avr.

Software

    The camera software is PixyMon.
    For the arduino we are using the Arduino IDE
    
Usage

  Camera

    First connect the camera with your usb 2.0 cable to your computer and open the PixyMon program.
    It should automaticlly show what the cameras sees.
    To set an object go into Action -> Set signature
    The screen will freeze and you will select the area/color/object that you want to detect.
    In the program you can also configure the brightness, sharpness ext.
    
  Arduino
  
    PixyMon has a dedicated library for the arduino(see the file). We are getting the x,y , signature and the color of the object from the camera.
    By that we determine the exact location and color of the object and we can use it for example detecting the combinations of "seashells".
    
The Code

    In the define section we define the tolerance of the camera, the I/O ports and the x and y positions of the object we want.
    
    The get_x_y_position() function prints the x,y and signature to the serial. It will only print the information about the objects that we set in the PixyMon program.
      
    The purple_get_position() and green_get_position() checks the x and y that the camera is returning and puts the information into an array.
    
    The get_combination() function checks the array and determines the combination of the "seashells" on the table and turns on the communication pins.
  
    In the loop
    
      The if(digitalRead(side_pin)) checks the "color" switch and by that sets the color/group of x and y.
      
      The rest of the code is an auto generated code from the PixyMon library. It is always checking for the blocks and changing the x,y and sig variables.
    
    
