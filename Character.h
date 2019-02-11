#ifndef CHARACTER_H
#define CHARACTER_H

#include <iomanip>
#include "Armor.h"
#include "Weapon.h"
                      //  0  1    2    3    4    5    6      7   8      9      10
const int exp_tabela[11]={0,500,1000,2000,4000,8000,16000,32000,64000,128000,240000};

const string skil_tabela[4]={"Podwojne ciecie","Postawa bojowa","Oslabienie","Ogluszenie"}; // skil leczenie

class Postac
{
    string imie;
    int pz; //stat
    int zwinnosc; //stat
    int atak; //stat
    int wytrzymalosc;

    int lvl;
    int exp;
    int monety;

    int obrona;
    float sz_uniku;
    int dmg;
    int poz_wytrzymalosc;
    int poz_zycie;
    int zycie;
    int ogolny_ciezar;

    Bron* bron;
    Zbroja* zbroja;
    int skil; // 0-brak skila, 1-Podwojne ciecie, 2-Postawa bojowa, 3-Oslabienie (przy przypisywaniu tabela[i-1]
    string skil_nazwa;
    int mikstury_pz_duze;
    int mikstury_pz_male;

public:
    void ustaw_staty()
    {
        ogolny_ciezar=4;
        dmg=2.5*atak;
        if(bron!=nullptr)
        {
            ogolny_ciezar+=bron->daj_ciezar();
            dmg+=bron->daj_atak();
        }
        poz_zycie=zycie=45*pz+250;
        obrona=1.5*zwinnosc;
        if(zbroja!=nullptr) obrona+=zbroja->daj_obrona();
        sz_uniku=0.2*(float)zwinnosc;
        if(skil!=0) skil_nazwa=skil_tabela[skil-1];
        else skil_nazwa="BRAK";
    }
    Postac(string _imie): imie(_imie)
    {
        atak=6;
        zwinnosc=3;
        wytrzymalosc=poz_wytrzymalosc=40;
        pz=0;
        bron=nullptr;
        zbroja=nullptr;
        lvl=0;
        exp=0;
        //proba skila
        skil=0;
        //proba skila
        monety=0;
        mikstury_pz_duze=mikstury_pz_male=0;
        ustaw_staty();
    }

    Postac(string _imie,int _pz,int _zwinnosc,int _atak,int _wytrzymalosc,int _lvl,int _exp,int _monety,Bron* _bron,Zbroja* _zbroja)
     :imie(_imie),pz(_pz),zwinnosc(_zwinnosc),atak(_atak),wytrzymalosc(_wytrzymalosc),lvl(_lvl),exp(_exp),monety(_monety),bron(_bron),zbroja(_zbroja)
    {
        poz_wytrzymalosc=wytrzymalosc;
        poz_zycie=zycie;
        skil=0;
        ustaw_staty();
    }
    ~Postac()
    {
        delete bron;
        delete zbroja;
        zbroja=nullptr;
        bron=nullptr;
    }
    void obrazenia(int ile)
    {
        poz_zycie-=ile;
        if(poz_zycie<=0) poz_zycie=0;
    }
    void zmeczenie(int ile)
    {
        poz_wytrzymalosc-=ile;
        if(poz_wytrzymalosc<=0) poz_wytrzymalosc=0;
    }
    int odpocznij()
    {
        int ile=10;
        poz_wytrzymalosc+=ile;
        if(poz_wytrzymalosc>=wytrzymalosc) poz_wytrzymalosc=wytrzymalosc;
        return ile;
    }
    void odpocznij_cale()
    {
        poz_wytrzymalosc=wytrzymalosc;
    }
    void ulecz(int ile)
    {
        poz_zycie+=ile;
        if(poz_zycie>=zycie) poz_zycie=zycie;
    }
    int zaatakuj_lekko(Postac* rywal)
    {
        float ile=rand()%21-10;
        ile=ile/100;
        ile=((float)dmg*ile)+dmg;
        ile-=rywal->daj_obrone();

        int liczba=rand()%100+1;
        if(liczba<=rywal->daj_sz_uniku()) ile=0;

        rywal->obrazenia((int)ile);
        zmeczenie(ogolny_ciezar);
        return ile;
    }
    int szansa_mocne(Postac* rywal) //szansa, wieksza im przeciwnik bardziej zmeczony, do tego dodaje sie twoja szanse na unik, wynikajaca ze zwinnosci
    {
        float szansa=(1.00-((float)rywal->daj_poz_wytrzymalosc()/(float)rywal->daj_wytrzymalosc()))+(sz_uniku/100);
        szansa=szansa*100;
        int ile=rand()%9-4;
        szansa+=ile;
        if(szansa>=100) szansa =100;
        else if(szansa<=0) szansa=0;
        return szansa;
    }
    int zaatakuj_mocno(Postac* rywal)
    {
        float ile=rand()%11-5;
        ile=ile/100;
        ile=((float)dmg*ile)+(float)dmg*1.3;
        ile-=rywal->daj_obrone();

        int liczba=rand()%100+1;
        if(liczba<=(rywal->daj_sz_uniku()/2)) ile=0;
        if(liczba>szansa_mocne(rywal)) ile=0;

        rywal->obrazenia((int)ile);
        zmeczenie(ogolny_ciezar*2);
        return ile;
    }
//--------------------------- skile
    void podwojne_ciecie(Postac* rywal)
    {
        int pierwsze=zaatakuj_lekko(rywal);
        int drugie= zaatakuj_lekko(rywal);
        cout<<"Pierwszy atak zadal "<<pierwsze<<" obrazen."<<endl;
        cout<<"Drugi atak zadal "<<drugie<<" obrazen."<<endl;
    }
//-------------------------------------
    void zmien_imie(string iimie)
    {
        imie=iimie;
    }
    void zmien_bron(Bron* ibron)
    {
        Bron* tmp=bron;
        bron= ibron;
        delete tmp;
        if(bron!=nullptr)
        {
            skil=1;
            cout<<endl<<"Pozyskano umiejetnosc: "<<skil_tabela[skil-1]<<endl;
        }
        else skil=0;
        ustaw_staty();
    }
    void zmien_zbroje(Zbroja* izbroja)
    {
        Zbroja* tmp=zbroja;
        zbroja= izbroja;
        delete tmp;
        ustaw_staty();
    }

