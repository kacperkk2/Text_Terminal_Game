#include <iostream>

#include "Character.h"
#include "Armor.h"
#include "Weapon.h"
#include "Text.h"
#include "Lokacje.h"
#include "Fabula.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Postac hero("(gracz)");
    Postac* hero_wsk = &hero;
    cela(hero_wsk);
    return 0;
}
