/* Justin Tromp
 * Date: 01/21/2019
 * Email: trompj@oregonstate.edu
 * Description: Zoo Class - This class is used in setting up and running the zoo tycoon simulation. It holds the
 * variables associated with the various dynamically allocated pointer arrays for each animal type. In addition,
 * the class contains variables for all financial aspects such as revenue, profit, expenditures, balance, and
 * revenue boom. There are also temporary/transition variables to hold values for animal purchases for use in
 * various functions, variables holding total number of animals in each array, and variables for the actual size
 * of each array. In addition to all of this there eis also a variable for each user animal input to create the user
 * animal to user input specifications, which is passed through constructor to the user animal class.
 * Member Functions:
 * zoo - Constructor sets zoo balance to 100,000
 * zoo destructor - Destructor removes dynamic array allocations to prevent memory leaks
 * initializeArrays - Initializes all dynamic arrays to 10 and purchases initial animals for zoo from zooSetup.
 * increaseArray - Increases array size by 10 if the number of animals exceeds capacity.
 * decrease(ANIMALTYPE)Array - These four functions act by deleting one animal from the array type, set that position
 * to nullptr, and also reduces the counter for total number of animals in that type by one.
 * setupUserAnimal - Prompts and accepts user input to setup the user animal.
 * add(ANIMALTYPE) - Four functions act by adding animals to array and accepting parameters for age of animal to be
 * added and number added.
 * remove(ANIMALTYPE) - Four functions act by checking to see if there is an animal to remove. If there is, returns
 * true and if there isn't returns false. If there is an animal to remove, calls decrease(ANIMALTYPE)Array to actually
 * remove it.
 * randomEvent - Randomly initiates a random event and calls the function that is randomly called by a series of integer
 * values.
 * sicknessEvent - Randomly selects animal type to die from sickness, if no animals are available, inform user of such
 * and nothing occurs.
 * revenueBoomEvent - If there are tigers in the zoo, random revenue bonus for each tiger. Inform user of such.
 * birthEvent - If there are any animals 3 days old or more, there is a birth event for number of babies relative
 * to that class.
 * dayTurn - Run through the events for each day. Resets counter variables as needed, allows user to select feed type,
 * increases animal age, pay maintenance fees for each animal, activate random event, calculate zoo revenue/profit/balance.
 * increaseAge - Increases age of all animals in zoo.
 * payMaintenance - Calculates feeding costs for all animals (maintenance for zoo). If cheap or expensive food types
 * are chosen, adjust calculation.
 * zooAnimalRevenue - Calculate revenue from all animals in zoo.
 * zooPlay - Performs dayTurn, prints the status of the zoo for user, checks for bankruptcy, asks user if they
 * would like to buy more animals, an then adds purchased animals through add(ANIMALTYPE) function. Returns true if
 * user goes bankrupt to end simulation and returns false if user still has funds.
 * startMenu - Allows user to select start or quit.
 * endMenu - Allows user to select to keep playing or quit.
 * printZooStatus - Prints out zoo information for user.
 * (ANIMALTYPE)Birth - Four functions add animals at zoo at age 0 by add(ANIMALTYPE) functions based on number of babies
 * born for that animal type.
 * feedType - Allows user to select for feed type at start of day. Cheap, generic, or expensive are the options.
 * randomInt - Takes parameters for lowest and highest integer value to be returned and returns a random value in that
 * range.
 * selects more animals than they can afford, they are re-prompted for a more suitable amount. Returns purchase price.
 * outputEventMessage - Prints event message to file.
 * inputEventMessage - Reads event message from file that was output to in previous function and prints to screen.
 * printAge - Prints out ages for all animals in each animal type array.
*/

#include <iostream>
#include "Zoo.hpp"
#include "Turtle.hpp"

//Default constructor sets zooBalance to 100,000 and initializes arrays.
Zoo::Zoo () {
    //Set starting zoo balance funds
    zooBalance = 100000;

    //Initialize the animal object arrays
    initializeArrays();
}

//Destructor to deallocate dynamically allocated memory
Zoo::~Zoo() {

    //Free dynamically allocated memory of animal array
    for (int count=0; count < turtleArraySize; count++) {
        delete turtleArray[count];
    }

    //Deallocate turtle array
    delete[] turtleArray;

    //Free dynamically allocated memory of animal array
    for (int count=0; count < penguinArraySize; count++) {
        delete penguinArray[count];
    }

    //Deallocate penguin array
    delete[] penguinArray;

    //Free dynamically allocated memory of animal array
    for (int count=0; count < tigerArraySize; count++) {
        delete tigerArray[count];
    }

    //Deallocate tiger array
    delete[] tigerArray;

    //Free dynamically allocated memory of animal array
    for (int count=0; count < userAnimalArraySize; count++) {
        delete userAnimalArray[count];
    }

    //Deallocate user animal array
    delete[] userAnimalArray;
}

//Initialize arrays to nullptr and adds initial animals from zoo setup.
void Zoo::initializeArrays() {
    //Initialize all turtleArray to nullptr;
    for (int count = 0; count < 10; count++) {
        turtleArray[count] = nullptr;
    }

    //Initialize all penguinArray to nullptr;
    for (int count = 0; count < 10; count++) {
        penguinArray[count] = nullptr;
    }

    //Initialize all tigerArray to nullptr;
    for (int count = 0; count < 10; count++) {
        tigerArray[count] = nullptr;
    }

    //Initialize all userArray to nullptr;
    for (int count = 0; count < 10; count++) {
        userAnimalArray[count] = nullptr;
    }
}

