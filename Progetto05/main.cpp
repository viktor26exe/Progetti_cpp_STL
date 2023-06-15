#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <fstream>

int main()
{
    // costruiamo un vector con tutte le parole del vocabolario
    std::fstream fileVocavolario("italiano.txt");

    // anche gli stream sono containers!!
    // NOTA: il costruttore di default crea un end of stream iterator
    std::istream_iterator<std::string> inizioFile(fileVocavolario), fineFile;

    // creiamo un vector e lo carichiamo con tutte le parole presenti nel file
    std::vector<std::string> vocabolario(inizioFile, fineFile);

    std::string daAnagrammare = "ciao"; // string è considerato un vector<char> ...

    // il container deve prima essere ordinato
    std::sort(daAnagrammare.begin(), daAnagrammare.end());

    int conta = 0;

    // versione con find
    do
    {
        conta++;

        if (std::find(vocabolario.begin(), vocabolario.end(), daAnagrammare) != vocabolario.end())
        {
            std::cout << conta << ":" << daAnagrammare << std::endl;
        }
        // next_permutation genera la permutazione successiva cambiando direttamente la parola
        // restituisce false quando ha generato tutte le permutazioni
    } while (std::next_permutation(daAnagrammare.begin(), daAnagrammare.end()));

    // versione con binary_search
    conta = 0;
    do
    {
        conta++;

        if (std::binary_search(vocabolario.begin(), vocabolario.end(), daAnagrammare))
        {
            std::cout << conta << ":" << daAnagrammare << std::endl;
        }
    } while (std::next_permutation(daAnagrammare.begin(), daAnagrammare.end()));

    return 0;
}