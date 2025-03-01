#include <iostream>
#include <map>

using namespace std;

void displayInventory(const map<string, int>& inventory) {
    cout << "Current Inventory:\n";
    for (const auto& item : inventory) {
        cout << item.first << ": " << item.second << " in stock\n";
    }
    cout << endl;
}

void addNewProduct(map<string, int>& inventory, string newProduct, int quantity){
    cout << "Adding the product:" << newProduct << endl;
    inventory.insert({newProduct, quantity});
}

void updateInventory(map<string,int>& inventory, string product, int quantity){
    cout << "Updating the product:" << product << endl;
    inventory[product] = quantity;
}

int main() {
    map<string, int> inventory; // Adding products
    inventory["Laptop"] = 5;
    inventory["Mouse"] = 20;
    inventory["Keyboard"] = 10;

    addNewProduct(inventory, "Router", 15);
    updateInventory(inventory, "Mouse", 19);
    displayInventory(inventory);

    return 0;
}