// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SteelCadenceCharacterMovement.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum ESteelCadenceMovementMode : uint8
{
	CMOVE_None   UMETA(Hidden),
	CMOVE_Dash   UMETA(DisplayName = "Dash"),
};

/**
 * 
 */
UCLASS()
class STEELCADENCE_API USteelCadenceCharacterMovement : public UCharacterMovementComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "Dash")
	float DashImpulse = 1500.f;

	UPROPERTY(EditDefaultsOnly, Category = "Dash")
	float DashDuration = 0.2f;

	UFUNCTION(BlueprintCallable, Category = "Dash")
	void StartDash();
protected:
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;
	void PhysDash(float deltaTime, int32 Iterations);

private:
	/** Seconds left in the current dash. Counted down in PhysDash. */
	float DashTimeRemaining = 0.f;

	/** Direction captured when the dash starts, so mid-dash input can't steer it. */
	FVector DashDirection = FVector::ZeroVector;
};
