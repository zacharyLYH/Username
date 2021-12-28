#include<string>
using namespace std;
class Header{
    private:
        
    public :
        int sumOfClause; 
        void write(string username, string name);
        bool checkExist(string checkExistsUsername);//for admin uses
        int clause[4] = {1,1,0,0};
        int takeName(std::string first, std::string last, std::string  middle, std::string suffix);
        void twoClause(std::string first, std::string last, bool cameFromOthers);
        void threeClause(std::string first, std::string last, string middle);
        void fourClause(std::string first, std::string last, string middle, string suffix);
        void clauseCounter(std::string first, std::string last, std::string  middle, std::string suffix);
        void storeNum(int number, int i) {
            clause[i] = number;
        }
        bool sendtoUser(string username, string givenName);
        void receipt(string username, string name);
        void admin();
        string returnUsername(string name);
};