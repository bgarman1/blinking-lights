
  
  int ledPin = 11;   //define varaible
  
  int input1 = 0;  // input for heat resistor

  int value = 0;  // the varable to store the read value

  int loopflag = 0;

  int upchange = 0;

  int breakout = 0;
  
void setup() {

  Serial.begin(9600); 

  pinMode(ledPin,OUTPUT); // led light useing pin 11


}


void loop()    //main               // put your main code here, to run repeatedly:
{
value = analogRead(input1);

Serial.println(value);

if( value == 0 )

        {
                      if (loopflag == 0)
                       {
                         while(1)
                         {
                          loopflag = 1;
                          delay(2);      
                          for(int dim = 255; dim > 0; dim--)
                              {
                                analogWrite(ledPin, dim);
                                 breakout = analogRead(input1);
                                  
                                  if(breakout == 0)
                                 {
                                  upchange = 1;
                                  break;
                                 }
                                 
                                 delay(10);
                               }
                               
                               if (upchange == 1)
                               break;
                            
                            for(int dim= 0; dim < 255 ; dim++)
                          {
                            analogWrite(ledPin,dim);
                            breakout = analogRead(input1);
                            if(breakout == 0)
                            {
                             upchange = 1;
                              break;
                            }
                            delay(10);
                          }
                            
                            if (upchange == 1)
                            break;
                        }
                    
                   }
                   
                   else if(loopflag == 1)
                   {
                    digitalWrite(ledPin, LOW);
                    delay(500);
                    loopflag = 0;
                   }
       }
                      
                   

      
}
