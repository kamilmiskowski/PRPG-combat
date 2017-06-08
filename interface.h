


void show(Player player, NPC npc) //Prints battleground on the screen showing NPC'a, and Player's position
{
	
	T[player.gety()][player.getx()]=206;
	T[npc.gety()][npc.getx()]=207;
	
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<40;j++) cout<<T[19-i][j];
		cout<<endl;
	}
	
	if(player.gety()<5||player.gety()>15)T[player.gety()][player.getx()]=178;
		else T[player.gety()][player.getx()]=219;
		
	if(npc.gety()<5||npc.gety()>15) T[npc.gety()][npc.getx()]=178;
		else T[npc.gety()][npc.getx()]=219;
		
	player.statusbar(npc);
}

int profchoice () //Asks user to choose his character's proffesion
{
	int i;
	do
	{
	cout<<"Welcome to combat simulation. Please choose youre class"<<endl;
	cout<<"1. Warrior"<<endl;
	cout<<"2. Archer"<<endl;
	cout<<"3. Mage"<<endl;
	cin>>i;
	if(i<1||i>3)cout<<"Please enter number between 1 and 3"<<endl;
	}
	while(i<1||i>3);
	return i;
}




void game(Player& player,NPC& npc)
{
	show(player,npc);
	while(true)
	{
		int i;
	
		   	while(true)
			   {
			   	  
				cin>>i;
			   	if(i>=1&&i<=9&&i!=5)
				   {
				  
				   player.move(i);
				   if (player.fleecheck()==true) return;  
				   show(player,npc);
				  
				   } 
			   	if(i==5){player.attack(npc); break;}
				if(i==0)break;   
			   }
		 
		if(npc.deathcheck()==true) break;   
		npc.seek(player);
		npc.attack(player);
		if(player.deathcheck()==true) break;
		npc.setMP(npc.getMPmax());
		player.setMP(player.getMPmax());
		show(player,npc);
	
	}
}



