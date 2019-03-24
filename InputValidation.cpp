/* Justin Tromp
 * Date: 01/11/2019
 * Description: Input validation functions to ensure valid input is accepted and prompt user
 * for re-entry as needed.
*/

#include "InputValidation.hpp"

//Validate integer input from 1 through 35000
int validateInputIntRange1_35000 () {
    int userInput = 0;
    std::string userStringInput = " ";

    //Accept input from user
    getline(std::cin, userStringInput);

    //If input is an integer, store value in userInput
    if (std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) && !userStringInput.empty()) {
        userInput = std::stoi(userStringInput);
    }

    bool inputNotValidated = false;
    //Minimum and maximum values accepted
    int min = 1;
    int max = 35000;
    //As long as user inputs non-digits, loop to request correct input
    while ((!std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) || inputNotValidated ||
           (userStringInput.empty()) || userInput < min || userInput > max) {

        //Change to true as user input must be validated before placing in userInput as integer
        inputNotValidated = true;

        //Re-prompt user for input
        std::cout << "Please enter a valid integer (i.e., without decimals) and within "
                     "the previously specified range." << std::endl;

        //Accept input from user
        getline(std::cin, userStringInput);

        //If conditions are met, move user input from string to integer variable and update input validation
        //boolean value to allow loop exit.
        if ((std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) && !userStringInput.empty()) {
            userInput = std::stoi(userStringInput);
            inputNotValidated = false;
        }
    }

    return userInput;
}

//Validate integer input from 1 through 100
int validateInputIntRange1_100 () {
    int userInput = 0;
    std::string userStringInput = " ";

    //Accept input from user
    getline(std::cin, userStringInput);

    //If input is an integer, store value in userInput
    if (std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) && !userStringInput.empty()) {
        userInput = std::stoi(userStringInput);
    }

    bool inputNotValidated = false;
    //Minimum and maximum values accepted
    int min = 1;
    int max = 100;
    //As long as user inputs non-digits, loop to request correct input
    while ((!std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) || inputNotValidated ||
           (userStringInput.empty()) || userInput < min || userInput > max) {

        //Change to true as user input must be validated before placing in userInput as integer
        inputNotValidated = true;

        //Re-prompt user for input
        std::cout << "Please enter a valid integer (i.e., without decimals) and within "
                     "the previously specified range." << std::endl;

        //Accept input from user
        getline(std::cin, userStringInput);

        //If conditions are met, move user input from string to integer variable and update input validation
        //boolean value to allow loop exit.
        if ((std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) && !userStringInput.empty()) {
            userInput = std::stoi(userStringInput);
            inputNotValidated = false;
        }
    }

    return userInput;
}

//Validate integer input from 1 through 30000
int validateInputIntRange1_30000 () {
    int userInput = 0;
    std::string userStringInput = " ";

    //Accept input from user
    getline(std::cin, userStringInput);

    //If input is an integer, store value in userInput
    if (std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) && !userStringInput.empty()) {
        userInput = std::stoi(userStringInput);
    }

    bool inputNotValidated = false;
    //Minimum and maximum values accepted
    int min = 1;
    int max = 30000;
    //As long as user inputs non-digits, loop to request correct input
    while ((!std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) || inputNotValidated ||
           (userStringInput.empty()) || userInput < min || userInput > max) {

        //Change to true as user input must be validated before placing in userInput as integer
        inputNotValidated = true;

        //Re-prompt user for input
        std::cout << "Please enter a valid integer (i.e., without decimals) and within "
                     "the previously specified range." << std::endl;

        //Accept input from user
        getline(std::cin, userStringInput);

        //If conditions are met, move user input from string to integer variable and update input validation
        //boolean value to allow loop exit.
        if ((std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) && !userStringInput.empty()) {
            userInput = std::stoi(userStringInput);
            inputNotValidated = false;
        }
    }

    return userInput;
}

//Validate integer input from 0 or 1
int validateInputIntRange0_1 () {
    int userInput = 0;
    std::string userStringInput = " ";

    //Accept input from user
    getline(std::cin, userStringInput);

    //If input is an integer, store value in userInput
    if (std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) && !userStringInput.empty()) {
        userInput = std::stoi(userStringInput);
    }

    bool inputNotValidated = false;
    //Minimum and maximum values accepted
    int min = 0;
    int max = 1;
    //As long as user inputs non-digits, loop to request correct input
    while ((!std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) || inputNotValidated ||
           (userStringInput.empty()) || userInput < min || userInput > max) {

        //Change to true as user input must be validated before placing in userInput as integer
        inputNotValidated = true;

        //Re-prompt user for input
        std::cout << "Please enter a valid integer (i.e., without decimals) 0 or 1." << std::endl;

        //Accept input from user
        getline(std::cin, userStringInput);

        //If conditions are met, move user input from string to integer variable and update input validation
        //boolean value to allow loop exit.
        if ((std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) && !userStringInput.empty()) {
            userInput = std::stoi(userStringInput);
            inputNotValidated = false;
        }
    }

    return userInput;
}

