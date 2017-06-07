

class creature
{
	int x;
	int y;
	int HPmax;
	int HP;
	int AC;
	int MPmax;
	int MP;
	int range;
	int DMGdie;
	stats stat;
public:
	creature(int);
	int look(creature);
	void attack(creature&);	

	int getx(){return x;};	
	void setx(int a){x=a;}; 
	void increasex(){x++;}; 
	void decreasex(){x--;};
	
	int gety(){return y;};	
	void sety(int b){y=b;}; 
	void increasey(){y++;}; 
	void decreasey(){y--;};
	
	int getHPmax(){return HPmax;};	
	int getHP(){return HP;};	
	void setHP(int h){HP=h;}; 
	void decreaseHP(int h){HP-=h;};
	
	int getAC(){return AC;};
		
	int getMPmax(){return MPmax;};
	int getMP() {return MP;};	
	void setMP(int m){MP=m;}; 
	void decreaseMP(){MP--;};
	
	int getrange(){return range;};
	int getDMGdie(){return DMGdie;};
	stats getstat(){return stat;};
	
};

creature::creature(int prof)
{
	
	stats st(prof);
	
	switch(prof)
	{
		case 1:
		
			stat=st;
			HPmax=60/prof;
			HP=HPmax;
			AC=19-(3*prof);
			MPmax=4;
			MP=MPmax;
			range=1;
			DMGdie=8;
			break;
		case 2:
			
			stat=st;
			HPmax=60/prof;
			HP=HPmax;
			AC=19-(3*prof);
			MPmax=6;
			MP=MPmax;
			range=8;
			DMGdie=6;	
			break;
		case 3:
			
			stat=st;
			HPmax=60/prof;
			HP=HPmax;
			AC=19-(3*prof);
			MPmax=5;
			MP=MPmax;
			range=4;
			DMGdie=10;	
			break;
			
	}
}

int creature::look(creature enemy)
{
	int moves=0;
	int vx=getx();
	int vy=gety();
	
	while (vx!=enemy.getx()||vy!=enemy.gety())
	{
	if(vx<enemy.getx()&&vy<enemy.gety()){vx++;vy++; moves++;}
	else if(vx<enemy.getx()&&vy>enemy.gety()){vx++;vy--; moves++;} 
	else if(vx>enemy.getx()&&vy>enemy.gety()){vx--;vy--; moves++;} 
	else if(vx>enemy.getx()&&vy<enemy.gety()){vx--;vy++; moves++;} 
	else if(vx<enemy.getx()&&vy==enemy.gety()){vx++; moves++;}
	else if(vx>enemy.getx()&&vy==enemy.gety()){vx--; moves++;}
	else if(vx==enemy.getx()&&vy<enemy.gety()){vy++; moves++;}
	else if(vx==enemy.getx()&&vy>enemy.gety()){vy--; moves++;}
	}

	return moves;	
	
}

void creature::attack(creature &enemy)
{
	if(look(enemy)<=range)
	{
		if(diceroll(20,1)+getstat().getdmgmod()>=enemy.getAC()){enemy.decreaseHP(diceroll(getDMGdie(),1)+getstat().getdmgmod());}
		else cout<<"You missed";
		
	} else cout<<"Enemy out of range";
}





















