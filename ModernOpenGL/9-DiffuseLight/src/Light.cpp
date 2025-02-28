#include "Light.h"

Light::Light()
{
	colour = glm::vec3(1.0f, 1.0f, 1.0f); // amount of the color it will be shown in a texture 1 towards showing more, a red brick if we set r = 0 it would be pitch black
	ambientIntensity = 1.0f;

	direction = glm::vec3(0.0f, -1.0f, 0.0f);
	diffuseIntensity = 0.0f;
}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, 
	GLfloat xDir, GLfloat yDir, GLfloat zDir, GLfloat dIntensity)
{
	colour = glm::vec3(red, green, blue);
	ambientIntensity = aIntensity;

	direction = glm::vec3(xDir, yDir, zDir);
	diffuseIntensity = dIntensity;
}

void Light::UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation, 
	GLfloat diffuseIntensityLocation, GLfloat directionLocation)
{
	glUniform3f(ambientColourLocation, colour.r, colour.g, colour.b); // could also use colour.x, colour.y, colour.z
	glUniform1f(ambientIntensityLocation, ambientIntensity);

	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
	glUniform1f(diffuseIntensityLocation, diffuseIntensity);
}

Light::~Light()
{
}
