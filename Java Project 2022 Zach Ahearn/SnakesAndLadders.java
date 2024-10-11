/*
*Name: Zach Ahearn
*Date: 03/12/2022
*Function: Get Keyboard Input
*/


import java.util.Scanner;
import java.util.Random;

public class SnakesAndLadders
{//start of class
    public static void main (String [] args)
	{//start of the method
	    //Variables
		Scanner scan = new Scanner(System.in);
		Random rand = new Random(System.currentTimeMillis());
		
		//Player's Positions
		int p1score = 0;
	    String p1name;
		int p2score = 0;
		String p2name;
		//Win Variable
		boolean win = false;
		
		//Dice Variable
		String roll;
		char r;
		int dice1 = 0;
		int dice2 = 0;
		int dice3 = 0;
		int dicesum = 0;
		//Countdown Array Variables
		int [] arrNums = {1, 2, 3};
	    arrNums[0] = 3;
	    arrNums[1] = 2;
	    arrNums[2] = 1;
		
		
		//Game Setup
		System.out.println("Welcome to Snakes and ladders!");
		System.out.println("This is a special game of Snakes and Ladders with special rules");
		System.out.println("1. Players can save themselves from a snake if they roll a 6");
		System.out.println("2. 3 dice are used each turn, first 2 are added to your position, the 3rd subtracts");
		System.out.println("3. When a player rolls a 0, they are teleported to the opposing players position");
		System.out.println("4. When a player lands on a ladder, if they roll 4-6, they go up the ladder,");
		System.out.println("   If they roll 1-3, they go halfway up the ladder");
		System.out.println("5. When a player goes up a ladder, the opposing player is set back 2 spaces (does not apply to the first ladder)");
		
		
		System.out.println("Player 1, please input your name");
		p1name = scan.next();
		System.out.println("Player 1 name: " + p1name);		
		
		System.out.println("Player 2, please input your name");
		p2name = scan.next();
		System.out.println("Player 2 name: " + p2name);
		
		System.out.println("GET READY");
		
		//Use of Array
	    for(int i = 0; i < 3; i++)
	    {
		    System.out.println(arrNums[i] + "!");
	    }
		System.out.println("LET THE GAME BEGIN!");
		
		//Game Start
		do
		{
		//Player 1 turn--------------------------------------------------------------------------------------------------------------------------------------------------------
		System.out.println(p1name + ", input 'r' to roll your 3 dice");
		roll = scan.next();
	    r = roll.charAt(0);
	    if(r=='r')
	    {
			dice1 = rand.nextInt(6) + 1;
	    	System.out.println(dice1);
			dice2 = rand.nextInt(6) + 1;
		    System.out.println(dice2);
			dice3 = rand.nextInt(6) + 1;
		    System.out.println(dice3);
	    }
		
	    dicesum = dice1 + dice2 - dice3;
		p1score = p1score + dicesum;
		System.out.println(p1name + " has moved to position " + p1score);
		
		//List of Possible Events
		if(p1score==1)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p1score = 38;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p1score = 19;
					System.out.println(p1name + " has moved to position " + p1score);
				}
			}
		}
		else if(p1score==4)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p1score = 14;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p1score = 9;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				System.out.println(p2name + " gets set back 2 spaces!");
				p2score = p2score - 2;
				System.out.println(p2name + " has moved to position " + p2score);
			}
		}
		else if(p1score==8)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p1score = 30;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p1score = 19;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				System.out.println(p2name + " gets set back 2 spaces!");
				p2score = p2score - 2;
				System.out.println(p2name + " has moved to position " + p2score);
			}
		}
		else if(p1score==21)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p1score = 42;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p1score = 31;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				System.out.println(p2name + " gets set back 2 spaces!");
				p2score = p2score - 2;
				System.out.println(p2name + " has moved to position " + p2score);
			}
		}
		else if(p1score==28)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p1score = 76;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p1score = 52;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				System.out.println(p2name + " gets set back 2 spaces!");
				p2score = p2score - 2;
				System.out.println(p2name + " has moved to position " + p2score);
			}
		}
		else if(p1score==32)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p1score = 10;
					System.out.println(p1name + " has moved to position " + p1score);
				}
			}
		}
		else if(p1score==36)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p1score = 6;
					System.out.println(p1name + " has moved to position " + p1score);
				}
			}
		}
		else if(p1score==48)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p1score = 26;
					System.out.println(p1name + " has moved to position " + p1score);
				}
			}
		}
		else if(p1score==50)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p1score = 67;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p1score = 58;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				System.out.println(p2name + " gets set back 2 spaces!");
				p2score = p2score - 2;
				System.out.println(p2name + " has moved to position " + p2score);
			}
		}
		else if(p1score==62)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p1score = 18;
					System.out.println(p1name + " has moved to position " + p1score);
				}
			}
		}
		else if(p1score==71)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p1score = 92;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p1score = 82;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				System.out.println(p2name + " gets set back 2 spaces!");
				p2score = p2score - 2;
				System.out.println(p2name + " has moved to position " + p2score);
			}
		}
		else if(p1score==80)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p1score = 99;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p1score = 89;
					System.out.println(p1name + " has moved to position " + p1score);
				}
				System.out.println(p2name + " gets set back 2 spaces!");
				p2score = p2score - 2;
				System.out.println(p2name + " has moved to position " + p2score);
			}
		}
		else if(p1score==88)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p1score = 24;
					System.out.println(p1name + " has moved to position " + p1score);
				}
			}
		}
		else if(p1score==95)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p1score = 56;
					System.out.println(p1name + " has moved to position " + p1score);
				}
			}
		}
		else if(p1score==97)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p1score = 78;
					System.out.println(p1name + " has moved to position " + p1score);
				}
			}
		}
		else if(dicesum==0)
		{
			System.out.println("You rolled a 0, teleport to opposing player's position!");
			p1score = p2score;
			System.out.println(p1name + " has moved to position " + p1score);
		}
		else if(p1score>=100)
		{
			break;
		}
		
		
		
		//Player 2 turn---------------------------------------------------------------------------------------------------------------------------------------------------
		System.out.println(p2name + ", input 'r' to roll your 3 dice");
		roll = scan.next();
	    r = roll.charAt(0);
	    if(r=='r')
	    {
			dice1 = rand.nextInt(6) + 1;
	    	System.out.println(dice1);
			dice2 = rand.nextInt(6) + 1;
		    System.out.println(dice2);
			dice3 = rand.nextInt(6) + 1;
		    System.out.println(dice3);
	    }
	   
	    dicesum = dice1 + dice2 - dice3;
		p2score = p2score + dicesum;
		System.out.println(p2name + " has moved to position " + p2score);
		
		
		
		if(p2score==1)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p2score = 38;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p2score = 19;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				System.out.println(p1name + " gets set back 2 spaces!");
				p1score = p1score - 2;
				System.out.println(p1name + " has moved to position " + p1score);
			}
			
		}
		else if(p2score==4)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p2score = 14;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p2score = 9;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				System.out.println(p1name + " gets set back 2 spaces!");
				p1score = p1score - 2;
				System.out.println(p1name + " has moved to position " + p1score);
			}
		}
		else if(p2score==8)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p2score = 30;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p2score = 19;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				System.out.println(p1name + " gets set back 2 spaces!");
				p1score = p1score - 2;
				System.out.println(p1name + " has moved to position " + p1score);
			}
		}
		else if(p2score==21)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p2score = 42;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p2score = 31;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				System.out.println(p1name + " gets set back 2 spaces!");
				p1score = p1score - 2;
				System.out.println(p1name + " has moved to position " + p1score);
			}
		}
		else if(p2score==28)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p2score = 76;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p2score = 52;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				System.out.println(p1name + " gets set back 2 spaces!");
				p1score = p1score - 2;
				System.out.println(p1name + " has moved to position " + p1score);
			}
		}
		else if(p2score==32)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p2score = 10;
					System.out.println(p2name + " has moved to position " + p2score);
				}
			}
		}
		else if(p2score==36)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p2score = 6;
					System.out.println(p2name + " has moved to position " + p2score);
				}
			}
		}
		else if(p2score==48)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p2score = 26;
					System.out.println(p2name + " has moved to position " + p2score);
				}
			}
		}
		else if(p2score==50)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p2score = 67;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p2score = 58;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				System.out.println(p1name + " gets set back 2 spaces!");
				p1score = p1score - 2;
				System.out.println(p1name + " has moved to position " + p1score);
			}
		}
		else if(p2score==62)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p2score = 18;
					System.out.println(p2name + " has moved to position " + p2score);
				}
			}
		}
		else if(p2score==71)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p2score = 92;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p2score = 82;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				System.out.println(p1name + " gets set back 2 spaces!");
				p1score = p1score - 2;
				System.out.println(p1name + " has moved to position " + p1score);
			}
		}
		else if(p2score==80)
		{
			System.out.println("You landed on a ladder!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1>3)
				{
					System.out.println("Go the full way up he ladder!");
					p2score = 99;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				else if(dice1<4)
				{
					System.out.println("Go halfway up the ladder!");
					p2score = 89;
					System.out.println(p2name + " has moved to position " + p2score);
				}
				System.out.println(p1name + " gets set back 2 spaces!");
				p1score = p1score - 2;
				System.out.println(p1name + " has moved to position " + p1score);
			}
		}
		else if(p2score==88)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p2score = 24;
					System.out.println(p2name + " has moved to position " + p2score);
				}
			}
		}
		else if(p2score==95)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p2score = 56;
					System.out.println(p2name + " has moved to position " + p2score);
				}
			}
		}
		else if(p2score==97)
		{
			System.out.println("You landed on a snake!");
			System.out.println("Type 'r'(Roll) to roll dice");
	        roll = scan.next();
	        r = roll.charAt(0);
	        if(r=='r')
	        {
			    dice1 = rand.nextInt(6) + 1;
		        System.out.println(dice1);
	            if(dice1==6)
				{
					System.out.println("Snake has been avoided!");
				}
				else if(dice1<6)
				{
					System.out.println("Go down the snake!");
					p2score = 78;
					System.out.println(p2name + " has moved to position " + p2score);
				}
			}
		}
		else if(dicesum==0)
		{
			System.out.println("You rolled a 0, teleport to opposing player's position!");
			p2score = p1score;
			System.out.println(p2name + " has moved to position " + p2score);
		}
		else if(p2score>=100)
		{
			break;
		}
		
		

            if(p1score>100){
                System.out.println(p1score);
                win = true;
            }
            else if(p2score>100){
                System.out.println(p2score);
                win = true;
            }
	    }while(win != true);
		
		if(p1score>100)
		{
			System.out.println(p1name + " wins the game!");
		}
        else if(p2score>100)
		{
			System.out.println(p2name + " wins the game!");
		}
		
		
		
		
	
	}
	
}
	