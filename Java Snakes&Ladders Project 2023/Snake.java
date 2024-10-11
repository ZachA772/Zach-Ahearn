import java.util.Random;
public class Snake extends AbstractSnake
{
    public void downSnake(int playerCurrent, boolean snakeEnd)
	{
		Random rand = new Random(System.currentTimeMillis());
		int chance = 0;
		
		chance = rand.nextInt(6) + 1;
	
		if(chance == 1)
		{
			snakeEnd = true;
		}
		else
		{
			snakeEnd  = false;
		}
			
			
		
		
		
    }
}
