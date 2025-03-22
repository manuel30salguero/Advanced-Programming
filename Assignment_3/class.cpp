#include <iostream>
#include "class.h"

ContactList::ContactList(map<string, string> contacts)
    : contacts(contacts), num_of_contacts(contacts.size()) {}

ContactList::ContactList() : contacts(), num_of_contacts(0) {}

int ContactList::get_num_of_contacts() const { return num_of_contacts; }

void ContactList::print_contacts() const {
  if (get_num_of_contacts() == 0) {
    cout << "Currently you have no contacts, please add some!" << endl;
    return;
  }

  cout << "Number of contacts: " << get_num_of_contacts() << endl;
  for (const auto& contact : contacts) {
    cout << "> " << contact.first << '-' << contact.second << endl;
  }
}

void ContactList::set_contacts(map<string, string> new_contacts) { 
  contacts = new_contacts; 
  num_of_contacts = contacts.size();  
}

void ContactList::add_contact(pair<string, string> contact) {
  contacts.insert(contact);
  num_of_contacts = contacts.size();    
}

map<string, string> ContactList::uppercaseContactName() const{
  map<string, string> uppercaseContacts;
  for(const auto& contact : contacts){
    string name = contact.first;
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    uppercaseContacts.insert({name, contact.second});
  }
  return uppercaseContacts;
}