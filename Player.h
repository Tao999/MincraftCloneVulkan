#pragma once
#include "appli.h"

constexpr int PL_FORWARD = 1 << 0;
constexpr int PL_BACKWARD = 1 << 1;
constexpr int PL_LEFT = 1 << 2;
constexpr int PL_RIGHT = 1 << 3;
constexpr int PL_UP = 1 << 4;
constexpr int PL_DOWN = 1 << 5;

constexpr float SPEED = 15;

class Player
{
private:
	glm::vec3 position = { -5, 32, 0.5 };
	glm::vec3 front = { -1, 0, 0 };
	glm::vec3 up = { 0, 1, 0 };
	glm::vec3 right = { 0.5, 0.5, 0.5 };

	float yaw = 0;
	float pitch = 0;

	float mouseSensitivity = 0.1f;

	int kbFlags = 0;

	void updateCameraVector();

public:
	void SetFlag(int f);
	void ClrFlag(int f);

	void process(float d);
	void processMouseMov(float xOffset, float yOffset);

	glm::mat4 GetView();
};

