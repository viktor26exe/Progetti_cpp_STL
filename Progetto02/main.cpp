#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Gli iterator sono da cosiderare come dei puntatori
    auto cursore = v.begin(); // iterator a un vector di int

    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "-----------------------------------------------\n\n";

    for (auto x : v)
        std::cout << x << std::endl;

    std::cout << "-----------------------------------------------\n\n";

    // iteratore const
    for (auto it = v.cbegin(); it != v.cend(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "-----------------------------------------------\n\n";

    // reverse iterator, il ++ è considertato un decremento
    // il preincremento è preferibile perchè è più efficiente
    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "-----------------------------------------------\n\n";

    return 0;
}