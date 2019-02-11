#ifndef INTERAKCJA_H
#define INTERAKCJA_H

//#include "Lokacje.h"

using namespace std;

void Longsam_alchemik_kup(Postac* hero)
{
    system("clear");
    char wybor;
    do{
        cout<<"Lokacja: Longsam - alchemik"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"           Towar                            Cena "<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<" 1. Mikstura zycia (mala)"<<setw(23)<<"25"<<endl;
        cout<<" 2. Mikstura zycia (duza)"<<setw(23)<<"70"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<" Masz: "<<hero->daj_monety()<<" monet"<<endl;
        cout<<" w. Wroc"<<endl;
        cout<<"***Co kupujesz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case '1': { if(hero->monety_down(25)==0) cout<<"Masz za malo monet."<<endl;
                        else cout<<"Kupiles Mikstura zycia (mala)"<<endl;
                        cin.get();
                        break;}
            case '2': { if(hero->monety_down(70)==0) cout<<"Masz za malo monet."<<endl;
                        else cout<<"Kupiles Mikstura zycia (duza)"<<endl;
                        cin.get();
                        break;}
        }
        system("clear");
    }while(wybor!='w');
}

void Longsam_alchemik(Postac* hero)
{
    system("clear");
    char wybor;
    do{
        cout<<"Lokacja: Longsam - alchemik"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"Jest malutkie pomieszczenie, przed toba stoi lada, a za nia, wysoki elf. Na stolach, na okolo ciebie,"<<
              " pelno jest najrozniejszych skladnikow do mikstur: smocze palce, skory zwierzat, kosci gargulcow, czy tez"<<
              " wywary z kwiatow. Za elfem zas, na polkach, stoja mieniace sie fiolki z kolorowymi miksturami."<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"(Alchemik)- Witaj podrozniku! Szukasz dobrych mikstur? Na pewno u mnie je znajdziesz."<<endl;
        cout<<" 1. Pokaz co masz na sprzedaz"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<" s. Wyswietl statystyki"<<endl;
        cout<<" w. Wroc do miasta"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case 's': {hero->pokaz_staty();cin.get();break;}
            case '1': {Longsam_alchemik_kup(hero);break;}
        }
        system("clear");
    }while(wybor!='w');
}

void Longsam_kowal(Postac* hero)
{
    system("clear");
    char wybor;
    do{
        cout<<"Lokacja: Longsam - kowal"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"Wielki piec na srodku pomieszczenia i krasnoludy wykuwajace jasno-pomaranczowe miecze"<<
              " jeszcze gorace od zaru. To tutaj mieszkancy Longsam kupuja pancerz i bronie na polowania."<<
              " Stare krasnoludy dobrze znaja sie na rzeczy, sa najlepsi w calym Longsam."<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"(Kowal)- Witaj w naszej kuzni towarzyszu! Jak moge ci pomoc?"<<endl;
        cout<<" 1. Kup bron"<<endl;
        cout<<" 2. Kup zbroje"<<endl;
        cout<<" 3. Ulepsz bron"<<endl;
        cout<<" 4. Ulepsz zbroje"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<" s. Wyswietl statystyki"<<endl;
        cout<<" w. Wroc do miasta"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case 's': {hero->pokaz_staty();cin.get();break;}
            case '1': {break;}
            case '2': {break;}
            case '3': {break;}
            case '4': {break;}
        }
        system("clear");
    }while(wybor!='w');
}

void Longsam_swiatynia_modlitwa(Postac* hero)
{
    system("clear");
    char wybor;
    do{
        cout<<"Lokacja: Longsam - swiatynia"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"~~Odmawiasz modlitwe, czujesz jak twoje cialo napelnia wewnetrzna moc."<<
              "~~Regenerujesz 10 pktow zdrowia."<<endl;
        hero->ulecz(10);
        cout<<"-----------------------"<<endl;
        cout<<" s. Wyswietl statystyki"<<endl;
        cout<<" w. Wroc"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case 's': {hero->pokaz_staty();cin.get();break;}
        }
        system("clear");
    }while(wybor!='w');
}

void Longsam_swiatynia(Postac* hero)
{
    system("clear");
    char wybor;
    do{
        cout<<"Lokacja: Longsam - swiatynia"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"Wchodzisz do starej swiatyni, na wprost widac kilku mnichow modlacych sie przy oltarzu,"<<
              " w powietrzu unosi sie zapach olejkow i kwatow. Panuje tu polmrok, w scianach widoczne sa jedynie male okienka."<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<" 1. Odmow modlitwe z mnichami"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<" s. Wyswietl statystyki"<<endl;
        cout<<" w. Wroc do miasta"<<endl;
        cout<<"***Co robisz?"<<endl;
        cin>>wybor;
        cin.get();
        switch(wybor)
        {
            case 's': {hero->pokaz_staty();cin.get();break;}
            case '1': {Longsam_swiatynia_modlitwa(hero);break;}
        }
        system("clear");
    }while(wybor!='w');
}

#endif // INTERAKCJA_H