//Check array sizes against number of animals, if any animal counts exceed array size,
//then increase the size of that array by doubling previous size according to assignment.
void Zoo::increaseArray() {
    //If number of tigers exceeds size of array, then increase array size
    if (totalTigers >= tigerArraySize) {
        //Set new array size
        tigerArraySize = tigerArraySize * 2;
        //Create new pointer array that is 10 larger
        Tiger **newArray = new Tiger *[tigerArraySize];


        //Initialize all to nullptr;
        for (int count = 0; count < (tigerArraySize); count++) {
            newArray[count] = nullptr;
        }

        //Copy contents of old array to new turtle array
        for (int count = 0; count < totalTigers; count++) {
            newArray[count] = tigerArray[count];
        }

        delete [] tigerArray;

        //Set old array address equal to new array.
        tigerArray = newArray;
    }

    //If number of penguins exceeds size of array, then increase array size
    if (totalPenguins >= penguinArraySize) {
        //Set new array size
        penguinArraySize = penguinArraySize * 2;
        //Create new pointer array that is 10 larger
        Penguin **newArray = new Penguin *[penguinArraySize];


        //Initialize all to nullptr;
        for (int count = 0; count < (penguinArraySize); count++) {
            newArray[count] = nullptr;
        }

        //Copy contents of old array to new turtle array
        for (int count = 0; count < totalPenguins; count++) {
            newArray[count] = penguinArray[count];
        }

        delete [] penguinArray;

        //Set old array address equal to new array.
        penguinArray = newArray;
    }

    //If number of turtles exceeds size of array, then increase array size
    if (totalTurtles >= turtleArraySize) {
        //Set new array size
        turtleArraySize = turtleArraySize * 2;
        //Create new pointer array that is 10 larger
        Turtle **newArray = new Turtle *[turtleArraySize];


        //Initialize all to nullptr;
        for (int count = 0; count < (turtleArraySize); count++) {
            newArray[count] = nullptr;
        }

        //Copy contents of old array to new turtle array
        for (int count = 0; count < totalTurtles; count++) {
            newArray[count] = turtleArray[count];
        }

        delete [] turtleArray;

        //Set old array address equal to new array.
        turtleArray = newArray;
    }

    //If number of user animals exceeds size of array, then increase array size
    if (totalUserAnimals >= userAnimalArraySize) {
        //Set new array size
        userAnimalArraySize = userAnimalArraySize * 2;
        //Create new pointer array that is 10 larger
        UserAnimal **newArray = new UserAnimal *[userAnimalArraySize];


        //Initialize all to nullptr;
        for (int count = 0; count < (userAnimalArraySize); count++) {
            newArray[count] = nullptr;
        }

        //Copy contents of old array to new turtle array
        for (int count = 0; count < totalUserAnimals; count++) {
            newArray[count] = userAnimalArray[count];
        }

        delete [] userAnimalArray;

        //Set old array address equal to new array.
        userAnimalArray = newArray;
    }
}

//Decrease turtle array by one turtle object and frees the memory/sets to null.
void Zoo::decreaseTurtleArray() {
    //Decrease turtle size counter
    totalTurtles--;
    //Deallocate old turtle object
    delete turtleArray[totalTurtles];
    //Set to nullptr
    turtleArray[totalTurtles] = nullptr;
}

//Decrease penguin array size by 1 and free memory/set to null.
void Zoo::decreasePenguinArray() {
    //Decrease penguin size counter
    totalPenguins--;
    //Deallocate old penguin object
    delete penguinArray[totalPenguins];
    //Set to nullptr
    penguinArray[totalPenguins] = nullptr;
}

//Decrease tiger array size by 1
void Zoo::decreaseTigerArray() {
    //Decrease tiger size counter
    totalTigers--;
    //Deallocate old turtle object
    delete tigerArray[totalTigers];
    //Set to nullptr
    tigerArray[totalTigers] = nullptr;
}

//Decrease user animal array size by 1
void Zoo::decreaseUserAnimalArray() {
    //Decrease user animal size counter
    totalUserAnimals--;
    //Deallocate old user animal object
    delete userAnimalArray[totalUserAnimals];
    //Set to nullptr
    userAnimalArray[totalUserAnimals] = nullptr;
}

//Setup user animal class from user input
void Zoo::setupUserAnimal() {

    std::cout << "ADD YOUR OWN ANIMAL" << std::endl;
    std::cout << "What kind of animal would you like to see in the zoo? ";
    //Accept input from user
    getline(std::cin, userAnimalName);

    // Request food cost multiplier
    std::cout << "What food cost multiplier would you like to use (.1 - 100)? Base food cost is 10 dollars. ";
    inputFoodCostMult = validateInputDoubleRangePt1_100();

    //Request animal cost
    std::cout << "How much would you like the animal to cost? Enter an integer of 1 through 35000. ";
    inputAnimalCost = validateInputIntRange1_35000();

    //Request birth rate
    std::cout << "What would you like the birth rate to be? How many animals per birth event? 1 through 100. ";
    inputBirthRate = validateInputIntRange1_100();

    //Request revenue for animal
    std::cout << "How much revenue would you like each animal to bring in per day? Enter an integer from 1 through 30000. ";
    inputRevenue = validateInputIntRange1_30000();
    std::cout << std::endl;

    //Output user entry to user for validation
    std::cout << "You have entered:" << std::endl;
    std::cout << "Animal Type: " << userAnimalName << std::endl;
    std::cout << "Food Cost Multiplier: " << inputFoodCostMult << std::endl;
    std::cout << "Animal Cost: " << inputAnimalCost << std::endl;
    std::cout << "Birth Rate: " << inputBirthRate << std::endl;
    std::cout << "Revenue Per Animal: " << inputRevenue << std::endl;
}

