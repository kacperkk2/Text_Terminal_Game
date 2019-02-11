#ifndef TEXT_H
#define TEXT_H

using namespace std;

void ucieczka3()
{
    cout<<"~~Znajdujesz sie w miescie, Elron pomogl ci sie oddalic od wiezienia";cin.get();
    cout<<"(Elron)-Wolni! No, a to wszystko co widzisz dookola to Longsam, jak sie juz rozgoscisz to popytaj o mnie w Gildii, niedaleko glownego targu";cin.get();
    cout<<"***Co odpowiadasz?"<<endl;
    cout<<"1. Jasne, dzieki za pomoc"<<endl<<
          "2. Raczej podziekuje, starczy mi przygod"<<endl<<
          "3. Mam tyle pytan, nic nie pamietam"<<endl;
    int wybor;
    cin>>wybor;
    switch(wybor)
    {
        case 1: { cout<<"(Elron)-Rowniez dziekuje, bez ciebie moglo sie to nie udac, w takim razie do zobaczenia."<<endl;break;}
        case 2: { cout<<"(Elron)-Dobrze sie zastanow, jestes dobrym wojownikiem, widzialem jak poradziles sobie ze straznikiem, czekam na ciebie w Gildii, nie rozczaruj mnie."<<endl;break;}
        case 3: { cout<<"(Elron)-Na wszystko przyjdzie czas, spotkajmy sie w Gildii."<<endl;break;}
    }
    cin.get();
    cout<<"~~Elron oddala sie i znika gdzies w tlumie, zostajesz sam w centrum miasta"<<endl;cin.get();

    system("clear");
}

void tytul()
{
    cout<<endl;
    cout<<" +---------------------------------------------------------------------------+"<<endl;
    cout<<" |                                                                           |"<<endl;
    cout<<" |                                WITAJ W GRZE !                             |"<<endl;
    cout<<" |                                                                           |"<<endl;
    cout<<" |                           Tytul, ktorego nie mam :)                       |"<<endl;
    cout<<" |                                                                           |"<<endl;
    cout<<" |                                                                           |"<<endl;
    cout<<" |                                                                           |"<<endl;
    cout<<" |                                                                           |"<<endl;
    cout<<" |                                                                           |"<<endl;
    cout<<" |                                                                           |"<<endl;
    cout<<" |                                                                           |"<<endl;
    cout<<" |                                                                           |"<<endl;
    cout<<" +---------------------------------------------------------------------------+"<<endl;
}

void ucieczka2()
{
    cout<<"~~Pod twoimi mogami lezy martwy straznik, obracasz sie w strone Elrona";cin.get();
    cout<<"(Elron)-Jestes caly???";cin.get();
    cout<<"***Co odpowiadasz?"<<endl;
    cout<<"1. Tak, wszystko w porzadku"<<endl<<
          "2. Przezylem, ale ledwo co"<<endl<<
          "3. Mam pare skaleczen, zle sie czuje"<<endl;
    int wybor;
    cin>>wybor;
    switch(wybor)
    {
        case 1: { cout<<"(Elron)-To dobrze, on nie mial tyle szczescia..."<<endl;break;}
        case 2: { cout<<"(Elron)-Cale szczescie, we dwojke mamy wieksze szanse na przezycie, on chyba umarl"<<endl;break;}
        case 3: { cout<<"(Elron)-Musisz wytrzymac, wydaje mi sie ze jestesmy blisko wyjscia..."<<endl;break;}
    }
    cout<<"~~Patrzysz na martwego wieznia z mieczem wbitym w piers..."<<endl;cin.get();
    cout<<"(Elron)-Musimy go tak zostawic, dalej! ruszajmy poki mozemy!";cin.get();
    cout<<"~~Biegniecie we dwojke dalej przez ciemny korytarz, w oddali widoczne sa drzwi, przez ktorych kraty przebija sie slonce...";cin.get();
    cout<<"~~Docieracie do drzwi ale sa zamkniete..";cin.get();
    cout<<"(Elron)-Tak! to tutaj, odsun sie mam klucz.";cin.get();
    cout<<"~~Elron szybkim ruchem otwiera drzwi, swiatlo slonecznego poludnia razi cie w oczy...";cin.get();
    cout<<"~~Wydostaliscie sie...";cin.get();
    system("clear");
}

