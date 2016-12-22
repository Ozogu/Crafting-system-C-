//Ossi Perä
//246295
//ossi.pera@student.tut.fi

#ifndef MLISTA_H
#define MLISTA_H

#include <string>
// Julistetaan lista tässä kohtaa, jotta vältetään
// kääntäjän virhe: class does not name a type

class Lista;
// rakenne mihin materiaaliin liittyvät tiedot tallennetaan
struct materiaali {
    std::string minun_nimi;
    Lista* minusta_tehdaan;
    Lista* minut_tehdaan;
};

// Materiaali lista on linkitetty lista olio jonka listan tietona on materiaali rakenne
class Mlista
{
private:
    struct Mlistan_alkio {
        materiaali  alkio;
        Mlistan_alkio *seuraavan_osoite;
    };
    Mlistan_alkio *ML_viimeinen_;
    // listan ensimmäisen alkion osoite
    Mlistan_alkio *ML_ensimmainen_;

public:


    Mlista();
    // lisää listaan materiaali alkion
    void lisaa_alkio(const materiaali& lisattava);
    // tulostaa listan tiedot
    void tulosta() const;
    // tulostaa tuotteen tarvittavan materiaali listan aakkosissa
    void tulosta_aakkosissa(std::string tuote) const;
    // tulostaa tuotteen tekemiseen tarvittavat materiaalit
    void tulosta_materiaalit(std::string tuote) const;
    // käy listaa läpi etsien tuotetta. jos löytää, niin lisää tuotteeseen
    // tarvittavien materiaalien (tehtaviin = false)
    // tai tehvaien materiaalien (tehtaviin = true) listaan lisattava:n
    bool etsi_ja_lisaa(const std::string& etsittava, std::string& lisattava, bool tehtaviin);
    bool etsi_tuote(const std::string& etsittava);
    bool etsi_materiaali(const std::string& etsittava);
    bool vertaa_materiaaleja(Lista& reppu, std::string& tuote);
    bool vertaa_materiaaleja_bonus(Lista& reppu, std::string tuote);

    ~Mlista();
    



};

#endif // MLISTA_H