//Add a purchased user animal class object to array
void Zoo::addUserAnimal(int age, int numAdded) {
    //Adds selected number of turtle to array
    for (int count = 0; count < numAdded; count++) {
        //If total turtles if larger than array size
        if (totalUserAnimals >= userAnimalArraySize) {
            increaseArray();
        }
        //If total user animals is less than array size, add user animal
        if (totalUserAnimals < userAnimalArraySize) {
            //Add user animal to user animal array
            userAnimalArray[totalUserAnimals] = new UserAnimal(age, userAnimalName, inputAnimalCost, inputFoodCostMult,
                    inputRevenue, inputBirthRate);

            //Check to make sure it is not a birth event, if it is, there is no cost.
            if (age != 0) {
                //Update purchase cost
                animalPurchaseCost += userAnimalArray[totalUserAnimals]->getAnimalCost();
            }

            //Increase total number of turtles in zoo
            totalUserAnimals++;
        }
    }
}

//Remove a user animal from array and return true if completed, false if no animals to remove
bool Zoo::removeUserAnimal() {
    //If no turtles are in zoo, return false
    if (totalUserAnimals == 0) {
        return false;
    }
    //If a turtle is in the zoo, remove and return true
    else {
        //Remove turtle from turtle array
        decreaseUserAnimalArray();

        return true;
    }
}

//Add a purchased turtle to array
void Zoo::addTurtle(int age, int numAdded) {
    //Adds selected number of turtle to array
    for (int count = 0; count < numAdded; count++) {

        //If total turtles if larger than array size
        if (totalTurtles >= turtleArraySize) {
            increaseArray();
        }

        //If total turtles is less than array size, then add turtle
        if (totalTurtles < turtleArraySize) {
            //Add turtle to turtle array
            turtleArray[totalTurtles] = new Turtle(age);

            //Check to make sure it is not a birth event, if it is, there is no cost.
            if (age != 0) {
                //Update animal cost variable
                animalPurchaseCost += turtleArray[(totalTurtles)]->getAnimalCost();
            }

            //Increase total number of turtles in zoo
            totalTurtles++;
        }
    }
}

//Remove a turtle from array and return true if completed, false if no animals to remove
bool Zoo::removeTurtle() {
    //If no turtles are in zoo, return false
    if (totalTurtles == 0) {
        return false;
    }
    //If a turtle is in the zoo, remove and return true
    else {
        //Remove turtle from turtle array
        decreaseTurtleArray();

        return true;
    }
}

//Add a purchased penguin to array
void Zoo::addPenguin(int age, int numAdded) {
    //Adds selected number of penguins to array
    for (int count = 0; count < numAdded; count++) {
        //If total penguins is larger than array size
        if (totalPenguins >= penguinArraySize) {
            increaseArray();
        }
        //If total penguins is less than array size, add penguin
        if (totalPenguins < penguinArraySize) {
            //Add penguin to penguin array
            penguinArray[(totalPenguins)] = new Penguin(age);

            //Check to make sure it is not a birth event, if it is, there is no cost.
            if (age != 0) {
                //Update purchase cost
                animalPurchaseCost += penguinArray[(totalPenguins)]->getAnimalCost();
            }

            //Increase total number of penguins in zoo
            totalPenguins++;
        }
    }
}

//Remove a penguin from array and return true if completed, false if no animals to remove
bool Zoo::removePenguin() {
    //If no penguins are in zoo, return false
    if (totalPenguins == 0) {
        return false;
    }
    //If a penguin is in the zoo, remove and return true
    else {
        //Remove turtle from turtle array
        decreasePenguinArray();

        return true;
    }
}

//Add a purchased tiger to array
void Zoo::addTiger(int age, int numAdded) {
    //Adds selected number of tigers to array
    for (int count = 0; count < numAdded; count++) {
        //If total tigers is larger than array size
        if (totalTigers >= tigerArraySize) {
            increaseArray();
        }
        //If total tigers is less than array size, add tiger
        if (totalTigers < tigerArraySize) {
            //Add penguin to penguin array
            tigerArray[(totalTigers)] = new Tiger(age);

            //Check to make sure it is not a birth event, if it is, there is no cost.
            if (age != 0) {
                //Update purchase cost
                animalPurchaseCost += tigerArray[(totalTigers)]->getAnimalCost();
            }

            //Increase total number of penguins in zoo
            totalTigers++;
        }
    }
}

//Remove a tiger from array and return true if completed, false if no animals to remove
bool Zoo::removeTiger() {
    //If no tigers are in zoo, return false
    if (totalTigers == 0) {
        return false;
    }

    //If a tiger is in the zoo, remove and return true
    else {
        //Remove turtle from turtle array
        decreaseTigerArray();

        return true;
    }
}