void ucieczka1(Postac* straznik)
{
    cout<<"~~Biegniesz za dwojka wiezniow przez ciemny korytarz, ledwo dostrzegasz ich postacie, mimo ze sa 2 metry od ciebie"<<endl;
    cout<<"~~W oddali widzisz lekkie swiatlo, cos jakby poswiata pochodni lub malutkie okienko.";cin.get();
    cout<<"***Co robisz?"<<endl;
    cout<<"1. Zatrzymujesz towarzyszy i mowisz o mozliwym niebezpieczenstwie"<<endl<<
          "2. Nie odzywasz sie i biegniesz dalej"<<endl;
    int wybor;
    cin>>wybor;
    system("clear");
    switch(wybor)
    {
        case 1: {cout<<"(Elron)-Pssst... zatrzymujemy sie, faktycznie, tam cos jest"<<endl;
                 cout<<"(Nieznajomy)-To mi wyglada na 2 straznikow, jeden chyba trzyma wygaszajaca sie pochodnie";cin.get();
                 cout<<endl<<"***Nacisnij 0 zeby przyjrzec sie jednej z postaci"<<endl;
                 int zero;
                 do{cin>>zero;}while(zero!=0);
                 straznik->pokaz_staty();cin.get();
                 cout<<"(Elron)-No mlody, widzialem jak zalatwiles tego z celi, ten straznik po lewej jest twoj, pokaz co potrafisz."<<endl;
                 cout<<"(Elron)-My zajmujemy sie tym po prawej, zaczynaj";cin.get();
                break;}
        case 2: {cout<<"~~Biegniecie dalej, swiatlo robi sie coraz wyrazniejsze"<<endl;
                 cout<<"~~Teraz zdajesz sobie sprawe z tego co to jest, to wygaszajaca sie pochodnia, w rece jednego ze straznikow";cin.get();
                 cout<<"~~Jest juz za pozno zeby zatrzymac towarzyszy, wyjmujesz noz ktory dostales od Elrona";cin.get();
                 cout<<"(Nieznajomy)- AAAAAAAAA! POMOCY!"<<endl;
                 cout<<"~~Jeden ze straznikow blyskawicznie wyjal miecz i wbil go w jednego z twoich towarzszy, zostajecie we dwojke na bolu bitwy";cin.get();
                 cout<<"~~Naprzeciwko was stoi dwoch uzbrojonych straznikow"<<endl;
                 cout<<"(Elron)-JA ZAJME SIE TYM! TAMTEN JEST TWOJ! NO DALEJ!!!";cin.get();
                break;}
        default: ;
    }
    system("clear");
}

