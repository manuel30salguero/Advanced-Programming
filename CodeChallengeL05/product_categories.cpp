#include <iostream>
#include <set>

using namespace std;

void addNewCategory(set<string>& categories, string newCategory){
    cout << "Adding category: " << newCategory << endl;
    categories.insert(newCategory);
    cout << endl;
}

void displayCategory(const set<string>& categories){
    cout << "Product Categories:\n";
    for (const auto& category : categories) {
        cout << "- " << category << "\n";
    }
}

int main() {
    set<string> productCategories;

    // Adding categories
    // productCategories.insert("Electronics");
    // productCategories.insert("Accessories");
    // productCategories.insert("Peripherals");

    addNewCategory(productCategories, "Electronics");
    addNewCategory(productCategories, "Accessories");
    addNewCategory(productCategories, "Peripherals");

    // std::cout << "Product Categories:\n";
    // for (const auto& category : productCategories) {
    //     std::cout << "- " << category << "\n";
    // }

    displayCategory(productCategories);

    return 0;
}