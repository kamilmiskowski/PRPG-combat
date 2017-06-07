char hue=219;
 char huez=178;

 char T[20][40];
 
 void fillT()
 {
 	 for(int i=0;i<20;i++)
 	 {
 	   	for(int j=0;j<40;j++) T[i][j]=219;
	 }
 }
 
void show(Player player, NPC npc)
{
	T[player.gety()][player.getx()]=206;
	T[npc.gety()][npc.getx()]=207;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<40;j++) cout<<T[i][j];
		cout<<endl;
	}
	T[player.gety()][player.getx()]=219;
	T[npc.gety()][npc.getx()]=219;
		player.statusbar();
}

int profchoice ()
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
			   	if(i>=1&&i<=9&&i!=5){player.move(i);show(player,npc);} 
			   	if(i==5){player.attack(npc);show(player,npc); break;}
				if(i==0)break;   
			   }
		npc.seek(player);
		npc.attack(player);
		npc.setMP(npc.getMPmax());
	
	}
}



