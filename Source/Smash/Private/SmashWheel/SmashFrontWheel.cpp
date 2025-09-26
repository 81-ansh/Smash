// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashWheel/SmashFrontWheel.h"

USmashFrontWheel::USmashFrontWheel()
{
	WheelRadius = 30.f;
	SuspensionMaxRaise = 10.f;
	SuspensionMaxDrop = 10.f;
	MaxSteerAngle = 45.f;
	AxleType = EAxleType::Front;
	bAffectedByHandbrake = false;
	bAffectedBySteering = true;
	
}