//Validate input for options 1 or 2 to ensure that the correct value is entered. If not, request input again.
int validateInputIntRange1_2() {
    int userInput = 0;
    std::string userStringInput = " ";

    //Accept input from user
    getline(std::cin, userStringInput);

    //If user input is all digits, accept and place in userInput integer variable.
    if (std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) && !userStringInput.empty()) {
        userInput = std::stoi(userStringInput);
    }

    bool inputNotValidated = false;
    //As long as user inputs non-digits or digits that do not match desired values, loop to request correct input
    while (!std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) || inputNotValidated ||
           userStringInput.empty() || (userInput != 1 && userInput != 2)) {

        //Re-prompt user for input
        std::cout << "Please enter a valid integer (i.e., without decimals) selection "
                     "of 1 or 2." << std::endl;

        //Change to true as user input must be validated before placing in userInput as integer
        inputNotValidated = true;

        //Accept input from user
        getline(std::cin, userStringInput);

        //If conditions are met, move user input from string to integer variable and update input validation
        //boolean value to allow loop exit.
        if ((std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) && !userStringInput.empty()) {
            userInput = std::stoi(userStringInput);
            inputNotValidated = false;
        }
    }

    return userInput;
}

//Validate input for options 1 through 3 to ensure that the correct value is entered. If not, request input again.
int validateInputIntRange1_3() {
    int userInput = 0;
    std::string userStringInput = " ";

    //Accept input from user
    getline(std::cin, userStringInput);

    //If user input is all digits, accept and place in userInput integer variable.
    if (std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) && !userStringInput.empty()) {
        userInput = std::stoi(userStringInput);
    }

    bool inputNotValidated = false;
    //As long as user inputs non-digits or digits that do not match desired values, loop to request correct input
    while (!std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) || inputNotValidated ||
           userStringInput.empty() || (userInput != 1 && userInput != 2 && userInput != 3)) {

        //Re-prompt user for input
        std::cout << "Please enter a valid integer (i.e., without decimals) selection "
                     "of 1 through 3." << std::endl;

        //Change to true as user input must be validated before placing in userInput as integer
        inputNotValidated = true;

        //Accept input from user
        getline(std::cin, userStringInput);

        //If conditions are met, move user input from string to integer variable and update input validation
        //boolean value to allow loop exit.
        if ((std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) && !userStringInput.empty()) {
            userInput = std::stoi(userStringInput);
            inputNotValidated = false;
        }
    }

    return userInput;
}

//Validate menu input for options 1 or 2 to ensure that the correct value is entered. If not, request input again.
int validateInputMenu() {
    int userInput = 0;
    std::string userStringInput = " ";

    //Accept input from user
    getline(std::cin, userStringInput);

    //If user input is all digits, accept and place in userInput integer variable.
    if (std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) && !userStringInput.empty()) {
        userInput = std::stoi(userStringInput);
    }

    bool inputNotValidated = false;
    //As long as user inputs non-digits or digits that do not match desired values, loop to request correct input
    while (!std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) || inputNotValidated ||
           userStringInput.empty() || (userInput != 1 && userInput != 2)) {

        //Re-prompt user for input
        std::cout << "Please enter a valid integer (i.e., without decimals) selection "
                     "based on the menu options above." << std::endl;

        //Change to true as user input must be validated before placing in userInput as integer
        inputNotValidated = true;

        //Accept input from user
        getline(std::cin, userStringInput);

        //If conditions are met, move user input from string to integer variable and update input validation
        //boolean value to allow loop exit.
        if ((std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) && !userStringInput.empty()) {
            userInput = std::stoi(userStringInput);
            inputNotValidated = false;
        }
    }

    return userInput;
}


//Validate double value input from .1 through 100
double validateInputDoubleRangePt1_100 () {
    double userInput = 0;
    std::string userStringInput = "";

    //Accept input from user
    getline(std::cin, userStringInput);

    //Minimum and maximum values accepted
    double min = .1;
    double max = 100;
    bool inputNotValidated = false;

    if (userStringInput.find_first_not_of("1234567890.") != std::string::npos || userStringInput.empty() ||
        (userInput < min || userInput > max)) {
        userInput = std::atof(userStringInput.c_str());
    }

    //Check for non-digits other than a . and loop to request correct input if empty, contains a non-digit other
    //than specified previously, or is outside of the range.
    while (userStringInput.find_first_not_of("1234567890.") != std::string::npos || userStringInput.empty() ||
        (userInput < min || userInput > max) || inputNotValidated) {

        //Change to true as user input must be validated before placing in userInput as integer
        inputNotValidated = true;

        //Re-prompt user for input
        std::cout << "Please enter a valid number from .1 through 100." << std::endl;

        //Accept input from user
        getline(std::cin, userStringInput);

        //If conditions are met, move user input from string to integer variable and update input validation
        //boolean value to allow loop exit.
        if (!(std::all_of(userStringInput.begin(), userStringInput.end(), ::isalpha)) && !userStringInput.empty()) {
            userInput = std::atof(userStringInput.c_str());
            inputNotValidated = false;
        }
    }

    return userInput;
}
