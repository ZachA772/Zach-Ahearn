//UNIQUE GAME FEATURES
//1. 3 Dice - add two, minus third (Arrays)
//2. Both Player's Position's are swapped when 0 is rolled (Class Files)
//3. If a player rolls a 10, the opposing player is set back 2 spaces
//4. If both players end on the same position, 50% chance player 1 or 2 will be sent back 5 spaces
//5. If player lands on a snake, 1/6 chance to not go down snake (Abstract Class)
//6. If player lands on ladder, 50% chance to go halfway up ladder instead of full ladder
//---------------------------------------------------------------------------------------------------
// Class Files - Line 98
// Encapsulation - Line 60
// Abstraction - Line 91
// Inheritance - Line - 36
// Composition - Line 93
// Abstract Classes - Line 103
// Interfaces - Line 106
// Polymorphism. - Line 380
// Arrays - Line 279
// Collections - Line 713
//---------------------------------
import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.Dimension;
import java.awt.Font;
import javax.swing.JLabel;
import java.awt.Color;
import java.awt.Image;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.util.*;

//INHERITANCE - The class SnakesAndLaddersProject2023 extends the class JFrame which forms an inheritance relationship
public class SnakesAndLaddersProject2023 extends JFrame 
{
	
	
	public static void main(String[] args) 
	{
       JFrame frame = new SnakesAndLaddersProject2023();
		frame.setTitle("SNAKES AND LADDERS");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
    }
	
	private JLabel imageLabel;
	private JLabel welcomeLabel;
	private JButton rollDiceButton; 
	private JLabel player1Label;
	private JLabel player2Label;
	private JLabel Letters;
	private JLabel currentPlayerLabel;
	private int currentPlayer = 1;
	String snakeString;
	
	
	//ENCAPSULATION - The EncapPlayer class uses getter and setter public methods which are used to change the private int variable inside the class. This is used to get and set the position of the players 
	private EncapPlayer p1Position;
	//private int p1Position = 0;
	
	private EncapPlayer p2Position;
	
	boolean winner = false;
	
	private static final int FRAME_WIDTH = 1530;
	private static final int FRAME_HEIGHT = 1080;
	
	private Dice dice;
	
	 private PositionSwap positionSwap;
	 
	 private MaxRoll maxRoll;
	 
	 private Overlap positionOverlap;
	 
	 private Snake possibleSnake;
	 
	 private Ladder doLadder;
	 
	 private Set<String> snake = new LinkedHashSet<>();
	 
	 

	

