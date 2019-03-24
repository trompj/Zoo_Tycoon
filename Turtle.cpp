/* Justin Tromp
 * Date: 01/21/2019
 * Email: trompj@oregonstate.edu
 * Description: Turtle class is child class of animal class. Class is set up to allow use of turtles
 * for zoo simulation game. Base variables used are the same as animal class and include animalCost, foodCost,
 * animalRevenue, numberBabies, and animalAge.
 * Member functions:
 * default turtle constructor - Default constructor sets up turtle animal object based on default values.
 * turtle constructor - Sets values for turtle class and takes age as parameter to set age of object being added.
*/

#include "Turtle.hpp"

//Default constructor to create turtle object
Turtle::Turtle() : Animal() {}

//Constructor for turtle class to set age and other default values for object
Turtle::Turtle(int inputAge) : Animal(inputAge) {
    animalCost = 100;
    foodCost = baseFoodCost * .5;
    animalRevenue = .05 * animalCost;
    numberBabies = 10;
}