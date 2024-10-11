public class MaxRoll 
{
    public void rollMax(EncapPlayer player1, EncapPlayer player2, int playerCurrent) 
	{
		if(playerCurrent == 1)
		{
			player2.setPosition(player2.getPosition() - 2);
		}
		else if(playerCurrent == 2)
		{
			player1.setPosition(player1.getPosition() - 2);
		}
    }
}
