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

#ifndef TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"

class Tiger : public Animal {
public:
    //Default constructor for tiger class
    Tiger();

    //Constructor for tiger class to set age and other default values for object
    Tiger(int);
};


#endif //TIGER_HPP
