// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Drone.generated.h"
class UProjectileMovementComponent;
class ATargetOrb;
UCLASS()
class AREIALDRONES_API ADrone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrone();
protected:
	enum DroneStates
	{
		TOGETHER,
		SPLIT,
		ONTARGET
	};
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	DroneStates m_DroneState;
	void MoveToward(FVector goal, float DeltaTime);
	float m_timer;
public:
	UPROPERTY(EditAnywhere)
	ATargetOrb* m_DroneTarget = NULL;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetDroneTarget(ATargetOrb* DroneTarget);
	UProjectileMovementComponent* Movement;
	FVector StartPos;

};