    public SnakesAndLaddersProject2023() 
	{
		//ABSTRACTION - Dice, Snake, and Ladder are all used to hide the details of the classes in different files and only show important features of the objects
		
		//COMPOSITION - The Dice class contains a new object of Random. This is used to apply the random values for the 3 die
		dice = new Dice();
		
		positionSwap = new PositionSwap();
		
		//CLASS FILES - MaxRoll is a class file used to send back a player spaces when the opposite player rolls the max value they can roll
		maxRoll = new MaxRoll();
		
		positionOverlap = new Overlap();
		
		//ABSTRACT - The class Snake extends class AbstractSnake which is an abstract class
		possibleSnake = new Snake();
		
		//INTERFACE - The ladder class implements another class named interfaceLadder which is an interface class
		doLadder = new Ladder();
        
        setSize(FRAME_WIDTH, FRAME_HEIGHT);
        
        setLayout(null);

		JButton rollDiceButton = new JButton("Roll Dice!");
		rollDiceButton.setBackground(Color.YELLOW);
		rollDiceButton.setVisible(true);
		
		JButton playButton = new JButton("Play");
		playButton.setBackground(Color.GREEN);
		
        JButton exitButton = new JButton("Exit");
		exitButton.setBackground(Color.RED);
		
		
		
		
		imageLabel = new JLabel();
		
		ImageIcon icon = new ImageIcon("board.png");
		Image img = icon.getImage().getScaledInstance(1200, 780, Image.SCALE_SMOOTH);
		imageLabel.setIcon(new ImageIcon(img));
		imageLabel.setPreferredSize(new Dimension(1200, 780));
		imageLabel.setBounds(0, 0, 1200, 780);
		imageLabel.setVisible(false);
		
		welcomeLabel = new JLabel();
		
		ImageIcon welcomeIcon = new ImageIcon("welcome.png");
		Image welimg = welcomeIcon.getImage().getScaledInstance(1500, 1000, Image.SCALE_SMOOTH);
		welcomeLabel.setIcon(new ImageIcon(welimg));
		welcomeLabel.setPreferredSize(new Dimension(1500, 1000));
		welcomeLabel.setBounds(50, -300, 1500, 1000);

		player1Label = new JLabel("Player: 1 Position: - ");
		player1Label.setVisible(true);
		player2Label = new JLabel("Player: 2 Position: - ");
		player2Label.setVisible(true);
		currentPlayerLabel = new JLabel("It is now player " + currentPlayer + "'s turn");
		currentPlayerLabel.setVisible(true);
		
		Letters = new JLabel("Letters collected: -");
		Letters.setVisible(true);
		
		 // Set a larger font for the buttons
        Font font = new Font("Comic Sans MS", Font.PLAIN, 20);
		rollDiceButton.setFont(font);
        playButton.setFont(font);
        exitButton.setFont(font);
		Letters.setFont(font);
		//-------------------------
		Font playerFont = new Font("Comic Sans MS", Font.PLAIN, 23);
		player1Label.setFont(playerFont);
		player2Label.setFont(playerFont);
		currentPlayerLabel.setFont(playerFont);
		//-------------------------------------
		
		p1Position = new EncapPlayer();
		p1Position.setPosition(0);
		
		p2Position = new EncapPlayer();
		p2Position.setPosition(0);
		
        rollDiceButton.setBounds(1220, 600, 270, 100);
        rollDiceButton.setVisible(false);
        playButton.setBounds(615, 400, 300, 60);
        exitButton.setBounds(615, 500, 300, 60);
        player1Label.setBounds(1220, 100, 270, 100);
        player1Label.setVisible(false);
        player2Label.setBounds(1220, 200, 270, 100);
        player2Label.setVisible(false);
		Letters.setBounds(1220, 300, 270, 100);
        Letters.setVisible(false);
        currentPlayerLabel.setBounds(1220, 0, 270, 100);
        currentPlayerLabel.setVisible(false);

       
	   rollDiceButton.addActionListener(new ActionListener() 
		{
            public void actionPerformed(ActionEvent e) 
			{
				if(!winner)
				{
					rollingDice();
				}
				else
				{
					rollDiceButton.setVisible(false);
					imageLabel.setVisible(false);
					player1Label.setVisible(false);
					player2Label.setVisible(false);
					Letters.setVisible(false);
					currentPlayerLabel.setVisible(false);
					playButton.setVisible(true);
					playButton.setText("Play Again?");
					exitButton.setVisible(true);
					
					
					
				}
			}
        });
	   //----------------------------------------------------------------------------------
	   
	    //PLAY BUTTON/RESET BUTTON=======================================
        playButton.addActionListener(new ActionListener() 
		{
            
            public void actionPerformed(ActionEvent e) 
			{
                //System.out.println("Clicked Play");
				welcomeLabel.setVisible(false);
				playButton.setVisible(false);
				exitButton.setVisible(false);
				imageLabel.setVisible(true);
				rollDiceButton.setVisible(true);
				currentPlayerLabel.setVisible(true);
				player1Label.setVisible(true);
				player2Label.setVisible(true);
				Letters.setVisible(true);
				
				currentPlayer = 1;
				p1Position.setPosition(0);
				p2Position.setPosition(0);
				
				currentPlayerLabel.setText("It is now player " + currentPlayer + "'s turn");
				player1Label.setText("Player: 1 Position: - ");
				player2Label.setText("Player: 2 Position: - ");
				
				if(winner)
				{
					if(snakeString.length() == 5)
					{
						snake.clear();
						snakeString = ""; 
						Letters.setText("Letters collected: -");
					}
				}
				winner = false;		
					
				
            }
        });
//=========================================================================================
        exitButton.addActionListener(new ActionListener() 
		{
            public void actionPerformed(ActionEvent e) 
			{
                System.exit(0);
            }
        });
		
		//ADD OBJECTS TO PANEL========================================================
		add(imageLabel);
		add(rollDiceButton);
		add(welcomeLabel);
        add(playButton);
        add(exitButton);
        add(player1Label);
        add(player2Label);
        add(Letters);
        add(currentPlayerLabel);
		
		//Centres the frame to the middle of the screen
        setLocationRelativeTo(null);
        
    }

