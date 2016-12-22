//Ossi Perä
//246295
//ossi.pera@student.tut.fi

#ifndef LUETIEDOSTO_HH
#define LUETIEDOSTO_HH

#include "materiaalit.hh"
#include <string>

//lukee tiedoston ja tallentaa sen olioon ohjelman käyttöä varten.
bool lue_tiedosto(std::ifstream& virta, Materiaalit& materiaalit);

#endif // LUETIEDOSTO_HH
