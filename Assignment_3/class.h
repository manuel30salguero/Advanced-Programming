#pragma once

#include <string>
#include <map>
#include <algorithm>

using namespace std;

class ContactList {
  public:
    ContactList(map<string, string> contacts);
    ContactList();

    void print_contacts() const;
    int get_num_of_contacts() const;

    void set_contacts(map<string, string> new_contacts);
    void add_contact(pair<string, string> contact);

  private:
    map<string, string> contacts;
    int num_of_contacts;

    map<string, string> uppercaseContactName() const;
};