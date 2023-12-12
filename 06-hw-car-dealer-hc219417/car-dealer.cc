/**
 *   @file: car-dealer.cc
 * @author: Hannah Culver
 *   @date: October 31, 2021
 *  @brief: homework 6 (objectives: use arrays/vectors, files, searching arrays/vectors, manipulating array/vector contents, characters, and strings)
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/**
 * displayMenu
 * @param none
 * @return menu with six choices
 */
void displayMenu();

/**
 * selectModel
 * @param none
 * @return model choice
 */
char selectModel();

/**
 * displayOptions
 * @param options vector of available options
 * @param prices vector of corresponding prices
 * @param number_of_options number of options
 * @return available options with prices
 */
void displayOptions(vector <string> options, vector <int> prices, int number_of_options);

/**
 * addOption (not to exceed 6, duplicates not allowed)
 * @param options vector of available options
 * @param number_of_options number of options
 * @param options_added vector of currently selected options
 * @return updated vector of selected options
 */
int addOption(vector <string> options, int number_of_options, vector <string> options_added);

/**
 * duplicateOption - checks whether or not a duplicate option has been entered
 * @param options_added vector of currently selected options
 * @param options vector of available options
 * @param location location within the options vector of option that needs tested
 * @return true if a duplicate option has been entered
 */
bool duplicateOption(vector <string> options_added, vector <string> options, int location);

/**
 * removeOption (ignore any options not already present)
 * @param removed_option option to be removed from options_added
 * @param options_added vector of currently selected options
 * @param options vector of available options
 * @param number_of_options number of options
 * @return updated vector of selected options
 */
int removeOption(string removed_option, vector <string> options_added, vector <string> options, int number_of_options);

/**
 * findOptionPrice - find price amount to be removed
 * @param removed_option option to be removed from options_added
 * @param options vector of available options
 * @param prices vector of corresponding prices
 * @param number_of_options number of options
 * @return location of removed_option in options
 */
int findOptionPrice(string removed_option, vector <string> options, vector <int> prices, int number_of_options);

/**
 * searchOptionsAdded - search through the vector or currently selected options
 * @param options_added vector of currently selected options
 * @param removed_option option to be searched for in options_added
 * @return location of option to be removed from options_added
 */
int searchOptionsAdded(vector <string> options_added, string removed_option);

/**
 * cancelOrder
 * @param options_added vector of currently selected options
 * @return empty options_added vector
 */
vector <string> cancelOrder(vector <string> options_added);

/**
 * convertLowercase - converts a string to lowercase for comparison
 * @param added_or_removed_option string to be converted to lowercase
 * @return lowercase string
 */
string convertLowercase(string added_or_removed_option);

/**
 * validOption - checks the validity of an option
 * @param added_or_removed_option string to be checked for validity
 * @param options vector of all available options
 * @param number_of_options number of options
 * @return true if an option is valid
 */
bool validOption(string added_or_removed_option, vector <string> options, int number_of_options);

/**
 * validOptionLocation - finds the location of the option (if valid)
 * @param added_or_removed_option string to be used to find a match
 * @param options vector of all available options
 * @param number_of_options number of options
 * @return location of the option
 */
int validOptionLocation(string added_or_removed_option, vector <string> options, int number_of_options);

/**
 * displayOptionsAdded
 * @param options_added vector of currently selected options
 * @return display of options added to the order so far
 */
void displayOptionsAdded(vector <string> options_added);

