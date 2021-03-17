#include <string>
#include <memory.h>

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

int main(int argc, char * argv[]){
    Widget && var1 = Widget(); // rvalue reference
    auto&& var2 = var1; // universal reference
    return 0;
}