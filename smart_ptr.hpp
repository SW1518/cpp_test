#pragma once
#include <memory>
class Widget{
    public:
        Widget();
        ~Widget();
        Widget(Widget&& rhs) noexcept;//move ctor
        Widget& operator=(Widget&& rhs) noexcept;

        Widget(const Widget& rhs);
        Widget& operator=(const Widget& rhs);//copy ctor
    private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;
};