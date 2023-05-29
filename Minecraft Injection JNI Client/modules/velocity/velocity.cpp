#include "velocity.h"

#include "../../net/minecraft/entity/entity.h"

void Velocity::runModule()
{
	if (C_Entity::getHurttime() > 0)
	{
		jdouble motionX = C_Entity::getMotionX();
		jdouble motionY = C_Entity::getMotionY();
		jdouble motionZ = C_Entity::getMotionZ();

		motionX *= 0.5;
		motionY *= 0.5;
		motionZ *= 0.5;

		C_Entity::setMotionX(motionX);
		C_Entity::setMotionY(motionY);
		C_Entity::setMotionZ(motionZ);
	}
}