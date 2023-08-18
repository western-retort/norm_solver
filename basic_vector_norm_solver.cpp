#include <iostream>
#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<string>
#include <cmath>

//no need for file reader as this is 1d
std::vector<long double> read_vector() {
    bool read = true;
    std::vector<long double> vector;

    std::cout << "Enter each element one by one\nq: quit (vector is complete)\nr: reset\nd: delete previous\n";

    while (read) {
        std::string entered;
        std::cout << "=> ";
        std::cin >> entered;

        if (entered == "q") {
            read = false; // Quit the loop
        } else if (entered == "r") {
            vector.clear(); // Reset the vector
        } else if (entered == "d") {
            if (!vector.empty()) {
                vector.pop_back(); // Delete the last element
            } else {
                std::cout << "Vector is already empty.\n";
            }
        } else {
            // Try to convert the entered value to long double
            try {
                long double num = std::stold(entered);
                vector.push_back(num);
            } catch (const std::invalid_argument&) {
                std::cout << "Invalid input. Please enter a number or a valid command.\n";
            } catch (const std::out_of_range&) {
                std::cout << "Number out of range. Please enter a valid number.\n";
            }
        }
    }

    return vector;
}


long double norm1(std::vector<long double> numbers){
    long double total=0;

    for(size_t i = 0; i < numbers.size(); ++i){
        double positiveValue = std::abs(numbers[i]);
        total += positiveValue;
    }
    return total;
}

long double norm2(std::vector<long double> numbers){
    long double total = 0;
    for(size_t i = 0; i < numbers.size(); ++i){
        double positiveValue = std::abs(numbers[i]);
        total += positiveValue*positiveValue;
    }
    return sqrt(total);
}

long double norm_infinity(std::vector<long double> numbers){
    long double largest = numbers[0]; // Initialize with the first element

    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }
    return largest;
}

int main(){
    std::vector<long double> numbers = read_vector();

    std::cout << "\n\nOperation?\n1=manhattan norm / norm1 \n2=uclidean norm / norm2 \n3=max norm / norm_infinity\nTYPE THE NUMBER : ";
    int selection;
    std::cin >> selection;
    
    while(true){
        if(selection == 1){
            std::cout <<"\n" << norm1(numbers);
            return 0;
        }

        else if (selection == 2){
            std::cout <<"\n" << norm2(numbers);
            return 0;
        }
        
        else if (selection == 3){
            std::cout <<"\n" << norm_infinity(numbers);
            return 0;
        }

        else{
            "invalid number";
        }
    }
}
