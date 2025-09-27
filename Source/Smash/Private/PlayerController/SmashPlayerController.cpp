// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/SmashPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "SmashCar/SmashCar.h"
#include "ChaosVehicleMovementComponent.h"

ASmashPlayerController::ASmashPlayerController()
{
	bReplicates = true;
}

void ASmashPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(SmashContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(SmashContext, 0);
}

void ASmashPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(Throttle, ETriggerEvent::Triggered, this, &ASmashPlayerController::ApplyThrottle);
	EnhancedInputComponent->BindAction(Brake, ETriggerEvent::Triggered, this, &ASmashPlayerController::ApplyBrake);
	EnhancedInputComponent->BindAction(Handbrake, ETriggerEvent::Triggered, this, &ASmashPlayerController::OnHandbrakePressed);
	EnhancedInputComponent->BindAction(Handbrake, ETriggerEvent::Started, this, &ASmashPlayerController::OnHandbrakeReleased);
	EnhancedInputComponent->BindAction(Steering, ETriggerEvent::Completed, this, &ASmashPlayerController::ApplySteering);
}

void ASmashPlayerController::ApplyThrottle(const FInputActionValue& InputActionValue)
{
	if (APawn* ControlledPawn = GetPawn())
	{
		if (auto* Vehicle = Cast<AWheeledVehiclePawn>(ControlledPawn))
		{
			Vehicle->GetVehicleMovementComponent()->SetThrottleInput(InputActionValue.Get<float>());
		}
	}
}

void ASmashPlayerController::ApplyBrake(const FInputActionValue& InputActionValue)
{
	if (APawn* ControlledPawn = GetPawn())
	{
		if (auto* Vehicle = Cast<AWheeledVehiclePawn>(ControlledPawn))
		{
			Vehicle->GetVehicleMovementComponent()->SetBrakeInput(InputActionValue.Get<float>());
		}
	}
}

void ASmashPlayerController::ApplySteering(const FInputActionValue& InputActionValue)
{
	if (APawn* ControlledPawn = GetPawn())
	{
		if (auto* Vehicle = Cast<AWheeledVehiclePawn>(ControlledPawn))
		{
			Vehicle->GetVehicleMovementComponent()->SetSteeringInput(InputActionValue.Get<float>());
		}
	}
}

void ASmashPlayerController::OnHandbrakePressed(const FInputActionValue& InputActionValue)
{
	if (APawn* ControlledPawn = GetPawn())
	{
		if (auto* Vehicle = Cast<AWheeledVehiclePawn>(ControlledPawn))
		{
			Vehicle->GetVehicleMovementComponent()->SetHandbrakeInput(true);
		}
	}
}

void ASmashPlayerController::OnHandbrakeReleased(const FInputActionValue& InputActionValue)
{
	if (APawn* ControlledPawn = GetPawn())
	{
		if (auto* Vehicle = Cast<AWheeledVehiclePawn>(ControlledPawn))
		{
			Vehicle->GetVehicleMovementComponent()->SetHandbrakeInput(false);
		}
	}
}
