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
 * outputEventMessage - Prints event message to file.
 * inputEventMessage - Reads event message from file that was output to in previous function and prints to screen.
 * printAge - Prints out ages for all animals in each animal type array.
*/

#ifndef ZOO_HPP
#define ZOO_HPP

#include <random>
#include <fstream>
#include <iomanip>
#include "Animal.hpp"
#include "Turtle.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "UserAnimal.hpp"
#include "InputValidation.hpp"

class Zoo {
    //Number of animal class types
    const int animalTypes = 4;
private:
    Tiger **tigerArray = new Tiger *[10];
    Penguin **penguinArray = new Penguin *[10];
    Turtle **turtleArray = new Turtle *[10];
    UserAnimal **userAnimalArray = new UserAnimal *[10];

    //EC User Input Animal
    std::string userAnimalName = "";
    double inputFoodCostMult = 0.0;
    int inputAnimalCost = 0;
    int inputBirthRate = 0;
    int inputRevenue = 0;
    int foodType = 0;

    //Container sizes for animal array classes
    int tigerArraySize = 10, turtleArraySize = 10, penguinArraySize = 10, userAnimalArraySize = 10;
    int dayNumber = 0;
    double zooBalance = 0, zooProfit = 0, zooRevenue = 0, zooExpenditures = 0, animalPurchaseCost = 0;
    double revenueBoom = 0;
    int turtlePurchase = 0, penguinPurchase = 0, tigerPurchase = 0, userAnimalPurchase = 0;

    //Size of array for various animal array classes (indicated number of animal objects present in array)
    int totalTigers = 0, totalPenguins = 0, totalTurtles = 0, totalUserAnimals = 0;
    bool revBoomTF = false;


    //Initializes dynamic arrays to 10
    void initializeArrays();

    //Increase array size by 10
    void increaseArray();

    //Decrease turtle array size by 1
    void decreaseTurtleArray();

    //Decrease penguin array size by 1
    void decreasePenguinArray();

    //Decrease tiger array size by 1
    void decreaseTigerArray();

    //Decrease tiger array size by 1
    void decreaseUserAnimalArray();

    //Setup user animal class from user input
    void setupUserAnimal();

    //Add a purchased turtle to array
    void addUserAnimal(int, int);

    //Remove a turtle from array
    bool removeUserAnimal();

    //Add a purchased turtle to array
    void addTurtle(int, int);

    //Remove a turtle from array
    bool removeTurtle();

    //Add a purchased penguin to array
    void addPenguin(int, int);

    //Remove a penguin from array
    bool removePenguin();

    //Add a purchased tiger to array
    void addTiger(int, int);

    //Remove a tiger from array
    bool removeTiger();

    //Receives random integer value from randomInt function and picks random event
    void randomEvent();

    //Sickness occurs at the zoo! One animal dies
    void sicknessEvent();

    //Boost in revenue for the day
    void revenueBoomEvent();

    //One animal gives birth
    void birthEvent();

    //Day of play or one turn of play
    void dayTurn();

    //Increase age of animal
    void increaseAge();

    void printAge();

    //Pay maintenance costs of animals
    void payMaintenance();

    //Daily profit from animals
    void zooAnimalRevenue();

    //Print out zoo status such as number of animals, zoo funds available, and turn profit.
    void printZooStatus();

    //Add turtle babies
    void turtleBirth();

    //Add penguin babies
    void penguinBirth();

    //Add tiger babies
    void tigerBirth();

    //User added animal birth
    void userAnimalBirth();

    //Allows user to select feed type
    void feedType();

    //Returns random integer value between two values passed as parameters
    int randomInt(int, int);

    //Output message to file and read message from file. Parameter integer acts to inform which message
    //type is printed.
    void outputEventMsg(int, std::string);

    //Prints event message from text file to screen
    void inputEventMsg();

public:
    //Default zoo constructor that sets zoo balance sheet to 100000 and initializes array
    Zoo();

    //Destructor to deallocate data assigned to the dynamic animal arrays
    ~Zoo();

    //Setup zoo tycoon/simulation through user input
    void zooSetup();

    //Play zoo tycoon and run simulation
    bool zooPlay();

    //Menu to start or not start game
    int startMenu();

    //Menu to continue game or quit at end of turn
    int endMenu();
};

#endif //ZOO_HPP
