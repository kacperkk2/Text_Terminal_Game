#ifndef WEAPON_H
#define WEAPON_H

class Bron
{
protected:
    string nazwa;
    int ciezar;
    int atak;
public:
    void bron_staty()
    {
        cout<<nazwa<<"(At:"<<atak<<",C:"<<ciezar<<")";
    }
    Bron(string inazwa,int iciezar,int iatak): nazwa(inazwa),ciezar(iciezar),atak(iatak){}
    int daj_atak(){return atak;}
    int daj_ciezar(){return ciezar;}
    string daj_nazwa(){return nazwa;}
};

class Scyzoryk : public Bron
{
public:
    Scyzoryk(): Bron("Scyzoryk",6,10){}
};

class Noz : public Bron
{
public:
    Noz(): Bron("Noz",8,25){}
};

class Zardzewialy_miecz : public Bron
{
public:
    Zardzewialy_miecz(): Bron("Zardzewialy miecz",15,33){}
};

class Palka : public Bron
{
public:
    Palka(): Bron("Palka",15,55){}
};

class Pazury : public Bron
{
public:
    Pazury(): Bron("Pazury",5,20){}
};

class Miecz : public Bron
{
public:
    Miecz(): Bron("Miecz",20,70){}
};

class Luk : public Bron
{
public:
    Luk(): Bron("Luk",10,50){}
};


#endif //WEAPON.H
