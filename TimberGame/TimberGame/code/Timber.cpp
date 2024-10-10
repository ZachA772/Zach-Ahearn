// Include important C++ libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

// Make code easier to type with "using namespace"
using namespace sf;
// Function declaration
void updateBranches(int seed);

const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];

// Where is the player/branch? 
// Left or Right
enum class side { LEFT, RIGHT, NONE };
side branchPositions[NUM_BRANCHES];


int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	Texture textureHorrorBackground;

	Texture textureBossBackground;



	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.png");

	textureHorrorBackground.loadFromFile("graphics/horrorBackground.png");

	textureBossBackground.loadFromFile("graphics/bossBackground.png");

	// Create a sprite
	Sprite spriteBackground;


	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	// Make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");

	Texture textureHorrorTree;
	textureHorrorTree.loadFromFile("graphics/horrorTree.png");

	Texture textureBossTree;
	textureBossTree.loadFromFile("graphics/bossTree.png");

	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	// Prepare the bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");

	Texture textureEyeball;
	textureEyeball.loadFromFile("graphics/eyeball.png");

	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);

	//Prepare 2nd bee

	Sprite spriteBee2;
	spriteBee2.setTexture(textureBee);
	spriteBee2.setPosition(0, 700);

	Texture textureDragon1;
	textureDragon1.loadFromFile("graphics/dragon1.png");

	Texture textureDragon2;
	textureDragon2.loadFromFile("graphics/dragon2.png");

	//Bee 3
	Sprite spriteBee3;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 600);

	// Dragon sprite provided by Jordn Irwin at https://opengameart.org/content/flying-dragon-rework


	// Is the bee currently moving?
	bool beeActive = false;
	bool beeActive2 = false;
	bool beeActive3 = false;

	// How fast can the bee fly
	float beeSpeed = 0.0f;
	float beeSpeed2 = 0.0f;
	float beeSpeed3 = 0.0f;

	int beeHeight2 = 0.0;

	// make 3 cloud sprites from 1 texture
	Texture textureCloud;
	Texture textureHorrorCloud;

	// Load 1 new texture
	textureCloud.loadFromFile("graphics/cloud.png");
	textureHorrorCloud.loadFromFile("graphics/horrorCloud.png");

	// 3 New sprites withe the same texture
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	//Horror Cloud
	Sprite horrorCloud;

	// Position the clouds off screen
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 150);
	spriteCloud3.setPosition(0, 300);

	// Are the clouds currently on screen?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	// How fast is each cloud?
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	// Variables to control time itself
	Clock clock;
	
	Time gameTimeTotal;
	float timeRemaining = 60.0f;
	
	// Boss Health bar===============================================================================
	RectangleShape healthBar;
	float healthBarStartWidth = 400;
	float healthBarHeight = 80;
	healthBar.setSize(Vector2f(healthBarStartWidth, healthBarHeight));
	healthBar.setFillColor(Color::Magenta);
	healthBar.setPosition((1920 / 2) - healthBarStartWidth / 2, 1500);

	bool shouldDecreaseHealthBar = false;
	//================================================================================================
	// Track whether the game is running
	bool paused = true;
	// Draw some text
	int score = 0;
	int logsChopped = 0;

	sf::Text messageText;
	sf::Text timerText;
	sf::Text logsText;
	sf::Text bossNameText;

	// We need to choose a font
	sf::Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	sf::Font logfont;
	logfont.loadFromFile("fonts/Happy-Dance.ttf");

	sf::Font bossfont;
	bossfont.loadFromFile("fonts/Deadly_Killers.ttf");

	// Set the font to our message
	messageText.setFont(font);
	timerText.setFont(font);
	logsText.setFont(logfont);
	bossNameText.setFont(bossfont);
	

	// Assign the actual message
	messageText.setString("Press Enter to start!");
	timerText.setString("TIME REMAINING = 60");
	logsText.setString("Logs Chopped = 0");
	bossNameText.setString("Fallen Angel");
	
	// Make it really big
	messageText.setCharacterSize(75);
	timerText.setCharacterSize(50);
	logsText.setCharacterSize(50);
	bossNameText.setCharacterSize(50);
	

	// Choose a color
	messageText.setFillColor(Color::White);
	timerText.setFillColor(Color::White);
	logsText.setFillColor(Color::Magenta);
	bossNameText.setFillColor(Color::Red);
	

	// Position the text
	FloatRect textRect = messageText.getLocalBounds();

	messageText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

	timerText.setPosition(20, -200);

	logsText.setPosition(1120, 20);

	bossNameText.setPosition(840, 1500);


	// Prepare 5 branches
	Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch.png");

	Texture textureHorrorBranch;
	textureHorrorBranch.loadFromFile("graphics/horrorBranch.png");

	Texture textureFireBall;
	textureFireBall.loadFromFile("graphics/fireball.png");


	// Set the texture for each branch sprite
	for (int i = 0; i < NUM_BRANCHES; i++) {
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(-2000, -2000);

		// Set the sprite's origin to dead center
		// We can then spin it round without changing its position
		branches[i].setOrigin(220, 20);
	}

	// Prepare the player
	Texture texturePlayer;
	texturePlayer.loadFromFile("graphics/player.png");

	Texture textureHurtPlayer;
	textureHurtPlayer.loadFromFile("graphics/hurtPlayer.png");

	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(580, 720);

	// The player starts on the left
	side playerSide = side::LEFT;

	// Prepare the gravestone
	Texture textureRIP;
	textureRIP.loadFromFile("graphics/rip.png");
	Sprite spriteRIP;
	spriteRIP.setTexture(textureRIP);
	spriteRIP.setPosition(600, 860);

	// Prepare the axe
	Texture textureAxe;
	textureAxe.loadFromFile("graphics/axe.png");

	Texture textureSword;
	textureSword.loadFromFile("graphics/sword.png");

	Sprite spriteAxe;
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(700, 830);

	// Line the axe up with the tree
	const float AXE_POSITION_LEFT = 700;
	const float AXE_POSITION_RIGHT = 1075;

	// Prepare the flying log
	Texture textureLog;
	textureLog.loadFromFile("graphics/log.png");


	Texture textureHorrorLog;
	textureHorrorLog.loadFromFile("graphics/horrorLog.png");

	Sprite spriteLog;
	spriteLog.setTexture(textureLog);
	spriteLog.setPosition(810, 720);

	// Some other useful log related variables
	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = -1500;

	// Control the player input
	bool acceptInput = false;

	// Prepare the sound---------------------------------------------------------------------------------
	SoundBuffer chopBuffer;
	chopBuffer.loadFromFile("sound/chop.wav");
	Sound chop;
	chop.setBuffer(chopBuffer);

	SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("sound/death.wav");
	Sound death;
	death.setBuffer(deathBuffer);

	// Out of time
	SoundBuffer ootBuffer;
	ootBuffer.loadFromFile("sound/out_of_time.wav");
	Sound outOfTime;
	outOfTime.setBuffer(ootBuffer);

	// Background Track Sound
	SoundBuffer backgroundtrackBuffer;
	backgroundtrackBuffer.loadFromFile("sound/backgroundTrack.wav");
	Sound backgroundTrack;
	backgroundTrack.setBuffer(backgroundtrackBuffer);

	//Buzz Sound
	SoundBuffer buzzBuffer;
	buzzBuffer.loadFromFile("sound/Buzz.wav");
	Sound buzzTrack;
	buzzTrack.setBuffer(buzzBuffer);

	//Horror Music
	SoundBuffer horrorMusicBuffer;
	horrorMusicBuffer.loadFromFile("sound/horrorMusic.wav");
	Sound horrorMusicTrack;
	horrorMusicTrack.setBuffer(horrorMusicBuffer);

	//Boss Music
	SoundBuffer bossMusicBuffer;
	bossMusicBuffer.loadFromFile("sound/bossMusic.wav");
	Sound bossMusicTrack;
	bossMusicTrack.setBuffer(bossMusicBuffer);

	//Boss Roar
	SoundBuffer bossRoarBuffer;
	bossRoarBuffer.loadFromFile("sound/bossRoar.wav");
	Sound bossRoarTrack;
	bossRoarTrack.setBuffer(bossRoarBuffer);

	//----------------------------------------------------------------------------------------

	while (window.isOpen())
	{
		// score ++;
		Event event;
		while (window.pollEvent(event))
		{


			if (event.type == Event::KeyReleased && !paused)
			{
				// Listen for key presses again
				acceptInput = true;

				// hide the axe
				spriteAxe.setPosition(2000,
					spriteAxe.getPosition().y);
			}

		}

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			//------------------------------------------------------------------------------------------
			backgroundTrack.play();
			backgroundTrack.setLoop(true);
			//------------------------------------------------------------------------------------------
			paused = false;

			// Reset the time and the score
			shouldDecreaseHealthBar = false;
			healthBarStartWidth = 400;
			healthBar.setSize(Vector2f(healthBarStartWidth, healthBarHeight));
			score = 0;
			logsChopped = 0;
			timeRemaining = 60;

			timerText.setPosition(20, -200);
			healthBar.setPosition((1920 / 2) - healthBarStartWidth / 2, 1500);
			bossNameText.setPosition(840, 1500);

			//Reset Sprites---------------------------------------------------------------------

			spriteCloud1.setTexture(textureCloud);
			spriteCloud2.setTexture(textureCloud);
			spriteCloud3.setTexture(textureCloud);

			spriteBackground.setTexture(textureBackground);
			spriteTree.setTexture(textureTree);
			spriteLog.setTexture(textureLog);
			spriteBee.setTexture(textureBee);
			spriteBee2.setTexture(textureBee);
			spriteBee3.setTexture(textureBee);
			spriteAxe.setTexture(textureAxe);
			spritePlayer.setTexture(texturePlayer);

			for (int i = 0; i < NUM_BRANCHES; i++) {
				branches[i].setTexture(textureBranch);
				branches[i].setPosition(-2000, -2000);

				// Set the sprite's origin to dead center
				// We can then spin it round without changing its position
				branches[i].setOrigin(220, 20);
			}
			
			//------------------------------------------------------------------------------------
			// Make all the branches disappear
			for (int i = 1; i < NUM_BRANCHES; i++)
			{
				branchPositions[i] = side::NONE;
			}

			// Make sure the gravestone is hidden
			spriteRIP.setPosition(675, 2000);

			// Move the player into position
			spritePlayer.setPosition(580, 720);

			acceptInput = true;

			

		}

		// Wrap the player controls to
		// Make sure we are accepting input
		if (acceptInput)
		{

			// More code here next...
			// First handle pressing the right cursor key
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				// Make sure the player is on the right
				playerSide = side::RIGHT;

				logsChopped++;

				if (timeRemaining > 3)
				{
					score += 2;
				}
				else
				{
					score += 1;
				}

				// Add to the amount of time remaining
				//timeRemaining += (2 / timer) + .10;

				spriteAxe.setPosition(AXE_POSITION_RIGHT,
					spriteAxe.getPosition().y);



				spritePlayer.setPosition(1200, 720);

				// update the branches
				updateBranches(score);

				// set the log flying to the left
				spriteLog.setPosition(810, 720);
				logSpeedX = -5000;
				logActive = true;


				acceptInput = false;

				// Play a chop sound
				chop.play();

			}

			// Handle the left cursor key
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				// Make sure the player is on the left
				playerSide = side::LEFT;


				logsChopped++;
				if (timeRemaining > 3)
				{
					score += 2;
				}
				else
				{
					score += 1;
				}

				// Add to the amount of time remaining
				//timeRemaining += (2 / timer) + .10;

				spriteAxe.setPosition(AXE_POSITION_LEFT,
					spriteAxe.getPosition().y);


				spritePlayer.setPosition(580, 720);

				// update the branches
				updateBranches(score);

				// set the log flying
				spriteLog.setPosition(810, 720);
				logSpeedX = 5000;
				logActive = true;


				acceptInput = false;

				// Play a chop sound
				chop.play();

			}



		}


		/*
		****************************************
		Update the scene
		****************************************
		*/
		if (!paused)
		{
				// Measure time
				Time dt = clock.restart();

				//Horror Starts after X amount of chops===============================================================
				//Jumpscare 1//---------------------------------------------------------------------------------------
				if (logsChopped == 23)
				{
					buzzTrack.play();

				}
				if(logsChopped == 24)
				{
					backgroundTrack.stop();
					spriteCloud1.setTexture(textureHorrorCloud);
				}
				
				if (logsChopped == 24)
				{
					backgroundTrack.play();
					backgroundTrack.setLoop(true);
				}
				if (logsChopped == 25)
				{
					spriteCloud1.setTexture(textureCloud);

				}

				//Jumpscare 2//---------------------------------------------------------------------------------------
				if (logsChopped == 56)
				{
					buzzTrack.play();

				}
				if (logsChopped == 57)
				{
					backgroundTrack.stop();
					spriteBee.setTexture(textureEyeball);
					spriteCloud2.setTexture(textureHorrorCloud);
				}

				if (logsChopped == 57)
				{
					backgroundTrack.play();
					backgroundTrack.setLoop(true);
				}
				if (logsChopped == 58)
				{
					spriteBee.setTexture(textureBee);
					spriteCloud2.setTexture(textureCloud);

				}

				//Jumpscare 3//---------------------------------------------------------------------------------------
				if (logsChopped == 88)
				{
					buzzTrack.play();

				}
				if (logsChopped == 89)
				{
					backgroundTrack.stop();
					spriteTree.setTexture(textureHorrorTree);
					spriteCloud2.setTexture(textureHorrorCloud);
					spriteCloud3.setTexture(textureHorrorCloud);
				}

				if (logsChopped == 89)
				{
					backgroundTrack.play();
					backgroundTrack.setLoop(true);
				}
				if (logsChopped == 90)
				{
					spriteTree.setTexture(textureTree);
					spriteCloud2.setTexture(textureCloud);
					spriteCloud3.setTexture(textureCloud);

				}

				//------------------------------------------------------------------------------------------
				
				if (logsChopped == 99)
				{
					
					horrorMusicTrack.play();
					horrorMusicTrack.setLoop(true);
					
				}
				if (logsChopped >= 100) 
				{
					backgroundTrack.stop();

					spriteCloud1.setTexture(textureHorrorCloud);
					spriteCloud2.setTexture(textureHorrorCloud);
					spriteCloud3.setTexture(textureHorrorCloud);

					spriteBackground.setTexture(textureHorrorBackground);
					spriteTree.setTexture(textureHorrorTree);
					spriteLog.setTexture(textureHorrorLog);
					spriteBee.setTexture(textureEyeball);
					spriteBee2.setTexture(textureEyeball);
					spriteBee3.setTexture(textureEyeball);

					for (int i = 0; i < NUM_BRANCHES; i++) 
					{
						branches[i].setTexture(textureHorrorBranch);
						branches[i].setPosition(-2000, -2000);

						// Set the sprite's origin to dead center
						// We can then spin it round without changing its position
						branches[i].setOrigin(220, 20);
					}


					
				}
				//BOSS FIGHT!!!!!!!!!!-------------------------------------------------------
				
				if (logsChopped == 149)
				{
					bossMusicTrack.play();
					bossMusicTrack.setLoop(true);
					bossRoarTrack.play();

				}
				if (logsChopped >= 150)
				{
					horrorMusicTrack.stop();
					shouldDecreaseHealthBar = true;

					spriteBackground.setTexture(textureBossBackground);
					spriteTree.setTexture(textureBossTree);
					spriteAxe.setTexture(textureSword);
					spritePlayer.setTexture(textureHurtPlayer);
					timerText.setPosition(20, 20);
					bossNameText.setPosition(840, 910);

					healthBar.setPosition((1920 / 2) - healthBarStartWidth / 2, 980);


					// Subtract from the amount of time remaining
					timeRemaining -= dt.asSeconds();
					// size up the time bar
					/*timeBar.setSize(Vector2f(timeBarWidthPerSecond*
						timeRemaining, timeBarHeight));
						*/
					for (int i = 0; i < NUM_BRANCHES; i++)
					{
						branches[i].setTexture(textureFireBall);
						branches[i].setPosition(-2000, -2000);

						// Set the sprite's origin to dead center
						// We can then spin it round without changing its position
						branches[i].setOrigin(220, 20);
					}
				}
				if (logsChopped == 185 || logsChopped == 220 || logsChopped == 255 || logsChopped == 290)
				{
					bossRoarTrack.play();
				}


				// Update health bar based on key presses and the bool
				bool lButtonPress = true;
				bool rButtonPress = true;

				if (shouldDecreaseHealthBar)
				{
					if (Keyboard::isKeyPressed(Keyboard::Left) && lButtonPress)
					{
						healthBar.setSize(Vector2f(healthBarStartWidth -= 0.15, healthBarHeight));
						lButtonPress = false;
						rButtonPress = true;
					}
					else if (Keyboard::isKeyPressed(Keyboard::Right) && rButtonPress)
					{
						healthBar.setSize(Vector2f(healthBarStartWidth -= 0.15, healthBarHeight));
						rButtonPress = false;
						lButtonPress = true;
					}
				}
				


				/*if (shouldDecreaseHealthBar && (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Left)))
				{

					healthBar.setSize(Vector2f(healthBarStartWidth -= 0.1, healthBarHeight));
				}
				*/
				
			//------------------------------------------------------------------------------------------
				if (timeRemaining <= 0.0f) 
				{

					// Pause the game
					paused = true;

					// Change the message shown to the player
					messageText.setString("Out of time!!");

					//Reposition the text based on its new size
					FloatRect textRect = messageText.getLocalBounds();
					messageText.setOrigin(textRect.left +
						textRect.width / 2.0f,
						textRect.top +
						textRect.height / 2.0f);

					messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

					// Play the out of time sound
					outOfTime.play();


				}
			if (healthBarStartWidth <= 0) 
			{

				// Pause the game
				paused = true;

				// Change the message shown to the player
				messageText.setString("YOU WIN!!");

				//Reposition the text based on its new size
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left +
					textRect.width / 2.0f,
					textRect.top +
					textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

				// Play the out of time sound
				


			}
			//====================================================================================

			// Setup the bee
			if (!beeActive)
			{

				// How fast is the bee
				srand((int)time(0) * 10);
				beeSpeed = (rand() % 200) + 200;

				// How high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;

			}
			else
				// Move the bee
			{

				spriteBee.setPosition(
					spriteBee.getPosition().x -
					(beeSpeed * dt.asSeconds()),
					spriteBee.getPosition().y);

				// Has the bee reached the right hand edge of the screen?
				if (spriteBee.getPosition().x < -100)
				{
					// Set it up ready to be a whole new cloud next frame
					beeActive = false;
				}
			}

			//Setting up the second bee
			if (!beeActive2)
			{

				// How fast is the bee
				srand((int)time(0) * 10);
				beeSpeed2 = (rand() % 201) + 300;

				// How high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 201) + 600;
				beeHeight2 = height;
				spriteBee2.setPosition(2000, height);
				beeActive2 = true;

			}
			else
				// Move the bee
			{


				int newX = spriteBee2.getPosition().x -
					(beeSpeed2 * dt.asSeconds());

				int heightChange = (((1920 - newX) / 300) * 20);
				int newY = beeHeight2 - heightChange;

				if (logsChopped >= 150)
				{
					if (heightChange == 0 || heightChange == 40 || heightChange == 80 || heightChange == 120)
					{
						// Adjust the texture of the second bee
						spriteBee2.setTexture(textureDragon1);
					}
					else
					{
						spriteBee2.setTexture(textureDragon2);
					}
				}
				std::cout << heightChange << std::endl;


				spriteBee2.setPosition(newX, newY);

				// Has the bee reached the right hand edge of the screen?
				if (spriteBee2.getPosition().x < -100)
				{
					// Set it up ready to be a whole new cloud next frame
					beeActive2 = false;
				}
			}

			//Setting up Bee 3
			if (!beeActive3)
			{

				// How fast is the bee
				srand((int)time(0) * 10);
				beeSpeed3 = (rand() % 200) + 100;

				// How high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 400;
				spriteBee3.setPosition(2000, height);
				beeActive3 = true;

			}
			else
				// Move the bee
			{

				spriteBee3.setPosition(
					spriteBee3.getPosition().x -
					(beeSpeed3 * dt.asSeconds()),
					spriteBee3.getPosition().y);

				// Has the bee reached the right hand edge of the screen?
				if (spriteBee3.getPosition().x < -100)
				{
					// Set it up ready to be a whole new cloud next frame
					beeActive3 = false;
				}
			}


			// Manage the clouds
			// Cloud 1
			if (!cloud1Active)
			{

				// How fast is the cloud
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200);

				// How high is the cloud
				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				cloud1Active = true;


			}
			else
			{

				spriteCloud1.setPosition(
					spriteCloud1.getPosition().x +
					(cloud1Speed * dt.asSeconds()),
					spriteCloud1.getPosition().y);

				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud1.getPosition().x > 1920)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud1Active = false;
				}
			}

			// Cloud 2
			if (!cloud2Active)
			{

				// How fast is the cloud
				srand((int)time(0) * 20);
				cloud2Speed = (rand() % 200);

				// How high is the cloud
				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				cloud2Active = true;


			}
			else
			{

				spriteCloud2.setPosition(
					spriteCloud2.getPosition().x +
					(cloud2Speed * dt.asSeconds()),
					spriteCloud2.getPosition().y);

				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud2.getPosition().x > 1920)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud2Active = false;
				}
			}

			if (!cloud3Active)
			{

				// How fast is the cloud
				srand((int)time(0) * 30);
				cloud3Speed = (rand() % 200);

				// How high is the cloud
				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteCloud3.setPosition(-200, height);
				cloud3Active = true;


			}
			else
			{

				spriteCloud3.setPosition(
					spriteCloud3.getPosition().x +
					(cloud3Speed * dt.asSeconds()),
					spriteCloud3.getPosition().y);

				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud3.getPosition().x > 1920)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud3Active = false;
				}
			}

			// Update the score text
			std::stringstream ss;
			ss << "TIME REMAINING = " << timeRemaining;
			timerText.setString(ss.str());

			// Update the logsChopped text
			std::stringstream ss2;
			ss2 << "Logs Chopped = " << logsChopped;
			logsText.setString(ss2.str());


			// update the branch sprites
			for (int i = 0; i < NUM_BRANCHES; i++)
			{

				float height = i * 150;

				if (branchPositions[i] == side::LEFT)
				{
					// Move the sprite to the left side
					branches[i].setPosition(610, height);
					// Flip the sprite round the other way
					branches[i].setOrigin(220, 40);
					branches[i].setRotation(180);
				}
				else if (branchPositions[i] == side::RIGHT)
				{
					// Move the sprite to the right side
					branches[i].setPosition(1330, height);
					// Set the sprite rotation to normal
					branches[i].setOrigin(220, 40);
					branches[i].setRotation(0);

				}
				else
				{
					// Hide the branch
					branches[i].setPosition(3000, height);
				}
			}

			// Handle a flying log				
			if (logActive)
			{

				spriteLog.setPosition(
					spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
					spriteLog.getPosition().y + (logSpeedY * dt.asSeconds()));

				// Has the insect reached the right hand edge of the screen?
				if (spriteLog.getPosition().x < -100 ||
					spriteLog.getPosition().x > 2000)
				{
					// Set it up ready to be a whole new cloud next frame
					logActive = false;
					spriteLog.setPosition(810, 720);
				}
			}

			// has the player been squished by a branch?
			if (branchPositions[5] == playerSide)
			{
				// death

				paused = true;
				acceptInput = false;

				// Draw the gravestone
				spriteRIP.setPosition(525, 760);

				// hide the player
				spritePlayer.setPosition(2000, 660);

				// Change the text of the message
				messageText.setString("SQUISHED!!");

				// Center it on the screen
				FloatRect textRect = messageText.getLocalBounds();

				messageText.setOrigin(textRect.left +
					textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f,
					1080 / 2.0f);

				// Play the death sound
				death.play();


			}



		}// End if(!paused)

		 /*
		 ****************************************
		 Draw the scene
		 ****************************************
		 */

		 // Clear everything from the last frame
		window.clear();

		// Draw our game scene here
		window.draw(spriteBackground);

		// Draw the clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		// Draw the branches
		for (int i = 0; i < NUM_BRANCHES; i++) {
			window.draw(branches[i]);
		}

		// Draw the tree
		window.draw(spriteTree);
		// Draw the player
		window.draw(spritePlayer);

		// Draw the axe
		window.draw(spriteAxe);

		// Draraw the flying log
		window.draw(spriteLog);

		// Draw the gravestone
		window.draw(spriteRIP);


		// Drawraw the bee
		window.draw(spriteBee);

		// Drawraw the 2nd bee
		window.draw(spriteBee2);

		// Drawraw the 3rd bee
		window.draw(spriteBee3);

		// Draw the score
		window.draw(timerText);

		// Draw the log counter
		window.draw(logsText);

		// Draw the Boss Name
		window.draw(bossNameText);

		/* Draw the timebar
		window.draw(timeBar);
		*/
		// Draw the Healthbar
		window.draw(healthBar);

		//While game is paused----------------------------------------------------------------------
		if (paused)
		{
			// Draw our message
			window.draw(messageText);
			backgroundTrack.stop();
			horrorMusicTrack.stop();
			bossMusicTrack.stop();
		}
		//--------------------------------------------------------------------------------------------
		
		// Show everything we just drew
		window.display();


	}

	return 0;
}

// Function definition
void updateBranches(int seed)
{
	// Move all the branches down one place
	for (int j = NUM_BRANCHES - 1; j > 0; j--) {
		branchPositions[j] = branchPositions[j - 1];
	}

	// Spawn a new branch at position 0
	// LEFT, RIGHT or NONE
	srand((int)time(0) + seed);
	int r = (rand() % 5);

	switch (r) {
	case 0:
		branchPositions[0] = side::LEFT;
		break;

	case 1:
		branchPositions[0] = side::RIGHT;
		break;

	default:
		branchPositions[0] = side::NONE;
		break;
	}


}