int main(int argc, char const *argv[]) {

    ifstream inStream;
    string input_filename = "options.txt";
	inStream.open(input_filename);
	if (inStream.fail())
	{
		cout << "Error: file not found" << endl;
		exit(0);
	}

    string option;
    int price;

    vector <string> options;
    vector <int> prices;

    int number_of_options = 0;
    //int const CAPACITY = 30;

    while (!inStream.eof())
    {
        inStream >> price;
        prices.push_back(price);
        inStream.ignore();
        getline(inStream,option);
        options.push_back(option);
        number_of_options++;
    }

    number_of_options = number_of_options - 1;
    inStream.close();

    int choice;
    string model = "NO MODEL SELECTED";
    vector <string> options_added;

    do {

        char ch_model;
        double base_price;

        if (model == "NO MODEL SELECTED")
        {
            cout << model << endl;
        }
        else if (model != "NO MODEL SELECTED")
        {
            cout << "Model: " << ch_model << ", $" << fixed << setprecision(2) << base_price << endl;
            displayOptionsAdded(options_added);
        }

        displayMenu();
        cin >> choice;

        if (choice == 1)
        {
            ch_model = selectModel();
            if (ch_model == 'E')
            {
                base_price = 10000;
            }
            else if (ch_model == 'L')
            {
                base_price = 12000;
            }
            else if (ch_model == 'X')
            {
                base_price = 18000;
            }
            model = "MODEL SELECTED";
        }

        else if (choice == 2)
        {
            cout << "Prices for model E, L, & X: $10000.00, $12000.00, $18000.00" << endl;
            cout << "Available options:" << endl;
            displayOptions(options,prices,number_of_options);
        }

        else if (choice == 3)
        {
            if (model == "NO MODEL SELECTED")
            {
                cout << "Error: must select model first" << endl;
            }
            else
            {
                int location = addOption(options,number_of_options,options_added);
                if (duplicateOption(options_added,options,location))
                {
                    cout << "Error: duplicate option" << endl;
                    exit(0);
                }
                options_added.push_back(options.at(location));
                base_price += prices.at(location);
            }
        }

        else if (choice == 4)
        {
            if (model == "NO MODEL SELECTED")
            {
                cout << "Error: must select model first" << endl;
            }
            else if (options_added.empty())
            {
                cout << "Error: must add an option first" << endl;
            }
            else
            {
                string removed_option;
                cout << "Please enter the option that you would like to remove: "; //spelling matters
                cin.ignore(100,'\n');
                getline(cin,removed_option);
                removed_option = convertLowercase(removed_option);

                int option_location = removeOption(removed_option,options_added,options,number_of_options);
                options_added.erase(options_added.begin() + option_location);

                int price_location = findOptionPrice(removed_option,options,prices,number_of_options);
                base_price -= prices.at(price_location);
            }
        }

        else if (choice == 5)
        {
            if (model == "NO MODEL SELECTED")
            {
                cout << "Error: must select model first" << endl;
            }
            else
            {
                options_added = cancelOrder(options_added);
                model = "NO MODEL SELECTED";
            }
        }

    } while (choice != 6);

    return 0;
}/// main

void displayMenu()
{
    cout << "1. Select a model (E, L, X)" << endl;
    cout << "2. Display available options and prices" << endl;
    cout << "3. Add an option" << endl;
    cout << "4. Remove an option" << endl;
    cout << "5. Cancel order" << endl;
    cout << "6. Quit" << endl;
    cout << "Please enter your choice: ";
}

char selectModel()
{
    char model_choice;
    char model_selection;

    do {
        cout << "Please enter the model (E, L, X): ";
        cin >> model_choice;

        if (model_choice == 'E' || model_choice == 'e')
        {
            model_selection = 'E';
        }

        else if (model_choice == 'L' || model_choice == 'l')
        {
            model_selection = 'L'; 
        }

        else if (model_choice == 'X' || model_choice == 'x')
        {
            model_selection = 'X';       
        }
    } while (model_choice != 'E' && model_choice != 'e' && model_choice != 'L' && model_choice != 'l' && model_choice != 'X' && model_choice != 'x');

    return model_selection;
}

void displayOptions(vector <string> options, vector <int> prices, int number_of_options)
{
    vector <string> string_prices;
    vector <string> options_and_prices;
    for (int i = 0; i < number_of_options; i++)
    {
        string_prices.push_back(to_string(prices[i]));
        options_and_prices.push_back(options.at(i) + " ($" + string_prices.at(i) + ") ");
        cout << left << setw(30);
        cout << options_and_prices[i];
        if ((i + 1) % 3 == 0)
        {
            cout << endl; //start a new line every 3 options
        }
    }
    cout << endl;
}

int addOption(vector <string> options, int number_of_options, vector <string> options_added)
{
    if (options_added.size() == 6)
    {
        cout << "Error: maximum number of options allowed" << endl;
        exit(0);
    }
    else
    {
        string added_option;
        cout << "Please enter the option that you would like to add: "; //spelling matters
        cin.ignore(100,'\n');
        getline(cin,added_option);
        added_option = convertLowercase(added_option);
        if (validOption(added_option,options,number_of_options))
        {
            int location = validOptionLocation(added_option,options,number_of_options);
            return location;
        }
        else
        {
            cout << "invalid option" << endl;
            exit(0);
        }
    }
}

