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
boolean stop= false; 
int delayStep=500;
int delayMS=0;
int keyi=0;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup()
{
  delayMS=delayStep;
  pinMode (10, OUTPUT); 
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
  Serial.begin(9600); // Открываем последовательную связь на скорости 9600
}
  
void loop(){
  if (stop==false){
  digitalWrite(13, HIGH);
    delayMicroseconds(delayMS); 
  digitalWrite(13, LOW);
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
   
     if ((keyi<=9)&&(keyi>=1)){
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

     if (key=='C') {
      stop=false;
      digitalWrite(13, HIGH);
    }
     if (key=='D') {
      stop=true;
      digitalWrite(13, LOW);
    }
  }
}