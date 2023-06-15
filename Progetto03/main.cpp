#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

template <typename T>
void stampa(std::vector<T> v)
{
    for (T s : v)
    {
        std::cout << s << std::endl;
    }
    std::cout << "=====================================\n";
}

int main()
{
    std::vector<std::string> alunni3A{"Marco", "Paolo", "Giovanni", "Lucia", "Marta",
                                      "Fabrizio", "Piero", "Iris", "Viktor", "Marcella", "Ettore"};

    // creazione clonando tutti gli elementi di un altro container
    // caso A: tutti promossi in quarta
    //         si indica come estremi intervallo da copiare begin e end
    std::vector<std::string> alunni4A(alunni3A.begin(), alunni3A.end());

    // caso B: Marco, Paolo e Ettore si trasferiscono e vanno esclusi dalla copia
    std::vector<std::string> alunni4ABis(alunni3A.begin() + 2, alunni3A.end() - 1);

    // ASSEGNAMENTI
    // se fornisco meno elementi di quelli presenti quelli in eccesso sono eliminati
    alunni4A.assign({"primo", "secondo", "terzo"});

    // scambio tra tutti gli elementi di due vector
    alunni4A.swap(alunni4ABis);

    std::vector<std::string> squadra{"Messi", "FANTOZZI", "Ronaldo", "Neymar", "Neuer",
                                     "Ibrahimovic", "Suarez", "Bale", "Robben"};

    // find ()
    // primo parametro: un iterator al primo elemento dell'intervallo di ricerca
    // secondo parametro: un iterator all'ultimo elemento dell'intervallo di ricerca
    // NB: l'ultimo elemento dell'intervallo è ESCLUSO dalla ricerca

    // find restituisce:
    //      - un iterator all'oggetto trovato
    //      - un iterator all'ultimo elemento dell'intervallo se non trova

    // è CASE SENSITIVE

    auto iteratorGiocatoreTrovato = std::find(squadra.begin(), squadra.end(), "FANTOZZI");
    if (iteratorGiocatoreTrovato != squadra.end())
    {
        squadra.erase(iteratorGiocatoreTrovato);
        std::cout << "FANTOZZI trovato ed eliminato\n\n";
        stampa(squadra);
    }
    else
    {
        std::cout << "FANTOZZI non trovato\n";
    }

    // ===========================================================================================

    // localizza il primo blocco di N elementi consecutivi uguali ad un valore
    std::string bitString = "101011011100101010";
    auto itTrovatiBit = std::search_n(bitString.begin(), bitString.end(), 5, '1');
    if (itTrovatiBit != bitString.end())
    {
        std::cout << "Trovati" << std::endl;
    }
    else
    {
        std::cout << "Non trovati" << std::endl;
    }

    // prepariamo la gara tra find e binary_searc
    std::vector<int> tantiNumeri;
    const int QUANTI = 10000000;
    tantiNumeri.reserve(QUANTI);

    for (int i = 0; i < QUANTI; i++)
    {
        tantiNumeri.push_back(i);
    }

    const int QUANTE_RICERCHE = 100000;

    // Ricerca sequenziale con find
    auto inizio = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < QUANTE_RICERCHE; i++)
    {
        auto it = find(tantiNumeri.begin(), tantiNumeri.end(),
                       rand() % (QUANTE_RICERCHE * 10));
    }

    auto fine = std::chrono::high_resolution_clock::now();
    auto microsecondi = std::chrono::duration_cast<std::chrono::microseconds>(fine - inizio);
    auto secondi = std::chrono::duration_cast<std::chrono::seconds>(fine - inizio);
    std::cout << microsecondi.count() << " microsec  -  ";
    std::cout << secondi.count() << " sec" << std::endl;

    // Ricerca binaria con binary_search
    inizio = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < QUANTE_RICERCHE; i++)
    {
        bool trovato = std::binary_search(tantiNumeri.begin(), tantiNumeri.end(),
                                          rand() % (QUANTI * 2));
    }

    fine = std::chrono::high_resolution_clock::now();
    microsecondi = std::chrono::duration_cast<std::chrono::microseconds>(fine - inizio);
    secondi = std::chrono::duration_cast<std::chrono::seconds>(fine - inizio);
    std::cout << microsecondi.count() << " microsec  -  ";
    std::cout << secondi.count() << "  sec" << std::endl;

    return 0;
}