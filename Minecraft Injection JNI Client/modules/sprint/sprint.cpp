#include "sprint.h"
#include <Windows.h>

#include "../../net/minecraft/entity/entity.h"

void Sprint::runModule() 
{
	if (!GetAsyncKeyState('W') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_LCONTROL)) return;

	C_Entity::setSprinting(true);
}