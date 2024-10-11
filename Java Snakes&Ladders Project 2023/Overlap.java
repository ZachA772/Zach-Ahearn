import java.util.Random;
public class Overlap 
{
    public void overlapPosition(EncapPlayer player1, EncapPlayer player2) 
	{
		Random rand = new Random(System.currentTimeMillis());
		int chance = 0;
		
		chance = rand.nextInt(2) + 1;
		
		if(chance == 1)
		{
			player1.setPosition(player1.getPosition() - 5);
		}
		else if(chance == 2)
		{
			player2.setPosition(player2.getPosition() - 5);
		}
		
    }
}
