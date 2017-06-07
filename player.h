class Player : public creature
{
	public:
		Player(int prof):creature(prof){};
		void move(int);
		void attack(creature&);	
		void statusbar();
};

void Player::move(int m)
{
	switch(m)
	{
		case 8: 
			increasey();
			break;
		
		case 9: 
			increasey(); 
			increasex(); 
			break;
		case 6: 
			increasex(); 
			break;
		case 3: 
			increasex(); 
			decreasey(); 
			break;
		case 2: 
			decreasey(); 
			break;
		case 1: 
			decreasey(); 
			decreasex(); 
			break;
		case 4: 
			decreasex(); 
			break;
		case 7: 
			decreasex(); 
			increasey(); 
			break;
	}
}


void Player::statusbar()
{
	cout<<"HP:"<<getHP()<<"/"<<getHPmax()<<"   MP:"<<getMP()<<"/"<<getMPmax()<<"   Range:"<<getrange()<<"   x:"<<getx()<<"   y:"<<gety()<<endl;
}

void Player::attack(creature &enemy)
{
	if(look(enemy)<=getrange())
	{
		if(diceroll(20,1)+getstat().getdmgmod()>=enemy.getAC()){enemy.decreaseHP(diceroll(getDMGdie(),1)+getstat().getdmgmod());}
		else cout<<"You missed";
		
	} else cout<<"Enemy out of range"<<endl;;
}





