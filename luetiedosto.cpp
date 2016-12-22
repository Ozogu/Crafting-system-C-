//Ossi Perä
//246295
//ossi.pera@student.tut.fi

#include "luetiedosto.hh"
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

namespace {
    bool materiaalin_lisays(const string& rivi, Materiaalit& materiaalit) {
        // kommentti tunnistaa rivin <välejä> # <mitä tahansa>
        regex kommentti("[[:space:]]*"
                            "#"
                            ".*"
        );
        // jos löydetään kommentti niin liikutaan eteenpäin
        if (regex_match(rivi,kommentti)) return true;

        // tyhja tunnistaa tyhjän rivin.
        regex tyhja("[[:space:]]*");
        if (regex_match(rivi,tyhja)) return true;

        // materiaali tunnistaa rivin <välejä><sana><välejä>:<välejä><sana><välejä>
        regex materiaali(
                    "[[:space:]]*"
                    "([[:alpha:]_]+)"
                    "[[:space:]]*"
                    ":"
                    "[[:space:]]*"
                    "([[:alpha:]_]+)"
                    "[[:space:]]*"

        );
        smatch tulos;
        // tarkistaa sopiiko rivi materiaaliksi
        if (regex_match(rivi,tulos,materiaali)) {
            // lisää materiaalin materiaali olioon
             if(materiaalit.lisaa(tulos.str(1),tulos.str(2))) return true;
             else return false;
        }
        return false;
    }
}

bool lue_tiedosto(ifstream& virta, Materiaalit& materiaalit) {
    // käy rekursiivisesti tiedoston läpi ja lisää tiedoston rivin materiaaleihin
    // mikäli virheitä ei ilmene palauttaa true, muuten false
    // ifstream& virta: virta joka käy tiedostoa läpi

    // rivi johon kerätään käyttäjän syöte
    string rivi;
    getline(virta,rivi);
    // tarkistetaan onko tiedosto loppu
    if (virta.eof()) return true;
    // lisätään tehtävä, jos ei onnistu niin palautetaan false ja ohjelma sulkeutuu
    if (materiaalin_lisays(rivi, materiaalit))
        // jos lisäys onnistuu siirrytään seuraavaan riviin,
        if (!lue_tiedosto(virta, materiaalit))
            // jos aiemmalta kierrokselta on palautunut false, niin laitetaan viesti eteenpäin
            return false;
        else
            // jos aiemmalta true, niin eteenpäin.
            return true;
    else
        return false;
}

