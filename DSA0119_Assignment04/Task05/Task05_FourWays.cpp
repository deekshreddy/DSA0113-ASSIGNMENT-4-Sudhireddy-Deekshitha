
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Cart {
private:
    string item;
    double price;

public:
    Cart(string i = "No Item", double p = 0)
        : item(i), price(p) {}

    void display() const {
        cout << "Item: " << item << '\n';
        cout << "Price: Rs. " << price << '\n';
    }
};

int main() {

    cout << fixed << setprecision(2);

    cout << "===== DIRECT OBJECT =====\n";

    Cart c1("Rice", 60);

    c1.display();

    cout << "\n===== POINTER ACCESS =====\n";

    Cart* p = &c1;

    p->display();

    cout << "\n===== REFERENCE ACCESS =====\n";

    Cart& ref = c1;

    ref.display();

    cout << "\n===== DYNAMIC OBJECT =====\n";

    Cart* dynamicCart = new Cart("Oil", 180);

    dynamicCart->display();

    delete dynamicCart;
    dynamicCart = nullptr;

    cout << "\nMemory released successfully.\n";

    return 0;
}
