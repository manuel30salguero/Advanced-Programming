/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

 #include <map>
 #include "class.h" 
 
 void sandbox() {
   map<string, string> contacts = {{"Deyanira", "0998119191"}};
   ContactList elias_contacts{};
   elias_contacts.set_contacts(contacts);
 }