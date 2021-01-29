#include "Player.h"
#include "World.h"
#include "Chunk.h"

void Player::process(float d)
{

	if (mIsBitsSet(kbFlags, PL_FORWARD)) {
		position += SPEED * front * d;
	}
	if (mIsBitsSet(kbFlags, PL_BACKWARD)) {
		position -= SPEED * front * d;
	}
	if (mIsBitsSet(kbFlags, PL_RIGHT)) {
		position += glm::normalize(glm::cross(front, up)) * SPEED * d;
	}
	if (mIsBitsSet(kbFlags, PL_LEFT)) {
		position -= glm::normalize(glm::cross(front, up)) * SPEED * d;
	}
	if (mIsBitsSet(kbFlags, PL_UP)) {
		position += SPEED * up * d;
	}
	if (mIsBitsSet(kbFlags, PL_DOWN)) {
		position -= SPEED * up * d;
	}
}

glm::mat4 Player::GetView()
{
	return glm::lookAt(position, position + front, up);
}

void Player::processMouseMov(float xOffset, float yOffset)
{
	xOffset *= mouseSensitivity;
	yOffset *= mouseSensitivity;

	yaw += xOffset;
	pitch -= yOffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	updateCameraVector();
}

void Player::updateCameraVector()
{
	front = glm::vec3(
		cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
		sin(glm::radians(pitch)),
		sin(glm::radians(yaw)) * cos(glm::radians(pitch))
	);

	front = glm::normalize(front);
	right = glm::normalize(glm::cross(front, glm::vec3(0.0, 1.0, 0.0)));
	up = glm::normalize(glm::cross(right, front));
}

Player::Player()
{
	position.x = float(WORLD_NB_CHUNK * CHUNK_SIZE) / 2.0 + 0.5;
	position.y = float(WORLD_MAX_HEIGHT + WORLD_MIN_HEIGHT + 1);
	position.z = float(WORLD_NB_CHUNK * CHUNK_SIZE) / 2.0 + 0.5;
}

void Player::SetFlag(int f)
{
	int temp = kbFlags;
	mBitsSet(kbFlags, f);
}

void Player::ClrFlag(int f)
{
	mBitsClr(kbFlags, f);
}
