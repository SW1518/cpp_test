#include <stdio.h>
#include <iostream>
#include <memory>

class Investment {};
class Stock      : public Investment {};
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
                        };
    std::unique_ptr<Investment, decltype(delInvmt)> pInv (nullptr, delInvmt);
    return 0;
}