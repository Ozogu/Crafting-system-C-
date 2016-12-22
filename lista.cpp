//Ossi Perä
//246295
//ossi.pera@student.tut.fi

#include "lista.hh"
#include <iostream>

using namespace std;

Lista::Lista(): viimeisen_osoite_{nullptr},
    ensimmaisen_osoite_{nullptr} {
}

Lista::~Lista() {
   Listan_alkio *vapautettavan_osoite;
   // käy listaa läpi kunnnes se päättyy
   while ( ensimmaisen_osoite_ != nullptr ) {
      vapautettavan_osoite = ensimmaisen_osoite_;
      // siirretään ensimmäinen osoite seuraavaan ja poistetaan vanhaksi jäänyt alkio
      ensimmaisen_osoite_
          = ensimmaisen_osoite_->seuraavan_osoite;

      delete vapautettavan_osoite;
   }
   ensimmaisen_osoite_ = nullptr;
   viimeisen_osoite_ = nullptr;
}

void
Lista::lisaa_aakkosissa(string& lisattava_tehtava) {
   Listan_alkio *uuden_osoite{
       new Listan_alkio{lisattava_tehtava, nullptr} };

   // ensimmäinen alkio
   if ( ensimmaisen_osoite_ == nullptr ) {
      ensimmaisen_osoite_ = uuden_osoite;
      viimeisen_osoite_ = uuden_osoite;
      return;
   } else {
        auto apuos = ensimmaisen_osoite_;
        // käy listaa läpi ja arvioi minne laitetaan
        while(apuos) {
            // lisää tehtävän ensimmäiseksi alkioksi
            if (lisattava_tehtava < apuos->tehtava) {
                uuden_osoite->seuraavan_osoite = ensimmaisen_osoite_;
                ensimmaisen_osoite_ = uuden_osoite;
                return;
            }
            // lisää alkion listan viimeiseksi
            else if (apuos->seuraavan_osoite == nullptr) {
                viimeisen_osoite_->seuraavan_osoite = uuden_osoite;
                viimeisen_osoite_ = uuden_osoite;
                return;
            }
            // lisää alkion jonnekkin keskelle
            else if( lisattava_tehtava < apuos->seuraavan_osoite->tehtava) {
                uuden_osoite->seuraavan_osoite = apuos->seuraavan_osoite;
                apuos->seuraavan_osoite = uuden_osoite;
                return;
            }
        apuos = apuos->seuraavan_osoite;
        }
   }
}

bool
Lista::etsi_alkio(string etsittava)  {
    auto apuptr = ensimmaisen_osoite_;
    while (apuptr) {
        // ehto löytymiselle
        if (apuptr->tehtava == etsittava) return true;
        // liikutaan listassa jos ei löydy
        apuptr = apuptr->seuraavan_osoite;
      // lopetetaan kun lista on käyty
    } return false;
}

void Lista::tyhjenna() {
    // alkaa alusta loppuun poistamaan alkioita.

    // tarkistaa onko lista tyhjä, jos ja kun on palauttaa true
    while (!onko_tyhja()) {
        // tehdään osoitin listan ensimmäiseen alkioon, joka poistetaan
        Listan_alkio *poistettavan_osoite{ ensimmaisen_osoite_ };

        // jos ensimmäinen osoite on sama kuin viimeinen osoite, listassa on
        // yksi alkio. pointterit laitetaan osoittamaan tyhjää ennen poistoa
        if ( ensimmaisen_osoite_ == viimeisen_osoite_ ) {
           ensimmaisen_osoite_ = nullptr;
           viimeisen_osoite_ = nullptr;
        // muuten osoitin siirretään seuraavaan, ja poistetaan alkio tämän jälkeen
        } else {
           ensimmaisen_osoite_
               = ensimmaisen_osoite_->seuraavan_osoite;
        }
        delete poistettavan_osoite;
    }
    return;
}

void
Lista::tulosta() const {
   Listan_alkio *tulostettavan_osoite{ ensimmaisen_osoite_ };

   // silmukka käy listan läpi
   while (tulostettavan_osoite) {
      cout << tulostettavan_osoite->tehtava << endl;
      tulostettavan_osoite = tulostettavan_osoite->seuraavan_osoite;
   }
}
void
Lista::lisaa_alkio_loppuun(const string& lisattava_tehtava) {
   // luodaan uusi alkio
   Listan_alkio *uuden_osoite{
       new Listan_alkio{lisattava_tehtava, nullptr} };

   // tarkistetaan onko lista tyhjä
   if ( ensimmaisen_osoite_ == nullptr ) {
        // tyhjään listaan lisätään alkio
        ensimmaisen_osoite_ = uuden_osoite;
        viimeisen_osoite_ = uuden_osoite;
   } else {
        // lisätään viimeiseen osoitteeseen alkio ja siirretään osoite
        viimeisen_osoite_->seuraavan_osoite = uuden_osoite;
        viimeisen_osoite_ = uuden_osoite;
   }
}

bool
Lista::onko_tyhja() const {
   if ( ensimmaisen_osoite_ == nullptr ) return true;
   else return false;
}

bool
Lista::vertaa_sisaltoja(Lista &reppu){
    auto apuos = ensimmaisen_osoite_;
    // käy tätä listaa läpi
    while (apuos){
        // etsii repusta täsää olevaa alkiota
        if (!reppu.etsi_alkio(apuos->tehtava)) return false;
        apuos = apuos->seuraavan_osoite;
    }
    return true;
}

void
Lista::poista_viimeinen() {
    Listan_alkio* poistettava = ensimmaisen_osoite_;
    auto apuptr = poistettava;
    while ( poistettava->seuraavan_osoite ) {
        apuptr = poistettava;
        poistettava = poistettava->seuraavan_osoite;
    }
    delete poistettava;
    apuptr->seuraavan_osoite = nullptr;
    return;
}

bool
Lista::vertaa_sisaltoja_bonus(string &tuote) {

}
