#include <iostream>
#include <stack>
#include <string>

void Reverse(std::string &str) {
    std::stack<char> S;

    for (char c : str) {
        S.push(c);
    }

    for (size_t i = 0; i < str.length(); i++) {
        str[i] = S.top();
        S.pop();
    }
}

int main() {
    std::string input;
    std::cout << "Enter a String: ";
    std::getline(std::cin, input);

    Reverse(input);
    
    std::cout << "Output = " << input << std::endl;

    return 0;
}
