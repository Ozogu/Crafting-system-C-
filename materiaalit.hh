//Ossi Perä
//246295
//ossi.pera@student.tut.fi

#ifndef MATERIAALIT_HH
#define MATERIAALIT_HH

#include "lista.hh"
#include "mlista.hh"
#include <string>

// Julistetaan lista tässä kohtaa, jotta vältetään
// kääntäjän virhe: class does not name a type
class Mlista;

// Materiaalit jotka luetaan tiedostosta tallennetaan tähän olioon
class Materiaalit
{
public:
    Materiaalit();
    // tulostaa materiaalit jotka tarvitaan tuotteen tekemiseen
    void materiaalit(std::string tuote);
    // lisää materiaalin nimen ja siihen tarvittavan osan linkitettyyn listaan
    bool lisaa(const std::string& nimeni,const std::string& minuun_tarvitaan);
    // tutkii löytyykö tuotteeseen tarvittavat materiaalit repusta
    bool askarreltavissa(Lista& reppu, std::string tuote);
    bool askarreltavissa_bonus(Lista& reppu, std::string tuote);
    // etsii materiaali listasta etsittavan tuotteen
    bool etsi_tuote(std::string etsittava);
    // etsii materiaali listasta materiaalin jota ei rakenneta mistään
    bool etsi_materiaali(std::string etsittava);
    ~Materiaalit();

private:
    Mlista materiaali_lista;

};

#endif // MATERIAALIT_HH