//Receives random integer value from randomInt function and picks random event
void Zoo::randomEvent() {
    int randomEventValue = 0;

    //User selected cheap food, increased chance of sickness
    if (foodType == 1) {
        randomEventValue = randomInt(1, 10);
    }

    //User selected generic food, regular rate of sickness
    if (foodType == 2) {
        randomEventValue = randomInt(1, 4);
    }

    //User selected expensive food, reduced chance of sickness
    if (foodType == 3) {
        randomEventValue = randomInt(1, 7);
    }

    //Sickness event - probability changes based on food selection
    if (randomEventValue == 1 || randomEventValue == 8 || randomEventValue == 9 || randomEventValue == 10) {
        sicknessEvent();
    }

    //Boom event - probability changes based on food selection
    else if (randomEventValue == 2 || randomEventValue == 5) {
        //Calculate boom event revenue and print applicable messages to file and screen
        revenueBoomEvent();
    }

    //Birth event - probability changes based on food selection
    else if (randomEventValue == 3 || randomEventValue == 6) {
        //Checks for birth possibility and outputs messages regarding birth
        birthEvent();
    }

    //No event, quiet day - probability changes based on food selection
    else if (randomEventValue == 4 || randomEventValue == 7){
        outputEventMsg(4, "");
        inputEventMsg();
    }
}

//Sickness occurs at the zoo! One animal dies as long as there is an animal.
void Zoo::sicknessEvent() {
    int animalDeathSelection = randomInt(1, animalTypes);
    bool animalDeath = false;
    int numAnimalsChecked = 0;

    //Loop through animals until a death occurs and while animals checked is less than
    //the number of types available. If no animals are in the zoo, nothing happens.
    while (!animalDeath && numAnimalsChecked < animalTypes) {
        if (animalDeathSelection == 1) {
            if (totalTurtles > 0) {
                //Output message to file and then read message and print to screen.
                outputEventMsg(1, "turtle");
                inputEventMsg();

                //If removeTurtle removes a turtle, returns true for animalDeath
                animalDeath = removeTurtle();

            //Else, add one to number of animals checked and change animal selection.
            } else {
                animalDeathSelection = 2;
                numAnimalsChecked++;
            }
        }

        if (animalDeathSelection == 2) {
            if (totalPenguins > 0) {
                //Output message to file and then read message and print to screen.
                outputEventMsg(1, "penguin");
                inputEventMsg();

                //If removePenguin removes a penguin, returns true for animalDeath
                animalDeath = removePenguin();

            //Else, add one to number of animals checked and change animal selection.
            } else {
                animalDeathSelection = 3;
                numAnimalsChecked++;
            }
        }

        if (animalDeathSelection == 3) {
            if (totalTigers > 0) {
                //Output message to file and then read message and print to screen.
                outputEventMsg(1, "tiger");
                inputEventMsg();

                //If removeTiger removes a tiger, returns true for animalDeath
                animalDeath = removeTiger();

            //Else, add one to number of animals checked and change animal selection.
            } else {
                animalDeathSelection = 4;
                numAnimalsChecked++;
            }
        }

        if (animalDeathSelection == 4) {
            if (totalUserAnimals > 0) {
                //Output message to file and then read message and print to screen.
                outputEventMsg(1, userAnimalName);
                inputEventMsg();

                //If removeUserAnimal removes a user animal, returns true for animalDeath
                animalDeath = removeUserAnimal();

            //Else, add one to number of animals checked and change animal selection.
            } else {
                animalDeathSelection = 1;
                numAnimalsChecked++;
            }
        }
    }

    //If no death occurred, then print message saying so.
    if (!animalDeath) {
        outputEventMsg(6, "");
        inputEventMsg();
    }

}

//Boost in revenue for the day
void Zoo::revenueBoomEvent() {
    //Calculate revenue boom amount
    revenueBoom = totalTigers * randomInt(250, 500);

    //Check to see if there are tigers, if so, set even to true. If not, set to false.
    if (totalTigers > 0) {
        //Set revenue boom event variable to true for output later
        revBoomTF = true;
    }
    //Else, set revBoomTF to false for later use. No revenue output for tiger boom.
    else {
        revBoomTF = false;
    }

    //If revenue boom event is true, output message 2. Otherwise, output message 7.
    if (revBoomTF == true) {
        //Output message to file and then read message and print to screen.
        outputEventMsg(2, "");
    }
    //Else, set output message to 7, which is no tigers in zoo for revenue boom.
    else {
        outputEventMsg(7, "");
    }

    //Print message to screen from .txt file
    inputEventMsg();
}

