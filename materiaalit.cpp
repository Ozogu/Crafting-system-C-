//Ossi Perä
//246295
//ossi.pera@student.tut.fi

#include "materiaalit.hh"
#include "mlista.hh"
#include <iostream>

using namespace std;

Materiaalit::Materiaalit()
{
}

Materiaalit::~Materiaalit() {
    materiaali_lista.~Mlista();
}

bool Materiaalit::lisaa(const string &nimeni, const string & minuun_tarvitaan) {
    // apu muuttujat
    string apu = minuun_tarvitaan;
    string apu2 = nimeni;
    // etsii materiaalista lisättävää materiaalia. jos löytää niin lisää tarvittavat materiaalit
    // listaan alkion
    if (materiaali_lista.etsi_ja_lisaa(nimeni,apu,false)) {
        materiaali_lista.etsi_ja_lisaa(minuun_tarvitaan,apu2,true);
        return true;
   }
    // muuten tekee uuden materiaalin
    else {
        // etsi_materiaalia palauttaa falsen ja nimeää "nimeni" virheeksi
        // jos materiaali oli jo listassa, sekä sen tekemiseen tarvittava osa oli listassa.
        if (apu == "virhe") return false;
        // luodaan uusi materiaali ja sen sisällä oleva lista
        materiaali* uusi = new materiaali;
        uusi->minut_tehdaan = new Lista;
        uusi->minusta_tehdaan = new Lista;
        // nimetään materiaali
        uusi->minun_nimi = nimeni;
        // lisätään tarvittavien materiaalien listaan arvo
        uusi->minut_tehdaan->lisaa_aakkosissa(apu);
        // lisätään uusi materiaali lsitaan
        materiaali_lista.lisaa_alkio(*uusi);
        return true;
    }
}

bool
Materiaalit::etsi_tuote(string etsittava) {
    // viitettä varten tyhjä string
    string tyhja;
    // kysytään listalta onko etsittavaa olemassa
    if (materiaali_lista.etsi_tuote(etsittava)) return true;
    else return false;
}

void
Materiaalit::materiaalit (string tuote) {
    // viitetta varten tyhja string
    string tyhja;
    if (materiaali_lista.etsi_tuote(tuote)) {
       // pyytää listaa tulostamaan tarvittavat materiaalit.
       materiaali_lista.tulosta_aakkosissa(tuote);
    // ei tee mitään jos tuote on pelkästään materiaali
    } else if (materiaali_lista.etsi_materiaali(tuote));
    // muissa tapauksissa virhe
    else cout << "Virhe; materiaalia ei ole määritelty\n";
}

bool
Materiaalit::askarreltavissa(Lista &reppu,string tuote) {
    // tutkitaan onko repussa jo kyseinen tuote
    if (reppu.etsi_alkio(tuote)) return true;
    return materiaali_lista.vertaa_materiaaleja(reppu,tuote);
}

bool
Materiaalit::askarreltavissa_bonus(Lista &reppu, string tuote) {
    if ( reppu.etsi_alkio(tuote)) return true;
    return materiaali_lista.vertaa_materiaaleja_bonus(reppu,tuote);
}

bool
Materiaalit::etsi_materiaali(string etsittava) {
    // kysyy listalta onko materiaalia jonka vastauksen palauttaa
    return materiaali_lista.etsi_materiaali(etsittava);
}




