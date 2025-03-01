#include <iostream>
#include <stack>

using namespace std;

void addRestockBatch(stack<pair<string, int>>& restocks, pair<string, int> restockBatch){
    cout << "New restock batch: " << restockBatch.first << endl ;
    restocks.push(restockBatch);
}

void processRestocks(stack<pair<string,int>>& restocks){
    cout << "Processing stack of restocks:" << endl;
    while(!restocks.empty()){
        pair<string,int> item = restocks.top();
        cout << "- " << item.first << " : " << item.second << endl;
        restocks.pop();
    }
}

int main() {
    stack<pair<string, int>> restocks;

    // Adding restock batches
    // restocks.push({"Mouse", 10});
    // restocks.push({"Laptop", 2});
    // restocks.push({"Keyboard", 5});

    addRestockBatch(restocks, {"Mouse", 10});
    addRestockBatch(restocks, {"Laptop", 2});
    addRestockBatch(restocks, {"Keyboard", 5});

    cout << endl;

    // Processing restocks
    // while (!restocks.empty()) {
    //     auto item = restocks.top();
    //     cout << "Restocking " << item.second << " units of " << item.first << endl;
    //     restocks.pop();
    // }
    processRestocks(restocks);

    return 0;
}