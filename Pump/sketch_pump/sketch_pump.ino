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
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup()
{
  Serial.begin(9600); // Открываем последовательную связь на скорости 9600
}
  
void loop(){
  
  char key = keypad.getKey();  // Читаем состояние кнопок
   if (key){
    Serial.print("Key Pressed : ");
    Serial.println(key);
  }
}