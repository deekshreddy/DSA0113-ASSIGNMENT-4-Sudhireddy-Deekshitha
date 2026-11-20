
#include <iostream>
using namespace std;

class Account {
public:
    double rate() const {
        return 3.5;
    }

    ~Account() {
        cout << "Account Destructor\n";
    }
};

class SeniorAccount : public Account {
private:
    double* history;

public:
    SeniorAccount() : history(new double[100]) {
        cout << "SeniorAccount Constructor\n";
    }

    double rate() const {
        return 4.0;
    }

    ~SeniorAccount() {
        delete[] history;
        cout << "SeniorAccount Destructor\n";
    }
};

int main() {

    cout << "===== FAULTY BANKING SYSTEM =====\n";

    Account* accounts[2] = {
        new Account,
        new SeniorAccount
    };

    cout << "\nInterest Rates:\n";

    for (Account* a : accounts) {
        cout << a->rate() << '\n';
    }

    cout << "\nDeleting Accounts:\n";

    for (Account* a : accounts) {
        delete a;
    }

    cout << "\n===== OBJECT SLICING =====\n";

    Account copy = SeniorAccount();

    cout << "Base Account rate: "
         << copy.rate() << '\n';

    return 0;
}
