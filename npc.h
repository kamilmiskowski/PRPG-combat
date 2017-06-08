
class NPC : public creature
{
	public:
		NPC(int prof):creature(prof){};
		void seek(creature);
		void attack(creature&);	
		void checkterrain();
		bool deathcheck();
};

void NPC::seek(creature enemy) //Moves as close as NPC can towards the given creature
{
	while(look(enemy)>getrange()&&getMP()>0)
	{
		if(getx()<enemy.getx()&&gety()<enemy.gety()){increasex();increasey(); checkterrain();decreaseMP();}
		else if(getx()<enemy.getx()&&gety()>enemy.gety()){increasex();decreasey(); checkterrain();decreaseMP();}
		else if(getx()>enemy.getx()&&gety()>enemy.gety()){decreasex();decreasey(); checkterrain();decreaseMP();}	
		else if(getx()>enemy.getx()&&gety()<enemy.gety()){decreasex();increasey(); checkterrain();decreaseMP();}	
		else if(getx()<enemy.getx()&&gety()==enemy.gety()){increasex(); checkterrain();decreaseMP();}	
		else if(getx()>enemy.getx()&&gety()==enemy.gety()){decreasex(); checkterrain();decreaseMP();}
		else if(getx()==enemy.getx()&&gety()<enemy.gety()){increasey(); checkterrain();decreaseMP();}		
		else if(getx()==enemy.getx()&&gety()>enemy.gety()){decreasey(); checkterrain();decreaseMP();}
	}
}

void NPC::attack(creature &enemy) // Attack action that has probability of success based on dicerolls and NPC' statistics. 
{									// If successfull, reduces given creatures HP		
	if(look(enemy)<=getrange())
	{
		if(diceroll(20,1)+getstat().getdmgmod()>=enemy.getAC())
		{
			int a=diceroll(getDMGdie(),1)+getstat().getdmgmod();	
			enemy.decreaseHP(a);
			cout<<"Enemy did "<<a<<" dmg to you"<<endl;
		}
		else cout<<"Enemy missed"<<endl;
		
	} 
}

void  NPC::checkterrain() //Checks if terrain if difficult
{
 	if(gety()<5||gety()>15) 
	 {
		 decreaseMP();
	 } 
}

bool NPC::deathcheck() //Checks if NPC is still alive 
{
	if(getHP()<=0)
	{
		cout<<"You won!"<<endl;
		cout<<"Enemy was defeated"<<endl;
		return true;
	}
	else return false;
}

