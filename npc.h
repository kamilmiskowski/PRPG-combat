
class NPC : public creature
{
	public:
		NPC(int prof):creature(prof){};
		void seek(creature);
		void attack(creature&);	
};

void NPC::seek(creature enemy)
{
	while(look(enemy)>getrange()&&getMP()>0)
	{
	if(getx()<enemy.getx()&&gety()<enemy.gety()){increasex();increasey(); decreaseMP();}
	if(getx()<enemy.getx()&&gety()>enemy.gety()){increasex();decreasey(); decreaseMP();}
	if(getx()>enemy.getx()&&gety()>enemy.gety()){decreasex();decreasey(); decreaseMP();}	
	if(getx()>enemy.getx()&&gety()<enemy.gety()){decreasex();increasey(); decreaseMP();}	
	 if(getx()<enemy.getx()&&gety()==enemy.gety()){increasex(); decreaseMP();}	
	 if(getx()>enemy.getx()&&gety()==enemy.gety()){decreasex(); decreaseMP();}
	 if(getx()==enemy.getx()&&gety()<enemy.gety()){increasey(); decreaseMP();}		
	 if(getx()==enemy.getx()&&gety()>enemy.gety()){decreasey(); decreaseMP();}
	}
}

void NPC::attack(creature &enemy)
{
	if(look(enemy)<=getrange())
	{
		if(diceroll(20,1)+getstat().getdmgmod()>=enemy.getAC()){enemy.decreaseHP(diceroll(getDMGdie(),1)+getstat().getdmgmod());}
		
		
	} 
}




