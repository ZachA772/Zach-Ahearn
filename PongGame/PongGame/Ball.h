#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f m_Position;
	RectangleShape m_Shape;

	float m_Speed = 1500.0f;
	float m_DirectionX = .2f;
	float m_DirectionY = .2f;

public:
	Ball(float startX, float startY, float speed);

	FloatRect getPosition();

	RectangleShape getShape();

	void speedIncrease();

	float getXVelocity();

	void reboundSides();

	void ballResetSpeed();

	void reboundBatOrTop();

	void reboundBottom();

	void update(Time dt);

	void setPosition(float x, float y);

};
