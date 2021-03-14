#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include "smart_ptr.hpp"

using Gadget = std::unordered_map<std::string, std::string>;

struct Widget::Impl {
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

Widget::Widget()
: pImpl(std::make_unique<Impl>())
{}

Widget::~Widget() = default;

Widget::Widget(Widget&& rhs) noexcept = default;
Widget& Widget::operator=(Widget&& rhs) noexcept = default;

Widget::Widget(const Widget& rhs)
: pImpl(nullptr)
{ if(rhs.pImpl) pImpl = std::make_unique<Impl>(*rhs.pImpl);}
Widget& Widget::operator=(const Widget& rhs)
{
    if (!rhs.pImpl) pImpl.reset();
    else if(!pImpl) pImpl=std::make_unique<Impl>(*rhs.pImpl);
    else *pImpl = *rhs.pImpl;
    return *this;
}
class Investment {
    const std::string ID = "investment";
    public:
        void getID() noexcept;
};

void Investment::getID() noexcept
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
    //pShar->getID();
    auto spw = std::make_shared<Investment>();
    std::weak_ptr<Investment> wpw(spw);
    //auto temp = *wpw; ** No deference for weak pointer **
    auto stemp = *spw;
    // method 1
    std::shared_ptr<Investment> spw1 = wpw.lock();
    // method 2
    auto spw2 = wpw.lock();
    // method 3
    std::shared_ptr<Investment> spw3(wpw);
    if (spw1 == spw2)
        std::cout<<"equal"<<std::endl;
    spw = nullptr;
    if (wpw.expired())
        std::cout<<"wpw is nullptr"<<std::endl;
    system("pause");
    return 0;
}