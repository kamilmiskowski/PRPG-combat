class Player : public creature
{
	public:
		Player(int prof):creature(prof){};
		void move(int);
		void attack(creature&);	
		void statusbar(NPC);
		void checkterrain();
		bool deathcheck();
		bool fleecheck();
};

void Player::move(int m) //Moves in direction chosen by the player
{
	if(getMP()>0)
	{
	switch(m)
	{
		case 8: 
			increasey();
			decreaseMP();
			checkterrain();
			break;
		
		case 9: 
			increasey(); 
			increasex();
			decreaseMP(); 
			checkterrain();
			break;
		case 6: 
			increasex();
			decreaseMP(); 
			checkterrain();
			break;
		case 3: 
			increasex(); 
			decreasey(); 
			decreaseMP();
			checkterrain();
			break;
		case 2: 
			decreasey(); 
			decreaseMP();
			checkterrain();
			break;
		case 1: 
			decreasey(); 
			decreasex(); 
			decreaseMP();
			checkterrain();
			break;
		case 4: 
			decreasex(); 
			decreaseMP();
			checkterrain();
			break;
		case 7: 
			decreasex(); 
			increasey(); 
			decreaseMP();
			checkterrain();
			break;
	}
	} else cout<<"You can't move in this round anymore"<<endl;
}


void Player::statusbar(NPC enemy) //Prints statusbar on the screen
{
	cout<<"HP:"<<getHP()<<"/"<<getHPmax()<<"   MP:"<<getMP()<<"/"<<getMPmax()<<"   Range:"<<getrange()<<"   x:"<<getx()<<"   y:"<<gety()<<"   Distance:"<<look(enemy)<<endl;
}

void Player::attack(creature &enemy) //Attact action towards given creature
{
	if(look(enemy)<=getrange())
	{
		if(diceroll(20,1)+getstat().getdmgmod()>=enemy.getAC())
		{
			int a=diceroll(getDMGdie(),1)+getstat().getdmgmod();	
			enemy.decreaseHP(a);
			cout<<"You did "<<a<<" dmg to youre enemy"<<endl;
		}
		else cout<<"You missed"<<endl;
		
	} else cout<<"You missed. Enemy out of range"<<endl;;
}

void  Player::checkterrain() //Checks if terrain if difficult
 {
 	if(gety()<5||gety()>15) 
	 {
	 	cout<<"You're in difficult terrain. Youre MP will be decreased"<<endl;
		decreaseMP();	
	 }
	 
 }

bool Player::deathcheck() //Checks if player is dead
{
	if(getHP()<=0)
	{
		cout<<"You lost the fight"<<endl;
		cout<<"You died"<<endl;
		return true;
	}
	else return false;
}

bool Player::fleecheck() // Checks if player fleed from the battle
{
	if(getx()<0||getx()>39||gety()<0||gety()>19) 
	{
		cout<<"You fleed from the battleground"<<endl<<"You lost"<<endl;
		return true;
	}
	return false;
}