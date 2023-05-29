#include "cheat.h"
#include "java.h"

#include <thread>
#include <chrono>
#include <Windows.h>

#include "net/minecraft/client/minecraft.h"
#include "net/minecraft/entity/entity.h"
#include "net/minecraft/world/world.h"

void runModules()
{
	while (true)
	{
		if (!C_Minecraft::getInstance()) continue;
		if (!C_World::getInstance()) continue;
		if (!C_Entity::getInstance()) continue;

		Sprint::runModule();
		Velocity::runModule();

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}