    public int[] rollingDice() 
	{
		//ARRAY - Array used to hold the values of the 3 die when they are assigned random values.
        int[] diceValues = new int[3];

        for (int i = 0; i < 3; i++) 
		{
            diceValues[i] = dice.roll();
        }

        int diceSum = diceValues[0] + diceValues[1] - diceValues[2];
		
		//System.out.println(diceSum);
		/*
		System.out.println("ZZZZZZZZZZ");
		System.out.println(diceValues[0]);
		System.out.println(diceValues[1]);
		System.out.println(diceValues[2]);
		System.out.println("ZZZZZZZZZZ");
		*/
		
		//Checks if the diceSum is 0 to swap the player's positions
		if(diceSum == 0)
		{
			 positionSwap.swapPositions(p1Position, p2Position);
			 player1Label.setText("Player: " + 1 + " | Position: " + p1Position.getPosition());
			 player2Label.setText("Player: " + 2 + " | Position: " + p2Position.getPosition());
			 return diceValues; 
		}
		
		//Checks if the diceSum is 10 to set back a player spaces
		if(diceSum == 10)
		{
				 maxRoll.rollMax(p1Position, p2Position, currentPlayer);
				 player1Label.setText("Player: " + 1 + " | Position: " + p1Position.getPosition());
				 player2Label.setText("Player: " + 2 + " | Position: " + p2Position.getPosition());
		}
		
		//Checks if the diceSum is not 0 to add value of the diceSum to the correct player
		if(diceSum!=0)
		{
			if(currentPlayer == 1)
			{
				p1Position.setPosition(p1Position.getPosition() + diceSum);
				
			   player1Label.setText("Player: " + 1 + " | Position: " + p1Position.getPosition());

			}
			else if(currentPlayer == 2)
			{
			   p2Position.setPosition(p2Position.getPosition() + diceSum);
			   
			   player2Label.setText("Player: " + 2 + " | Position: " + p2Position.getPosition());
			}
		}
		
		//Checks if both player positions are equal and calls a method to determine which player should be set back spaces
		if(p1Position.getPosition() == p2Position.getPosition())
		{
			positionOverlap.overlapPosition(p1Position, p2Position);
			player1Label.setText("Player: " + 1 + " | Position: " + p1Position.getPosition());
			player2Label.setText("Player: " + 2 + " | Position: " + p2Position.getPosition());
		}
		
		//Sets player position accordingly if they have landed on a snake or a ladder
		p1Position.setPosition(laddSnk1(p1Position.getPosition()));
		p2Position.setPosition(laddSnk2(p2Position.getPosition()));
		
		//Updates the player text
		player1Label.setText("Player: " + 1 + " | Position: " + p1Position.getPosition());
		player2Label.setText("Player: " + 2 + " | Position: " + p2Position.getPosition());
		
		currentPlayer = 3 - currentPlayer;
		currentPlayerLabel.setText("It is now player " + currentPlayer + "'s turn");
		
		//Updates the snake string to show how many letters have been collected
		snakeString = convertSnakeSetToString(snake);
		Letters.setText("Letters collected: " + snakeString);
		//System.out.println(snake);
		
		//Checks to see if any player has won
		checkForWinner(p1Position.getPosition(), p2Position.getPosition(), snakeString);
		winner = checkForWinner(p1Position.getPosition(), p2Position.getPosition(), snakeString);
		
		
		
		 return diceValues;

    }
	
	
	//METHODS TO DETERMINE IF A PLAYER HAS LANDED ON A SNAKE OR LADDER
	//Ladder method 1
	private int laddSnk1(int p1Position)
	{
		boolean goDownSnake = true;
		boolean goUpLadder = true;
		
		 switch (p1Position) 
		 {
            //HANDLING SNAKES==========================================================
            case 18:
			
				////POLYMORPHISM - a method is called within the Snake class which extends an abstract class
				possibleSnake.downSnake(currentPlayer, goDownSnake);
				snake.add("s");
				
				if(!goDownSnake)
				{
					goDownSnake = true;
					return 6;
					
				}
				else
				{
					return p1Position;
				}
				
					
            case 29:
				possibleSnake.downSnake(currentPlayer, goDownSnake);
				snake.add("n");
				
				if(!goDownSnake)
				{
					goDownSnake = true;
					return 7;
					
				}
				else
				{
					return p1Position;
				}
			 case 61:
				
				possibleSnake.downSnake(currentPlayer, goDownSnake);
				snake.add("a");
				
				if(!goDownSnake)
				{
					goDownSnake = true;
					return 16;					
				}
				else
				{
					return p1Position;
				}
			 case 72:
				possibleSnake.downSnake(currentPlayer, goDownSnake);
				snake.add("k");
				
				if(!goDownSnake)
				{
					goDownSnake = true;
					return 47;
					
				}
				else
				{
					return p1Position;
				}
			 case 96:
				possibleSnake.downSnake(currentPlayer, goDownSnake);
				snake.add("e");
				
				if(!goDownSnake)
				{
					goDownSnake = true;
					return 76;
					
				}
				else
				{
					return p1Position;
				}
            //HANDLING LADDERS=======================================================
            case 2:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("s");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 20;
					
				}
				else
				{
					return 38;
				}
            case 9:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("n");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 12;
					
				}
				else
				{
					return 14;
				}
			 case 15:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("a");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 34;
					
				}
				else
				{
					return 82;
				}
			 case 16:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("k");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 35;
					
				}
				else
				{
					return 54;
				}
			 case 50:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("e");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 71;
					
				}
				else
				{
					return 91;
				}
			 case 74:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("s");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 81;
					
				}
				else
				{
					return 87;
				}
            default:
                return p1Position;
		 }
		
	}
	
	//Ladder method 2
	private int laddSnk2(int p2Position)
	{
		boolean goDownSnake = true;
		boolean goUpLadder = true;
		
		switch (p2Position) 
		{
            //HANDLING SNAKES==================================================
            case 18:
				possibleSnake.downSnake(currentPlayer, goDownSnake);
				snake.add("s");
				
				if(!goDownSnake)
				{
					goDownSnake = true;
					return 6;
					
				}
				else
				{
					return p2Position;
				}
            case 29:
				possibleSnake.downSnake(currentPlayer, goDownSnake);
				snake.add("n");
				
				if(!goDownSnake)
				{
					goDownSnake = true;
					return 7;
					
				}
				else
				{
					return p2Position;
				}
			 case 61:
				possibleSnake.downSnake(currentPlayer, goDownSnake);
				snake.add("a");
				
				if(!goDownSnake)
				{
					goDownSnake = true;
					return 16;
					
				}
				else
				{
					return p2Position;
				}
			 case 72:
				possibleSnake.downSnake(currentPlayer, goDownSnake);
				snake.add("k");
				
				if(!goDownSnake)
				{
					goDownSnake = true;
					return 47;
					
				}
				else
				{
					return p2Position;
				}
			 case 96:
			 possibleSnake.downSnake(currentPlayer, goDownSnake);
			 snake.add("e");
				
				if(!goDownSnake)
				{
					goDownSnake = true;
					return 76;
					
				}
				else
				{
					return p2Position;
				}
            // HANDLING LADDERS=================================================================
            case 2:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("s");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 20;
					
				}
				else
				{
					return 38;
				}
            case 9:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("n");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 12;
					
				}
				else
				{
					return 14;
				}
			 case 15:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("a");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 34;
					
				}
				else
				{
					return 82;
				}
			 case 16:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("k");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 35;
					
				}
				else
				{
					return 54;
				}
			 case 50:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("e");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 71;
					
				}
				else
				{
					return 91;
				}
			 case 74:
				doLadder.halfLadder(currentPlayer, goUpLadder);
				snake.add("s");
				
				if(!goUpLadder)
				{
					goUpLadder = true;
					return 81;
					
				}
				else
				{
					return 87;
				}
            default:
                return p2Position;
		 }
		
	}
	
	//COLLECTION - Goes through a string set and converts it into a single string
	//Player collects letters if they go down a snake
	private String convertSnakeSetToString(Set<String> snakeSet) 
	 {
		StringBuilder snakeString = new StringBuilder();

		for (String letter : snakeSet) 
		{
			snakeString.append(letter);
		}

		return snakeString.toString();
	}
	
	
	
	
	//Method to check for winner
	public boolean checkForWinner(int p1Check, int p2Check, String stringOfSnake) 
	{
		if (p1Check >= 100 || p2Check >= 100) 
		{
			return true;
		}
		else if(stringOfSnake.length() == 5)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
}