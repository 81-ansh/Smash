// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashWheel/SmashRearWheel.h"

USmashRearWheel::USmashRearWheel()
{
	WheelRadius = 30.f;
	SuspensionMaxRaise = 10.f;
	SuspensionMaxDrop = 10.f;
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}
