#include<string>
using namespace std;
class Header{
    private:
        
    public :
        int sumOfClause; 
        void write(string username, string name);
        void read(string &readTo);
        void read(string &readTo, string checkExistsUsername);//for admin uses
        int clause[4] = {1,1,0,0};
        int takeName(std::string first, std::string last, std::string  middle, std::string suffix);
        std::string twoClause(std::string first, std::string last);
        void clauseCounter(std::string first, std::string last, std::string  middle, std::string suffix);
        void storeNum(int number, int i) {
            clause[i] = number;
        }
        

};