void cela2(Postac* hero)
{
    cout<<"~~Wiezien z krzykiem opada na ziemie, wypuszcza z reki scyzoryk, ktory laduje pod sciana.";cin.get();
    cout<<"***Co robisz?"<<endl;
    cout<<"1. Podnosisz scyzoryk i zostawiasz go sobie"<<endl<<
          "2. Zostawiasz scyzoryk na ziemi"<<endl;

    int wybor;
    cin>>wybor;
    system("clear");
    int czy_bron=wybor; //1 wzial, 2 nie
    switch(wybor)
    {
        case 1: {cout<<"~~Podnosisz bron: Scyzoryk(At:5,C:1)";cin.get();break;}
        case 2: {cout<<"~~Podnosisz wzrok ze scyzoryka, nie podnosisz go";cin.get();break;}
        default: ;
    }
    cin.get();
    cout<<"~~Slyszysz jakies zamieszanie, wiec podchodzisz do krat u brzegu celi, widzisz 2 straznikow ktorzy ida w twoja strone..."<<endl;
    cout<<"(Straznik1)-CELA 7!! To chyba dochodzilo stamtad!";cin.get();
    cout<<"~~W tym momencie zdajesz sobie sprawe ze uslyszeli bojke z wiezniem, ktory lezy w krwi pod sciana, a straznicy ida wlasnie do twojej celi...";
    cin.get();
    cout<<"(Straznik2)-TAK, TO TUTAJ, ODSUN SIE OD KRAT!";cin.get();
    cout<<"~~Odsuwasz sie pod sciane i slyszysz jak kraty sie otwieraja, do celi wchodzi 2 straznikow w zbrojach z mieczami";cin.get();
    cout<<"(Straznik1)-Zabieramy go.";cin.get();
    cout<<"~~Straznik blyskawicznie wyciaga srebrny miecz i jedyne co czujesz to twarda, metalowa rekojesc na twojej glowie."<<endl;
    cout<<"~~Tracisz "<<hero->daj_poz_zycie()-1<<" punktow zdrowia i osuwasz sie na ziemie, straznicy wyciagaja cie poza cele, tracisz przytomnosc";cin.get();
    hero->obrazenia(hero->daj_poz_zycie()-1);
    ////////////////////////////////////////////////////
    system("clear");
    cout<<"~~Budzisz sie w innym pomieszczeniu, jestes zwiazany, przed toba stoi 3 straznikow.";cin.get();
    cout<<"(Straznik1)-Przeszukaj go.";cin.get();
    if(czy_bron==1) {cout<<"(Straznik2)-Ha! Scyzoryk, niezly cwaniak!"<<endl;cout<<"~~Tracisz bron: Scyzoryk(At:5,C:1)";cin.get();}
    else {cout<<"(Straznik2)-Nic! Jest czysty!";cin.get();}
    cout<<"(Straznik3)-Zaczynaj w koncu!"<<endl;
    cout<<"~~Straznik wyciaga noz, przybliza go do twojej glowy...";cin.get();
    cout<<"(Straznik1)-No to teraz gadaj! Skad wziales sie w celi?! Nie przypominam sobie twojej mordy z zadnej dostawy wiezniow!";cin.get();
    cout<<"(Straznik3)-Mowilem, ze to jakis czarodziej, niby jak by inaczej tu wlazl?!";cin.get();
    cout<<"(Straznik1)-Moze masz racje, z tego moga byc same....";cin.get();
    cout<<"BOOOOOM!!"<<endl;
    cout<<"~~Jedyne co widzisz to gesty pyl unoszacy sie w pomieszczeniu, lecz nagle czujesz czyjas reke na twojej glowie i zimna stal na swoich rekach...";cin.get();
    cout<<"~~Ktos przecina grube sznury ktorymi wziazali cie straznicy"<<endl;
    cout<<"(Nieznajomy)-A ty cos za jeden?! Jestes wiezniem? Tak? To dobrze sie sklada, bo sie stad zwijamy, Elron w koncu zrobil uzytek z prochu z przemytu!";cin.get();
    cout<<"(Elron)-Jak sie nazywasz??"<<endl;
    cout<<"***Podaj swoje imie: ";
    string imie;
    cin>>imie;
    hero->zmien_imie(imie);
    cout<<"(Elron)-Witaj "<<imie<<", ja jestem Elron, a teraz podnos sie i spieprzamy stad bo jeszcze chwila i nici z ucieczki."<<endl;
    cout<<"(Elron)-Masz przyda ci sie.";cin.get();
    Noz* noz= new Noz;
    Koszula* koszula= new Koszula;
    hero->zmien_bron(noz);
    hero->zmien_zbroje(koszula);
    hero->daj_bron()->bron_staty();cout<<endl;
    hero->daj_zbroje()->zbroja_staty();cin.get();
    cout<<"~~Wybiegacie we 3 z zadymionego pomieszczenia...";cin.get();
}

void cela1()
{
    cout<<"~~Budzisz sie w mokrej, cuchnacej celi..."<<endl;
    cout<<"~~Rozgladasz sie i widzisz brudna podloge, kawalek futra na ktorym siedzisz i malutkie okno z ktorego snop swiatla"<<
          " oswietla ledwo widoczna postac w rogu celi...";cin.get();
    cout<<"~~Z tego co widzisz jest to ork, wyjatkowo rozzloszczony, napewno nie jest nastawiony przyjaznie";cin.get();
    cout<<"~~Zastanawiasz sie jak tu trafiles, jedyne co pamietasz to swoje imie, przynajmniej wydaje ci sie ze jest twoje";cin.get();
    cout<<"~~Ork, ktory siedzi z toba w celi zdaje sie nie byc zadowolony z twojej obecnosci"<<endl;
    cout<<"~~Widzisz ze podnosi sie z podlogi, a w reku trzyma scyzoryk";cin.get();
    cout<<"(Wiezien)-Na co sie tak gapisz smieciu?!"<<endl;
    cout<<"***Co odpowiadasz?"<<endl;
    cout<<"1. Poprostu dawno nie widzialem takiego brudasa jak ty"<<endl<<
          "2. Spokojnie, nie szukam klopotow"<<endl<<
          "3. Musze sie stad wydostac, pomozesz mi?"<<endl;

    int wybor;
    cin>>wybor;
    system("clear");
    switch(wybor)
    {
        case 1: {cout<<"(Wiezien)-COO?!!? Zaraz pokaze ci gdzie twoje miejsce szczeniaku"; break;}
        case 2: {cout<<"(Wiezien)-Za to ja szukam, a ty mi sie nie podobasz, lepiej wystaw piesci smieciu!"; break;}
        case 3: {cout<<"(Wiezien)-Oczywiscie, moze polame ci kosci to cie stad zabiora?!"; break;}
        default: ;
    }

    cin.get();cin.get();
    cout<<"~~Wiezien zaczyna isc w twoja strone, przygotuj sie do walki...";cin.get();system("clear");
}

#endif //TEXT.H
