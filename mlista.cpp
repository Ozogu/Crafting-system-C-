//Ossi Perä
//246295
//ossi.pera@student.tut.fi

#include "mlista.hh"
#include "lista.hh"
#include <iostream>

using namespace std;

Mlista::Mlista(): ML_viimeinen_{nullptr},
    ML_ensimmainen_{nullptr}
{
}

Mlista::~Mlista() {
    Mlistan_alkio *vapautettavan_osoite;
    // käy listaa läpi, siirtää ensimmäistä merkintää eteenpäin
    // ja poistaa alkion sen jälkeen
    while ( ML_ensimmainen_!= nullptr ) {
        // tuhotaan materiaali rakenteen sisällä oleva dynaaminen muisti
        ML_ensimmainen_->alkio.minusta_tehdaan->~Lista();
        ML_ensimmainen_->alkio.minut_tehdaan->~Lista();
        vapautettavan_osoite = ML_ensimmainen_;
        ML_ensimmainen_
           = ML_ensimmainen_->seuraavan_osoite;

    delete vapautettavan_osoite;
    }

}

void
Mlista::tulosta_materiaalit(string tuote) const {
    // pointeri käymään listaa läpi
    Mlistan_alkio *apumuuttuja = ML_ensimmainen_;
    // silmukka käymään silmukkaa läpi
    while (apumuuttuja != nullptr) {
        // ehto materiaalin löytymiselle
        if (apumuuttuja->alkio.minun_nimi == tuote)  {
            // pyytää materiaali oliota tulostamaan itsensä
            apumuuttuja->alkio.minut_tehdaan->tulosta();
            return;
        }
        // liikkuu eteenpäin listassa
        apumuuttuja = apumuuttuja->seuraavan_osoite;
    } return;
}

bool
// etsii listasta tuotteen sen nimen perusteella
Mlista::etsi_ja_lisaa(const std::string& etsittava, string& lisattava,bool tehtaviin){
    // pointeri käymään listaa läpi
    Mlistan_alkio *apumuuttuja = ML_ensimmainen_;
    // silmukka käymään listaa läpi
    while (apumuuttuja != nullptr) {
        // ehto tuotteen löytymiselle
        if (apumuuttuja->alkio.minun_nimi == etsittava && tehtaviin == false)  {
            if (apumuuttuja->alkio.minut_tehdaan->etsi_alkio(lisattava)) {
                lisattava = "virhe";
                return false;
            }
            apumuuttuja->alkio.minut_tehdaan->lisaa_aakkosissa(lisattava);
            return true;
        } else if (apumuuttuja->alkio.minun_nimi == etsittava && tehtaviin == true) {
            apumuuttuja->alkio.minusta_tehdaan->lisaa_aakkosissa(lisattava);
            return true;
        }
        apumuuttuja = apumuuttuja->seuraavan_osoite;
    }
    return false;
}

bool
Mlista::etsi_tuote(const string &etsittava) {
    // pointeri käymään listaa läpi
    Mlistan_alkio *apumuuttuja = ML_ensimmainen_;
    // silmukka käymään listaa läpi
    while (apumuuttuja != nullptr) {
        // ehto tuotteen löytymiselle
        if (apumuuttuja->alkio.minun_nimi == etsittava)  {
            return true;
        }
        apumuuttuja = apumuuttuja->seuraavan_osoite;
    }
    return false;
}

bool
// etsii listasta materiaalin sen nimen perusteella
Mlista::etsi_materiaali(const string &etsittava){

    // pointeri käymään listaa läpi
    Mlistan_alkio *apumuuttuja = ML_ensimmainen_;
    // silmukka käymään listaa läpi
    while (apumuuttuja != nullptr) {
        // ehto materiaalin löytymiselle
        if (apumuuttuja->alkio.minut_tehdaan->etsi_alkio(etsittava)) return true;
        apumuuttuja = apumuuttuja->seuraavan_osoite;
    }
    return false;
}

void
Mlista::lisaa_alkio(const materiaali& lisattava){
    // luo uuden alkion
    Mlistan_alkio *uuden_osoite = new Mlistan_alkio{lisattava, nullptr};

    // toiminta tyhjässä listassa
    if ( ML_ensimmainen_ == nullptr ) {
      // siirtää osoittimet ensimmäiseen alkioon
      ML_ensimmainen_= uuden_osoite;
      ML_viimeinen_= uuden_osoite;
      // toiminta ei tyhjässä listassa
    } else {
        // siirtää viimeisen alkion merkintöjä
        ML_viimeinen_->seuraavan_osoite = uuden_osoite;
        ML_viimeinen_= uuden_osoite;
    }
}

void
Mlista::tulosta() const {
   // luodaan apu muuttuja
   Mlistan_alkio *tulostettavan_osoite{ ML_ensimmainen_ };

   // muuttuja käy listaa läpi
   while ( tulostettavan_osoite != nullptr ) {
        // tulostaa alkion nimen
        cout << tulostettavan_osoite->alkio.minun_nimi << endl;
        // liikkuu listassa eteenpäin
        tulostettavan_osoite = tulostettavan_osoite->seuraavan_osoite;
   }
}

void
Mlista::tulosta_aakkosissa(string tuote) const {
    // pointeri käymään listaa läpi
    Mlistan_alkio *apumuuttuja = ML_ensimmainen_;
    // silmukka käymään listaa läpi
    while (apumuuttuja != nullptr) {
        // ehto materiaalin löytymiselle
        if (apumuuttuja->alkio.minun_nimi == tuote)  {
            // pyytää materiaali oliota tulostamaan itsensä
            apumuuttuja->alkio.minut_tehdaan->tulosta();
            return;
        }
        // liikkuu eteenpäin listassa
        apumuuttuja = apumuuttuja->seuraavan_osoite;
    } return;
}

bool
Mlista::vertaa_materiaaleja(Lista &reppu, string &tuote){
    // pointeri käymään listaa läpi
    Mlistan_alkio *apumuuttuja = ML_ensimmainen_;
    // silmukka käymään listaa läpi
    while (apumuuttuja != nullptr) {
        // ehto tuotteen löytymiselle
        if (apumuuttuja->alkio.minun_nimi == tuote)  {
            if (apumuuttuja->alkio.minut_tehdaan->vertaa_sisaltoja(reppu)) return true;
        }
        apumuuttuja = apumuuttuja->seuraavan_osoite;
    }
    return false;

}

bool
Mlista::vertaa_materiaaleja_bonus(Lista &reppu, string tuote) {
    reppu.vertaa_sisaltoja(reppu);
}

