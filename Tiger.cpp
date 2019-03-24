/* Justin Tromp
 * Date: 01/21/2019
 * Email: trompj@oregonstate.edu
 * Description: Tiger class is child class of animal class. Class is set up to allow use of tiger
 * for zoo simulation game. Base variables used are the same as animal class and include animalCost, foodCost,
 * animalRevenue, numberBabies, and animalAge.
 * Member functions:
 * default tiger constructor - Default constructor sets up tiger animal object based on default values.
 * tiger constructor - Sets values for tiger class and takes age as parameter to set age of object being added.
*/

#include "Tiger.hpp"

//Default constructor for tiger class
Tiger::Tiger() : Animal() {}

//Constructor for tiger class to set age and other default values for object
Tiger::Tiger(int inputAge) : Animal(inputAge) {
    animalCost = 10000;
    foodCost = baseFoodCost * 5;
    animalRevenue = .2 * animalCost;
    numberBabies = 1;
}