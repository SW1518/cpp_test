#include <string>
#include <memory.h>
#include <math.h>
#include <set>
#include <chrono>
#include <vector>
#include <map>
#include <type_traits>

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
        template<typename T, typename = typename std::enable_if<
                                        !std::is_base_of<Person, typename std::decay<T>::type>::value // Constraint: Only call perfect fordwarding constr when type!=Person
                                        &&
                                        !std::is_integral<std::remove_reference_t<T>>::value // Distinguish integral/non-integral arguments
                                        >
        >
        // Less code in C14
        // template<typename T, typename = typename std::enable_if_t<
        //                                 !std::is_base_of<Person,
        //                                                 typename std::decay_t<T>
        //                                                 >::value
        //                                 >
        // >
        explicit Person(T&& n) : name(std::forward<T>(n)) {
            // assertion
            static_assert(std::is_constructible<std::string, T>::value,
            "Parameter n can't be used to construct a std::string");
        }
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

// Avoid universal ref overloading


int main(int argc, char * argv[]){
    Widget && var1 = Widget(); // rvalue reference
    auto&& var2 = var1; // universal reference
    std::string petName("Darla");
    logAndAdd(petName);
    logAndAdd(std::string("Perephone"));
    logAndAdd("Patty Dog");
    return 0;
}