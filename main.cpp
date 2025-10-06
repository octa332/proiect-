#include <iostream>    
#include <iomanip>    //functii pentru manipularea formatului de citire/afisare
#include <sstream>    //librarie pentru efectuarea operatiilor pe baza variabilelor de tip string
#include <fstream>    //librarie pentru efectuarea citirii si afisarii din fisiere

class HexInt {
private:
    long long value;

public:
    HexInt() : value(0) {}
    HexInt(long long val) : value(val) {}
    HexInt(const std::string &hexStr) {
        if (hexStr.substr(0, 2) == "0x" || hexStr.substr(0, 2) == "0X") {
            value = std::stoll(hexStr, nullptr, 16);
        } else {
            value = std::stoll(hexStr);
        }
    }

    // metode de citire si afisare
    void readFromHex(const std::string &hexStr) {
        if (hexStr.substr(0, 2) == "0x" || hexStr.substr(0, 2) == "0X") {
            value = std::stoll(hexStr, nullptr, 16);
        } else {
            value = std::stoll(hexStr);
        }
    }

    std::string toHexString() const {
        std::ostringstream oss;
        oss << "0x" << std::hex << value;
        return oss.str();
    }


    // operatori supradefiniti
    HexInt& operator=(const HexInt &other) {
        if (this == &other) return *this;
        value = other.value;
        return *this;
    }

    HexInt operator+(const HexInt &other) const {
        return HexInt(value + other.value);
    }

    HexInt operator-(const HexInt &other) const {
        return HexInt(value - other.value);
    }

    HexInt operator*(const HexInt &other) const {
        return HexInt(value * other.value);
    }

    HexInt operator/(const HexInt &other) const {
        return HexInt(value / other.value);
    }

    bool operator==(const HexInt &other) const {
        return value == other.value;
    }

    bool operator!=(const HexInt &other) const {
        return value != other.value;
    }

    bool operator<(const HexInt &other) const {
        return value < other.value;
    }

    bool operator<=(const HexInt &other) const {
        return value <= other.value;
    }

    bool operator>(const HexInt &other) const {
        return value > other.value;
    }

    bool operator>=(const HexInt &other) const {
        return value >= other.value;
    }

    operator long long() const {
        return value;
    }

    operator std::string() const {
        return toHexString();
    }
};


// functii pentru afisarea meniului
void showMenu() {
    std::cout << "1. Descriere program (help)\n";
    std::cout << "2. Adunare\n";
    std::cout << "3. Scadere\n";
    std::cout << "4. Inmultire\n";
    std::cout << "5. Impartire\n";
    std::cout << "6. Iesire\n";
    std::cout << "Alegeti o optiune: ";
}

void description() {
    std::cout << "Acest program manipuleaza numere in format hexazecimal utilizand clasa HexInt.\n";
}

void writeToFile(const std::string &operation, const std::string &hex1, const std::string &hex2, const std::string &result) {
    std::ofstream file("results.txt", std::ios::app);
    if (file.is_open()) {
        file << "Operatie: " << operation << "\n";
        file << "Primul numar: " << hex1 << "\n";
        file << "Al doilea numar: " << hex2 << "\n";
        file << "Rezultatul: " << result << "\n";
        file << "--------------------------\n";
        file.close();
    } else {
        std::cerr << "Nu se poate deschide fisierul pentru scriere." << std::endl;
    }
}

void performAddition() {
    std::string hex1, hex2;
    std::cout << "Introduceti primul numar hexazecimal: ";
    std::cin >> hex1;
    std::cout << "Introduceti al doilea numar hexazecimal: ";
    std::cin >> hex2;
    
    HexInt num1(hex1);
    HexInt num2(hex2);
    HexInt result = num1 + num2;

    std::string resultStr = result.toHexString();
    std::cout << "Rezultatul adunarii este: " << resultStr << std::endl;

    writeToFile("Adunare", hex1, hex2, resultStr);
}

void performSubtraction() {
    std::string hex1, hex2;
    std::cout << "Introduceti primul numar hexazecimal: ";
    std::cin >> hex1;
    std::cout << "Introduceti al doilea numar hexazecimal: ";
    std::cin >> hex2;
    
    HexInt num1(hex1);
    HexInt num2(hex2);
    HexInt result = num1 - num2;

    std::string resultStr = result.toHexString();
    std::cout << "Rezultatul scaderii este: " << resultStr << std::endl;

    writeToFile("Scadere", hex1, hex2, resultStr);
}

void performMultiplication() {
    std::string hex1, hex2;
    std::cout << "Introduceti primul numar hexazecimal: ";
    std::cin >> hex1;
    std::cout << "Introduceti al doilea numar hexazecimal: ";
    std::cin >> hex2;
    
    HexInt num1(hex1);
    HexInt num2(hex2);
    HexInt result = num1 * num2;

    std::string resultStr = result.toHexString();
    std::cout << "Rezultatul inmultirii este: " << resultStr << std::endl;

    writeToFile("Inmultire", hex1, hex2, resultStr);
}

void performDivision() {
    std::string hex1, hex2;
    std::cout << "Introduceti primul numar hexazecimal: ";
    std::cin >> hex1;
    std::cout << "Introduceti al doilea numar hexazecimal: ";
    std::cin >> hex2;
    
    HexInt num1(hex1);
    HexInt num2(hex2);
    HexInt result = num1 / num2;

    std::string resultStr = result.toHexString();
    std::cout << "Rezultatul impartirii este: " << resultStr << std::endl;

    writeToFile("Impartire", hex1, hex2, resultStr);
}

bool authenticate() {
    std::string password;
    std::cout << "Introduceti parola: ";
    std::cin >> password;
    return password == "parola_secreta";
}

int main() {
    if (!authenticate()) {
        std::cout << "Parola incorecta!" << std::endl;
        return 1;
    }

    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                description();
                break;
            case 2:
                performAddition();
                break;
            case 3:
                performSubtraction();
                break;
            case 4:
                performMultiplication();
                break;
            case 5:
                performDivision();
                break;
            case 6:
                std::cout << "La revedere!" << std::endl;
                return 0;
            default:
                std::cout << "Optiune invalida!" << std::endl;
        }
    }

    return 0;
}