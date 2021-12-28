# username: adminFunctions.o fileio.o generator.o landingpage.o sendToUser.o verifyName.o receipt.o
# 	g++ adminFunctions.o fileio.o generator.o landingpage.o sendToUser.o verifyName.o receipt.o -o username

tester: adminFunctions.o fileio.o generator.o sendToUser.o verifyName.o tester.o receipt.o
	g++ adminFunctions.o fileio.o generator.o sendToUser.o verifyName.o tester.o receipt.o -o tester

adminFunctions.o: adminFunctions.cpp
	g++ -c -g adminFunctions.cpp

fileio.o: fileio.cpp
	g++ -c -g fileio.cpp

generator.o: generator.cpp
	g++ -c -g generator.cpp

tester.o: tester.cpp
	g++ -c -g tester.cpp

sendToUser.o: sendToUser.cpp
	g++ -c -g sendToUser.cpp

verifyName.o: verifyName.cpp
	g++ -c -g verifyName.cpp

receipt.o: receipt.cpp
	g++ -c -g receipt.cpp

clean: 
	rm *.o username tester