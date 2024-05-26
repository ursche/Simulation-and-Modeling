#include <iostream>
#include <set>

class LCG {
private:
    int Xn; // Current value
    int a, c, m; // Parameters

public:
    // Constructor
    LCG(int seed, int multiplier, int increment, int modulus) : Xn(seed), a(multiplier), c(increment), m(modulus) {}

    // Mixed LCG
    int mixedLCG() {
        Xn = (a * Xn + c) % m;
        return Xn;
    }

    // Additive LCG
    int additiveLCG() {
        Xn = (Xn + c) % m;
        return Xn;
    }

    // Multiplicative LCG
    int multiplicativeLCG() {
        Xn = (a * Xn) % m;
        return Xn;
    }
};

int main() {
    int seed, a, c, m;

    // Taking user input
    std::cout << "Enter seed (Xn): ";
    std::cin >> seed;

    std::cout << "Enter multiplier (a): ";
    std::cin >> a;

    std::cout << "Enter increment (c): ";
    std::cin >> c;

    std::cout << "Enter modulus (m): ";
    std::cin >> m;

    // Creating LCG object
    LCG lcg(seed, a, c, m);

    std::set<int> generatedNumbers;

    while (true) {
        int option;

        std::cout << "Choose an option:\n";
        std::cout << "1. Mixed LCG\n";
        std::cout << "2. Additive LCG\n";
        std::cout << "3. Multiplicative LCG\n";
        std::cout << "4. Exit\n";
        std::cin >> option;

        // Check if the user wants to exit
        if (option == 4) {
            std::cout << "Exiting program.\n";
            break;
        }

        // Generating random numbers based on user's choice
        switch(option) {
            case 1:
                std::cout << "Mixed LCG sequence:\n";
                break;
            case 2:
                std::cout << "Additive LCG sequence:\n";
                break;
            case 3:
                std::cout << "Multiplicative LCG sequence:\n";
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
                continue;
        }

        // Generate and print a sequence of random numbers
        while (true) {
            int randomNumber;
            switch(option) {
                case 1:
                    randomNumber = lcg.mixedLCG();
                    break;
                case 2:
                    randomNumber = lcg.additiveLCG();
                    break;
                case 3:
                    randomNumber = lcg.multiplicativeLCG();
                    break;
            }

            std::cout << randomNumber << " ";

            // Check if the generated number is already repeated
            if (generatedNumbers.find(randomNumber) != generatedNumbers.end()) {
                std::cout << "\nRepeated number generated. Starting new sequence.\n" << std::endl;
                generatedNumbers.clear(); // Clear the set for a new sequence
                break; // Exit the loop to start a new sequence
            } else {
                generatedNumbers.insert(randomNumber);
            }
        }
    }

    return 0;
}
