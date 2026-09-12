// Fill out your copyright notice in the Description page of Project Settings.


#include "SteelCadenceCharacterMovement.h"

void USteelCadenceCharacterMovement::StartDash()
{
	// Already dashing - ignore rather than restarting, so mashing the key
	// can't extend a dash indefinitely.
	if (MovementMode == MOVE_Custom && CustomMovementMode == CMOVE_Dash)
	{
		return;
	}

	// Only allow dashing from grounded or airborne states.
	if (!IsMovingOnGround() && !IsFalling())
	{
		return;
	}

	// Dash toward current input if there is any, otherwise straight ahead.
	// Captured once here so input during the dash can't steer it.
	DashDirection = Acceleration.IsNearlyZero()
		? UpdatedComponent->GetForwardVector()
		: Acceleration.GetSafeNormal();

	DashDirection.Z = 0.f;
	DashDirection = DashDirection.GetSafeNormal();

	DashTimeRemaining = DashDuration;

	SetMovementMode(MOVE_Custom, CMOVE_Dash);
}

void USteelCadenceCharacterMovement::PhysCustom(float deltaTime, int32 Iterations)
{
	Super::PhysCustom(deltaTime, Iterations);

	switch (CustomMovementMode)
	{
	case CMOVE_Dash:
		PhysDash(deltaTime, Iterations);
		break;

	default:
		// An unhandled custom mode would leave the character with no physics
		// running at all. Fall back to walking so the bug is visible.
		SetMovementMode(MOVE_Walking);
		break;
	}
}

void USteelCadenceCharacterMovement::PhysDash(float deltaTime, int32 Iterations)
{
	// TODO:
	//   1. Count DashTimeRemaining down by deltaTime
	//   2. When it reaches zero, SetMovementMode(MOVE_Walking) and return
	//   3. Set Velocity = DashDirection * DashImpulse
	//   4. Move with SafeMoveUpdatedComponent(...) and handle the hit result
}