    void pokaz_staty()
    {
        cout<<setw(10)<<"-> "<<setw(11)<<left<<imie<<" LVL. "<<lvl<<" <-"<<endl;
        cout<<"Exp:"<<setw(31)<<right<<exp<<"/"<<exp_tabela[lvl+1]<<endl;
        cout<<"Monety:"<<setw(31)<<monety<<endl;
        cout<<"Zycie:"<<setw(10)<<pz<<"pkt"<<setw(16)<<poz_zycie<<"/"<<zycie<<endl;
        cout<<"Obrazenia:"<<setw(6)<<atak<<"pkt"<<setw(19)<<dmg<<endl;
        cout<<"Obrona:"<<setw(9)<<zwinnosc<<"pkt"<<setw(19)<<obrona<<endl;
        cout<<"Wytrzymalosc:"<<setw(23)<<poz_wytrzymalosc<<"/"<<wytrzymalosc<<endl;
        cout<<"Szansa uniku:"<<setw(24)<<sz_uniku<<"%"<<endl;
        cout<<"Ogolny ciezar:"<<setw(24)<<ogolny_ciezar<<endl;
        if(bron!=nullptr) cout<<"Bron:  "<<setw(17)<<bron->daj_nazwa()<<"(At:"<<setw(3)<<bron->daj_atak()<<",C:"<<setw(3)<<bron->daj_ciezar()<<")"<<endl;
        else cout<<"Bron:    "<<setw(29)<<"BRAK"<<endl;
        if(zbroja!=nullptr) cout<<"Zbroja:"<<setw(22)<<zbroja->daj_nazwa()<<"(Obr:"<<setw(3)<<zbroja->daj_obrona()<<")"<<endl;
        else cout<<"Zbroja:  "<<setw(29)<<"BRAK"<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
    }

    void wypij_miksture_pz_mala() // 50 pktow
    {
        ulecz(50);
    }
    void wypij_miksture_pz_duza() // 150 pktow
    {
        ulecz(150);
    }
    int monety_down(int ile) // zwraca 0 jesli nie ma tyle kasy, zwraca 1 jesli ma tyle kasy i odejmuje
    {
        if(monety>=ile)
        {
            monety-=ile;
            return 1;
        }
        else return 0;
    }
    void monety_up(int ile)
    {
        monety+=ile;
    }
    void exp_up(int ile)
    {
        exp+=ile;
    }
    void lvl_up()
    {
        ++lvl;
        ++pz;
        ++zwinnosc;
        ++atak;
        wytrzymalosc+=10;
        ustaw_staty();
        poz_wytrzymalosc=wytrzymalosc;
    }
    void pz_up()
    {
        ++pz;
        wytrzymalosc+=2;
        ustaw_staty();
        poz_wytrzymalosc=wytrzymalosc;
    }
    void zwinnosc_up()
    {
        ++zwinnosc;
        ustaw_staty();
    }
    void atak_up()
    {
        ++atak;
        wytrzymalosc+=1;
        ustaw_staty();
        poz_wytrzymalosc=wytrzymalosc;
    }
    int daj_zycie(){return zycie;}
    int daj_monety(){return monety;}
    int daj_mikstury_pz_duze(){return mikstury_pz_duze;}
    int daj_mikstury_pz_male(){return mikstury_pz_male;}
    int daj_skil(){return skil;}
    string daj_skil_nazwa(){return skil_nazwa;}
    int daj_exp(){return exp;}
    int daj_lvl(){return lvl;}
    int daj_pz(){return pz;}
    int daj_ogolny_ciezar(){return ogolny_ciezar;}
    int daj_dmg(){return dmg;}
    int daj_sz_uniku(){return sz_uniku;}
    int daj_poz_zycie(){return poz_zycie;}
    int daj_wytrzymalosc(){return wytrzymalosc;}
    int daj_poz_wytrzymalosc(){return poz_wytrzymalosc;}
    int daj_atak(){return atak;}
    int daj_zwinnosc(){return zwinnosc;}
    int daj_obrone(){return obrona;}
    string daj_imie(){return imie;}
    Bron* daj_bron(){return bron;}
    Zbroja* daj_zbroje(){return zbroja;}
};

#endif //CHARACTER.H
