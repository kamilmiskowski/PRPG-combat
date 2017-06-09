#include <iostream>
#include <cstdlib>
#include <time.h>  
#include "dice.h"
#include "stats.h"
#include "creature.h"
#include "npc.h"
#include "player.h"
#include "terrain.h"
#include "interface.h"

using namespace std;

int main()
{	
	srand (time(NULL));
	fillT();

	Player player(profchoice());
	NPC npc (diceroll(3,1));
	player.setx(10);
	player.sety(10);
	npc.setx(30);
	npc.sety(10);

	game(player, npc);
	system("PAUSE");
    return 0;       
}
