#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

int main()
{
    // COSTRUZIONE
    std::vector<int> v1; // vector con 0 elementi (iniziali)

    // NB: è richiesto il costruttore di default!
    // occhio alle performance per via dei costruttori di default
    std::vector<int> v2(15);           // vector con 15 elementi inizializzati a 0
    std::vector<std::string> vs1(100); // vector di 100 elementi inizializzati a ""

    // con espressione di inizializzazione identica per tutti gli elementi
    std::vector<int> v3(15, -1);                      // vector con 15 elementi inizializzati a -1
    std::vector<std::string> nomi(17, "sconosciuto"); // 17  stringhe inizializzate

    // con liste di inizializzazione
    std::vector<int> v4{1, 2, 3, 4}; // con lista di inizializzazione
    std::vector<char> vocali{'a', 'e', 'i', 'o', 'u'};

    // clonando vector esistenti (richiede il copy constructor!)
    std::vector<int> v1Clonato(v1);
    std::vector<char> vocaliClonato = vocali;

    std::vector<int> v5;
    v5.reserve(1000); // riserva lo spazio per n elementi e non richiama il costruttore
    // quindi bisogna stare attenti in futuro creando prima gli oggetti

    for (int i = 0; i < 10; i++)
    {
        v5.push_back(100);
        std::cout << i + 1 << ":"
                  << "Size " << v5.size() << "  -  Capacity: " << v5.capacity() << std::endl;
    }

    std::cout << "---------------------------------------------\n\n";

    // c'è la fa il mio PC
    std::vector<int> vint;
    std::vector<std::string> vstring;

    std::cout << "vint potra' contenere al massimo " << vint.max_size() << " interi\n";
    std::cout << "vstring potra' contenere (memoria permettendo) al massimo "
              << vstring.max_size() << " stirnghe \n";

    std::string s = "";
    std::cout << "Massimo numero di caratteri in una stringa " << s.max_size() << std::endl;
    s.push_back('A');
    std::cout << s << std::endl;

    // accesso diretto agli elementi
    std::vector <std::string> pianeti {"Mercurio", "Venere", "Terra", "Marte"};
    
    // operator []
    // std::cout << "Primo pianeta " << pianeti[0] << std::endl; 
    std::cout << "Primo pianeta " << pianeti.front() << std::endl;
    std::cout << "Ultimo pianeta " << pianeti.back() << std::endl;
    std::cout << "Secondo pianeta " << pianeti.at(2) << std::endl; // at -> accede alla poszione tra parentesi
    // e restituisce un reference

    // essendo memorizzati in un unico blocco si possono usare i puntatori
    std::string *p = pianeti.data(); // equivalente al più oscuro string *p = &pianteti[0]
    

    return 0;
}