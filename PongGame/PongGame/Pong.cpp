// Pong.cpp : Defines the entry point for the console application.
//

#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;


int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game

	RenderWindow window(vm, "Pong", Style::Fullscreen);

	//SETTING UP TEXTURES======================================================================================
	
	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.png");
	
	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);
	
	//Crowd
	Texture textureCrowd;

	// Load a graphic into the texture
	textureCrowd.loadFromFile("graphics/crowd.png");

	// Create a sprite
	Sprite spriteCrowd;


	// Attach the texture to the sprite
	spriteCrowd.setTexture(textureCrowd);

	// Set crowd position
	spriteCrowd.setPosition(0, 1000);

	//Setting up monster 
	Texture textureMonster;

	// Load a graphic into the texture
	textureMonster.loadFromFile("graphics/monster.png");

	// Create a sprite
	Sprite spriteMonster;

	// Attach the texture to the sprite
	spriteMonster.setTexture(textureMonster);

	// Set monster position
	spriteMonster.setPosition(0, 0);

	//Setting up WIZARD 
	Texture textureWizard1;
	Texture textureWizard2;
	Texture textureWizard3;

	// Load a graphic into the texture
	textureWizard1.loadFromFile("graphics/wizard1.png");
	textureWizard2.loadFromFile("graphics/wizard2.png");
	textureWizard3.loadFromFile("graphics/wizard3.png");

	// Create a sprite
	Sprite spriteWizard;


	// Attach the texture to the sprite
	spriteWizard.setTexture(textureWizard1);

	// Set wizard position
	spriteWizard.setPosition(30, 795);


	//Setting up Light around the bat
	Texture textureBatLight;

	textureBatLight.loadFromFile("graphics/batLight.png");

	Sprite spriteBatLight;


	spriteBatLight.setTexture(textureBatLight);

	//Setting up light around fireball 
	Texture textureFireLight;

	textureFireLight.loadFromFile("graphics/fireLight.png");

	Sprite spriteFireLight;

	spriteFireLight.setTexture(textureFireLight);




	

	// Control the player input
	bool acceptInput = false;
	//------------------------


	// Player Health bar===============================================================================
	RectangleShape healthBar;
	float healthBarStartWidth = 1890;
	float healthBarHeight = 10;
	healthBar.setSize(Vector2f(healthBarStartWidth, healthBarHeight));
	healthBar.setFillColor(Color::Red);
	healthBar.setPosition(20, 990);

	// Boss Health bar===============================================================================
	RectangleShape bossHealthBar;
	float bossHealthBarStartWidth = 1890;
	float bossHealthBarHeight = 10;
	bossHealthBar.setSize(Vector2f(bossHealthBarStartWidth, bossHealthBarHeight));
	bossHealthBar.setFillColor(Color::Green);
	bossHealthBar.setPosition(20, 90);
	//=========================================================================================================

	// Track whether the game is running
	bool paused = true;
	//----------------





	// Create a bat
	Bat bat(1920 / 2, 1080 - 100);

	// We will add a ball in the next chapter
	Ball ball(1920 / 2, 30, 2000.0f);

	//Setting up Fireball
	Texture textureFireball;

	textureFireball.loadFromFile("graphics/fireball.png");

	Sprite spriteFireball;

	spriteFireball.setTexture(textureFireball);

	spriteFireball.setScale(2, 2);

	

	// Create a Text object called HUD
	Text hud;

	// A cool retro-style font
	Font font;
	font.loadFromFile("fonts/Happy-Dance.ttf");

	// Set the font to our retro-style
	hud.setFont(font);

	// Make it nice and big
	hud.setCharacterSize(200);

	// Choose a color
	hud.setFillColor(Color::White);

	hud.setPosition(-100, -100);

	// Here is our clock for timing everything
	Clock clock;

	//SETTING UP COUNTER FOR WIZARD ANIMATION
	int animationCounter = 1;

	//SETTING UP SOUNDS
	SoundBuffer playerDamageBuffer;
	playerDamageBuffer.loadFromFile("sound/playerDamage.wav");
	Sound playerDamage;
	playerDamage.setBuffer(playerDamageBuffer);

	SoundBuffer bossDamageBuffer;
	bossDamageBuffer.loadFromFile("sound/bossDamage.wav");
	Sound bossDamage;
	bossDamage.setBuffer(bossDamageBuffer);

	SoundBuffer bossMusicBuffer;
	bossMusicBuffer.loadFromFile("sound/bossMusic.wav");
	Sound bossMusicTrack;
	bossMusicTrack.setBuffer(bossMusicBuffer);
	bossMusicTrack.setVolume(30.f);

	SoundBuffer shieldBuffer;
	shieldBuffer.loadFromFile("sound/shield.wav");
	Sound shield;
	shield.setBuffer(shieldBuffer);

	//Setting up boundary bools for the bat
	bool batLeft = true;
	bool batRight = true;


	while (window.isOpen())
	{
		/*
		Handle the player input
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyReleased && !paused)
			{
				// Listen for key presses again
				acceptInput = true;

			}
		}

		

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;

			bossMusicTrack.play();
			//Reset Game---------------------------------------------------------------------
			
			
			ball.setPosition(1920 / 2, 30);
			ball.ballResetSpeed();

			healthBarStartWidth = 1890;
			healthBar.setSize(Vector2f(healthBarStartWidth, healthBarHeight));

			bossHealthBarStartWidth = 1890;
			bossHealthBar.setSize(Vector2f(bossHealthBarStartWidth, bossHealthBarHeight));


			hud.setPosition(-200, -200);


			
			acceptInput = true;
		}


		//============================================================================================
		 
		// Wrap the player controls to
		// Make sure we are accepting input
		
		if (acceptInput)
		{
			// Handle the pressing and releasing of the arrow keys
			if (Keyboard::isKeyPressed(Keyboard::Left) && batLeft)
			{
				bat.moveLeft();
			}
			else
			{
				bat.stopLeft();
			}

			if (bat.getPosition().left < 0)
			{
				batLeft = false;
			}
			else 
			{
				batLeft = true;
			}

			if (Keyboard::isKeyPressed(Keyboard::Right) && batRight)
			{
				bat.moveRight();
			}
			else
			{
				bat.stopRight();
			}
			if (bat.getPosition().left > 1785)
			{
				batRight = false;
			}
			else
			{
				batRight = true;
			}
		}

		/*
		Update the bat and the ball
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/

		if (!paused)
		{
			

			// Update the delta time
			Time dt = clock.restart();
			bat.update(dt);
			ball.update(dt);
			


			
			// Handle ball hitting the bottom
			if (ball.getPosition().top > window.getSize().y)
			{
				// reverse the ball direction
				ball.reboundBottom();

				healthBarStartWidth -= 200;
				healthBar.setSize(Vector2f(healthBarStartWidth, healthBarHeight));

				playerDamage.play();
			}

			// Handle ball hitting top
			if (ball.getPosition().top < 0)
			{
				ball.reboundBatOrTop();

				// Take from boss health bar
				bossHealthBarStartWidth -= 95;
				bossHealthBar.setSize(Vector2f(bossHealthBarStartWidth, bossHealthBarHeight));
				ball.speedIncrease();

				bossDamage.play();

			}

			// Handle ball hitting sides
			if (ball.getPosition().left < 0 ||
				ball.getPosition().left + 10 > window.getSize().x)
			{
				ball.reboundSides();
			}

			// Has the ball hit the bat?
			if (ball.getPosition().intersects(bat.getPosition()))
			{
				// Hit detected so reverse the ball and add to wizard animatiom counter
				ball.reboundBatOrTop();
				animationCounter++;
				shield.play();
			}

			//HANDLING WIZARD ANIMATION
			if (animationCounter == 1)
			{
				spriteWizard.setTexture(textureWizard1);
			}
			else if (animationCounter == 2)
			{
				spriteWizard.setTexture(textureWizard2);
			}
			else if (animationCounter == 3)
			{
				spriteWizard.setTexture(textureWizard3);
			}
			else if (animationCounter == 4)
			{
				animationCounter = 1;
			}

			//Setting up sprites that update there position after the ball or bats position is also updated
			int ball_x = ball.getPosition().left - 55;
			int ball_y = ball.getPosition().top - 20;
			spriteFireball.setPosition(ball_x, ball_y);

			int bat_x = bat.getPosition().left - 120;
			int bat_y = bat.getPosition().top - 180;

			spriteBatLight.setPosition(bat_x, bat_y);
			spriteBatLight.setScale(4, 4);

			spriteFireLight.setPosition(ball_x - 120, ball_y - 180);
			spriteFireLight.setScale(4, 4);





			/*
			cout << "DEBUG: " << ball_x << endl;
			cout << "DEBUG: " << ball_y << endl;
			*/
		}
		


		if (healthBarStartWidth <= 0)
		{
			bossMusicTrack.stop();

			// Pause the game
			paused = true;

			// Change the message shown to the player
			
			hud.setString("YOU LOSE!!");

			
			hud.setPosition(450, 400);

		}

		if (bossHealthBarStartWidth <= 0)
		{
			bossMusicTrack.stop();
			// Pause the game
			paused = true;

			// Change the message shown to the player

			hud.setString("YOU WIN!!");


			hud.setPosition(450, 400);





		}

		/*
		Draw everything
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
		window.clear();

		window.draw(spriteBackground);
		window.draw(spriteCrowd);

		window.draw(spriteMonster);
		window.draw(spriteWizard);

		window.draw(healthBar);
		window.draw(bossHealthBar);

		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(spriteBatLight);
		
		window.draw(ball.getShape());
		window.draw(spriteFireball);
		window.draw(spriteFireLight);
		window.display();
	}

	return 0;
}