//Animal gives birth
void Zoo::birthEvent() {
    int babyAnimalSelection = randomInt(1, animalTypes);
    bool oldEnough = false;
    bool birthOccurred = false;
    int oldEnoughChecks = 0;

    //Loop while no animal old enough has been found or until all animals have been checked
    while (!oldEnough && oldEnoughChecks < animalTypes && !birthOccurred) {
        //Check to see if there is a turtle 3 days or older, if so it can have babies.
        if (babyAnimalSelection == 1) {
            //If a turtle is old enough, set oldEnough to true.
            for (int count = 0; count < totalTurtles; count++) {
                if ((turtleArray[count]->getAnimalAge()) >= 3) {
                    oldEnough = true;
                }
            }
            //If old enough, then turtle birth occurs.
            if (oldEnough) {
                //Initiate turtle birth
                turtleBirth();
                birthOccurred = true;

                //Output message to file and then read message and print to screen.
                outputEventMsg(3, "turtle");
                inputEventMsg();
            //If no turtles are old enough, set animal selection to 2 and add 1 to old enough checks.
            } else {
                babyAnimalSelection = 2;
                oldEnoughChecks++;
            }
        }

        //Check to see if there is a penguin 3 days or older, if so it can have babies.
        if (babyAnimalSelection == 2) {
            //If penguin is old enough, set oldEnough to true.
            for (int count = 0; count < totalPenguins; count++) {
                if ((penguinArray[count]->getAnimalAge()) >= 3) {
                    oldEnough = true;
                }
            }
            //If there is a penguin old enough, initiate penguin birth and set birth event to true.
            if (oldEnough) {
                penguinBirth();
                birthOccurred = true;

                //Output message to file and then read message and print to screen.
                outputEventMsg(3, "penguin");
                inputEventMsg();
            //If no penguins are old enough, set animal selection to 3 and add 1 to old enough checks.
            } else {
                babyAnimalSelection = 3;
                oldEnoughChecks++;
            }
        }

        //Check to see if there is a tiger 3 days or older, if so it can have babies.
        if (babyAnimalSelection == 3) {
            //If tiger is old enough, set old enough to true.
            for (int count = 0; count < totalTigers; count++) {
                if ((tigerArray[count]->getAnimalAge()) >= 3) {
                    oldEnough = true;
                }
            }
            //If there is a tiger old enough, initiate birth of tiger and set birth event to true.
            if (oldEnough) {
                tigerBirth();
                birthOccurred = true;

                //Output message to file and then read message and print to screen.
                outputEventMsg(3, "tiger");
                inputEventMsg();
            //If no tigers are old enough, set animal selection to 4 and add 1 to old enough checks.
            } else {
                babyAnimalSelection = 4;
                oldEnoughChecks++;
            }
        }

        //Check to see if there is a user animal 3 days or older, if so it can have babies.
        if (babyAnimalSelection == 4) {
            //Check to see if there is a user animal old enough and set old enough to true if so.
            for (int count = 0; count < totalUserAnimals; count++) {
                if ((userAnimalArray[count]->getAnimalAge()) >= 3) {
                    oldEnough = true;
                }
            }
            //If there is one old enough, there is a birth event and set birth occurred to true.
            if (oldEnough) {
                userAnimalBirth();
                birthOccurred = true;

                //Output message to file and then read message and print to screen.
                outputEventMsg(3, userAnimalName);
                inputEventMsg();
            //If no user animals are old enough, add one to old enough checks and set birth selection to 1.
            } else {
                babyAnimalSelection = 1;
                oldEnoughChecks++;
            }
        }
    }

    //If none are old enough, output message 5 for no animals old enough.
    if (!oldEnough) {
        outputEventMsg(5, "");
        inputEventMsg();
    }

}

//Sets up zoo simulation by prompting user for input of initial animal purchases and initializes arrays after
//user selections.
void Zoo::zooSetup() {
    //Output messages to user explaining basics of simulation.
    std::cout << "Welcome to zoo tycoon!" << std::endl;
    std::cout << "You are given a gift of 100,000 dollars to start out." << std::endl;
    std::cout << "You are entrusted to running a zoo of tigers, penguins," << std::endl;
    std::cout << "and turtles." << std::endl;
    std::cout << "Rules of the game:" << std::endl;
    std::cout << "Tigers cost: 10,000" << std::endl;
    std::cout << "Penguins cost: 1,000" << std::endl;
    std::cout << "Turtles cost: 100" << std::endl;
    std::cout << std::endl;

    //Setup user animal
    setupUserAnimal();

    //Prompt user for initial animal purchases
    std::cout << std::endl << "To start out, you must select at least one of each animal but"
        " no more than two." << std::endl;
    std::cout << "How many turtles would you like to purchase? ";
    turtlePurchase = validateInputIntRange1_2();
    std::cout << std::endl;
    std::cout << "How many penguins would you like to purchase? ";
    penguinPurchase = validateInputIntRange1_2();
    std::cout << std::endl;
    std::cout << "How many tigers would you like to purchase? ";
    tigerPurchase = validateInputIntRange1_2();
    std::cout << std::endl;
    std::cout << "How many " << userAnimalName << "s would you like to purchase? ";
    userAnimalPurchase = validateInputIntRange1_2();
    std::cout << std::endl;

    //Initialize the number of animals selected at start for purchase in each array
    addTurtle(1, turtlePurchase);
    addPenguin(1, penguinPurchase);
    addTiger(1, tigerPurchase);
    addUserAnimal(1, userAnimalPurchase);

    //Update zoo profit for first day
    zooProfit -= animalPurchaseCost;

    //Update zoo balance sheet for first day
    zooBalance += zooProfit;

    //Print zoo status for end of day. No events on first day of zoo, only input is cost of animals
    //and adding animals to array. No increase in age or feeding for day 0.
    printZooStatus();

    //Print animal ages to user for day 0
    printAge();
}

//Day of play or one turn of play
void Zoo::dayTurn() {
    //Reset zooProfit to zero for next day
    zooProfit = 0;
    //Reset revenueBoom if applicable to zero for next day
    revenueBoom = 0;
    //Reset zoo revenue
    zooRevenue = 0;
    //Reset zoo maintenance fees
    zooExpenditures = 0;
    //Update day counter
    dayNumber++;
    //Reset food type
    foodType = 0;
    //Reset animal purchase cost
    animalPurchaseCost = 0;

    //Inform user of start of day
    std::cout << std::endl << "START OF DAY " << dayNumber << std::endl;

    //Allow user to select food type
    feedType();

    //Increase age of all animals by 1
    increaseAge();

    //Pay feeding/maintenance costs for all animals
    payMaintenance();

    //Random event takes place at the zoo and prints applicable messages
    randomEvent();

    //Calculate zoo revenue before end of turn animal purchase
    zooAnimalRevenue();

    //Calculate profit for the day
    zooProfit = zooRevenue - zooExpenditures;

    //Add revenue boom if it was generated
    zooProfit += revenueBoom;
}

