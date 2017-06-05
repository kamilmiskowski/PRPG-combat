


int diceroll(int die, int amount)
{
	int outcome=0;
	for(int i=0; i<amount; i++)
	{
		outcome+= rand() % die + 1;
	}
	return outcome;
}