/**
    MyKepypadTest Projet
    Expérimentations sur l'utilisation d'un Keypad et un ESP32
    @file main.cpp
    @author ThaninaAdda 
    @version 1.0 20/04/21  
    
    Historique des vérsions   
                            Versions  Date      Auteur      Déscription
                            1.0      20/04/21   Ta          Première version qui démontre l'utilisation du esp32 et du keypad
                            
    platform = espressif32
    board = esp32doit-devkit-v1
    framework = arduino
    lib_deps = 
            chris--a/Keypad@^3.1.1         (Pour le Keypad)
    Classes du système

        Main      V1.0    qui contient le projet
            ROWS 4 :contient les 4 lignes du keypad
            COLS 4 :contient les 4 colonnes du keypad
**/

// la librairie est include dans le projet main.cpp
#include "Keypad.h"
const byte ROWS = 4; //contient les 4 lignes du keypad
const byte COLS = 4; //contient les 4 colonnes du keypad

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


// pour ESP32 Microcontroller
byte rowPins[ROWS] = {19, 18, 17, 16};  // Rangées 19 à 16 // si vous modifiez vos broches, vous devez également le modifier
byte colPins[COLS] = {15, 14, 13, 12};  //Colonnes de 15 à 12

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// la fonction setup
void setup() {
  Serial.begin(9600);   //initilise l'écran
}

void loop() {
  char key = keypad.getKey();  // Attend constamment qu'une touche soit enfoncé

  if (key){
    Serial.println(key);   // sur Serial Monitor , ça affiche la touche enfoncé.
  }
}