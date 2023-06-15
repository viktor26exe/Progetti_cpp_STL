#include <iostream>
#include <vector>
#include <set> // molto veloci negli inserimenti e nella cancelazione e mantiene da solo l'ordine secondo un criterio e rifiuta i duplicati
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype> // per tolower

int main()
{
    std::vector<std::string> fileDaFondare{"400_parole_composte.txt", "1000_parole_italiane_comuni.txt", "9000_nomi_propri.txt", "60000_parole_italiane.txt",
                                           "95000_parole_italiane_con_nomi_propri.txt", "110000_parole_italiane_con_nomi_propri.txt", "280000_parole_italiane.txt",
                                           "660000_parole_italiane.txt", "coniugazione_verbi.txt", "lista_38000_cognomi.txt", "lista_bedwors.txt", "lista_cognomi.txt", "parole_uniche.txt"};

    std::set<std::string> fusione; // conterrà tutte le parole

    std::string parti = "";
    std::cin >> parti;

    for (std::string nomeFile : fileDaFondare)
    {
        std::ifstream leggi(nomeFile);
        std::string parola = "";
        std::cout << "Scansione del file " << nomeFile << "...\n";
        int contaParola = 0; // track del progresso

        while (std::getline(leggi, parola))
        {
            contaParola++;
            if (contaParola % 1000 == 0)
            {
                std::cout << "Esaminando " << parola << "...\n";
            }

            // Converte in minuscolo ogni carattere
            std::transform(parola.begin(), parola.end(), parola.begin(), ::tolower);

            //auto trovata = std::lower_bound(fusione.begin(), fusione.end(), parola);

            // parola nuova che inseriamo
            /*
            if (trovata == fusione.end() || parola != *trovata)
            {
                fusione.insert(trovata, parola);
            }
            */

           fusione.insert(parola);
        }

        leggi.close();
        leggi.clear();
    }

    // scrittura del dizionario ordinato su file
    std::ofstream scrivi ("italiano.txt");
    for(std::string s : fusione)
    {
        scrivi << s << std::endl;
    }

    scrivi.close();

    return 0;
}