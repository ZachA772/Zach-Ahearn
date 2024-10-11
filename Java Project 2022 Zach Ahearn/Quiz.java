/*
*Name: Zach Ahearn
*Date: 09/11/2022
*Function: Get Keyboard Input
*/


import java.util.Scanner;

public class Quiz
{//start of class
    public static void main (String [] args)
	{//start of the method
	    //Variables
		Scanner scan = new Scanner(System.in);
		
		//Q1
		String question1;
		//Q2
		int question2 = 0;
		//Q3
		boolean question3 = true;
		//Q4
		String question4;
		char q4char;
		//Q5
		String question5;
		//Q6
		int question6 = 0;
		//Q7
		String question7;
		char q7char;
		//Q8
		boolean question8 = true;
		//Q9
		String question9;
		char q9char;
		//10
		String question10;
		//Q11
		boolean question11 = false;
		//Q12
		int question12 = 0;
		//Q13
		String question13;
		//Q14
		int question14 = 0;
		//Q15
		boolean question15 = false;
		//Q16
		String question16;
		char q16char;
		//Q17
		int question17 = 0;
		//Q18
		String question18;
		//Q19
		String question19;
		char q19char;
		//Q20
		boolean question20 = false;
		//Score
		int score = 0;
		//Loop Variable
		String playagain;
		char no = 'n';
		int i = 0;
		
		//Start of the quiz
		do
		{
		System.out.println("THIS IS A QUIZ BASED ON THE 2011 GAME 'TERRARIA'");
		System.out.println("There will be 20 questions with a mix of multiple choice, true or false, ect.");
		System.out.println("Please answer questions in lowercase");
		
		//Q1--------------------------------------------------------------------
		System.out.println("Question 1: What ore are your starting tools made from upon loading your charcater for the first time?");
		question1 = scan.next();
		
		
		if(question1.equals("copper"))
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was 'copper'.");
		}
		
		//Q2----------------------------------------------------------------------
		
		System.out.println("Question 2: How many bosses can you fight in pre-hardmode in one world?");
		question2 = scan.nextInt();
		
		if(question2 == 7)
		{
			System.out.println("Correct!");
			score = score + 5;
		}
		else{
			System.out.println("Incorrect! The correct answer is '7'");
		}
		
		//Q3------------------------------------------------------------------------
		System.out.println("Question 3: True or False, the Wall of Flesh is the final boss before Hard-mode");
		question3 = scan.nextBoolean();
		 
		if(question3 == true)
		{
			System.out.println("Correct!");
			score = score + 5;
		}
		else if(question3 == false)
		{
			System.out.println("Incorrect! The correct answer is 'True'");
		}
		//Q4---------------------------------------------------------------------------
		System.out.println("Question 4: What is the requirement for the Merchant NPC to move into your world?(Choose 'a', 'b' or 'c'");
		System.out.println("a)You have aquired at least 50 copper coins");
		System.out.println("b)You have aquired at least 50 silver coins");
		System.out.println("c)You have aquired at least 1 gold coin");
		
		question4 = scan.nextLine();
		question4 = scan.nextLine();
		q4char = question4.charAt(0);
		
		switch(q4char)
		
		
		//Output   
		
		{
		 case 'a':
		 case 'A': System.out.println("Incorrect! The correct answer was 'c'");
		 break;
		 case 'b':
		 case 'B': System.out.println("Incorrect! The correct answer was 'c'");
		 break;
		 case 'c':
		 case 'C': System.out.println("Correct!");
		           score = score + 5;
		 break;
		 default: System.out.println("Invalid Entry");
		}
		
		//System.out.println("DEBUG " + score);
		//Q5------------------------------------------------------------------
		System.out.println("Question 5: What ore has a chance to drop from the sky after defeating The Goblin Army?");
		question5 = scan.nextLine();
		
		
		
		if(question5.equals("meteorite"))
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was 'meteorite'.");
		}
		
		//Q6---------------------------------------------------------------------
		System.out.println("Question 6: How many NPCs are there in the game?");
		question6 = scan.nextInt();

		if(question6 == 32)
		{
			System.out.println("Correct!");
			score = score + 5;
		}
		else{
			System.out.println("Incorrect! The correct answer is '32'");
		}
		
		//Q7-------------------------------------------------------------------
		System.out.println("Question 7: Which of these bosses is NOT a hardmode boss?(Choose 'a', 'b' or 'c'");
		System.out.println("a)Brain of Cthulu");
		System.out.println("b)The Twins");
		System.out.println("c)Duke Fishron");
		
		question7 = scan.next();
		q7char = question7.charAt(0);
		
