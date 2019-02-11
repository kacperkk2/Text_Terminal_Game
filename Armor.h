#ifndef ARMOR_H
#define ARMOR_H

using namespace std;

class Zbroja
{
protected:
    string nazwa;
    int obrona;
public:
    void zbroja_staty()
    {
        cout<<nazwa<<"(Obr:"<<obrona<<")";
    }
    Zbroja(string inazwa,int iobrona):nazwa(inazwa), obrona(iobrona){}
    int daj_obrona(){return obrona;}
    string daj_nazwa(){return nazwa;}
};

class Koszula : public Zbroja
{
public:
    Koszula(): Zbroja("Koszula",5){}//nazwa("Koszula"), obrona(5) {}
};

class Stara_zbroja : public Zbroja
{
public:
    Stara_zbroja(): Zbroja("Stara zbroja",9){}
};

class Plaszcz : public Zbroja
{
public:
    Plaszcz(): Zbroja("Plaszcz",20){}
};

class Drewniany_pancerz : public Zbroja
{
public:
    Drewniany_pancerz(): Zbroja("Drewniany pancerz",45){}
};

class Kirys : public Zbroja
{
public:
    Kirys(): Zbroja("Kirys",60){}
};

class Zbroja_plytowa : public Zbroja
{
public:
    Zbroja_plytowa(): Zbroja("Zbroja plytowa",100){}
};



#endif //ARMOR.H
