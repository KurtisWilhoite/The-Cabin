//cabinLib c++ file - This contains only the scenes and gameplay mechanics.
#include <iostream>
#include <cstdlib>
#include <iterator> //Used on checking array size for looping within the search function.
#include <windows.h> //Makes system pauses and sleep functional
#include <string> //Allows string returning functions which is vital to this game.
#include <array> //Measuring Array size for array searching function.
#include <algorithm> //This allows the "Options" function to do find(); to find if a choice matches from a preexisting array
#include "Utilities.h" //Personal utilities cpp for smaller things that help things run in the background
using namespace std;

//Function Declarations where needed, otherwise they're declared before usage.
void Scene1();
void Scene2();
void Scene3();
void Scene4();
void Scene4Skip();
void Scene5();

//This will display the player's inventory apon asking, any time the player asks for it. It works on a check system, the variable "invstatus" is increased in all scenes.
void inventory(int invStatus){
    if(invStatus == 1){
        Clear();
        changeScene();
        cout <<"\nInventory: ";
        cout <<"\nYou currently have no items.\n";
        system("pause");
        Scene1();
    } else if(invStatus == 3){
        Clear();
        changeScene();
        cout <<"\nInventory: ";
        cout <<"\n> Hacksaw - 'It is well suited for sawing through iron'\n";
        system("pause");
        Scene2();
    } else if(invStatus == 5){
        Clear();
        changeScene();
        cout << "\nInventory :";
        cout << "\n> Hacksaw - 'It is well suited for sawing through iron'\n";
        system("pause");
        Scene3();
    } else if (invStatus == 7){
        Clear();
        changeScene();
        cout << "\nInventory:";
        cout << "\n> Hacksaw - 'It is well suited for sawing through iron'\n";
        cout << "\n> Storm Lantern - 'It very worn, seems about half full.'\n";
        system("pause");
        Scene4Skip();
    }
}

//All this does is simplify the find(); function for cleaner searches
int Search(string array[],int aSize, string Choice){
    bool found = false;

    for(int i = 0; i < aSize; i++){
        if(Choice == array[i]){
            found = true;
        }
    }
    if(found == true){
        return 1;
    } else {
        return -1;
    }
}

