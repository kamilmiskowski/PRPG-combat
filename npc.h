
class NPC : public creature
{
	public:
		NPC(int prof):creature(prof){};
		void seek(creature);
};

void NPC::seek(creature enemy)
{
	while(look(enemy)>getrange()&&getMP()>0)
	{
	if(getx()<enemy.getx()&&gety()<enemy.gety()){increasex();increasey(); decreaseMP();}
	else if(getx()<enemy.getx()&&gety()>enemy.gety()){increasex();decreasey(); decreaseMP();}
	else if(getx()>enemy.getx()&&gety()>enemy.gety()){decreasex();decreasey(); decreaseMP();}	
	else if(getx()>enemy.getx()&&gety()<enemy.gety()){decreasex();increasey(); decreaseMP();}	
	else if(getx()<enemy.getx()&&gety()==enemy.gety()){increasex(); decreaseMP();}	
	else if(getx()>enemy.getx()&&gety()==enemy.gety()){decreasex(); decreaseMP();}
	else if(getx()==enemy.getx()&&gety()<enemy.gety()){increasey(); decreaseMP();}		
	else if(getx()==enemy.getx()&&gety()>enemy.gety()){decreasey(); decreaseMP();}
	}
}