//Increase age of all animals
void Zoo::increaseAge() {
    //Increase age of turtles
    for (int count = 0; count < totalTurtles; count++) {
        turtleArray[count]->increaseAnimalAge();
    }

    //Increase age of penguins
    for (int count = 0; count < totalPenguins; count++) {
        penguinArray[count]->increaseAnimalAge();
    }

    //Increase age of tigers
    for (int count = 0; count < totalTigers; count++) {
        tigerArray[count]->increaseAnimalAge();
    }

    //Increase age of user animals
    for (int count = 0; count < totalUserAnimals; count++) {
        userAnimalArray[count]->increaseAnimalAge();
    }
}

//Print ages of all animals in zoo to screen at function call
void Zoo::printAge() {
    //Output information for user about output
    std::cout << std::endl << "Animal Ages (Animal #: Age in Days):" << std::endl;

    //Output age of turtles
    std::cout << "Turtles: ";
    //Loop through each animal of type in zoo
    for (int count = 0; count < totalTurtles; count++) {
        //Move to next line if 5 animals have already been printed on current line.
        if(((count % 5) == 0)) {
            std::cout << std::endl << std::setw(3) << std::right << (count + 1) << ":"
                      << std::setw(3) << std::right << std::fixed << turtleArray[count]->getAnimalAge() << " ";
        }
        //Prints animal ages without extra line
        else {
            std::cout << std::setw(3) << std::right << std::fixed << (count+1) << ":" <<
                std::setw(3) << std::right << std::fixed << turtleArray[count]->getAnimalAge() << " ";
        }
    }

    //Add line space
    std::cout << std::endl;

    //Output age of penguins
    std::cout << "Penguins: ";
    //Loop through each animal of type in zoo
    for (int count = 0; count < totalPenguins; count++) {
        //Move to next line if 5 animals have already been printed on current line.
        if(((count % 5) == 0)) {
            std::cout << std::endl << std::setw(3) << std::right << (count + 1) << ":"
                      << std::setw(3) << std::right << std::fixed << penguinArray[count]->getAnimalAge() << " ";
        }
        //Prints animal ages without extra line
        else {
            std::cout << std::setw(3) << std::right << std::fixed << (count+1) << ":" <<
                      std::setw(3) << std::right << std::fixed << penguinArray[count]->getAnimalAge() << " ";
        }
    }

    //Add line space
    std::cout << std::endl;

    //Output age of tigers
    std::cout << "Tigers: ";
    //Loop through each animal of type in zoo
    for (int count = 0; count < totalTigers; count++) {
        //Move to next line if 5 animals have already been printed on current line.
        if(((count % 5) == 0)) {
            std::cout << std::endl << std::setw(3) << std::right << (count + 1) << ":"
                      << std::setw(3) << std::right << std::fixed << tigerArray[count]->getAnimalAge() << " ";
        }
        //Prints animal ages without extra line
        else {
            std::cout << std::setw(3) << std::right << std::fixed << (count+1) << ":" <<
                      std::setw(3) << std::right << std::fixed << tigerArray[count]->getAnimalAge() << " ";
        }
    }

    //Add line space
    std::cout << std::endl;

    //Output age of user animals
    std::cout << userAnimalName << "s: ";
    //Loop through each animal of type in zoo
    for (int count = 0; count < totalUserAnimals; count++) {
        //Move to next line if 5 animals have already been printed on current line.
        if(((count % 5) == 0)) {
            std::cout << std::endl << std::setw(3) << std::right << (count + 1) << ":"
                      << std::setw(3) << std::right << std::fixed << userAnimalArray[count]->getAnimalAge() << " ";
        }
        //Prints animal ages without extra line
        else {
            std::cout << std::setw(3) << std::right << std::fixed << (count+1) << ":" <<
                      std::setw(3) << std::right << std::fixed << userAnimalArray[count]->getAnimalAge() << " ";
        }
    }

    //Add line space
    std::cout << std::endl;
}

//Pay maintenance costs of animals
void Zoo::payMaintenance() {
    //Pay maintenance cost of turtles
    for (int count = 0; count < totalTurtles; count++) {
        zooExpenditures += turtleArray[count]->getFoodCost();
    }

    //Pay maintenance cost of penguins
    for (int count = 0; count < totalPenguins; count++) {
        zooExpenditures += penguinArray[count]->getFoodCost();
    }


    //Pay maintenance cost of tigers
    for (int count = 0; count < totalTigers; count++) {
        zooExpenditures += tigerArray[count]->getFoodCost();
    }

    //Pay maintenance cost of user animals
    for (int count = 0; count < totalUserAnimals; count++) {
        zooExpenditures += userAnimalArray[count]->getFoodCost();
    }

    //If cheap food is chosen at start of game, reduce cost by 50%
    if (foodType == 1) {
        zooExpenditures = zooExpenditures * .5;
    }

    //If expensive food is chosen at start of game, double cost of food.
    if (foodType == 3) {
        zooExpenditures = zooExpenditures * 2;
    }
}

//Daily profit from animals
void Zoo::zooAnimalRevenue() {
    //Calculate revenue of turtles
    for (int count = 0; count < totalTurtles; count++) {
        zooRevenue += turtleArray[count]->getAnimalRevenue();
    }

    //Calculate revenue of penguins
    for (int count = 0; count < totalPenguins; count++) {
        zooRevenue += penguinArray[count]->getAnimalRevenue();
    }

    //Calculate revenue of tigers
    for (int count = 0; count < totalTigers; count++) {
        zooRevenue += tigerArray[count]->getAnimalRevenue();
    }

    //Calculate revenue of user animals
    for (int count = 0; count < totalUserAnimals; count++) {
        zooRevenue += userAnimalArray[count]->getAnimalRevenue();
    }
}