//Beginning animation (is done by looping down each line and placing a random * if it matches a random int.)
void beginScene(){
    int twinkleX;
    for(int i = 0; i < 10;i++){
        twinkleX = rand() % 50;
        for(int j = 0; j < 50;j++){
            if(j == twinkleX){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "\nThe Cabin - By Shane Wilhoite\n";
    cout << "\nArt by - Furtado H./David Palmer\n";
    for(int i = 0; i < 10;i++){
        twinkleX = rand() % 50;
        for(int j = 0; j < 50;j++){
            if(j == twinkleX){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    Sleep(1000);
    system("cls");
}

//Gameover scene that plays apon death, functions the same way the beginning scene does.
void gameoverScene(){
    int twinkleX;
    for(int i = 0; i < 10;i++){
        twinkleX = rand() % 50;
        for(int j = 0; j < 50;j++){
            if(j == twinkleX){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "\nGame Over\n";
    for(int i = 0; i < 10;i++){
        twinkleX = rand() % 50;
        for(int j = 0; j < 50;j++){
            if(j == twinkleX){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    Sleep(1000);
    system("cls");
}

//This is the same snowfall animation displayed earlier, but with an additional cabin ascii art displayed afterward.
void finalAnimation(){
    int twinkleX;
    for(int i = 0; i < 10;i++){
        twinkleX = rand() % 50;
        for(int j = 0; j < 50;j++){
            if(j == twinkleX){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "\nYou're now safe!\n";
    for(int i = 0; i < 10;i++){
        twinkleX = rand() % 50;
        for(int j = 0; j < 50;j++){
            if(j == twinkleX){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    cabinArt();
    Sleep(1000);
    system("cls");
}
//Intro Scene that describes how the game works and that it's currently only available for windows and to allow the player to increase the window size
bool introWarning(bool startGame){
    changeScene();
    startGame = false;
    string Enter;
    cout << "The game you're about to play is a choose your own adventure style horror game.";
    cout << "\nThis game is played similarly to older style, text-based adventure games.";
    cout << "\nThis means you will need to type out commands in order to perform certain tasks.";
    cout << "\nThings such as 'open door', 'talk to _', will need to be typed on the command line to continue.";
    cout << "\nYou can also check your inventory this way. Please configure your window size to fit both '*~*' borders.";
    cout << "\n\nSadly, this game currently only works on Windows machines due to needing to clear the screen, sorry!";
    cout << "\nThis is a horror game. It will be potentally gorey and abundant in over detailing, proceed at your own risk.";
    cout << "\nDo you wish to 'continue' your adventure?\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
    cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n";
    cin >> Enter;
    while(!(Enter == "continue"||Enter == "Continue")){
        cout << "\nSorry, you need to confirm you wish to 'continue'.";
        cout << "\nDo you wish to 'continue' your adventure?\n";
        cin >> Enter;
    }
    if(Enter == "continue"||Enter == "Continue"){
        startGame = true;
        cout << "\nThats the spirit!\n";
        Sleep(1000);
        return startGame;
    }
    return startGame;
}

//Gameover scene 1 - Happens if you mistakenly choose to saw off your own leg, rather than the iron cuffs.
void gameOver1(){
    changeScene();
    cout << "You grit your teeth as you saw foolishly saw through your own leg.\n";
    cout << "Blood pools on the ground and as you hit bone, you pass out due to the immense pain.\n";
    cout << "Your dying thoughts are of the saw. It was a hacksaw, perfectly capable of cutting through the iron cuffs.\n";
    cout << "\nYou died. Gameover.\n";
    system("Pause");

    system("cls");
    for(int i=1;i<=5;i++){
            gameoverScene();
        }
}

//Gameover scene 2 - Happens if you chose to hide under the shabby bed or pile of pelts rather than the wardrobe/door.
void gameOver2(){
    changeScene();
    cout << "\nYou hide. (Stay silent, Don't type...)\n";
    Sleep(5000);
    cout << "\nYou hear footsteps walking feverishly infront of you.\n";
    Sleep(5000);
    cout << "\nYou hear ragid breathing...\n";
    Sleep(5000);
    cout << "\nThe creature bends to see you eye to eye!\n";
    Sleep(5000);
    Art();
    cout << "\nYou died. Gameover.\n";
    system("Pause");

    system("cls");
    for(int i=1;i<=5;i++){
            gameoverScene();
        }
}

//Gameover scene 3 - Happens if you chose to walk down the path rather than through the woods
void gameOver3(){
    changeScene();
    cout << "\nYou begin walking down the path. (Stay silent, Don't type...)\n";
    Sleep(5000);
    cout << "\nThe light is dim.\n";
    Sleep(5000);
    cout << "\nYour decide to turn on your light, it flickers.\n";
    Sleep(5000);
    cout << "\nThe light falls apon the snow, just on the edge of the light of your lantern...\n";
    Sleep(3000);
    Art();
    cout << "\nYou died. Gameover.\n";
    system("Pause");

    system("cls");
    for(int i=1;i<=5;i++){
            gameoverScene();
        }
}

//This contains a list of options that will be referred back to during the first scene.
void Options1(string Choice, int invStatus){
    Clear();
    //All of these strings have v beforehand to indicate that they're a variable and not to mix them with other variables.
    string vInventory[8] = {"inventory","Inventory", "Inv", "inv", "Open Inventory", "open inventory", "Open inventory", "open Inventory"};
    string vStand[12] = {"Stand up", "Stand", "stand", "stand up", "stand Up", "get up", "Get up", "get Up", "leave bed", "Leave bed", "get out of bed", "Get out of bed"};

    if(Search(vInventory,sizeof(vInventory) / sizeof(vInventory[0]),Choice) != -1){
        Clear();
        inventory(invStatus);
    } else if(Search(vStand,sizeof(vStand) / sizeof(vStand[0]),Choice) != -1){
        Clear();
        Scene2();
    } else {
        Clear();
        cout << "\nPhrase not understood, please try again.\n";
        char Choice[100];
        cin.getline(Choice,100);
        Options1(Choice,invStatus);
    }
}

//Opening Scene - In the cabin, on the bed.
void Scene1(){
    Clear();
    changeScene();
    char Choice[100];
    
    cout << "You awaken to the smell of wood. In a groggy state, you sit up in your bed.\n";
    cout << "The bed feels as though it's rougher than normal and more coarse. You feel beneath you to\n";
    cout << "realize the bed is made of straw. The smell of wood makes more sense as you open your eyes to\n";
    cout << "find that you're within a cabin. The wind howls outside and you shiver slightly from the blizzard\n";
    cout << "that seems to be well under-way. The room is dimly lit by a wood stove at the opposite end of the room.\n\n";
    cout << "Your head seems to throb with the effort of sitting up. Theres a metallic taste in your mouth. \nWhat do you do?\n";

    //This line progresses by 1 num each time an item is received and sent up the line in order to be able to notify the user what items they have currently in their inv.
    int invStatus = 1;
    cin.getline(Choice,100);
    Options1(Choice, invStatus);
}

//This contains a list of options that will be referred back to during the second scene.
void Options2(string Choice, int invStatus){
    Clear();
    //All of these strings have v beforehand to indicate that they're a variable and not to mix them with other variables.
    string vInventory[8] = {"inventory","Inventory", "Inv", "inv", "Open Inventory", "open inventory", "Open inventory", "open Inventory"};
    string vVague[6] = {"Cut", "cut", "chop", "Chop", "saw", "Saw"};
    string vLeg[] = {"Cut leg", "cut leg", "chop leg", "Chop leg", "saw leg", "Saw leg", "Leg", "leg", "Cut off leg", "cut off leg", "saw off leg", "Saw off leg", "Chop off leg", "chop off leg"};
    string vChain[]= {"Cut chain", "cut chain", "chop chain", "Chop chain", "saw chain", "Saw chain", "chain", "Chain", "saw cuffs", "Saw cuffs", "cut cuffs", "chains", "Chains", "Saw chains", "saw chains", "cut chains", "Cut chains"};

    if(Search(vInventory,sizeof(vInventory) / sizeof(vInventory[0]),Choice) != -1){
        Clear();
        inventory(invStatus);
    } else if(Search(vVague,sizeof(vVague) / sizeof(vVague[0]),Choice) != -1){
        Clear();
        cout << "\nYou have to specify what you wish to saw.\n";
        char Choice[100];
        cin.getline(Choice,100);
        Options2(Choice,invStatus);
    } else if(Search(vLeg,sizeof(vLeg) / sizeof(vLeg[0]),Choice) != -1){
        Clear();
        gameOver1();
    } else if(Search(vChain,sizeof(vChain) / sizeof(vChain[0]),Choice) != -1){
        Clear();
        Scene3();
    } else {
        Clear();
        cout << "\nPhrase not understood, please try again.\n";
        char Choice[100];
        cin.getline(Choice,100);
        Options2(Choice, invStatus);
    }
}

//Scene 2 - Confusion and the Saw
void Scene2(){
    Clear();
    changeScene();
    
    char Choice[100];
    cout << "You attempt to stand, hearing the rattle of chains along the way. You roughly fall.\n";
    cout << "Your ankles are extremely sore now, looking down you find your ankles have been chained to the bed.\n";
    cout << "You begin to panic, hyperventlating. Your mind races.\n\n";
    cout << "After a few minutes, you calm yourself. You focus on the room around you.\n";
    cout << "You feel an immense sense of urgency, not sure how you came into this predicament.\n";
    cout << "You notice a saw laying on a table near the bed. It appears within reach.\n\n";
    cout << "You grab the saw. What do you do next?\n";

    int invStatus = 3;
    cin.getline(Choice,100);
    Options2(Choice,invStatus);
}

//This contains a list of options that will be referred back to during the third scene.
void Options3(string Choice, int invStatus){
    Clear();
    //All of these strings have v beforehand to indicate that they're a variable and not to mix them with other variables.
    string vInventory[] = {"inventory","Inventory", "Inv", "inv", "Open Inventory", "open inventory", "Open inventory", "open Inventory"};
    string vBed[] = {"Bed", "bed", "Under bed", "under bed", "hide under bed", "Hide under bed"};
    string vWardrobe[] = {"closet", "wardrobe", "cabinet", "Cabinet", "Wardrobe", "Closet", "Hide in cabinet", "Hide cabinet", "hide cabinet", "hide wardrobe", "hide closet"};
    string vPelts[] = {"Under pelts", "under pelts", "pelts", "pelt", "Pelts", "Pelt", "furs", "under furs", "fur", "under fur", "lay under pelts", "Lay under pelts", "lay under furs", "Lay under furs"};
    string vDoor[] = {"Behind door", "door", "behind door", "Door", "Go behind door", "go behind door"};

    if(Search(vInventory,sizeof(vInventory) / sizeof(vInventory[0]),Choice) != -1){
        Clear();
        inventory(invStatus);
    } else if(Search(vBed,sizeof(vBed) / sizeof(vBed[0]),Choice) != -1){
        Clear();
        gameOver2();
    } else if(Search(vWardrobe,sizeof(vWardrobe) / sizeof(vWardrobe[0]),Choice) != -1){
        Clear();
        Scene4();
    } else if(Search(vPelts,sizeof(vPelts) / sizeof(vPelts[0]),Choice) != -1){
        Clear();
        gameOver2();
    } else if(Search(vDoor,sizeof(vDoor) / sizeof(vDoor[0]),Choice) != -1){
        Clear();
        Scene4();
    } else {
        Clear();
        cout << "\nPhrase not understood, please try again.\n";
        char Choice[100];
        cin.getline(Choice,100);
        Options3(Choice, invStatus);
    }
}

//Scene 3 - Hiding from the creature
void Scene3(){
    Clear();
    changeScene();

    char Choice[100];
    cout << "After around 5 minutes of sawing the cuffs, you saw through and free your ankles.\n";
    cout << "You rub your sore ankles, outside of some bruising and swelling, they seem fine and hold your weight.\n";
    cout << "\nYou get up to your feet and look around. The room contains a seemingly empty cabinet,\n";
    cout << "the bed you were chained to, a pile of old furs, the flickering furnace across the room,\n";
    cout << "and you notice a door!\n";
    cout << "\nYou walk to the door and notice the door handle turning before your hand. Where do you hide!?\n";

    int invStatus = 5;
    cin.getline(Choice,100);
    Options3(Choice,invStatus);
}

//This contains a list of options that will be referred back to during the second scene.
void Options4(string Choice, int invStatus){
    Clear();
    //All of these strings have v beforehand to indicate that they're a variable and not to mix them with other variables.
    string vInventory[] = {"inventory","Inventory", "Inv", "inv", "Open Inventory", "open inventory", "Open inventory", "open Inventory"};
    string vBack[] = {"go back", "Go back", "Back", "backward", "back", "go to cabin", "Go to cabin", "Backward", "Go back to cabin", "go back to cabin", "back in cabin", "Back in cabin"};
    string vPath[] = {"Down path", "Path", "path", "go down path", "Go down path", "down path", "follow path", "Follow path", "go to path", "Go to path"};
    string vForest[] = {"woods", "Woods", "Forest", "forest", "into forest", "into woods", "through woods", "through forest", "go to forest", "enter forest", "Go to forest", "Enter forest", "enter woods", "go to woods", "Go to woods", "Enter woods"};

    if(Search(vInventory,sizeof(vInventory) / sizeof(vInventory[0]),Choice) != -1){
        Clear();
        inventory(invStatus);
    } else if(Search(vBack,sizeof(vBack) / sizeof(vBack[0]),Choice) != -1){
        Clear();
        cout << "\nYou shiver at the thought of heading back to the home of the creature.";
        char Choice[100];
        cin.getline(Choice,100);
        Options4(Choice,invStatus);
    } else if(Search(vPath,sizeof(vPath) / sizeof(vPath[0]),Choice) != -1){
        Clear();
        gameOver3();
    } else if(Search(vForest,sizeof(vForest) / sizeof(vForest[0]),Choice) != -1){
        Clear();
        Scene5();
    } else {
        Clear();
        cout << "\nPhrase not understood, please try again.\n";
        char Choice[100];
        cin.getline(Choice,100);
        Options4(Choice, invStatus);
    }
}

//Scene 4 - Escape scene
void Scene4(){
    Clear();
    changeScene();

    cout << "You hide. (Stay silent, Don't type...)\n";
    Sleep(5000);
    cout << "\nYou control your breathing to stay more quiet...\n";
    Sleep(5000);
    cout << "\nYou hear bare feet scuffling around. The creature screams viciously.\n";
    Sleep(5000);
    cout << "\nYou hear the footsteps charge out the door, slaming it behind itself.\n";
    Sleep(2000);
    cout << "\nYou wait 5 minutes and you hear nothing outside outside of the wind howling outside.\n";
    system("pause");
    Scene4Skip();
}

//Originally part of Scene 4 - Now seperate in order to skip the hiding cutscene if the player chooses to open their inventory.
void Scene4Skip(){
    Clear();
    changeScene();

    char Choice[100];
    cout << "You come out of your hiding place, the room is now completely pitch-black as the furnace\n";
    cout << "has gone out. Only dim shapes can be seen in the room. You walk towards the door.\n\n";
    cout << "You hit your foot on something hard that creates a loud noise of rusty metal. You catch yourself\n";
    cout << "just before hitting the ground. At your feet, you see an old storm lantern. Shaking it lightly\n";
    cout << "reveals its less than half full with oil. You peer out the door, but your captor's trail has been covered\n";
    cout << "by the raging blizzard.\n";
    cout << "\nYou walk a short way out the door, the hard snow whipping your face, but it's better than being\n";
    cout << "inside that cabin. You eventually come to a wall of trees with a path. Where do you go?\n";

    int invStatus = 7;
    cin.getline(Choice,100);
    Options4(Choice,invStatus);
}

//Scene 5 - Finale after hiding in the woods
void Scene5(){
    Clear();
    changeScene();

    cout << "\nYou begin to walk through the woods (Cutscene, Don't type...)\n";
    Sleep(5000);
    cout << "\nJust as you enter the woods, you hear footsteps following the path to your right...\n";
    Sleep(2000);
    cout << "\nYou crouch quickly, close your eyes, and try to control your breathing...\n";
    Sleep(5000);
    cout << "\nCrunch..crunch...crunch....crunch.....The footsteps begin to gain distance.\n";
    Sleep(5000);
    cout << "\nYou wait, heartbeat racing. You wait long after the footsteps are heard going back into the house\n";
    cout << "You know the creature is back its home, as you can hear it thrashing about angrily.\n";
    system("pause");

    changeScene();
    cout << "As you walk, you come across a destroyed tent. You realize you can no longer feel your feet.\n";
    cout << "the tent is slashed and memories of being ambushed in your tent flashed through your mind,\n";
    cout << "as your remembering your attack, you find a map among the reckage. You find your position and the\n";
    cout << "nearest lodge. You put on your old, slightly torn winter clothing and continue on throughout\n";
    cout << "the night. By the time the sun is up, you're sleeping, safe and warm in the lodge as the police begin their investigation.\n";
    cout << "\nYou've survived the cabin!\n";
    system("pause");

    for(int i=1;i<=10;i++){
        finalAnimation();
    }
}