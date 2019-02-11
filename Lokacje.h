#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "Interakcja.h"
#include "Character.h"
#include "Armor.h"
#include "Text.h"
#include "Weapon.h"

using namespace std;

void Longsam(Postac*);

void ruch_rywala(Postac* hero,Postac* rywal)
{
    int decyzja;
    float iloraz=((float)rywal->daj_zwinnosc()/(float)hero->daj_zwinnosc());
    int ile_ciezar=0;
    if(rywal->daj_bron()!=nullptr) ile_ciezar=rywal->daj_bron()->daj_ciezar();
    ile_ciezar+=4;  // standardowo 4 to bez broni, po dodaniu sily do zmiany

    if(rywal->daj_poz_wytrzymalosc()<=ile_ciezar) decyzja=3;
    else if(((float)rywal->daj_poz_wytrzymalosc()/(float)rywal->daj_wytrzymalosc())<=0.6)
    {
        int liczba=rand()%100+1;
        if(iloraz<=0.2) // rywala zwinnosc duzo mniejsza niz hero
        {
            if(liczba <=10) decyzja=3;
            else if(liczba>10 && liczba<=15) decyzja=2;
            else decyzja=1;
        }
        else if(iloraz<=0.6) // rywala zwinnosc troche mniejsza niz hero
        {
            if(liczba <=10) decyzja=3;
            else if(liczba>10 && liczba<=30) decyzja=2;
            else decyzja=1;
        }
        else if(iloraz<=0.9) // porownywalne
        {
            if(liczba <=10) decyzja=3;
            else if(liczba>10 && liczba<=40) decyzja=2;
            else decyzja=1;
        }
        else // wieksze zw ma rywal
        {
            if(liczba <=10) decyzja=3;
            else if(liczba>10 && liczba<=55) decyzja=2;
            else decyzja=1;
        }
    }
    else
    {
        int liczba=rand()%100+1;
        if(iloraz<=0.2)
        {
            if(liczba <=5) decyzja=3;
            else if(liczba>5 && liczba<=10) decyzja=2;
            else decyzja=1;
        }
        else if(iloraz<=0.6)
        {
            if(liczba <=5) decyzja=3;
            else if(liczba>5 && liczba<=25) decyzja=2;
            else decyzja=1;
        }
        else if(iloraz<=0.9)
        {
            if(liczba <=5) decyzja=3;
            else if(liczba>5 && liczba<=40) decyzja=2;
            else decyzja=1;
        }
        else
        {
            if(liczba <=5) decyzja=3;
            else if(liczba>5 && liczba<=55) decyzja=2;
            else decyzja=1;
        }
    }

    if(decyzja==1) cout<<rywal->daj_imie()<<" wyprowadza lekki atak."<<endl<<"Zadaje "<<rywal->zaatakuj_lekko(hero)<<" obrazen.";
    else if(decyzja==2)
    {
        cout<<rywal->daj_imie()<<" wyprowadza mocny atak."<<endl;
        cout<<"Zadaje "<<rywal->zaatakuj_mocno(hero)<<" obrazen.";
    }
    else cout<<rywal->daj_imie()<<" odpoczywa i regeneruje "<<rywal->odpocznij()<<" wytrzymalosci"<<endl;
    cin.get();
}

void smierc_rywal(Postac* rywal)
{
    rywal->~Postac();
    //delete rywal;
}

