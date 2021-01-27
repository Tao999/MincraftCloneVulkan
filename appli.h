#pragma once

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <chrono>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <array>
#include <optional>
#include <set>


#define mBitsSet(flags,mask)		( flags |= (mask) )		//Forçage à 1 (SET)
#define mBitsClr(flags,mask)		( flags &= ~(mask) )	//Forçage à 0 (CLEAR)
#define mBitsTgl(flags,mask)		( flags ^= (mask) )		//Basculement (TOGGLE)

#define mBitsMsk(flags,mask)		( flags & (mask) )			//Masque (ne modifie pas les flags)

#define mIsBitsSet(flags,mask)		( (flags & (mask)) == (mask) )		//Test si bits à 1 (Is Bits Set ?)
#define mIsBitsClr(flags,mask)		( (~flags & (mask)) == (mask) )		//Test si bits à 0 (Is Bits Clear ?)


constexpr float SELECTED_TEX_X = 0;
constexpr float SELECTED_TEX_Y = 0;

constexpr float SELECTED_TEX_UP_X = 1;
constexpr float SELECTED_TEX_UP_Y = 0;

constexpr float SELECTED_TEX_DOWN_X = 0;
constexpr float SELECTED_TEX_DOWN_Y = 1;