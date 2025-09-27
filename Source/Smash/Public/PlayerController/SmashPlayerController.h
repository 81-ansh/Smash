// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "SmashPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class SMASH_API ASmashPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASmashPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> SmashContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> Throttle;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> Brake;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> Handbrake;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> Steering;

	void ApplyThrottle(const FInputActionValue& InputActionValue);
	void ApplyBrake(const FInputActionValue& InputActionValue);
	void ApplySteering(const FInputActionValue& InputActionValue);
	void OnHandbrakePressed(const FInputActionValue& InputActionValue);
	void OnHandbrakeReleased(const FInputActionValue& InputActionValue);
	
};
