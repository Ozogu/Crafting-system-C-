//Ossi Perä
//246295
//ossi.pera@student.tut.fi

#include "luetiedosto.hh"
#include "materiaalit.hh"
#include "lista.hh"

#include <regex>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string SANA = "[[:alpha:]_]+";     // tämän jälkeen mahdollisesti kirjaimia...
    string VALEJA = "[[:space:]]*";       // mahdollisesti....
    string JOTAIN = ".*";

    // riviin kerätään syöte tiedosto ja myöhemmin käyttäjä syöte
    string rivi;
    Materiaalit materiaalit;
    Lista reppu;

    cout << "Syotetiedosto: ";
    getline(cin,rivi);
    ifstream virta(rivi);
    // luetaan tiedosto ja jatketaan jos onnistuu
    if (!virta || !lue_tiedosto(virta,materiaalit)) {
        cout << "Virhe: tiedostoa ei voitu lukea\n";
        return 1;
    }
    //  onnistuessa ilmoittetaan
    cout << "Tuotantoketjut luettu onnistuneesti.\n";

    // nollataan rivi
    rivi = "";

    //käyttöliittymä
    while (cout << "testikayttoliittyma> " && getline(cin,rivi) ) {
        // lopetus
        if (regex_match(rivi,regex(VALEJA+"loppu"+VALEJA))) break;
        // repun täyttö
        else if (regex_match(rivi,regex(VALEJA+"reppu "+VALEJA+JOTAIN))) {
            bool virhe = false;
            regex tuotteet( VALEJA +
                           "reppu "
                            + VALEJA +
                            "("
                            + SANA +
                            ")" +
                            "("
                            +VALEJA +
                            SANA +
                            ")*"
                            + VALEJA
                           );
            // jos riivi sopii regexiin
            if( regex_match(rivi,tuotteet)) {
                reppu.tyhjenna();
                regex sana("[[:alpha:]_]+");
                // iteraattorit rivin lukemiseen
                sregex_iterator regit(rivi.begin(),rivi.end(),sana);
                sregex_iterator end;
                // skipataan reppu
                regit++;

                //silmukka käy riviä läpi
                while (regit != end) {
                    // jos materiaali ei ole repussa, mutta se on määritelty niin lisätään
                    if (!reppu.etsi_alkio(regit->str()) && (materiaalit.etsi_tuote(regit->str())
                            || materiaalit.etsi_materiaali(regit->str()))){
                        reppu.lisaa_alkio_loppuun(regit->str());
                    //muuten errori
                    } else {
                        cout << "Virhe: materiaali toistuu tai sitä ei ole määritelty" << endl;
                        reppu.tyhjenna();
                        virhe = true;
                        break;
                    }
                    // liikutaan rivin sanoissa
                    regit++;
                }
                // onnistuneessa syötteessä ilmoitus
                if (!virhe) cout << "Repun sisalto asetettu.\n";
            }
        }
        else if (regex_match(rivi,regex(VALEJA+"reppu"+VALEJA))) {
            reppu.tyhjenna();
            cout << "Reppu tyhjennetty.\n";
        }
        else if (regex_match(rivi,regex(VALEJA+"tulostareppu"+VALEJA))) {
            reppu.tulosta();
        }
        else if (regex_match(rivi,regex(VALEJA+"materiaalit"+VALEJA+SANA+VALEJA))) {
            regex tuote(SANA);
            sregex_iterator regit(rivi.begin(),rivi.end(),tuote);
            regit++;
            materiaalit.materiaalit(regit->str());
        }
        else if (regex_match(rivi,regex(VALEJA+"askarreltavissa"+VALEJA+SANA))) {
            regex tuote(SANA);
            sregex_iterator regit(rivi.begin(),rivi.end(),tuote);
            regit++;

            // etsii tuotetta määritellyista materiaaleista
            if (!(materiaalit.etsi_tuote(regit->str()) || materiaalit.etsi_materiaali(regit->str()))) {
                cout << "Virhe: tuotetta ei ole määritelty\n";
                continue;
            }
            // materiaalit olio kertoo tuloksen
            if (materiaalit.askarreltavissa(reppu,regit->str())) {
                cout << "On askarreltavissa.\n";
            } else cout << "Ei ole askarreltavissa\n";
        }
        else  {
            cout << "Virhe: tuntematon komento\n";
        }
    }
    return 0;
}

