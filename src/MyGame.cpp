#include "MyGame.h"

struct Vertex {
	float x, y, z;
};

const std::string ASSET_PATH = "assets";
const std::string SHADER_PATH = "/shaders";

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

	glGenBuffers(1, &m_VBO);	//Takes an int which specifies the number of buffers you are going to generate. 2nd parameter is a ponter to one or an array of ints.
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);	//all binds the specified buffer(2nd parameter) to the pipeline(this is a state!), the 1st parameter specifies what type of buffer we are binding(Array Buffer) will hold vertices.
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex), verts, GL_STATIC_DRAW);	// copies data to the bound buffer, 1st parameter is what type of buffer we are copying too, 2nd parameter is the size of the data we are copying into the buffer, 3rd parameter is the actual data we are copying, and the last parameter is a hint to OpenGL on what do with the buffer data, in this case the data in the buffer will not be updated during rendering.
	
	glGenVertexArrays(1, &m_VAO);	//call takes in an integer which specifies the number of vertex array object you are going to generate and the 2nd parameter is a pointer to one or an array of integers.
	glBindVertexArray(m_VAO);	//call takes in an integer which specifies the Vertex Array Object which is bound to the pipeline.
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);	//call takes in an integer which specifies the Vertex Array Object which is bound to the pipeline.

	glEnableVertexAttribArray(0);	//call takes in an integer which specifies the Vertex Array Object which is bound to the pipeline.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL); //call takes in (Index of the attrib to be defined, number of components, datatype, should it be normilized, stride, offset into the data)

	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);	
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