

using namespace std;

class stats
{
	int strenght; 		int strmod;	
	int dexterity;		int dexmod;	
	int constitution; 	int conmod;
	int intelligence; 	int intmod;
public:
	stats (int);
	int getstr(){return strenght;};
	int getdex(){return dexterity;};
	int getcon(){return constitution;};
	int getint(){return intelligence;};
	int getstrmod(){return strmod;};
	int getdexmod(){return dexmod;};
	int getconmod(){return conmod;};
	int getintmod(){return intmod;};
};

 stats::stats(int prof)
{
	switch(prof)
	{
	case 1: //warrior
		
		strenght=12+diceroll(8,1);		strmod=(strenght-10)/2;  
		dexterity=8+diceroll(4,1);		dexmod=(dexterity-10)/2;
		constitution=10+diceroll(6,1);	conmod=(constitution-10)/2;
		intelligence=8;					intmod=(intelligence-10)/2;
		break;
	
	case 2: //archer
		
		strenght=10+diceroll(6,1);		strmod=(strenght-10)/2;
		dexterity=12+diceroll(8,1);		dexmod=(dexterity-10)/2;
		constitution=8+diceroll(4,1);	conmod=(constitution-10)/2;
		intelligence=8;					intmod=(intelligence-10)/2;
		break;
	
	case 3: //mage
		
		strenght=8+diceroll(4,1);		strmod=(strenght-10)/2;
		dexterity=10+diceroll(6,1);		dexmod=(dexterity-10)/2;
		constitution=8;					conmod=(constitution-10)/2;
		intelligence=12+diceroll(8,1);	intmod=(intelligence-10)/2;
		break;
	
	}
	
}