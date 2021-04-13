#include <vector>
#include <functional>

using FilterContainer = std::vector<std::function<bool(int)>>;
FilterContainer filters;

int main(int argc, char * argv[])
{
    filters.emplace_back(
        [](int value) {return value % 5 == 0;}
    );

    std::vector<double> data;
    auto func_c14 = [data = std::move(data)] {/*use of data*/};

    auto func_c11 = std::bind([] (const std::vector<double>& data) {/*use of data*/},std::move(data));

    return 0;
}
