#include <string>
#include <memory.h>

class Widget{
    public:
        Widget(Widget&& rhs) : s(std::move(rhs.s))
        { ++moveCtorCalls;}//only parameter
        //Widget(Widget&& rhs) : s(std::forward<std::string>(rhs.s))
        //{ ++ moveCtorCalls;}//parameter and its type
    private:
        static std::size_t moveCtorCalls;
        std::string s;
};

int main(int argc, char * argv[]){
    return 0;
}