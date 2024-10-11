#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ZombieArena.h"
#include "Player.h"
#include "TextureHolder.h"
#include "Bullet.h"
#include "Pickup.h"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{

	// Here is the instabce of TextureHolder
	TextureHolder holder;

	// The game will always be in one of four states
	enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };
	// Start with the GAME_OVER state
	State state = State::GAME_OVER;


	// Get the screen resolution and create an SFML window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y),
		"Zombie Arena", Style::Fullscreen);

	// Create a an SFML View for the main action
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	// Here is our clock for timing everything
	Clock clock;
	// How long has the PLAYING state been active
	Time gameTimeTotal;

	// Where is the mouse in relation to world coordinates
	Vector2f mouseWorldPosition;
	// Where is the mouse in relation to screen coordinates
	Vector2i mouseScreenPosition;

	// Create an instance of the Player class
	Player player;

	// The boundaries of the arena
	IntRect arena;

	// Create the background
	VertexArray background;
	// Load the texture for our background vertex array
	Texture textureBackground = TextureHolder::GetTexture(
		"graphics/background_sheet.png");

	// Prepare for a horde of zombies
	int numZombies;
	int numZombiesAlive;
	Zombie* zombies = NULL;

	// 100 bullets should do
	Bullet bullets[100];
	int currentBullet = 0;
	int bulletsSpare = 24;
	int bulletsInClip = 6;
	int clipSize = 6;
	float fireRate = 1;
	// When was the fire button last pressed?
	Time lastPressed;

	// Hide the mouse pointer and replace it with crosshair
	window.setMouseCursorVisible(false);
	Sprite spriteCrosshair;
	Texture textureCrosshair = TextureHolder::GetTexture("graphics/crosshair.png");
	spriteCrosshair.setTexture(textureCrosshair);
	spriteCrosshair.setOrigin(25, 25);

	// Create a couple of pickups
	Pickup healthPickup(1);
	Pickup ammoPickup(2);

	// About the game
	int score = 0;
	int hiScore = 0;

	// For the home/game over screen
	Sprite spriteGameOver;
	Texture textureGameOver = TextureHolder::GetTexture("graphics/background.png");
	spriteGameOver.setTexture(textureGameOver);
	spriteGameOver.setPosition(0, 0);

	// Create a view for the HUD
	View hudView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	// Create a sprite for the ammo icon
	Sprite spriteAmmoIcon;
	Texture textureAmmoIcon = TextureHolder::GetTexture("graphics/ammo_icon.png");
	spriteAmmoIcon.setTexture(textureAmmoIcon);
	spriteAmmoIcon.setPosition(20, 980);

	// Load the font
	Font font;
	font.loadFromFile("fonts/zombiecontrol.ttf");

	// Paused
	Text pausedText;
	pausedText.setFont(font);
	pausedText.setCharacterSize(155);
	pausedText.setFillColor(Color::White);
	pausedText.setPosition(400, 400);
	pausedText.setString("Press Enter \nto continue");

	// Game Over
	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(125);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(250, 850);
	gameOverText.setString("Press Enter to play");

	// Levelling up
	Text levelUpText;
	levelUpText.setFont(font);
	levelUpText.setCharacterSize(80);
	levelUpText.setFillColor(Color::White);
	levelUpText.setPosition(150, 540);
	

	// Ammo
	Text ammoText;
	ammoText.setFont(font);
	ammoText.setCharacterSize(55);
	ammoText.setFillColor(Color::White);
	ammoText.setPosition(200, 980);

	// Score
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(55);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(20, 0);

	// Load the high score from a text file/
	std::ifstream inputFile("gamedata/scores.txt");
	if (inputFile.is_open())
	{
		inputFile >> hiScore;
		inputFile.close();
	}

	// Hi Score
	Text hiScoreText;
	hiScoreText.setFont(font);
	hiScoreText.setCharacterSize(55);
	hiScoreText.setFillColor(Color::White);
	hiScoreText.setPosition(1400, 0);
	std::stringstream s;
	s << "Hi Score:" << hiScore;
	hiScoreText.setString(s.str());

	// Zombies remaining
	Text zombiesRemainingText;
	zombiesRemainingText.setFont(font);
	zombiesRemainingText.setCharacterSize(55);
	zombiesRemainingText.setFillColor(Color::White);
	zombiesRemainingText.setPosition(1500, 980);
	zombiesRemainingText.setString("Zombies: 100");

	// Wave number
	int wave = 0;
	Text waveNumberText;
	waveNumberText.setFont(font);
	waveNumberText.setCharacterSize(55);
	waveNumberText.setFillColor(Color::White);
	waveNumberText.setPosition(1250, 980);
	waveNumberText.setString("Wave: 0");

	// Health bar
	RectangleShape healthBar;
	healthBar.setFillColor(Color::Red);
	healthBar.setPosition(450, 980);

	// When did we last update the HUD?
	int framesSinceLastHUDUpdate = 0;
	// What time was the last update
	Time timeSinceLastUpdate;
	// How often (in frames) should we update the HUD
	int fpsMeasurementFrameInterval = 100;

	// Prepare the hit sound
	SoundBuffer hitBuffer;
	hitBuffer.loadFromFile("sound/hit.wav");
	Sound hit;
	hit.setBuffer(hitBuffer);

	// Prepare the splat sound
	SoundBuffer splatBuffer;
	splatBuffer.loadFromFile("sound/splat.wav");
	sf::Sound splat;
	splat.setBuffer(splatBuffer);

	// Prepare the shoot sound
	SoundBuffer shootBuffer;
	shootBuffer.loadFromFile("sound/shoot.wav");
	Sound shoot;
	shoot.setBuffer(shootBuffer);

	// Prepare the reload sound
	SoundBuffer reloadBuffer;
	reloadBuffer.loadFromFile("sound/reload.wav");
	Sound reload;
	reload.setBuffer(reloadBuffer);

	// Prepare the failed sound
	SoundBuffer reloadFailedBuffer;
	reloadFailedBuffer.loadFromFile("sound/reload_failed.wav");
	Sound reloadFailed;
	reloadFailed.setBuffer(reloadFailedBuffer);

	// Prepare the powerup sound
	SoundBuffer powerupBuffer;
	powerupBuffer.loadFromFile("sound/powerup.wav");
	Sound powerup;
	powerup.setBuffer(powerupBuffer);

	// Prepare the pickup sound
	SoundBuffer pickupBuffer;
	pickupBuffer.loadFromFile("sound/pickup.wav");
	Sound pickup;
	pickup.setBuffer(pickupBuffer);


	//NEWLY ADDED VARIABLES===============
	bool objective1 = false;

	//------
	bool objective2 = false;
	bool objective2A = false;
	bool objective2B = false;
	bool objective2C = false;
	bool objective2D = false;


	Sprite spriteObj2One;
	Sprite spriteObj2Two;
	Sprite spriteObj2Three;
	Sprite spriteObj2Four;

	Texture textureObj2Off = TextureHolder::GetTexture("graphics/obj2Off.png");
	Texture textureObj2On = TextureHolder::GetTexture("graphics/obj2On.png");

	spriteObj2One.setTexture(textureObj2Off);
	spriteObj2Two.setTexture(textureObj2Off);
	spriteObj2Three.setTexture(textureObj2Off);
	spriteObj2Four.setTexture(textureObj2Off);

	spriteObj2One.setPosition(70, 500);
	spriteObj2Two.setPosition(500, 70);
	spriteObj2Three.setPosition(870, 500);
	spriteObj2Four.setPosition(500, 870);

	spriteObj2One.setScale(2, 2);
	spriteObj2Two.setScale(2, 2);
	spriteObj2Three.setScale(2, 2);
	spriteObj2Four.setScale(2, 2);
	//----
	Sprite spriteObj3;

	Texture textureObj3 = TextureHolder::GetTexture("graphics/blueFlame.png");

	spriteObj3.setTexture(textureObj3);

	int obj3X = 100;
	int obj3Y = 800;

	spriteObj3.setScale(2, 2);

	bool objective3 = false;
	int obj3Counter = 0;

	//
	Sprite spriteObj4;

	Texture textureObj4 = TextureHolder::GetTexture("graphics/portal.png");

	spriteObj4.setTexture(textureObj4);

	spriteObj4.setScale(.5, .5);

	spriteObj4.setPosition(800, 900);

	RectangleShape timeBar;
	float timeBarStartWidth = 0;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Green);
	timeBar.setPosition(spriteObj4.getPosition().x, spriteObj4.getPosition().y - 200);

	float timeRemaining = 0.0f;

	timeRemaining = 0;

	bool shouldDecreaseHealthBar = false;
	//----
	// 
	Sprite spriteBoss;

	Texture textureBoss1 = TextureHolder::GetTexture("graphics/boss1hand.png");
	Texture textureBoss2 = TextureHolder::GetTexture("graphics/boss2hand.png");

	spriteBoss.setTexture(textureBoss1);

	float bossAnimation = 0.0f;

	bossAnimation = 0;

	int animationCounter = 1;
	//=============================


	srand((int)time(0));



	//====================================

	// The main game loop
	while (window.isOpen())
	{
		/*
		************
		Handle input
		************
		*/

		// Handle events
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				// Pause a game while playing
				if (event.key.code == Keyboard::Return &&
					state == State::PLAYING)
				{
					state = State::PAUSED;
				}

				// Restart while paused
				else if (event.key.code == Keyboard::Return &&
					state == State::PAUSED)
				{
					state = State::PLAYING;
					// Reset the clock so there isn't a frame jump
					clock.restart();
				}

				// Start a new game while in GAME_OVER state
				else if (event.key.code == Keyboard::Return &&
					state == State::GAME_OVER)
				{
					state = State::LEVELING_UP;
					wave = 6;
					score = 0;


					// Prepare the gun and ammo for next game

					//#####Dev Guns######
					currentBullet = 0;
					bulletsSpare = 10000;
					bulletsInClip = 1000;
					clipSize = 1000;
					fireRate = 10;
					
					/*
					currentBullet = 0;
					bulletsSpare = 24;
					bulletsInClip = 6;
					clipSize = 6;
					fireRate = 1;
					*/
					// Reset the player's stats
					player.resetPlayerStats();
				}

				if (state == State::PLAYING)
				{
					// Reloading
					if (event.key.code == Keyboard::R)
					{
						if (bulletsSpare >= clipSize)
						{
							// Plenty of bullets. Reload.
							bulletsInClip = clipSize;
							bulletsSpare -= clipSize;
							reload.play();
						}
						else if (bulletsSpare > 0)
						{
							// Only few bullets left
							bulletsInClip = bulletsSpare;
							bulletsSpare = 0;
							reload.play();
						}
						else
						{
							// More here soon?!
							reloadFailed.play();
						}
					}
				}

			}
		}// End event polling


		 // Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle controls while playing
		if (state == State::PLAYING)
		{
			// Handle the pressing and releasing of the WASD keys
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.moveUp();
			}
			else
			{
				player.stopUp();
			}

			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.moveDown();
			}
			else
			{
				player.stopDown();
			}

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.moveLeft();
			}
			else
			{
				player.stopLeft();
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.moveRight();
			}
			else
			{
				player.stopRight();
			}

			// Fire a bullet
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (gameTimeTotal.asMilliseconds()
					- lastPressed.asMilliseconds()
					> 1000 / fireRate && bulletsInClip > 0)
				{

					// Pass the centre of the player and the centre of the crosshair
					// to the shoot function
					bullets[currentBullet].shoot(
						player.getCenter().x, player.getCenter().y,
						mouseWorldPosition.x, mouseWorldPosition.y);

					currentBullet++;
					if (currentBullet > 99)
					{
						currentBullet = 0;
					}
					lastPressed = gameTimeTotal;
					shoot.play();
					bulletsInClip--;
				}

			}// End fire a bullet

		}// End WASD while playing

		// Handle the levelling up state

		//As the player progresses through waves, they will be automatically upgraded after each wave
		if (state == State::LEVELING_UP)
		{
			if (wave == 0)
			{
				if (event.key.code == Keyboard::Return)
				{
					state = State::PLAYING;
				}
			}
			
			//Increased Pickup Power And Spawn Rate 
			if (wave == 1)
			{

				levelUpText.setString("Power Vacuum! \n(Increased Pickup Power And Spawn Rate \nPress 'Enter' To Continue)");
				if(event.key.code == Keyboard::Return)
				{
					healthPickup.upgrade();
					ammoPickup.upgrade();
					state = State::PLAYING;
				}
			}
			
			//Increased Clip Size
			if (wave == 2)
			{
				levelUpText.setString("Bandolier Bandit! \n(Increased Clip Size \nPress 'Enter' To Continue)");
				if (event.key.code == Keyboard::Return)
				{
					clipSize += clipSize;
					state = State::PLAYING;
				}
			}

			//Increased Health 
			if (wave == 3)
			{
				levelUpText.setString("Juggernog! \n(Increased Health \nPress 'Enter' To Continue)");
				
				if (event.key.code == Keyboard::Return)
				{
					player.upgradeHealth();
					state = State::PLAYING;
				}
			}

			//Increased Fire Rate 
			if (wave == 4)
			{
				levelUpText.setString("Double Tap Root Beer! \n(Increased Fire Rate \nPress 'Enter' To Continue)");
				
				if (event.key.code == Keyboard::Return)
				{
					fireRate += fireRate;
					state = State::PLAYING;
				}
			}

			//Increased Movement Speed 
			if (wave == 5)
			{
				levelUpText.setString("Stamina-Up! \n(Increased Movement Speed \nPress 'Enter' To Continue)");
				if (event.key.code == Keyboard::Return)
				{
					player.upgradeSpeed();
					state = State::PLAYING;
				}
			}

			//Machine Gun for Boss Fight
			if (wave == 6)
			{
				levelUpText.setString("You Been Granted A Machine Gun! \n Now Blow That Thing To Bits! \nPress 'Enter' To Continue");
				if (event.key.code == Keyboard::Return)
				{
					bulletsSpare = 10000;
					bulletsInClip = 100;
					clipSize = 100;
					fireRate = 10;
					state = State::PLAYING;
				}
			}
			
			//============================================


			if (state == State::PLAYING)
			{
				// Increase the wave number
				wave++;

				// Prepare thelevel
				// We will modify the next two lines later
				arena.width = 500 * wave;
				arena.height = 500 * wave;
				arena.left = 0;
				arena.top = 0;

				// Pass the vertex array by reference 
				// to the createBackground function
				int tileSize = createBackground(background, arena);

				// Spawn the player in the middle of the arena
				player.spawn(arena, resolution, tileSize);

				// Configure the pick-ups
				healthPickup.setArena(arena);
				ammoPickup.setArena(arena);

				// Create a horde of zombies
				//Allows for only 1 zombie to spawn on the boss round, which will be the boss zombie
				if (wave == 7)
				{
					numZombies = 1;
				}
				else
				{				
					numZombies = 5 * wave;
				}
				// Delete the previously allocated memory (if it exists)
				delete[] zombies;
				zombies = createHorde(numZombies, arena, wave);
				numZombiesAlive = numZombies;

				// Play the powerup sound
				powerup.play();

				// Reset the clock so there isn't a frame jump
				clock.restart();
			}
		}// End levelling up

		 /*
		 ****************
		 UPDATE THE FRAME
		 ****************
		 */
		if (state == State::PLAYING)
		{
			// Update the delta time
			Time dt = clock.restart();
			// Update the total game time
			gameTimeTotal += dt;
			// Make a decimal fraction of 1 from the delta time
			float dtAsSeconds = dt.asSeconds();

			// Where is the mouse pointer
			mouseScreenPosition = Mouse::getPosition();

			// Convert mouse position to world coordinates of mainView
			mouseWorldPosition = window.mapPixelToCoords(
				Mouse::getPosition(), mainView);

			// Set the crosshair to the mouse world location
			spriteCrosshair.setPosition(mouseWorldPosition);

			// Update the player
			player.update(dtAsSeconds, Mouse::getPosition());

			// Make a note of the players new position
			Vector2f playerPosition(player.getCenter());

			// Make the view centre around the player				
			mainView.setCenter(player.getCenter());

			// Loop through each Zombie and update them
			for (int i = 0; i < numZombies; i++)
			{
				if (zombies[i].isAlive())
				{
					zombies[i].update(dt.asSeconds(), playerPosition);
				}
			}

			// Update any bullets that are in-flight
			for (int i = 0; i < 100; i++)
			{
				if (bullets[i].isInFlight())
				{
					bullets[i].update(dtAsSeconds);
				}
			}

			// Update the pickups
			healthPickup.update(dtAsSeconds);
			ammoPickup.update(dtAsSeconds);





			// Collision detection
			// Have any zombies been shot?
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j <= numZombies; j++)
				{
					if (bullets[i].isInFlight() &&
						zombies[j].isAlive())
					{
						if (bullets[i].getPosition().intersects
						(zombies[j].getPosition()))
						{
							// Stop the bullet
							bullets[i].stop();

							// Register the hit and see if it was a kill
							if (zombies[j].hit())
							{
								// Not just a hit but a kill too
								score += 10;
								if (score >= hiScore)
								{
									hiScore = score;
								}

								numZombiesAlive--;
							}
							// When all the zombies are dead (again)
							//LEVEL 1
							if (numZombiesAlive == 0 && wave == 1 && !objective1)
							{
								state = State::LEVELING_UP;
								objective1 = true;
							}



							// Make a splat sound
							splat.play();

						}
					}

				}
			}// End zombie being shot

			// Have any zombies touched the player			
			for (int i = 0; i < numZombies; i++)
			{
				if (player.getPosition().intersects
				(zombies[i].getPosition()) && zombies[i].isAlive())
				{

					if (player.hit(gameTimeTotal))
					{
						// More here later
						hit.play();
					}

					if (player.getHealth() <= 0)
					{
						state = State::GAME_OVER;

						std::ofstream outputFile("gamedata/scores.txt");
						outputFile << hiScore;
						outputFile.close();

					}
				}
			}// End player touched

			// Has the player touched health pickup
			if (player.getPosition().intersects
			(healthPickup.getPosition()) && healthPickup.isSpawned())
			{
				player.increaseHealthLevel(healthPickup.gotIt());
				// Play a sound
				pickup.play();

			}

			// Has the player touched ammo pickup
			if (player.getPosition().intersects
			(ammoPickup.getPosition()) && ammoPickup.isSpawned())
			{
				bulletsSpare += ammoPickup.gotIt();
				// Play a sound
				reload.play();

			}

			// size up the health bar
			healthBar.setSize(Vector2f(player.getHealth() * 3, 70));

			// Increment the amount of time since the last HUD update
			timeSinceLastUpdate += dt;
			// Increment the number of frames since the last HUD calculation
			framesSinceLastHUDUpdate++;
			// Calculate FPS every fpsMeasurementFrameInterval frames
			if (framesSinceLastHUDUpdate > fpsMeasurementFrameInterval)
			{

				// Update game HUD text
				std::stringstream ssAmmo;
				std::stringstream ssScore;
				std::stringstream ssHiScore;
				std::stringstream ssWave;
				std::stringstream ssZombiesAlive;

				// Update the ammo text
				ssAmmo << bulletsInClip << "/" << bulletsSpare;
				ammoText.setString(ssAmmo.str());

				// Update the score text
				ssScore << "Score:" << score;
				scoreText.setString(ssScore.str());

				// Update the high score text
				ssHiScore << "Hi Score:" << hiScore;
				hiScoreText.setString(ssHiScore.str());

				// Update the wave
				ssWave << "Wave:" << wave;
				waveNumberText.setString(ssWave.str());

				// Update the high score text
				ssZombiesAlive << "Zombies:" << numZombiesAlive;
				zombiesRemainingText.setString(ssZombiesAlive.str());

				framesSinceLastHUDUpdate = 0;
				timeSinceLastUpdate = Time::Zero;
			}// End HUD update


			//LEVEL 2=============================================================================
			//Checking if player overlaps objectives
			if (!objective2A && player.getPosition().intersects(spriteObj2One.getGlobalBounds()))
			{
				objective2A = true;
				spriteObj2One.setTexture(textureObj2On);
			}

			if (!objective2B && player.getPosition().intersects(spriteObj2Two.getGlobalBounds()))
			{
				objective2B = true;
				spriteObj2Two.setTexture(textureObj2On);
			}

			if (!objective2C && player.getPosition().intersects(spriteObj2Three.getGlobalBounds()))
			{
				objective2C = true;
				spriteObj2Three.setTexture(textureObj2On);
			}

			if (!objective2D && player.getPosition().intersects(spriteObj2Four.getGlobalBounds()))
			{
				objective2D = true;
				spriteObj2Four.setTexture(textureObj2On);
			}
			//Checking if all 4 objectives are complete
			if (objective2A && objective2B && objective2C && objective2D)
			{
				objective2 = true;
			}
			//Checking if appropriate to end wave
			if (numZombiesAlive <= 0 && wave == 2 && objective2)
			{
				state = State::LEVELING_UP;
			}

			//LEVEL 3=============================================================================
			
			//Giving a random position to the objective so it teleports around the map when the player overlaps it
			if (player.getPosition().intersects(spriteObj3.getGlobalBounds()))
			{
				
				obj3X = (rand() % arena.width - 10);
				obj3Y = (rand() % arena.height);

				cout << "X: " << obj3X << ", Y: " << obj3Y << endl;
				
				obj3Counter++;
			}
			spriteObj3.setPosition(obj3X, obj3Y);
			if (numZombiesAlive == 0 && wave == 3 && obj3Counter >= 5)
			{
				state = State::LEVELING_UP;
			}

			//LEVEL 4=============================================================================
			//A time bar that takes 20 seconds to completr and will only progress while the player stands on it
			if (player.getPosition().intersects(spriteObj4.getGlobalBounds()))
			{
				if (timeRemaining < 21)
				{
					// Subtract from the amount of time remaining
					timeRemaining += dt.asSeconds();
					// size up the time bar
					timeBar.setSize(Vector2f(timeRemaining * 18, timeBarHeight));
				}
			}
			
			if (numZombiesAlive == 0 && wave == 4 && timeRemaining > 20)
			{
				state = State::LEVELING_UP;
			}

			//LEVEL 5=============================================================================
			//Making the zombies small on wave 5 using the setScale function
			if (wave == 5)
			{
				for (int i = 0; i < numZombies; ++i)
				{
					zombies[i].setScale(0.5f, 0.5f); // Example scale values
				}
			}
			//Resetting the scale afterwards
			if (numZombiesAlive == 0 && wave == 5)
			{
				for (int i = 0; i < numZombies; ++i)
				{
					zombies[i].setScale(1.0f, 1.0f); // Example scale values
				}
				state = State::LEVELING_UP;
			}


			//LEVEL 6=============================================================================
			//Making zombies faster on wave 6
			if (wave == 6)
			{
				for (int i = 0; i < numZombies; ++i)
				{
					zombies[i].setSpeed(100); // Example scale values
				}
			}
			//Resetting afterwards
			if (numZombiesAlive == 0 && wave == 6)
			{
				for (int i = 0; i < numZombies; ++i)
				{
					zombies[i].setSpeed(50); // Example scale values
				}
				state = State::LEVELING_UP;
			}

			//LEVEl 7 BOSS FIGHT=================================================================
			//Spawns the boss zombie
			if (wave == 7)
			{
				bossAnimation += dt.asSeconds();
				//Boss' animation changes every .25 seconds
				if (bossAnimation >= .25)
				{
					bossAnimation = 0;
					animationCounter++;
				}

				if (animationCounter % 2 == 0) // Check if animationCounter is even
				{
					spriteBoss.setTexture(textureBoss2);
				}
				else
				{
					spriteBoss.setTexture(textureBoss1);
				}

				// Get the position of the player
				Vector2f playerPosition = player.getCenter();

				// Get the position of the boss
				//Since there is only 1 zombie (the boss), the zombie[0] refers to the 1 zombie existing in the array
				//This is used to give a seperate texture to the boss. The boss is technically just a rectangle with a sprite over it to handle its hitboxe
				Vector2f bossPosition = zombies[0].getPositionVector();

				// Calculate the angle between the player and the boss
				float angle = atan2(playerPosition.y - bossPosition.y, playerPosition.x - bossPosition.x);
				angle = angle * 180 / 3.14159265; // Convert radians to degrees

				// Set the rotation of the boss sprite
				spriteBoss.setRotation(angle);

				// Set the position of the boss sprite
				spriteBoss.setPosition(bossPosition);

				//End game once the boss is killed
				if (numZombiesAlive == 0 && wave == 7)
				{
					state = State::GAME_OVER;
				}
			}



			

		}// End updating the scene

		 /*
		 **************
		 Draw the scene
		 **************
		 */

		if (state == State::PLAYING)
		{
			window.clear();

			// set the mainView to be displayed in the window
			// And draw everything related to it
			window.setView(mainView);

			// Draw the background
			window.draw(background, &textureBackground);

			

			//Draw Objectives only when they're needed========================
			if (wave == 2)
			{
				window.draw(spriteObj2One);
				window.draw(spriteObj2Two);
				window.draw(spriteObj2Three);
				window.draw(spriteObj2Four);
			}
			else if (wave == 3)
			{
				window.draw(spriteObj3);
			}
			else if (wave == 4)
			{
				window.draw(spriteObj4);
				if (player.getPosition().intersects(spriteObj4.getGlobalBounds()))
				{
					window.draw(timeBar);
				}

			}
			else if (wave == 7)
			{
				window.draw(spriteBoss);
			}

			//With the objectives drawn first, all other sprites will be drawn on top of them to ensure zombies, player, bullets are always visible

			// Draw the zombies
			for (int i = 0; i < numZombies; i++)
			{
				window.draw(zombies[i].getSprite());
			}

			for (int i = 0; i < 100; i++)
			{
				if (bullets[i].isInFlight())
				{
					window.draw(bullets[i].getShape());
				}
			}

			// Draw the player
			window.draw(player.getSprite());

			// Draw the pickups is currently spawned
			if (ammoPickup.isSpawned())
			{
				window.draw(ammoPickup.getSprite());
			}
			if (healthPickup.isSpawned())
			{
				window.draw(healthPickup.getSprite());
			}

			//Draw the crosshair
			window.draw(spriteCrosshair);



			// Switch to the HUD view
			window.setView(hudView);

			// Draw all the HUD elements
			window.draw(spriteAmmoIcon);
			window.draw(ammoText);
			window.draw(scoreText);
			window.draw(hiScoreText);
			window.draw(healthBar);
			window.draw(waveNumberText);
			window.draw(zombiesRemainingText);
		}

		if (state == State::LEVELING_UP)
		{
			window.draw(spriteGameOver);
			window.draw(levelUpText);
		}

		if (state == State::PAUSED)
		{
			window.draw(pausedText);
		}

		if (state == State::GAME_OVER)
		{
			window.draw(spriteGameOver);
			window.draw(gameOverText);
			window.draw(scoreText);
			window.draw(hiScoreText);
		}



		window.display();

	}// End game loop


	return 0;
}