//Zoo play function calls dayTurn to handle essentials of daily tasks such as feeding, increase age, etc...
//Once dayTurn is over, asks user if they would like to finish day by buying 1 animal of one animal type.
//If they do, purchase animal at 3 days old and adjust profit based on purchase cost. Once profit is adjusted
//the function will adjust the zoo balance and check balance of zoo to ensure it is not negative. If it is negative
//the simulation will end and return true for bankruptcy while printing end of game messages. Otherwise, output
//status of zoo to user at very end of turn and return false for no bankruptcy.
bool Zoo::zooPlay() {
    //Perform day/turn functions
    dayTurn();

    //Ask user if they would like to purchase another animal at end of day.
    //Reset purchase variables to 0
    turtlePurchase = 0, penguinPurchase = 0, tigerPurchase = 0, userAnimalPurchase = 0;

    std::cout << std::endl << "Would you like to purchase an adult animal for your zoo?" << std::endl;
    std::cout << "You may select either 0 or 1 for each option, but you may only purchase 1." << std::endl;
    std::cout << "If you select 1 for an animal type, no other selections will be offered this turn." << std::endl;
    std::cout << "You have " << zooBalance << " dollars to spend." << std::endl;

    //Ask user if they would like to purchase turtle
    std::cout << std::endl << "How many turtles would you like to purchase (100 dollars each)? ";
    turtlePurchase = validateInputIntRange0_1();

    //If turtle was not purchased, allow user to buy penguin
    if (turtlePurchase == 0) {
        std::cout << std::endl << "How many penguins would you like to purchase (1000 dollars each)? ";
        penguinPurchase = validateInputIntRange0_1();
        std::cout << std::endl;
    }

    //If turtle and penguin was not purchased, allow user to buy tiger
    if (turtlePurchase == 0 && penguinPurchase == 0) {
        std::cout << "How many tigers would you like to purchase (10000 dollars each)? ";
        tigerPurchase = validateInputIntRange0_1();
        std::cout << std::endl;
    }

    //If turtle, penguin, and tiger was not purchased, allow user to buy user created animal
    if (turtlePurchase == 0 && penguinPurchase == 0 && tigerPurchase == 0) {
        std::cout << "How many " << userAnimalName << " would you like to purchase (" << inputAnimalCost
        << " dollars each)? ";
        userAnimalPurchase = validateInputIntRange0_1();
    }

    //Add adult animals purchased to the zoo. Only run add if user selects to purchase that animal type.
    if (turtlePurchase > 0) {
        addTurtle(3, turtlePurchase);
    }
    if (penguinPurchase > 0) {
        addPenguin(3, penguinPurchase);
    }
    if (tigerPurchase > 0) {
        addTiger(3, tigerPurchase);
    }
    if (userAnimalPurchase > 0) {
        addUserAnimal(3, userAnimalPurchase);
    }

    //Update zoo profit for day
    zooProfit -= animalPurchaseCost;

    //Update zoo balance sheet after all costs and revenues are finished.
    zooBalance += zooProfit;

    //End game if zooBalance is below 0 at end of day
    if (zooBalance < 0) {
        std::cout << std::endl << "YOU HAVE GONE BANKRUPT! PLEASE TRY AGAIN." << std::endl;

        //Display end of turn menu if bankruptcy has not occurred
        //Print end of game stats for user and output day number
        std::cout << "END OF GAME STATS" << std::endl;
        std::cout << "Days Elapsed: " << (dayNumber) << std::endl;
        printZooStatus();

        //Reset number of days
        dayNumber = 0;

        return true;
    }

    //Display end of day zoo status to user
    printZooStatus();

    //Display ages of all animals in zoo
    printAge();

    return false;
}

//Menu to start or not start game
int Zoo::startMenu () {
    int userSelection = 0;

    //Output inquiries and menu options to user
    std::cout << "Welcome to Zoo Tycoon! Please select from the following options to get started: \n";
    std::cout << "1. Start Zoo Tycoon \n";
    std::cout << "2. Quit" << std::endl;

    //Initiate menu validation function to accept user input and ensure validity.
    userSelection = validateInputMenu();

    return userSelection;
}

//Menu to continue game or quit at end of turn
int Zoo::endMenu () {
    int userSelection = 0;

    //Output inquiries and menu options to user
    std::cout << std::endl;
    std::cout << "Would you like to continue playing? \n";
    std::cout << "1. Keep playing Zoo Tycoon \n";
    std::cout << "2. Quit" << std::endl;

    //Initiate menu validation function to accept user input and ensure validity.
    userSelection = validateInputMenu();

    return userSelection;
}

