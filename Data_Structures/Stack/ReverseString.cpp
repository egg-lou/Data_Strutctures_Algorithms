#include <iostream>
#include <stack>
#include <string>

// Function to reverse a string using a stack
void Reverse(std::string &str) {
    std::stack<char> S;

    // Push each character of the input string onto the stack
    for (char c : str) {
        S.push(c);
    }

    // Pop characters from the stack and put them back into the string
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = S.top(); // Assign the top character to the string
        S.pop(); // Remove the top character from the stack
    }
}

int main() {
    std::string input;
    std::cout << "Enter a String: ";
    std::getline(std::cin, input);

    Reverse(input); // Call the function to reverse the input string
    
    std::cout << "Output = " << input << std::endl;

    return 0;
}