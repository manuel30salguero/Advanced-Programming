#include <iostream>
#include <vector>

using namespace std;

void addItem(vector<string>& customerCart, string item){
    cout << item << "was added to your cart!" << endl;
    customerCart.push_back(item);
}

void displayItems(const vector<string>& customerCart){
    cout << "The items in your shopping cart are:" << endl;
    for(const string item: customerCart){
        cout << "- " << item << endl;
    }
}

int main() {
    vector<string> customerCart;

    // Adding items to cart
    // customerCart.push_back("Laptop");
    // customerCart.push_back("Mouse");
    // customerCart.push_back("Keyboard");
    addItem(customerCart, "Laptop");
    addItem(customerCart, "Mouse");
    addItem(customerCart, "Keyboard");

    cout << endl;

    // cout << "Items in customer cart:\n";
    // for (const auto& item : customerCart) {
    //     cout << "- " << item << "\n";
    // }
    displayItems(customerCart);

    return 0;
}