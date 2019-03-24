/* Justin Tromp
 * Date: 01/21/2019
 * Email: trompj@oregonstate.edu
 * Description: userAnimal class is child class of animal class. Class is set up to allow user to create an animal
 * for zoo simulation game. Base variables used are the same as animal class and include animalCost, foodCost,
 * animalRevenue, numberBabies, animalAge, and one additional variable called animalType. animalType allows user to
 * input name of animal and that input is stored in object.
 * Member functions:
 * userAnimal - Constructor sets up user animal object by parameters passed from user input.
 * setAnimalType - Sets the animalType to the string input by user.
 * setAnimalAge - Sets animal age value
 * setAnimalCost - Sets animal cost value.
 * setAnimalRevenue - Sets revenue generated by each animal.
 * setFoodCost - Sets food cost based on base food cost * the input food cost multiplier from user.
 * setAnimalBirthRate - Sets the birth rate for animal.
 * NOTE: These could be combined with animal class for overall functionality, however these functions are not used for
 * any of the other child classes as they are used to set the values, whereas the other child class values are
 * pre-determined.
*/

#include "UserAnimal.hpp"

//Default constructor to create user animal object
UserAnimal::UserAnimal() : Animal() {}

//Constructor for tiger class to set age and all other object values based on user input in zoo class
UserAnimal::UserAnimal(int inputAge, std::string inputAnimalType, int inputCost, double inputFoodCostMultiplier, int inputRevenue,
                       int inputBirthRate) : Animal(inputAge) {
    setAnimalType(inputAnimalType);
    setAnimalCost(inputCost);
    setFoodCost(inputFoodCostMultiplier);
    setAnimalRevenue(inputRevenue);
    setAnimalBirthRate(inputBirthRate);
}

//Set animal type based on user input
void UserAnimal::setAnimalType(std::string inputAnimalType) {
    animalType = inputAnimalType;
}

//Set animal cost based on user input
void UserAnimal::setAnimalCost(int inputCost) {
    animalCost = inputCost;
}

//Set animal food cost based on user input
void UserAnimal::setFoodCost(double inputFoodCost) {
    foodCost = inputFoodCost * baseFoodCost;
}

//Set animal revenue based on user input
void UserAnimal::setAnimalRevenue(int inputAnimalRevenue) {
    animalRevenue = inputAnimalRevenue;
}

//Set birth rate based on user input
void UserAnimal::setAnimalBirthRate(int inputBirthRate) {
    numberBabies = inputBirthRate;
}
