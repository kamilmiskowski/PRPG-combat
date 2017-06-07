class Player : public creature
{
	public:
		Player(int prof):creature(prof){};
		void move(int);
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



