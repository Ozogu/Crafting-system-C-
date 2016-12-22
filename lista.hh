//Ossi Perä
//246295
//ossi.pera@student.tut.fi

#ifndef LISTA_HH
#define LISTA_HH

#include "materiaalit.hh"
#include <string>

// Listaan tallenetaan repun sisältö
class Lista {
private:
    // tietorakenteen alkio
    struct Listan_alkio {
        // alkion tieto
        std::string tehtava;
        // osoite seuraavaan alkioon
        Listan_alkio *seuraavan_osoite;
    };
        Listan_alkio *viimeisen_osoite_;
        Listan_alkio *ensimmaisen_osoite_;
public:
    // osoitteet listan ensimmäisen alkion osoite


    Lista();
    void tyhjenna();
    void lisaa_alkio_loppuun(const std::string& lisattava_tehtava);
    bool onko_tyhja() const;
    void tulosta() const;
    bool etsi_alkio(std::string etsittava);
    void poista_viimeinen();
    void lisaa_aakkosissa(std::string& lisattava_tehtava);
    // vertaa onko annetussa listassa kaikki tämän listan alkiot
    bool vertaa_sisaltoja(Lista& reppu);
    bool vertaa_sisaltoja_bonus(std::string& tuote);

~Lista();



};

#endif