void tabela(Postac* hero,Postac* rywal,int kolej)
{
    system("clear");
    if(kolej==0) cout<<setw(7)<<"-> "<<left<<setw(8)<<hero->daj_imie()<<" <-"<<setw(35)<<" "<<setw(8)<<rywal->daj_imie()<<endl;
    else cout<<setw(7)<<" "<<left<<setw(8)<<hero->daj_imie()<<setw(38)<<right<<"-> "<<left<<setw(8)<<rywal->daj_imie()<<" <-"<<endl;
    cout<<right<<setw(11)<<hero->daj_lvl()<<setw(26)<<"-LVL-"<<setw(21)<<rywal->daj_lvl()<<endl;
    cout<<setw(10)<<hero->daj_poz_zycie()<<"/"<<hero->daj_zycie()<<setw(26)<<"-Zywotnosc-"<<setw(17)<<rywal->daj_poz_zycie()<<"/"<<rywal->daj_zycie()<<endl;
    cout<<setw(10)<<hero->daj_poz_wytrzymalosc()<<"/"<<hero->daj_wytrzymalosc()<<setw(28)<<"-Wytrzymalosc-"<<setw(16)<<rywal->daj_poz_wytrzymalosc()<<"/"<<rywal->daj_wytrzymalosc()<<endl;
    cout<<setw(11)<<hero->daj_dmg()<<setw(26)<<"-Atak-"<<setw(22)<<rywal->daj_dmg()<<endl;
    cout<<setw(11)<<hero->daj_obrone()<<setw(27)<<"-Obrona-"<<setw(21)<<rywal->daj_obrone()<<endl;

    if(hero->daj_bron()==nullptr) cout<<setw(12)<<"BRAK"<<setw(25);
    else cout<<setw(5)<<" "<<setw(27)<<left<<hero->daj_bron()->daj_nazwa();
    cout<<"-Bron-";
    if(rywal->daj_bron()==nullptr) cout<<setw(23)<<"BRAK"<<endl;
    else cout<<setw(27)<<right<<rywal->daj_bron()->daj_nazwa()<<endl;

    if(hero->daj_zbroje()==nullptr) cout<<setw(12)<<"BRAK"<<setw(26);
    else cout<<setw(5)<<" "<<setw(25)<<left<<hero->daj_zbroje()->daj_nazwa();
    cout<<"-Pancerz-";
    if(rywal->daj_zbroje()==nullptr) cout<<setw(22)<<"BRAK"<<endl;
    else cout<<setw(26)<<right<<rywal->daj_zbroje()->daj_nazwa()<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
}

void awansuj(Postac* hero)
{
    int wybor;
    hero->lvl_up();
    system("clear");
    cout<<"GRATULACJE, AWANSOWALES NA "<<hero->daj_lvl()<<" LVL !"<<endl;
    int pkty=4;
    do{
        cout<<"Masz "<<pkty<<" punkty do rozdania:"<<endl;
        cout<<"1. Zycie     ("<<hero->daj_pz()<<")"<<setw(20)<<"-Zwieksza zdrowie i wyrztmalosc o 2pkty"<<endl;
        cout<<"2. Obrona    ("<<hero->daj_zwinnosc()<<")"<<setw(20)<<"-Zwieksza zwinnosc i szanse uniku"<<endl;
        cout<<"3. Obrazenia ("<<hero->daj_atak()<<")"<<setw(20)<<"-Zwieksza zadawane obrazenia i wyrztmalosc o 1pkt"<<endl;
        cout<<"***Twoj wybor:";
        cin>>wybor;
        switch(wybor)
        {
            case 1: {cout<<"Wybrales Zywotnosc"<<endl;hero->pz_up();break;}
            case 2: {cout<<"Wybrales Zwinnosc"<<endl;hero->zwinnosc_up();break;}
            case 3: {cout<<"Wybrales Atak"<<endl;hero->atak_up(); break;}
            default: ;
        }
        cin.get();
        system("clear");
        --pkty;
    }while(pkty>0);

    hero->pokaz_staty();
    cin.get();
    system("clear");
}

void smierc(Postac* hero)
{
    char wybor;
    do{
        system("clear");
        cout<<"Lokacja: Longsam - swiatynia"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"~~Otwierasz powoli oczy, obraz rozjasnia ci sie, nad glowa widzisz sklepienie swiatyni"<<
              " a tuz nad soba pochylonego mnicha ktory mamrocze modlitwy. Przezyles, mnich wskrzesza cie"<<endl<<endl;
        cout<<"(Mnich)- To wielkie szczescie ze udalo mi sie ciebie znalezc tak szybko, jeszcze chwila i moja moc by tu nie pomogla."<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        hero->ulecz(10);
        hero->pokaz_staty();
        cout<<" w. Wroc do miasta"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
    }while(wybor!='w');
    Longsam(hero);
}

