#include "MyGame.h"

struct Vertex {
	float x, y, z;
};

MyGame::MyGame()
{
	m_VAO = 0;
	m_VBO = 0;
}

MyGame::~MyGame()
{
	
}

void MyGame::initScene()
{
	GameApplication::initScene();
	Vertex verts[] = {
		{-0.5f,-0.5f,0.0f},
		{0.5f,-0.5f,0.0f},
		{0.0f, 0.5f, 0.0f}
	};
	//Ended at 4.3
}

void MyGame::destroyScene()
{
	GameApplication::destroyScene();
}

void MyGame::render()
{
	GameApplication::render();
}

void MyGame::update()
{
	GameApplication::update();
}