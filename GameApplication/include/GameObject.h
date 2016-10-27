#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Common.h"
#include "Texture.h"
#include "Shader.h"
#include "Vertex.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void OnUpdate();
	void OnRender(mat4& view, mat4& projection);
	void OnInit();
	void OnDestroy();

	void loadTexture(const string& filename);
	void loadShaders(const string& vsFilename, const string& fsFilename);

	void copyVertexData(Vertex *pVertex, int numberOfVertecies);

private:
	GLuint m_VBO;
	GLuint m_VAO;

	GLuint m_ShaderProgram;

	mat4 m_ModelMatrix;

	GLuint m_Texture;
	GLuint m_ClampSampler;

	vec3 m_Position;
	vec3 m_Rotation;
	vec3 m_Scale;

	mat4 m_TranslationMatrix;
	mat4 m_RotationMatrix;
	mat4 m_ScaleMatrix;

	int m_NumberOfVerts;
protected:
};
#endif