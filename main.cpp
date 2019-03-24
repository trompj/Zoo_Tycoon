/* Justin Tromp
 * Date: 01/21/2019
 * Description: Runs zoo simulation by declaring zoo object. From zoo object, start menu is shown to user which allows
 * user to start game or quit. If user selects to quit, main ends. If user selects to start, then zooSetup function is
 * called and game will run from zooPlay in a loop until the user either goes bankrupt or selects to quit at end of turn
 * from endMenu function.
*/

#include <iostream>
#include "Zoo.hpp"

int main() {
    int menuSelection = 0;
    Zoo ZooSimulation;

    menuSelection = ZooSimulation.startMenu();

    //If user selects to start simulation, start zoo setup
    if (menuSelection == 1) {
        //Setup zoo simulation
        ZooSimulation.zooSetup();
    }

    bool userBankrupt = false;
    //Loop while user selects to continue game and while user has not lost due to bankruptcy
    while (menuSelection == 1 && !userBankrupt) {

        //Start zoo simulation
        userBankrupt = ZooSimulation.zooPlay();

        if (userBankrupt == false) {
            //Allow user to select from end menu
            menuSelection = ZooSimulation.endMenu();
        }
    }

    return 0;
}