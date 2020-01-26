//Utilities c++ file - This holds various little snippet codes that will be called various times throughout cabinLib for the sake of cleanness.
#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <windows.h>
using namespace std;

//Void function to clear the screen and begin new scenes with a new view
void changeScene(){
    system("cls"); //Need to find alternates for the other systems as well.
    cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
    cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n";
}

//Clear function to cleanly ensure there are no errors with the cin entries
void Clear(){
    cin.clear();
    cin.sync();
}

//Ascii art used for the creature.
void Art(){
    cout << R"(                 ,     ,  ._  ,
                _.MMmm.mMm_Mm.MMm_:mMMmmm.._  .
           _ .-mmMMMMMMMMMMMMm:MMm:MMMMMMMMMm._
            `-.mm.MMMMMMM:MMMMMMMmmMMMMMMMMMmm._
         _.mMMMMMmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"~.
          .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm._
         _.MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm._
      ..mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmmm.
     _.mmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm.
      _.MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm_
  .mmMMMMMMMMMMMMMMMMMMMMMMMM' `MMMMMMMMMMMMMMMMMMMMMMm,
 _.-' _.mMMMMMMMMMMMMMMMMMMM'      `MMMMMMMMMMMMMMMM""`
  _,MMMmMMMMMMMMMMMMMMMM'            `MMMMMMMMMMMMMMmm.
    _.-'MMMMMMMMMMMMMMM.'""`.    ,'""`.MMMMMMMMMMMMMMMM.
   .mmMMMMMMMMMMMMMMMM' <(o)>`  '<(o)>` MMMMMMMMMMMMMMMm.
      .MMMMMMMMMMMMMMM                 'MMMMMMMMMMMMMMM:
   ,MMMmMMMMMMMMMMMMM'                 `MMMMMMMMMMMMmm.
  ,ME:MMMMMMMMMMMMMM_6       -  -       7_MMMMMMMMM:Mm_
  !M:MmmMMMMMMMMMMMMML_                _JMMMMMMMMMm:MMm.
  '':mMMMMMMMMMMMMMMMM\     ______     /dMMMMMMMMMMM:'Mm.
   ':MMM:MMMMMMMMMMMMMM\    `.__.'    /MMMMMM:MMMMMMm: `
  .M:MMM:MMMMMMMMMMMMMMM`.          ,'MMMMMMM:MMMMMMMm
    .Mm:mMMMMMMMMMMMMMMM| `.      .' |MMMMMMm:.MMMMM.
   .Mm:mMMMMMMMMMMMMMMMM|   `----':: |MMMMMMMmm`MMMMMm.
     !:mMMMMMMMMMMMMMMMM|      ::::. |MMMMMMMMMMM``mMm.
       !MMMMMMMMM'MMMMMM|      .:::. |MMMMMMMMMMMMM.._
       MMMMMMMMM'MMMM'M/       ::::'  \MMMMMMMMMMMMMMm,
      .mMMMMMMM'MMMM'MMm.       '     .`".MMMMMMMMMMMMm.
       !!JmMMM'MMM' `M:.      ,  ,     .. M.".MMMMMMMMm.
        FMMMMMm.`M   M..              .. `Mm   `"".MMMmm.
        MMMM'    M      ..           ..    `M      MM`.M!
        Mm'               ..        ..      M      M'   \
        /                                                \dp)";
}

//Cabin ascii art used when successfully leaving the cabin and completing the game.
void cabinArt(){
    cout << R"(                           
                     *     (  (               *  /\
                            (_)          *      /  \  /\
                    ________[_]________      /\/    \/  \
    *      /\      /\        ______    \    /   /\/\  /\/\
          /  \    //_\       \    /\    \  /\/\/    \/    \
   /\    / /\/\  //___\       \__/  \    \/
  /  \  /\/    \//_____\       \ |[]|     \
 /\/\/\/       //_______\       \|__|      \    *
/      \      /XXXXXXXXXX\                  \
  *     \    /_I_II  I__I_\__________________\ *
               I_I|  I__I_____[]_|_[]_____I *       *
        *      I_II  I__I_____[]_|_[]_____I
    *          I II__I  I     XXXXXXX     I     *
            ~~~~~"   "~~~~~~~~~~~~~~~~~~~~~~~~)";
}