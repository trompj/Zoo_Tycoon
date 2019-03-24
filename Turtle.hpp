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

#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle : public Animal {
public:
    //Default constructor to create turtle object
    Turtle();
    //Constructor for turtle class to set age and other default values for object
    Turtle(int);
};


#endif //TURTLE_HPP