bool duplicateOption(vector <string> options_added, vector <string> options, int location)
{
    for (size_t i = 0; i < options_added.size(); i++)
    {
        if (options.at(location) == options_added.at(i))
        {
            return true;
        }
    }
} //warning: control reaches end of non-void function

int removeOption(string removed_option, vector <string> options_added, vector <string> options, int number_of_options)
{
    if (validOption(removed_option,options,number_of_options))
    {
        int location = searchOptionsAdded(options_added,removed_option);
        return location;
    }
    else
    {
        cout << "invalid option" << endl;
        exit(0);
    }
}

int findOptionPrice(string removed_option, vector <string> options, vector <int> prices, int number_of_options)
{
    int location;
    for (int i = 0; i < number_of_options; i++)
    {
        options.at(i) = convertLowercase(options.at(i));
        if (removed_option == options.at(i))
        {
            location = i;
        }
    }
    return location;
}

int searchOptionsAdded(vector <string> options_added, string removed_option)
{
    int match;
    int count = 0;
    for (size_t i = 0; i < options_added.size(); i++)
    {
        options_added.at(i) = convertLowercase(options_added.at(i));
        if (removed_option == options_added.at(i))
        {
            count++;
            match = i;
        }
        else
        {
            cout << "Error: option not previously added" << endl;
            exit(0);
        }
    }
    if (count > 0)
    {
        return match;
    }
} //warning: control reaches end of non-void function

vector <string> cancelOrder(vector <string> options_added)
{
    options_added.clear();
    if (!options_added.empty())
    {
        cout << "Error: could not clear order" << endl;
    }
    return options_added;
}

string convertLowercase(string added_or_removed_option)
{
    string lowercase = added_or_removed_option;
    for (size_t i = 0; i < lowercase.length(); i++)
    {
        lowercase.at(i) = tolower(lowercase.at(i));
    }
    return lowercase;
}

bool validOption(string added_or_removed_option, vector <string> options, int number_of_options)
{
    int count = 0;
    for (int i = 0; i < number_of_options; i++)
    {
        options.at(i) = convertLowercase(options.at(i));
        if (added_or_removed_option == options.at(i))
        {
            count++;
        }
    }
    if (count > 0)
    {
        return true;
    }
    else if (count == 0)
    {
        return false;
    }
} //warning: control reaches end of non-void function

int validOptionLocation(string added_or_removed_option, vector <string> options, int number_of_options)
{
    int match;
    int count = 0;
    for (int i = 0; i < number_of_options; i++)
    {
        options.at(i) = convertLowercase(options.at(i));
        if (added_or_removed_option == options.at(i))
        {
            count++;
            match = i;
        }
    }
    if (count > 0)
    {
        return match;
    }
} //warning: control reaches end of non-void function

void displayOptionsAdded(vector <string> options_added) //wasn't sure how else to separate the elements of the
{                                                       //options_added vector without having a trailing comma
    if (options_added.size() == 0)
    {
        options_added.push_back("None");
        cout << "Options: " << options_added.at(0) << endl;
    }
    else if (options_added.size() == 1)
    {
        cout << "Options: " << options_added.at(0) << endl;
    }
    else if (options_added.size() == 2)
    {
        cout << "Options: " << options_added.at(0) << ", " << options_added.at(1) << endl;
    }
    else if (options_added.size() == 3)
    {
        cout << "Options: " << options_added.at(0) << ", " << options_added.at(1) << ", " << options_added.at(2) << endl;
    }
    else if (options_added.size() == 4)
    {
        cout << "Options: " << options_added.at(0) << ", " << options_added.at(1) << ", " << options_added.at(2) << ", " << options_added.at(3) << endl;
    }
    else if (options_added.size() == 5)
    {
        cout << "Options: " << options_added.at(0) << ", " << options_added.at(1) << ", " << options_added.at(2) << ", " << options_added.at(3) << ", " << options_added.at(4) << endl;
    }
    else if (options_added.size() == 6)
    {
        cout << "Options: " << options_added.at(0) << ", " << options_added.at(1) << ", " << options_added.at(2) << ", " << options_added.at(3) << ", " << options_added.at(4) << ", " << options_added.at(5) << endl;
    }
}