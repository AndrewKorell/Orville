#include <iostream>
#include <vector>
#include <string>
#include <future>

int Rank(std::string dicTerm, std::string myTerm) {

    auto beginA = dicTerm.begin();
    //auto endA = dicTerm.end();
    auto beginB = myTerm.begin();
    //auto endB = myTerm.end();

    //We need to know the size of the longer term 
    int sizeSm = dicTerm.size() > myTerm.size() ? myTerm.size() : dicTerm.size();
    int sizeLg = dicTerm.size() < myTerm.size() ? myTerm.size() : dicTerm.size();

    std::string::iterator itA = beginA;
    std::string::iterator itB = beginB;

    int rank=0;
    int upStrength=1;
    int dwnStrength=1;

    for(int i = 0; i < sizeSm; i++) 
    {
        if(*itA == *itB)
        {
            //straight compare 
            dwnStrength--;
            rank += upStrength;
            upStrength++;
        }
        else if(toupper(*itA) == toupper(*itB)) 
        {
            //consider that one may be capitalized. 
            dwnStrength--;
            rank += upStrength;
            upStrength++;
        }
        else
        {
            upStrength--;
            rank -= dwnStrength;
            dwnStrength++;
        }

        //Make sure we're not ended up with these values at 0 or negative. 
        if(upStrength < 1) upStrength = 1;
        if(dwnStrength < 1) dwnStrength = 1;

        itA++;
        itB++;
    }

    for(int i = 0; i < (sizeLg - sizeSm); i++) 
    {
        rank -= dwnStrength;
        dwnStrength++;
    }

    return rank;
 }

int main()
{

    std::string potata = "potata";

    std::cout << "potato: " << Rank("potato", "potata") << std::endl;

    std::cout << "potatoes: " << Rank("potatoes", "potata") << std::endl;

    std::cout << "pot: " << Rank("pot", "potata") << std::endl;

    std::cout << "potash: " << Rank("potash", "potata") << std::endl;

    std::cout << "Potato: " << Rank("Potato", "potata") << std::endl;

    std::cout << "Ferby: " << Rank("Ferby", "potata") << std::endl;

    std::cout << "potassium: " << Rank("potassium", "potata") << std::endl;
}
