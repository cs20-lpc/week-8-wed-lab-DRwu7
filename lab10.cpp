#include "ArrayStack.hpp"
#include <iostream>
#include <string> // Added for clarity, though generally available via iostream

using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

double gRec(unsigned);
double gStack(unsigned);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls two functions in two different ways:
 * recursive and iterative. The outputs for both function calls should match
 * exactly.
 * * Input:
 * N/A
 * * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    unsigned startValue = 0;

    cout << "Enter the starting value for i: ";
    cin  >> startValue;

    cout << "\nRecursive:\n";
    cout << gRec(startValue) << endl;

    cout << "\nIterative:\n";
    cout << gStack(startValue) << endl;

    return 0;
}

/*******************************************************************************
 * Description:
 * Recursive function that calculates a result. Displays a message when a base
 * case is reached.
 * * Input:
 * i - an unsigned value that determines whether or not this is a base case
 * * Output:
 * The result of 1.1n + 3.2, where n is the depth of recursion
*******************************************************************************/

double gRec(unsigned i) {
    if (i == 0) {
        cout << "Base case!\n";
        return 3.2;
    }
    
    return gRec(i - 1) + 1.1;
}

/*******************************************************************************
 * Description:
 * Iterative function that simulates recursion using a stack. Calculates a
 * result. Displays a message when a base case is reached.
 * * Input:
 * i - an unsigned value that determines whether or not this is a base case
 * * Output:
 * The result of 1.1n + 3.2, where n is the depth of recursion
*******************************************************************************/

double gStack(unsigned i) {
    // 1. Setup the stack (ArrayStack holds the recursion state variable 'i')
    ArrayStack<unsigned> callStack(i + 1); // Max depth is i, so size is i+1 (for i=0)
    
    // 2. Unwind Phase: Simulate recursive calls by pushing 'i' onto the stack
    unsigned currentValue = i;
    while (currentValue > 0) {
        // Push the state (the depth i) onto the stack
        callStack.push(currentValue);
        currentValue--;
    }
    
    // 3. Base Case: Reached when currentValue is 0.
    cout << "Base case!\n";
    double result = 3.2; // The base case value
    
    // 4. Wind Phase: Calculate results by popping the stack
    while (!callStack.isEmpty()) {
        // Pop the state variable (not strictly needed, but mimics the return pop)
        callStack.pop(); 
        
        // Apply the calculation step: f(i) = f(i-1) + 1.1
        result += 1.1;
    }
    
    return result;
}