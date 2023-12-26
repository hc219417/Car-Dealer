# Car-Dealer
**Objective:** use arrays, files, searching arrays, manipulating array contents, characters, and strings

You are asked to implement a car ordering system for ***Bobcats Auto Dealership***. This dealership is brand new and only sells one brand of cars with three different models. However, a buyer can add options if they choose.

Write a C++ program that allows the user to order a single car with different options. All the options available will be stored in a file called "**options.txt**" along with their prices. You may assume that the file will not contain more than 30 options. The user should be able to select the car model, display options and prices, add options, remove options, or cancel the order. Allow the user to see all the available options and their prices. **The program should always display the car model, price, and the options ordered so far.** If the user has not selected a car model, then an error message should be displayed indicating that the order has not started yet (e.g. NO MODEL SELECTED). A user should not be able to add more than 6 options to the car.

The base prices of the three models: **E** ($10,000.00), **L** ($12,000.00), and **X** ($18,000.00)

**Implement the following menu options in separate functions:**

**1. Select a model (E, L, X)**

The user should enter either E, L, or X (either in lower or upper case). If the wrong character is entered, the user should be prompted repeatedly until the user enters a valid model. Update the order information after this selection.

**2. Display available options and prices**

List all the options 3 per line. They must be formatted neatly as shown below.

**3. Add an option**

The user should enter an option such as "DVD System", "10 Speakers", etc. The option entered must be one of the options available. If it's not, the user should be prompted repeatedly until the user enters a valid option or enters "cancel". After the selection, the order information should be updated (see sample input/output below). Duplicate options should not be allowed.

**4. Remove an option**

Allow the user to remove one of the options from the list of options added earlier. Update the order information. If the option name is not in the list of options, then it should be ignored.

**5. Cancel order**

Start over. Update the order information.

**6. Quit**
