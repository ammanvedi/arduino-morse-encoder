
int led = 12;
int led2 = 7;
int ascii_offset = 97;
String data = "abc";
int letter_space = 3;
int dotdelay = 30;
int word_space = 7;
String values[3] = {"132", "2313131","2313231"}; 

void setup() {                

  pinMode(led, OUTPUT);  
  pinMode(led2,OUTPUT);  
  Serial.begin(9600);
  
}

void loop() {
  
  int i;
  
  for(i = 0; i < data.length(); i++){
    char consider = data.charAt(i);
    
    
    
    if(consider == ' '){
      delay(7*dotdelay);
      break;
    }
    
    String code = values[(int)consider - ascii_offset];
    int x;
      for(x = 0; x < code.length(); x++){
          char code_partial = code.charAt(x);
          Serial.print(code_partial);
          
          
        if(code_partial == '1'){
            digitalWrite(led, HIGH);
            digitalWrite(led2, LOW);
            //add inner word spacing delay
            delay(dotdelay);
            digitalWrite(led, LOW);
    
            delay(dotdelay);
        }
        if(code_partial == '2'){
          digitalWrite(led2, HIGH);
          digitalWrite(led, LOW);
            //add inner word spacing delay
            delay(3*dotdelay);
            digitalWrite(led2, LOW);
            delay(dotdelay);
        }
        if(code_partial == '3'){
            //add inner word spacing delay
            digitalWrite(led2,LOW);
            digitalWrite(led,LOW);
            delay(3*dotdelay);

        }
        
      }
      
      //after each letter
      delay(3*dotdelay);
  }
  
  delay(7*dotdelay);

}
