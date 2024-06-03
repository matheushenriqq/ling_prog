#include <iostream>
#include <fstream>
#include <string>

// Definition of the "data" structure to represent dates
struct Data {
    int d, m, a;  // Day, month, year
};

int main() {
    Data d1 = {7, 9, 1999};  // Initialization of the first date
    Data d2 = {12, 5, 2024};  // Initialization of the second date
    
    Data e1;  // Declaration of another date for reading from the file
    Data e2;  // Declaration of another date for reading from the file

    std::string filename;  // String to store the file name
    
    // Asks the user for the file name
    std::cout << "Enter filename:";
    std::getline(std::cin, filename);  // Reads user input securely
    
    std::ofstream outfile(filename, std::ios::binary);  // Opens the file for binary writing
    if (!outfile.is_open()) {
        std::cerr << "Error! Unable to open file for writing!" << std::endl;
        return 1;  // Exits the program in case of error
    }
    outfile.write(reinterpret_cast<char*>(&d1), sizeof(Data));  // Writes the first structure to the file
    outfile.write(reinterpret_cast<char*>(&d2), sizeof(Data));  // Writes the second structure to the file
    outfile.close();  // Closes the file

    std::ifstream infile(filename, std::ios::binary);  // Opens the file for binary reading
    if (!infile.is_open()) {
        std::cerr << "Error! Unable to open file for reading!" << std::endl;
        return 1;  // Exits the program in case of error
    }
    infile.read(reinterpret_cast<char*>(&e1), sizeof(Data));  // Reads the first structure from the file
    infile.read(reinterpret_cast<char*>(&e2), sizeof(Data));  // Reads the second structure from the file
    infile.close();  // Closes the file

    // Displays the dates read from the file
    std::cout << "First Date: " << e1.a << "/" << e1.m << "/" << e1.d << std::endl;
    std::cout << "Second Date: " << e2.a << "/" << e2.m << "/" << e2.d << std::endl;

    return 0;  // Indicates that the program executed successfully
}
