#include <Keypad.h>    // Подключение библиотеки Keypad
 
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
int delayStep=500;
int delayMS=0;
int keyi=0;
int speed=1;
int workTime=20;
int ColIter=0;
boolean setSpeed=false;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup()
{
  delayMS=delayStep;
  ColIter=workTime;
  pinMode (A1, OUTPUT);
  pinMode (A0, OUTPUT);
  Serial.begin(9600); // Открываем последовательную связь на скорости 9600
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
 if (ColIter<workTime){
  digitalWrite(A0, HIGH);
    delayMicroseconds(delayMS); 
  digitalWrite(A0, LOW);
 }
  char key = keypad.getKey();  // Читаем состояние кнопок
   if (key){
  //  Serial.print("Key Pressed : ");
   // Serial.println(key);
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
      delayMS=delayStep*keyi;
       
       }
      }
    }
    } // end if A
//регулируем время работы
    if (key=='B') {
      char key1 = keypad.getKey();
     int workT=0;
     Serial.print("Now WT : ");
     Serial.println(workTime);
      while (key1!='#')
      {
         
       
      if (key1)
      {keyi=-1;
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
       
     if ((keyi<=9)&&(keyi>=0)){
      workT=workT*10+keyi;
       Serial.print("Work time : ");
     Serial.println(workT);
       }
Serial.print("key1 : ");
     Serial.println(key1);
         
      }
      key1 = keypad.getKey();
      if ((key1=='#')&&(workT!=0)){
        workTime=workT;
        ColIter=workTime;
      }
    }
    } // end if B

     if (key=='D') {
       stop=false;
       if (ColIter!=workTime){ColIter=workTime;}
       else{
       ColIter=0;
       }
    }
      
  }
 
   if (ColIter<workTime) {ColIter++;}
}