//Print out zoo status such as number of animals, zoo funds available, and turn profit.
void Zoo::printZooStatus() {
    //Output day number
    std::cout << std::endl;
    std::cout << "END OF DAY " << dayNumber << std::endl;
    std::cout << std::endl << "ZOO STATUS:" << std::endl;
    std::cout << "Animals purchased today do not count towards revenue or food costs." << std::endl;
    std::cout << "If death occurred, the animal was fed prior to passing away." << std::endl;
    std::cout << "Turtles At End Of Day:  " << totalTurtles << " Turtles Purchased:  " << turtlePurchase << std::endl;
    std::cout << "Penguins At End Of Day: " << totalPenguins << " Penguins Purchased: " << penguinPurchase << std::endl;
    std::cout << "Tigers At End Of Day:   " << totalTigers << " Tigers Purchased:   " << tigerPurchase << std::endl;
    std::cout << userAnimalName << "s At End Of Day:   " << totalUserAnimals << " " << userAnimalName
        << "s Purchased:   " << userAnimalPurchase << std::endl;
    std::cout << "Zoo Food Cost: " << std::setprecision(2) << std::fixed << zooExpenditures << std::endl;
    std::cout << "Zoo Animal Purchase Cost: " << animalPurchaseCost << std::endl;
    std::cout << "Zoo Revenue: " << zooRevenue << std::endl;
    if (revBoomTF) {
        std::cout << "Revenue Boom Occurred: " << revenueBoom << std::endl;
        revBoomTF = false;
    }
    std::cout << "Zoo Profit: " << zooProfit << std::endl;
    std::cout << "Available Funds: " << zooBalance << std::endl;
}

//Add turtle babies at 0 days old
void Zoo::turtleBirth() {
    addTurtle(0, (turtleArray[(totalTurtles-1)]->getNumberBabies()));
}

//Add penguin babies at 0 days old
void Zoo::penguinBirth() {
    addPenguin(0, (penguinArray[(totalPenguins-1)]->getNumberBabies()));
}

//Add tiger babies at 0 days old
void Zoo::tigerBirth() {
    addTiger(0, (tigerArray[(totalTigers-1)]->getNumberBabies()));
}

//Add user animal babies at 0 days old
void Zoo::userAnimalBirth() {
    addUserAnimal(0, (userAnimalArray[(totalUserAnimals-1)]->getNumberBabies()));
}

//Allows user to select feed type
void Zoo::feedType() {
    std::cout << "\nYou have the option to select which kind of food to use for the day." << std::endl;
    std::cout << "1. Cheap - Food costs half as much, but sickness is twice as likely to occur today." << std::endl;
    std::cout << "2. Generic - Food costs the base amount and sickness occurs normally." << std::endl;
    std::cout << "3. Expensive - Food costs twice as much but sickness is half as likely to occur today." << std::endl;
    foodType = validateInputIntRange1_3();
}

//Returns random integer value between two values passed as parameters
int Zoo::randomInt(int minVal, int maxVal) {
    //Obtain seed for random number engine
    std::random_device randomNumDevice;

    //Mersenne_twister_engine seeded with rd
    std::mt19937 generateNum(randomNumDevice());
    std::uniform_int_distribution<> dis(minVal, maxVal);

    return dis(generateNum);
}

//Output message to file and read message from file. msgType 1 = death event, 2 = zoo boom event,
//3 = birth event and 4 = quiet day
void Zoo::outputEventMsg(int msgType, std::string animalType) {
    std::ofstream outputFile;

    //Open zoo_tycoon.txt, if it cannot be opened then inform user of this
    outputFile.open("zoo_tycoon.txt");
    if (!outputFile) {
        std::cout << "zoo_tycoon.txt could not be opened for output!" << std::endl;
    }

    //Output zoo event messages to zoo_tycoon.txt
    else if (msgType == 1) {
        outputFile << "There was a sickness at the zoo and one of your animals did not recover! One " <<
            animalType << " has died." << std::endl;
    }

    //Message type 2 = zoo boom, extra money for tigers
    else if (msgType == 2) {
        outputFile << "Today is National Tiger Day! Tigers generate extra money today! You made: " <<
            (revenueBoom/totalTigers) << " extra dollars for each tiger you own!" << std::endl;
    }

    //If msgType = 3, there was a birth at the zoo
    else if (msgType == 3) {
        outputFile << "One of the " << animalType << "s gave birth today at the zoo!" << std::endl;
    }

    //Message type 4 = quiet day at the zoo, so nothing occurs
    else if (msgType == 4) {
        outputFile << "Today was a quiet day at the zoo. Nothing exciting to report today." << std::endl;
    }

    //If msgType = 5, there was a birth at the zoo but no animals were old enough.
    else if (msgType == 5) {
        outputFile << "None of the animals were old enough to have babies. Just another quiet day at"
            " the zoo." << std::endl;
    }

    //If msgType = 6, there was a sickness but there were no animals in the zoo yet the zoo is not bankrupt
    else if (msgType == 6) {
        outputFile << "There was a sickness running rampant in a nearby zoo! 'Luckily' you don't have any animals."
            << std::endl;
    }

    //Message type 7 = zoo boom, extra money for tigers but no tigers in the zoo!
    else if (msgType == 7) {
        outputFile << "Today is National Tiger Day! Tigers generate extra money today! Unfortunately, you have "
                      "no tigers." << std::endl;
    }

    //If output file is open, close it
    if (outputFile) {
        //Close output file
        outputFile.close();
    }

}

//Prints event message from text file to screen
void Zoo::inputEventMsg() {
    std::ifstream inputFile;

    //Open input file
    inputFile.open("zoo_tycoon.txt");

    if (!inputFile) {
        std::cout << "zoo_tycoon.txt could not be opened for input!" << std::endl;
    }

    else {
        //Initialize/declare variable to print zoo event messages to screen from zoo_tycoon.txt
        std::string stringRead = "";

        //Read paragraph in text file zoo_tycoon.txt and print to screen
        getline(inputFile, stringRead);

        //Print out event header
        std::cout << std::endl << "EVENT NEWS: ";

        //Print read line to screen
        std::cout << stringRead << std::endl;

        //Close input file
        inputFile.close();
    }
}