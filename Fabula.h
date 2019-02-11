#ifndef FABULA_H
#define FAUBLA_H

#include <iomanip>
#include "Character.h"
#include "Armor.h"
#include "Text.h"
#include "Weapon.h"
#include "Lokacje.h"

using namespace std;


void cela(Postac* hero)
{
    cela1();

    Scyzoryk* scyzoryk= new Scyzoryk;
    Postac wiezien("Wiezien",0,2,3,35,1,504,0,scyzoryk,nullptr);
    Postac* wsk=&wiezien;
    walka(hero,wsk);

    cela2(hero);

    Zardzewialy_miecz* zmiecz= new Zardzewialy_miecz;
    Stara_zbroja* szbroja= new Stara_zbroja;
    Postac str("Straznik",3,5,5,45,1,425,7,zmiecz,szbroja);
    Postac* wsk1=&str;

    ucieczka1(wsk1);

    walka(hero,wsk1);

    ucieczka2();
    tytul();
    ucieczka3();

    /////////////////
    hero->atak_up();hero->atak_up();
    hero->zwinnosc_up();hero->zwinnosc_up();
    hero->pz_up();hero->pz_up();hero->pz_up();hero->pz_up();
    //Zardzewialy_miecz* zmiecz= new Zardzewialy_miecz;
    //Stara_zbroja* szbroja= new Stara_zbroja;
    //hero->zmien_bron(zmiecz);
    //hero->zmien_zbroje(szbroja);
    hero->monety_up(100);
    /////////////////
    Longsam(hero);

}

#endif //FABULA.H