void walka(Postac* hero,Postac* rywal)
{
    int podwojne_ciecie=2; // mozna zrobic ogolna zmienna ze switchem ktora na poczatku patrzy jaki skil i przypisuje tyle do zmiennej w zal. od skila
    int wybor;
    do{
        tabela(hero,rywal,0);
        cout<<"***Co robisz?"<<endl;
        if(hero->daj_poz_wytrzymalosc()>=hero->daj_ogolny_ciezar()){
        cout<<"1. Zaatakuj lekkim ciosem ("<<rywal->daj_sz_uniku()<<"% szans na unik rywala)"<<endl;}
        if(hero->daj_poz_wytrzymalosc()>=hero->daj_ogolny_ciezar()*2){
        cout<<"2. Zaatakuj mocnym ciosem ("<<hero->szansa_mocne(rywal)<<"% szans na trafienie)"<<endl;}
        cout<<"3. Odpocznij"<<endl;
        if(hero->daj_skil()!=0 && podwojne_ciecie>0)
        {
            cout<<"----Umiejetnosc----"<<endl;
            cout<<"4. "<<hero->daj_skil_nazwa() <<" (pozostalo "<<podwojne_ciecie<<" uzycia)"<<endl;
        }

        cin>>wybor;
        switch(wybor)
        {
            case 1: {cout<<"Wyprowadzasz lekki atak."<<endl<<"Zadajesz "<<hero->zaatakuj_lekko(rywal)<<" obrazen.";break;}
            case 2: {cout<<"Wyprowadzasz mocny atak."<<endl<<"Zadajesz "<<hero->zaatakuj_mocno(rywal)<<" obrazen.";break;}
            case 3: {cout<<"Odpoczywasz i regenerujesz "<<hero->odpocznij()<<" wytrzymalosci"; break;}
            case 4: {
                        switch(hero->daj_skil())
                        {
                            case 1: {hero->podwojne_ciecie(rywal); podwojne_ciecie--;break;}
                            /*case 2: jakis inny
                            case 3:
                            case 4:
                            case 5:
                            case 6:*/
                        }
                        break;
                    }
            default: ;
        }
        cin.get();cin.get();
        system("clear");
        tabela(hero,rywal,1);

        //cin.get();
        if(rywal->daj_poz_zycie()>0) ruch_rywala(hero,rywal);

    }while(rywal->daj_poz_zycie()!=0 && hero->daj_poz_zycie()!=0);

    if(hero->daj_poz_zycie()==0) smierc(hero);

    hero->odpocznij_cale();
    hero->exp_up(rywal->daj_exp());
    hero->monety_up(rywal->daj_monety());
    cout<<endl<<"Zdobywasz "<<rywal->daj_exp()<<" pktow doswiadczenia ("<<hero->daj_exp()<<"/"<<exp_tabela[hero->daj_lvl()+1]<<")"<<endl;
    cout<<endl<<"Zdobywasz "<<rywal->daj_monety()<<" monet (masz: "<<hero->daj_monety()<<")"<<endl;

    cin.get();
    if(hero->daj_exp()>=exp_tabela[hero->daj_lvl()+1]) awansuj(hero);
    smierc_rywal(rywal);
}

void Pola_Longsam_podroz(Postac* hero)
{
    system("clear");
    char wybor;
    do{
        cout<<"Gdzie chcesz sie udac?"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<" 1. Longsam - wschod"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<" w. Zostan w biezacej lokacji"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case '1': {Longsam(hero);break;}
        }
        system("clear");
    }while(wybor!='w');
}

void Pola_Longsam(Postac* hero)
{
    system("clear");
    Postac dz("Dzik",6,6,10,20,3,400,9,nullptr,nullptr);  // dzik po walce ma 0 hp i malo wytrz, (lecze go pod koniec kazdej petli)
    Postac* dzik=&dz;
    char wybor;
    do{
        //Postac dz("Dzik",6,6,7,20,3,400,nullptr,nullptr);
        //Postac* dzik=&dz;

        cout<<"Lokacja: Pola Longsam"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"Rozlegle pola, ktore od miasta oddziela wysoki mur. To tutaj mieszkancy Longsam najczesciej wybieraja sie na polowanie,"<<
              " teren jest plaski, niewiele tu drzew czy krzakow, zas pelno tu dzikow."<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<" 1. Rozpocznij polowanie"<<endl;
        cout<<" 2. Przyjrzyj sie celowi"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<" s. Wyswietl statystyki"<<endl;
        cout<<" p. Podrozuj"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case 'p': {Pola_Longsam_podroz(hero);break;}
            case 's': {hero->pokaz_staty();cin.get();break;}
            case '1': {walka(hero,dzik);break;}
            case '2': {dzik->pokaz_staty();cin.get();break;}
        }
        //if(wybor!='1') delete dzik;
        dzik->ulecz(dzik->daj_zycie());
        dzik->odpocznij_cale();
        system("clear");
    }while(1);
}

