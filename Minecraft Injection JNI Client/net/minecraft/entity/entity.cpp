#include "entity.h"
#include "../client/minecraft.h"

jclass playerClass = NULL;

jobject playerObject = NULL;
jfieldID getPlayerField = NULL;

jmethodID setSprintingMethod = NULL;

jfieldID motionX = NULL;
jfieldID motionY = NULL;
jfieldID motionZ = NULL;

jfieldID hurttime = NULL;

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

jdouble C_Entity::getMotionX()
{
	if (motionX == NULL)
		motionX = ct.env->GetFieldID(getClass(), "v", "D");

	return ct.env->GetDoubleField(getInstance(), motionX);
}

jdouble C_Entity::getMotionY()
{
	if (motionY == NULL)
		motionY = ct.env->GetFieldID(getClass(), "w", "D");

	return ct.env->GetDoubleField(getInstance(), motionY);
}

jdouble C_Entity::getMotionZ()
{
	if (motionZ == NULL)
		motionZ = ct.env->GetFieldID(getClass(), "x", "D");

	return ct.env->GetDoubleField(getInstance(), motionZ);
}

void C_Entity::setMotionX(jdouble value)
{
	ct.env->SetDoubleField(getInstance(), motionX, value);
}

void C_Entity::setMotionY(jdouble value)
{
	ct.env->SetDoubleField(getInstance(), motionY, value);
}

void C_Entity::setMotionZ(jdouble value)
{
	ct.env->SetDoubleField(getInstance(), motionZ, value);
}

int C_Entity::getHurttime()
{
	if (hurttime == NULL)
		hurttime = ct.env->GetFieldID(getClass(), "Z", "I");

	return ct.env->GetIntField(getInstance(), hurttime);
}