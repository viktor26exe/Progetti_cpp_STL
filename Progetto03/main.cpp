#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void stampa (std::vector<T> v)
{
    for (T s: v)
    {
        std::cout << s << std::endl;
    }
    std::cout << "=====================================\n";
} 


int main()
{
    std::vector<std::string> alunni3A {"Marco", "Paolo", "Giovanni", "Lucia", "Marta", 
    "Fabrizio", "Piero", "Iris", "Viktor", "Marcella", "Ettore"};

    // creazione clonando tutti gli elementi di un altro container
    // caso A: tutti promossi in quarta
    //         si indica come estremi intervallo da copiare begin e end
    std::vector<std::string> alunni4A (alunni3A.begin(), alunni3A.end());
    
    // caso B: Marco, Paolo e Ettore si trasferiscono e vanno esclusi dalla copia
    std::vector <std::string> alunni4ABis (alunni3A.begin() + 2, alunni3A.end() - 1);

    // ASSEGNAMENTI
    // se fornisco meno elementi di quelli presenti quelli in eccesso sono eliminati 
    alunni4A.assign( {"primo", "secondo", "terzo"}); 

    // scambio tra tutti gli elementi di due vector
    alunni4A.swap(alunni4ABis);


    return 0;
}