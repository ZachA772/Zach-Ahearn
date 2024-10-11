//COMPOSITION
import java.util.Random;
public class Dice 
{
    private Random rand;

    public Dice() 
	{
        rand = new Random(System.currentTimeMillis());
    }

    public int roll() 
	{
        return rand.nextInt(6) + 1;
    }
}
