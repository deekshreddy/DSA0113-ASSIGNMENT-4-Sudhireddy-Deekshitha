#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual void display() const {
        cout << "General Account\n";
        cout << "Interest Rate: " << rate() << "%\n";
    }

    virtual ~Account() {
        cout << "Account Destructor\n";
    }
};

class SeniorAccount : public Account {
private:
    double* history;

public:
    SeniorAccount() : history(new double[100]) {
        cout << "SeniorAccount Constructor\n";

        for (int i = 0; i < 100; i++) {
            history[i] = 0.0;
        }
    }

    double rate() const override {
        return 4.0;
    }

    void display() const override {
        cout << "Senior Citizen Account\n";
        cout << "Interest Rate: " << rate() << "%\n";
    }

    ~SeniorAccount() override {
        delete[] history;
        cout << "SeniorAccount Destructor\n";
    }
};

int main() {

    cout << fixed << setprecision(1);

    cout << "===== REPAIRED BANKING SYSTEM =====\n";

    vector<unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Account>());

    accounts.push_back(make_unique<SeniorAccount>());

    cout << "\n===== ACCOUNT DETAILS =====\n";

    for (const auto& account : accounts) {
        account->display();
        cout << '\n';
    }

    cout << "===== INTEREST RATE SUMMARY =====\n";

    for (const auto& account : accounts) {
        cout << account->rate() << "%\n";
    }

    cout << "\n===== END OF PROGRAM =====\n";

    return 0;
}
