/* Justin Tromp
 * Date: 01/21/2019
 * Email: trompj@oregonstate.edu
 * Description: Penguin class is child class of animal class. Class is set up to allow use of penguins
 * for zoo simulation game. Base variables used are the same as animal class and include animalCost, foodCost,
 * animalRevenue, numberBabies, and animalAge.
 * Member functions:
 * default penguin constructor - Default constructor sets up penguin animal object based on default values.
 * penguin constructor - Sets values for penguin class and takes age as parameter to set age of object being added.
*/

#include "Penguin.hpp"

//Constructor for penguin class to set age and other default values for object
Penguin::Penguin(int inputAge) : Animal(inputAge){
    animalCost = 1000;
    foodCost = baseFoodCost;
    animalRevenue = .1 * animalCost;
    numberBabies = 5;
}

//Default constructor for penguin class
Penguin::Penguin() : Animal(){}

