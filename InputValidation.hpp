/* Justin Tromp
 * Date: 01/11/2019
 * Description: Input validation functions to ensure valid input is accepted and prompt user
 * for re-entry as needed.
*/

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP
#include <limits>
#include <iostream>
#include <string>
#include <algorithm>

int validateInputIntRange1_35000();

int validateInputIntRange1_100();

int validateInputIntRange1_30000();

int validateInputIntRange0_1();

int validateInputIntRange1_2();

int validateInputIntRange1_3();

int validateInputMenu();

double validateInputDoubleRangePt1_100();

#endif //INPUTVALIDATION_HPP
