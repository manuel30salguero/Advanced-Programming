#include <iostream>
#include <queue>

using namespace std;

void addOrder(queue<string>& orders, string newOrder){
    cout << "New Order: \n" << newOrder << endl;
    orders.push(newOrder);
}

void processOrders(queue<string>& orders){
    while(!orders.empty()) {
        cout << "Processing " << orders.front() << endl;
        orders.pop();
    }
}

int main() {
    std::queue<std::string> orders;

    // Adding orders
    // orders.push("Order#1: Laptop");
    // orders.push("Order#2: Mouse");
    // orders.push("Order#3: Keyboard");
    addOrder(orders, "Order#1: Laptop");
    addOrder(orders, "Order#2: Mouse");
    addOrder(orders, "Order#3: Keyboard");

    // Processing orders
    // while (!orders.empty()) {
    //     std::cout << "Processing " << orders.front() << std::endl;
    //     orders.pop();
    // }
    processOrders(orders);

    return 0;
}