# Username
Takes a First, Last, Middle, Suffix name (where applicable) and generates a username based on certain username formation rules. Username formed will check against a database of usernames to check availability, if a name is unavailable a new one will be formed. A satisfiable name will be registered into the database.

tester.cpp : 
Suite to test functionality of
1) generator.cpp 
- clauseCounter

generator.cpp:
-clauseCounter : Takes a well-formed name and counts the number of clauses in the name. For example : Muhammad Ali is a 2 clause name, John H. Smith is a 3 clause name, John H. Smith Jr. is a 4 clause name, Cheng Xiu Wen is a 3 clause name. The resulting number of clauses is stored for use of processing in username formation operations.
-twoClause : Takes a two clause name, such as John Smith and Jeremy Chan, and generates usernames. 

landingpage.cpp:
Generates a user interface that connects to the backend. This takes an First, Last, Middle and Suffix name (where applicable) and returns a username. A user may accept or reject a generated username. Upon acceptance, the program terminates. Upon rejection, the program regenerates usernames until satisfaction.
