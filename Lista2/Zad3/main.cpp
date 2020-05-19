#include <iostream>
#include <vector>

int scalar(const std::vector<int> &v, const std::vector<int> &v2)
{
    int result = 0;

    for (size_t i = 0; i < v.size(); ++i)
    {
        result += v[i] * v2[i];
    }
    
    return result;
}

int main()
{
    const std::vector<int> v = {1, 2, 3};
    const std::vector<int> v2 = {4, 5, 6};
    std::cout << scalar(v, v2) << std::endl;

    return 0;
}
