


int diceroll(int die, int amount)	//Returns sum of random numbers form range (1, die). 
{
	int outcome=0;
	for(int i=0; i<amount; i++)
	{
		outcome+= rand() % die + 1;
	}
	return outcome;
}