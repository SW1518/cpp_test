#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>

class Investment {
    const std::string ID = "investment";
    public:
        void getID();
};

void Investment::getID()
{
    std::cout<<ID<<std::endl;
}
class Stock      : public Investment {
    const std::string ID = "stock";
};
class Bond       : public Investment {};
class RealEstate : public Investment {};

template<typename Ty>
void makeLogEntry(Ty &&)
{
    std::cout<<"make logs"<<std::endl;
}

int main (int argc,char * argv[])
{
    auto delInvmt = [] (Investment * pInvestment)
                        {
                            makeLogEntry(pInvestment);
                            delete pInvestment;
                        };//custom deleter
    
    std::unique_ptr<Investment, decltype(delInvmt)> pInv (nullptr, delInvmt);
    std::shared_ptr<Investment> pShar(new Stock, delInvmt);
    pShar->getID();
    auto spw = std::make_shared<Investment>();
    std::weak_ptr<Investment> wpw(spw);
    //auto temp = *wpw; ** No deference for weak pointer **
    auto stemp = *spw;
    system("pause");
    return 0;
}