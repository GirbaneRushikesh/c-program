#include <iostream>
#include <sstream> // for stringstream

using namespace std;

int main() {
    string name1 = "AlphaUser";
    string name2 = "BetaUser";
    float balance1 = 0;
    float balance2 = 0;

    string history1[20];
    string history2[20];
    int count1 = 0, count2 = 0;

    int choice;
    float amount;

    cout << "?? Welcome to Simple Bank in Rupees ??\n";

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Deposit (AlphaUser)\n";
        cout << "2. Withdraw (AlphaUser)\n";
        cout << "3. Transfer to BetaUser\n";
        cout << "4. Show AlphaUser Info\n";
        cout << "5. Show BetaUser Info\n";
        cout << "6. Show AlphaUser History\n";
        cout << "7. Show BetaUser History\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        stringstream ss; // for string conversion

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit in ?: ";
                cin >> amount;
                balance1 += amount;
                ss << "Deposited ?" << (int)amount;
                history1[count1++] = ss.str();
                cout << "? Deposit successful.\n";
                break;

            case 2:
                cout << "Enter amount to withdraw in ?: ";
                cin >> amount;
                if (amount <= balance1) {
                    balance1 -= amount;
                    ss.str(""); ss.clear(); // reset stringstream
                    ss << "Withdrew ?" << (int)amount;
                    history1[count1++] = ss.str();
                    cout << "? Withdraw successful.\n";
                } else {
                    cout << "? Not enough balance.\n";
                }
                break;

            case 3:
                cout << "Enter amount to transfer in ?: ";
                cin >> amount;
                if (amount <= balance1) {
                    balance1 -= amount;
                    balance2 += amount;

                    ss.str(""); ss.clear();
                    ss << "Transferred ?" << (int)amount << " to BetaUser";
                    history1[count1++] = ss.str();

                    ss.str(""); ss.clear();
                    ss << "Received ?" << (int)amount << " from AlphaUser";
                    history2[count2++] = ss.str();

                    cout << "? Transfer successful.\n";
                } else {
                    cout << "? Not enough balance to transfer.\n";
                }
                break;

            case 4:
                cout << "\n--- AlphaUser Info ---\n";
                cout << "Name: " << name1 << "\n";
                cout << "Balance: ?" << balance1 << "\n";
                break;

            case 5:
                cout << "\n--- BetaUser Info ---\n";
                cout << "Name: " << name2 << "\n";
                cout << "Balance: ?" << balance2 << "\n";
                break;

            case 6:
                cout << "\nAlphaUser Transaction History:\n";
                for (int i = 0; i < count1; i++) {
                    cout << "- " << history1[i] << endl;
                }
                break;

            case 7:
                cout << "\nBetaUser Transaction History:\n";
                for (int i = 0; i < count2; i++) {
                    cout << "- " << history2[i] << endl;
                }
                break;

            case 0:
                cout << "?? Exiting. Thank you for using Simple Bank!\n";
                break;

            default:
                cout << "? Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}

