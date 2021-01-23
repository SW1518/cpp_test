//#pragma once
#include "hello.h"
#include <memory>
class Student {
	private:
		char name;
		int id;
	public:
		Student();
		Student& operator=(const Student&) = delete; //disable copy function
		virtual void print_info();
};

void Student::print_info(){
	std::cout<<"Name is:"<<Student::name;
	std::cout<<"Id is:"<<Student::id;
}

Student::Student(){
	std::cout<<"base object created"<<std::endl;
}

class Uni_student : public Student{
	private:
		int uni_id;
	public:
		Uni_student();
		virtual void print_info();
		~Uni_student();//destructor
		Uni_student(Uni_student&& rhs);//move constructor
		Uni_student& operator=(Uni_student&& rhs);//move assignment operator
		Uni_student(const Uni_student&) = default;//copy constructor
		Uni_student& operator=(const Uni_student&) = default;//copy assign
};

Uni_student::Uni_student(){
	std::cout<<"derived object created"<<std::endl;
}
void Uni_student::print_info(){
	std::cout<<"The uni id is:"<<Uni_student::uni_id<<std::endl;
}

int a = { 2 };
int &b = a;
auto c = b;
decltype(auto)d = b;
std::unordered_map<std::string, int> m;

//Template
template<typename T>
inline T const& Max (T const& a, T const& b) noexcept 
{
	return a > b ? a : b;
}

//enum class
enum class Colour {red, green};

int main() {
	Student tom;
	Student *ptr_s {nullptr};
	ptr_s = &tom;
	std::unique_ptr<Student> base_s = std::make_unique<Uni_student>();

	base_s->print_info();//Child class print
	base_s->Student::print_info();//Base class print

	a = { 5 };
	b = { 3 };
	std::swap(a,b);
	auto n = m;
	auto larger_num {Max(a,b)};
	auto d = static_cast<float>(larger_num); 
	Colour col;
	std::cout<<"colour is:"<<static_cast<int>(col)<<std::endl;
	std::nullptr_t ptr;
	if (nullptr == 0){
		std::cout<<"nullprt = 0"<<std::endl;
	}
	//std::cout<<ptr<<std::endl;
	std::cout<<"d is:"<<d<<std::endl;
	std::cout<<larger_num<<std::endl;
	//decltype(b);
	std::cout << b << std::endl;
	std::cout << &b << std::endl;
	std::cout << &a << std::endl;
	std::cout << a << std::endl;
	std::cout << typeid(b).name() << std::endl;
	return 0;
}
