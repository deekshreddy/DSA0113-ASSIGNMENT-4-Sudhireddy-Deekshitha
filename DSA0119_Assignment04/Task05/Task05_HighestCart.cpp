
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Cart {
private:
    string customer;
    string items[10];
    double prices[10];
    int n;
    double discount;

public:
    Cart(string name)
        : customer(name), n(0), discount(0) {}

    Cart& add(const string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }

        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += prices[i];
        }

        return sum * (100 - discount) / 100;
    }

    void display() const {
        cout << "Customer: " << customer << '\n';
        cout << "Cart Total: Rs. " << total() << '\n';
    }
};

int main() {

    cout << fixed << setprecision(2);

    Cart c1("Customer 1");
    Cart c2("Customer 2");
    Cart c3("Customer 3");

    c1.add("Rice", 60)
      .add("Dal", 120)
      .setDiscount(10);

    c2.add("Oil", 180)
      .add("Sugar", 80)
      .add("Wheat", 100);

    c3.add("Milk", 50)
      .add("Fruits", 200)
      .add("Vegetables", 150)
      .setDiscount(5);

    Cart* carts[3] = {&c1, &c2, &c3};

    int count = 3;

    Cart* highestCart = carts[0];

    for (int i = 1; i < count; i++) {

        if (carts[i]->total() > highestCart->total()) {
            highestCart = carts[i];
        }
    }

    cout << "===== ALL CUSTOMER CARTS =====\n\n";

    for (int i = 0; i < count; i++) {
        carts[i]->display();
        cout << '\n';
    }

    cout << "===== HIGHEST CART =====\n";

    highestCart->display();

    return 0;
}
