#include <LiquidCrystal.h>

#include <Keypad.h>    // Подключение библиотеки Keypad
 #include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h>
const byte ROWS = 4;   // Количество рядов 
const byte COLS = 4;   // Количество строк 
 
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte rowPins[ROWS] = {9, 8, 7, 6}; // Выводы, подключение к строкам
byte colPins[COLS] = {5, 4, 3, 2}; // Выводы, подключение к столбцам  
boolean stop= true; 
int delayStep=600;
int delayMS=0;
int keyi=0;
int speed=1;
long workTime=20;
long workTimeK=100;
long ColIter=0;
int Counter=0;
int rotate=0;
boolean setSpeed=false;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 LiquidCrystal_I2C LCD(0x27,16,2);
void setup()
{
  delayMS=delayStep;
  ColIter=workTime*workTimeK;
  pinMode (A1, OUTPUT);
  pinMode (A0, OUTPUT);
 
 digitalWrite(A1, HIGH);
  Serial.begin(9600); // Открываем последовательную связь на скорости 9600

 LCD.init(); // инициализация LCD дисплея
   LCD.backlight(); // включение подсветки дисплея
   
   LCD.setCursor(0, 0);     // ставим курсор на 1 символ первой строки
   LCD.print("Sp");     // печатаем сообщение на первой строке
  
   LCD.setCursor(4, 0);        // ставим курсор на 1 символ второй строки
   LCD.print("Time");  // печатаем сообщение на второй строке

   LCD.setCursor(9, 0);        // ставим курсор на 1 символ второй строки
   LCD.print("Count");  // печатаем сообщение на второй строке

LCD.setCursor(10, 1);        
   LCD.print(Counter);

   LCD.setCursor(1, 1);        // ставим курсор на 1 символ второй строки
   LCD.print(speed);  // печатаем сообщение на второй строке


   LCD.setCursor(5, 1);        // ставим курсор на 1 символ второй строки
   LCD.print(workTime);  // печатаем сообщение на второй строке

   LCD.setCursor(15, 0);        // ставим курсор на 1 символ второй строки
   LCD.print("R");  // печатаем сообщение на второй строке
  
   LCD.setCursor(15, 1);        // ставим курсор на 1 символ второй строки
   LCD.print(char(126));  // печатаем сообщение на второй строке


}
  void start (boolean start, int col, int delayMS){
    if (start==true){

   for (int i=0; i<=col; i++){   
  digitalWrite(A0, HIGH);
    delayMicroseconds(delayMS); 
  digitalWrite(A0, LOW);
   }
  }
  
} 
void loop(){
 

 //start(false,1);
 if (ColIter<workTime*workTimeK){
  digitalWrite(A0, HIGH);
    delayMicroseconds(delayMS); 
  digitalWrite(A0, LOW);
 }
  char key = keypad.getKey();  // Читаем состояние кнопок
   if (key){
    Serial.print("Key Pressed : ");
     Serial.println(key);
     switch (key){
      case '1':
        keyi=1;
      break;
       case '2':
        keyi=2;
      break;
       case '3':
        keyi=3;
      break;
       case '4':
        keyi=4;
      break;
       case '5':
        keyi=5;
      break;
       case '6':
        keyi=6;
      break;
       case '7':
        keyi=7;
      break;
       case '8':
        keyi=8;
      break;
       case '9':
        keyi=9;
      break;

     }
   
     /*if ((keyi<=9)&&(keyi>=1)){
      delayMS=delayStep*keyi;
      Serial.print("Задержка : ");
    Serial.println(delayMS);
    }
    if (key=='A') {
      digitalWrite(11, HIGH);
    }
    if (key=='B') {
      digitalWrite(11, LOW);
    }
      */
    //регулируем скорость
    if (key=='A') {
      char key1 = keypad.getKey();
      LCD.setCursor(0,1);
      LCD.print(char(62));
      while (key1!='#')
      {
        key1 = keypad.getKey();
      
      if (key1)
      {
        keyi=0;
        switch (key1){
      case '1':
        keyi=1;
      break;
       case '2':
        keyi=2;
      break;
       case '3':
        keyi=3;
      break;
       case '4':
        keyi=4;
      break;
       case '5':
        keyi=5;
      break;
       case '6':
        keyi=6;
      break;
       case '7':
        keyi=7;
      break;
       case '8':
        keyi=8;
      break;
       case '9':
        keyi=9;
      break;

     }
     
       Serial.print("Key1 : ");
     Serial.println(key1);
     if ((keyi<=9)&&(keyi>=1)){
      speed=keyi;
      LCD.setCursor(1, 1);        // ставим курсор на 1 символ второй строки
      LCD.print(speed);
      delayMS=delayStep*keyi;
       
       }
      }
        
    }
    LCD.setCursor(0,1);
       LCD.print(" ");
    } // end if A
//регулируем время работы
    if (key=='B') {
      char key1 = keypad.getKey();
     int workT=0;
     LCD.setCursor(4,1);
      LCD.print(char(62));
     //Serial.print("Now WT : ");
     //Serial.println(workTime);
      while(key1!='#'&&key1!='*' )
      {
         
       
      if (key1)
      {keyi=-1;
        switch (key1){
      
      case '0':
        keyi=0;
      break;
      case '1':
        keyi=1;
      break;
       case '2':
        keyi=2;
      break;
       case '3':
        keyi=3;
      break;
       case '4':
        keyi=4;
      break;
       case '5':
        keyi=5;
      break;
       case '6':
        keyi=6;
      break;
       case '7':
        keyi=7;
      break;
       case '8':
        keyi=8;
      break;
       case '9':
        keyi=9;
      break;

     }  
       
     if ((keyi<=9)&&(keyi>=0)){
        
       if (keyi==0){
          
      workT=workT*10;  
       }
       else{
      workT=workT*10+keyi;
       }
       Serial.print("Work time : ");
     Serial.println(workT);
     LCD.setCursor(5,1);
      LCD.print("     ");
     LCD.setCursor(5,1);
      LCD.print(workT);
       }
 
         
      }
      key1 = keypad.getKey();
      if ((key1=='#')&&(workT!=0)){
        workTime=workT;
        ColIter=workTime*workTimeK;
        
        LCD.setCursor(5, 1);
        LCD.print("     ");
        LCD.setCursor(5, 1);
        LCD.print(workTime);
 
        LCD.setCursor(4, 1);
        LCD.print(" ");
      }
      if (key1=='*'){
         
         
        
        LCD.setCursor(5, 1);
        LCD.print("     ");
        LCD.setCursor(5, 1);
        LCD.print(workTime);
 
        LCD.setCursor(4, 1);
        LCD.print(" ");
      }
    }
     LCD.setCursor(4, 1);
        LCD.print(" ");
     Serial.print("ColIter: ");
     Serial.println(ColIter);

    } // end if B
if (key=='C') {
      char key1 = keypad.getKey();
     int workT=0;
     LCD.clear();
     LCD.setCursor(0,1);
      LCD.print("Reset? #Yes *No");
     //Serial.print("Now WT : ");
     //Serial.println(workTime);
     
      while(key1!='#'&&key1!='*' )
      {
           key1 = keypad.getKey();
            
      }
        
      if (key1=='#') {Serial.println("Reset");Counter=0;}
     
      LCD.clear();
      LCD.setCursor(0, 0);     // ставим курсор на 1 символ первой строки
   LCD.print("Sp");     // печатаем сообщение на первой строке
  
   LCD.setCursor(4, 0);        // ставим курсор на 1 символ второй строки
   LCD.print("Time");  // печатаем сообщение на второй строке

   LCD.setCursor(9, 0);        // ставим курсор на 1 символ второй строки
   LCD.print("Count");  // печатаем сообщение на второй строке

LCD.setCursor(10, 1);        
   LCD.print(Counter);

   LCD.setCursor(1, 1);        // ставим курсор на 1 символ второй строки
   LCD.print(speed);  // печатаем сообщение на второй строке


   LCD.setCursor(5, 1);        // ставим курсор на 1 символ второй строки
   LCD.print(workTime);  // печатаем сообщение на второй строке

   LCD.setCursor(15, 0);        // ставим курсор на 1 символ второй строки
   LCD.print("R");  // печатаем сообщение на второй строке
  
   LCD.setCursor(15, 1);        // ставим курсор на 1 символ второй строки
   LCD.print(char(126));
    }// end if C



     if (key=='D') {
       stop=false;
       if (ColIter!=workTime*workTimeK){
          ColIter=workTime*workTimeK; 
          if (Counter>0) {Counter--;}
          LCD.setCursor(10, 1);        
   LCD.print(Counter);
          }
       else{
        Counter++;
        LCD.setCursor(10, 1);        // ставим курсор на 1 символ второй строки
   LCD.print(Counter);
       ColIter=0;
       }
    }
      
  }
 
   if (ColIter<workTime*workTimeK) {ColIter++;}
}