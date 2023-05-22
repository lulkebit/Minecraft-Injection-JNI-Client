#include "entity.h"
#include "../client/minecraft.h"

jclass playerClass = NULL;

jobject playerObject = NULL;
jfieldID getPlayerField = NULL;

jmethodID setSprintingMethod = NULL;

jclass C_Entity::getClass()
{
	if (playerClass == NULL)
		playerClass = ct.env->FindClass("bew");

	return playerClass;
}

jobject C_Entity::getInstance()
{
	if (getPlayerField == NULL)
		getPlayerField = ct.env->GetFieldID(C_Minecraft::getClass(), "h", "Lbew;");

	if (playerObject == NULL)
		playerObject = ct.env->GetObjectField(C_Minecraft::getInstance(), getPlayerField);

	return playerObject;
}

void C_Entity::setSprinting(bool state)
{
	if (setSprintingMethod == NULL)
		setSprintingMethod = ct.env->GetMethodID(getClass(), "d", "(Z)V");

	ct.env->CallBooleanMethod(getInstance(), setSprintingMethod, state);
}