void Las_Seirong_podroz(Postac* hero)
{
    system("clear");
    char wybor;
    do{
        cout<<"Gdzie chcesz sie udac?"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<" 1. Longsam - zachod"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<" w. Zostan w biezacej lokacji"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case '1': {Longsam(hero);break;}
        }
        system("clear");
    }while(wybor!='w');
}

void Las_Seirong(Postac* hero)
{
    system("clear");
    Pazury* p= new Pazury;
    Postac ch("Chochlik",12,9,14,40,5,750,16,p,nullptr);
    Postac* chochlik=&ch;
    char wybor;
    do{
        cout<<"Lokacja: Las Seirong"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"Las wydaje sie byc ciemniejszy i wiekszy po wejsciu do niego, panuje to nieprzenikniony chlod,"<<
              " legendy glosza, ze kilku krasnoludow ktorzy wybrali sie tu na polowanie na chochliki juz nigdy nie wrocilo."<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<" 1. Rozpocznij polowanie"<<endl;
        cout<<" 2. Przyjrzyj sie celowi"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<" s. Wyswietl statystyki"<<endl;
        cout<<" p. Podrozuj"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case 'p': {Las_Seirong_podroz(hero);break;}
            case 's': {hero->pokaz_staty();cin.get();break;}
            case '1': {walka(hero,chochlik);break;}
            case '2': {chochlik->pokaz_staty();cin.get();break;}
        }
        chochlik->ulecz(chochlik->daj_zycie());
        chochlik->odpocznij_cale();
        system("clear");
    }while(1);
}

void Longsam_podroz(Postac* hero)
{
    system("clear");
    char wybor;
    do{
        cout<<"Gdzie chcesz sie udac?"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<" 1. Pola Longsam - zachod"<<endl;
        cout<<" 2. Las Seirong - wschod"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<" w. Zostan w biezacej lokacji"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case '1': {Pola_Longsam(hero);break;}
            case '2': { if(hero->daj_lvl()<5) {cout<<"Wymagany co najmniej 5lvl"<<endl;cin.get();}
                        else Las_Seirong(hero);
                        break;}
        }
        system("clear");
    }while(wybor!='w');
}

void Longsam(Postac* hero)
{
    system("clear");
    char wybor;
    do{
        cout<<"Lokacja: Miasto Longsam"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"Znajdujesz sie w miescie tetniacym zyciem, mimo ze Longsam to miasto zbudowane przez ludzi,"<<
              " po ulicach przechadzaja sie postaci roznych ras: Krasnoludy, Eflowie, Orkowie, Reptiliony..."<<
              " Miejsce wydaje sie byc spokojnym schronieniem, mozna dostrzec wiele stoisk krasnoludow kowali, "<<
              "czy tez karczmy prowadzone przez ludzi."<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<" 1. Udaj sie do kowala"<<endl;
        cout<<" 2. Wejdz do swiatyni"<<endl;
        cout<<" 3. Idz do alchemika"<<endl;
        cout<<" 4. Odwiedz gildie"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<" s. Wyswietl statystyki"<<endl;
        cout<<" p. Podrozuj"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case 'p': {Longsam_podroz(hero);break;}
            case 's': {hero->pokaz_staty();cin.get();break;}
            case '1': {Longsam_kowal(hero);break;}
            case '2': {Longsam_swiatynia(hero);break;}
            case '3': {Longsam_alchemik(hero);break;}
            case '4': {cout<<"gildia misja gl";break;}
        }
        system("clear");
    }while(1);
}


#endif //FUNKCJE_H
