/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

 #include <fstream>
 #include <iostream>
 #include <queue>
 #include <set>
 #include <string>
 #include <sstream>
 #include <unordered_set>
 #include <cmath>
 #include <algorithm>
 
 std::string kYourName = "Manuel Salguero"; // Don't forget to change this!
 
 /**
  * Takes in a file name and returns a set containing all of the applicant names as a set.
  *
  * @param filename  The name of the file to read.
  *                  Each line of the file will be a single applicant's name.
  * @returns         A set of all applicant names read from the file.
  *
  * @remark Feel free to change the return type of this function (and the function
  * below it) to use a `std::unordered_set` instead. If you do so, make sure
  * to also change the corresponding functions in `utils.h`.
  */
 std::set<std::string> get_applicants(std::string filename) {
   // STUDENT TODO: Implement this function.
   std::set<std::string> applicants;
 
   std::ifstream file(filename);
 
   if (!file.is_open()) return applicants;
 
   std::string line;
 
   while(std::getline(file,line)){
     applicants.insert(line);
   }
 
   file.close();
 
   return applicants;
 }
 
 std::string initials(const std::string& value){
   std::string name_initials;
   std::stringstream value_stream(value);
 
   std::string portion;
 
   while(std::getline(value_stream, portion, ' ')){
     name_initials += portion[0];
   }
   
   return name_initials;
 }
 
 /**
  * Takes in a set of student names by reference and returns a queue of names
  * that match the given student name.
  *
  * @param name      The returned queue of names should have the same initials as this name.
  * @param students  The set of student names.
  * @return          A queue containing pointers to each matching name.
  */
 std::queue<const std::string*> find_matches(const std::string& name, const std::set<std::string>& students) {
   // STUDENT TODO: Implement this function.
   std::string seeker_initials = initials(name);
   std::queue<const std::string*> matching_names;
 
   for(const std::string& student: students)
     if (seeker_initials == initials(student)) matching_names.push(&student);
 
   return matching_names;
 }
 
 /**
  * Takes in a queue of pointers to possible matches and determines the one true match!
  *
  * You can implement this function however you'd like, but try to do something a bit
  * more complicated than a simple `pop()`.
  *
  * @param matches The queue of possible matches.
  * @return        Your magical one true love.
  *                Will return "NO MATCHES FOUND." if `matches` is empty.
  */
 
 std::string join_first_names(std::string name1, std::string name2){
   std::string result, portion;
   name1[0] = std::tolower(name1[0]);
   name2[0] = std::tolower(name2[0]);
   std::istringstream name_stream1(name1);
   std::istringstream name_stream2(name2);
 
   std::getline(name_stream1, portion, ' ');
   result += portion;
   std::getline(name_stream2, portion, ' ');
   result += portion;
 
   return result;
 }
 
 std::vector<int> calculate_percentage(const std::vector<int>& ocurrences){
   int size = ocurrences.size();
   if(size == 2) return ocurrences;
   int limit = (int) ceil(size/(double)2);
 
   std::vector<int> percentage;
   
   for(int i=0; i < limit; i++){
     if ((size % 2 != 0) && (i == (limit - 1))){
       percentage.push_back(ocurrences[i]);
       break;
     } 
     percentage.push_back(ocurrences[i] + ocurrences[size-i-1]);
   }
   return calculate_percentage(percentage);
 }
 
 
 std::stringstream compute_compatibility(const std::string& combined_names){
   std::set<char> letters;
   std::vector<int> ocurrences;
   
   for (const char& letter : combined_names){
     if (letters.contains(letter)) continue;
 
     ocurrences.push_back(std::ranges::count(combined_names, letter));
     letters.insert(letter);
   }
 
   std::vector<int> percentage = calculate_percentage(ocurrences);
   std::stringstream compatibility;
   compatibility << percentage[0] << percentage[1] ;
   return compatibility;
 }
 
 std::string get_match(std::queue<const std::string*>& matches) {
   // STUDENT TODO: Implement this function.
   // love formula: https://www.tiktok.com/@profejeff/video/7109985021242494214?lang=en
 
   if(matches.empty()) return "NO MATCHES FOUND.";
 
   std::pair<std::string, int> best_match = {"",0};
 
   while(!matches.empty()) {
     std::string match = *matches.front();
     std::string combined_first_names = join_first_names(kYourName, match);
     int percentage = 0;
     
     std::stringstream compatibility = compute_compatibility(combined_first_names);
     compatibility >> percentage;
 
     if (best_match.second < percentage){
       best_match.first = match;
       best_match.second = percentage;
     }
 
     matches.pop();
   }
 
   std::cout << "Your perfect match is " << best_match.first << " with"<< std::endl
             << "whom you share a compatibility of " << best_match.second << "%" << std::endl;
 
   return best_match.first;
 }
 
 /* #### Please don't remove this line! #### */
 #include "autograder/utils.hpp"
 
