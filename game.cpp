//The cabin - C++ Final Project (1st year - 1st Semester) - This is the one you run
#include <iostream>
#include "cabinLib.h"
#include <cstdlib>
#include <windows.h>
using namespace std;

//Intializes each scene, The scenes are explained further and how to get to the next scene.
int main(){
    bool startGame;
    //Plays the beginning scene for 6 rotations
    for(int i=1;i<=5;i++){
        beginScene();
    }
    //Plays the intial warning and begins the game 
    startGame = introWarning(startGame);
    if(startGame = true){
        Scene1();
    }
    return 0;
}