#include <string>
#include <memory.h>
#include <math.h>
#include <set>
#include <chrono>
#include <vector>
#include <map>

class Widget{
    public:
        Widget() = default;
        Widget(Widget&& rhs) : s(std::move(rhs.s))
        { ++moveCtorCalls;}//only parameter
        //Widget(Widget&& rhs) : s(std::forward<std::string>(rhs.s))
        //{ ++ moveCtorCalls;}//parameter and its type
    private:
        static std::size_t moveCtorCalls;
        std::string s;
};

class Person {
    public:
        template<typename T>
        explicit Person(T&& n) : name(std::forward<T>(n)) {}
        explicit Person(int idx) : name(nameFromIdx(idx)) {} //Perfect forwarding
        std::string nameFromIdx(int idx);
    private:
        std::string name;
};

std::multiset<std::string>names;

template<typename T>
void logAndAdd(T&& name)
{
    auto now = std::chrono::system_clock::now();
    //log(now, "logAndAdd");
    names.emplace(std::forward<T>(name));
}

int main(int argc, char * argv[]){
    Widget && var1 = Widget(); // rvalue reference
    auto&& var2 = var1; // universal reference
    std::string petName("Darla");
    logAndAdd(petName);
    logAndAdd(std::string("Perephone"));
    logAndAdd("Patty Dog");
    return 0;
}