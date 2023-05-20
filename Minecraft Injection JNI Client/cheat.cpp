#include "cheat.h"
#include "java.h"

#include <thread>
#include <chrono>

#include <Windows.h>

jclass getMinecraftClass()
{
	return ct.env->FindClass("ave");
}

jobject getMinecraft()
{
	jmethodID getMinecraftMehtod = ct.env->GetStaticMethodID(getMinecraftClass(), "A", "()Lave;"); // ave
	return ct.env->CallStaticObjectMethod(getMinecraftClass(), getMinecraftMehtod);
}

jobject getWorld()
{
	jfieldID getWorldField = ct.env->GetFieldID(getMinecraftClass(), "f", "Lbdb;"); // bdb
	return ct.env->GetObjectField(getMinecraft(), getWorldField);
}

jobject getPlayer()
{
	jfieldID getPlayerField = ct.env->GetFieldID(getMinecraftClass(), "h", "Lbew;"); // bew
	return ct.env->GetObjectField(getMinecraft(), getPlayerField);
}

void setPlayerSprint()
{
	if (!GetAsyncKeyState('W') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_LCONTROL)) return;

	jmethodID setSprintingMethod = ct.env->GetMethodID(ct.env->GetObjectClass(getPlayer()), "d", "(Z)V");

	ct.env->CallBooleanMethod(getPlayer(), setSprintingMethod, true);
}

void runModules()
{
	while (true)
	{
		if (!getMinecraft()) continue;
		if (!getWorld()) continue;
		if (!getPlayer()) continue;

		setPlayerSprint();

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}