		if(q7char == 'a')
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was 'a'.");
		}
		
		//Q8-------------------------------------------------------------------
		System.out.println("Question 8: True or False, the Plantera MUST be defeated before fighting Golem.");
		question8 = scan.nextBoolean();
		 
		if(question8 == true)
		{
			System.out.println("Correct!");
			score = score + 5;
		}
		else if(question3 == false)
		{
			System.out.println("Incorrect! The correct answer is 'True'");
		}
		
		//Q9--------------------------------------------------------------------
		System.out.println("Question 9: Which event is NOT a real event in-game?(Choose 'a', 'b' or 'c'");
		System.out.println("a)Pumpkin Moon");
		System.out.println("b)Martian Madness");
		System.out.println("c)Vampire Invasion");
		
		question9 = scan.next();
		q9char = question9.charAt(0);
		
		if(q9char == 'c')
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was 'c'.");
		}
		
		//Q10-------------------------------------------------------------------
		System.out.println("Question 10: What must the trader be named in order to drop the Green Cap when killed?");
		question10 = scan.nextLine();
		question10 = scan.nextLine();
		
		if(question10.equals("andrew"))
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was 'andrew'.");
		}
		
		//-----------------------------------------------------------------------
		System.out.println("YOU'RE HALF-WAY THERE! YOU CAN DO IT!");
		//-----------------------------------------------------------------------
		
		//Q11--------------------------------------------------------------------
		System.out.println("Question 11: True or False, the Lunatic Cultist is the final boss of the game.");
		question11 = scan.nextBoolean();
		 
		if(question11 == false)
		{
			System.out.println("Correct!");
			score = score + 5;
		}
		else if(question11 == true)
		{
			System.out.println("Incorrect! The correct answer is 'False'");
		}
		
		//Q12--------------------------------------------------------------------
		System.out.println("Question 12: How many hours is the day-time to night-time cycle?");
		question12 = scan.nextInt();
		
		if(question12==15)
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was '15'.");
		}
		
		//Q13--------------------------------------------------------------------
		System.out.println("Question 13: Which NPC moves into the world after Plantera is defeated?");
		question13 = scan.nextLine();
		question13 = scan.nextLine();
		
		
		if(question13.equals("cyborg"))
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was 'cyborg'.");
		}
		
		//Q14--------------------------------------------------------------------
		System.out.println("Question 14: How many Lunar Pillars must be defeated before the Moon Lord spawns?");
		question14 = scan.nextInt();
		
		if(question14==4)
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was '4'.");
		}
		
		//Q15--------------------------------------------------------------------
		System.out.println("Question 15: True or False, the Stylist is found in the jungle biome.");
		question15 = scan.nextBoolean();
		 
		if(question15 == false)
		{
			System.out.println("Correct!");
			score = score + 5;
		}
		else if(question3 == true)
		{
			System.out.println("Incorrect! The correct answer is 'False'");
		}
		
		//Q16--------------------------------------------------------------------
		System.out.println("Question 16: Which of these items IS dropped by the Moon Lord?(Choose 'a', 'b' or 'c'");
		System.out.println("a)Heat Ray");
		System.out.println("b)Nymph Banner");
		System.out.println("c)Portal Gun");
		
		question16 = scan.next();
		q16char = question16.charAt(0);
		
		if(q16char == 'c')
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was 'C'.");
		}
		
		//Q17--------------------------------------------------------------------
		System.out.println("Question 17: How much wood is involved in the making of a bed?");
		question17 = scan.nextInt();
		
		if(question17==15)
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was '15'.");
		}
		
		//Q18--------------------------------------------------------------------
		System.out.println("Question 18: What is the main colour assosicated with the Corruption Biome?");
		question18 = scan.nextLine();
		question18 = scan.nextLine();
		
		
		if(question18.equals("purple"))
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was 'Purple'.");
		}
		
		//Q19--------------------------------------------------------------------
		System.out.println("Question 19: What needs to be thrown into lava in hell in order to summon The Wall Of Flesh?(Choose 'a', 'b' or 'c'");
		System.out.println("a)Guide Vodoo Doll");
		System.out.println("b)Clothier Voodoo Doll");
		System.out.println("c)Shadowflame Hex Doll");
		question19 = scan.next();
		q19char = question19.charAt(0);
		
		if(q19char == 'a')
		{
			 System.out.println("Correct!");
			 score = score + 5;
		}
		else
		{
			System.out.println("Incorrect! The correct answer was 'a'.");
		}
		
		//Q20--------------------------------------------------------------------
		System.out.println("Question 20: True or False, Vortex armour improves the stats related to the Magic Class");
		question20 = scan.nextBoolean();
		 
		if(question20 == false)
		{
			System.out.println("Correct!");
			score = score + 5;
		}
		else if(question20 == true)
		{
			System.out.println("Incorrect! The correct answer is 'False'");
		}
		
		System.out.println("Congratulations! You have completed the Quiz!");
		System.out.println("You achieved an incredible score of " + score + " out of 100");
		
		System.out.println("Do you wish to play again? 'y'(yes) or 'n'(no)");
		playagain = scan.next();
		no = playagain.charAt(0);
		i++;
	}while(no == 'y');
	
		System.out.println("Thank you for playing my quiz <3");
		
		
		
		
		
	
	}
	
}
	