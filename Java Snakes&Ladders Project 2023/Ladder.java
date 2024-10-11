import java.util.Random;
public class Ladder implements interfaceLadder 
{
    public void halfLadder(int playerCurrent, boolean shouldLadder) 
	{
		Random rand = new Random(System.currentTimeMillis());
		int chance = 0;
		
		chance = rand.nextInt(2) + 1;
	
		if(chance == 1)
		{
			shouldLadder = true;
		}
		else
		{
			shouldLadder  = false;
		}
			
			
		
		
		
    }
}
