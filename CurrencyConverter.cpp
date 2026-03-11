#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class ConversionRecord {
public:
    string fromCurrency;
    string toCurrency;
    double inputAmount;
    double outputAmount;

    ConversionRecord(string from, string to, double in, double out) {
        fromCurrency = from;
        toCurrency = to;
        inputAmount = in;
        outputAmount = out;
    }
};

class HistoryManager {
private:
    vector<ConversionRecord> history;

public:
    void addRecord(string from, string to, double input, double output) {
        ConversionRecord record(from, to, input, output);
        history.push_back(record);
    }

    void showHistory() {
        if(history.empty()) {
            cout << "\nNo conversion history available.\n";
            return;
        }

        cout << "\n====== Conversion History ======\n";

        for(int i = 0; i < history.size(); i++) {
            cout << i+1 << ". "
                 << history[i].inputAmount << " "
                 << history[i].fromCurrency << " -> "
                 << history[i].outputAmount << " "
                 << history[i].toCurrency << endl;
        }

        cout << endl;
    }
};

class CurrencyConverter {
private:
    double inrToUsdRate;
    double eurToInrRate;

public:

    CurrencyConverter() {
        inrToUsdRate = 83.0;
        eurToInrRate = 90.0;
    }

    double convertINRtoUSD(double amount) {
        return amount / inrToUsdRate;
    }

    double convertEURtoINR(double amount) {
        return amount * eurToInrRate;
    }

};

class UI {
private:
    CurrencyConverter converter;
    HistoryManager history;

public:

    void printHeader() {
        cout << "\n=================================\n";
        cout << "      ADVANCED CURRENCY TOOL\n";
        cout << "=================================\n";
    }

    void showMenu() {
        cout << "\nChoose Conversion Option\n";
        cout << "1. INR -> USD\n";
        cout << "2. EUR -> INR\n";
        cout << "3. View Conversion History\n";
        cout << "4. Exit\n";
    }

    double getAmount() {
        double amount;

        while(true) {
            cout << "\nEnter amount: ";
            cin >> amount;

            if(cin.fail() || amount <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid amount. Try again.\n";
            }
            else {
                return amount;
            }
        }
    }

    void performINRtoUSD() {

        double amount = getAmount();

        double result = converter.convertINRtoUSD(amount);

        cout << fixed << setprecision(2);

        cout << "\nConverted Amount: "
             << result << " USD\n";

        history.addRecord("INR","USD",amount,result);
    }

    void performEURtoINR() {

        double amount = getAmount();

        double result = converter.convertEURtoINR(amount);

        cout << fixed << setprecision(2);

        cout << "\nConverted Amount: "
             << result << " INR\n";

        history.addRecord("EUR","INR",amount,result);
    }

    void startProgram() {

        int choice;

        while(true) {

            printHeader();
            showMenu();

            cout << "\nEnter choice: ";
            cin >> choice;

            if(cin.fail()) {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "\nInvalid input.\n";
                continue;
            }

            switch(choice) {

                case 1:
                    performINRtoUSD();
                    break;

                case 2:
                    performEURtoINR();
                    break;

                case 3:
                    history.showHistory();
                    break;

                case 4:
                    cout << "\nThank you for using Currency Tool.\n";
                    return;

                default:
                    cout << "\nInvalid option.\n";
            }

        }

    }

};

int main() {

    UI program;

    program.startProgram();

    return 0;
}