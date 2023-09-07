// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetOrb.generated.h"

UCLASS()
class AREIALDRONES_API ATargetOrb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetOrb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float range;
public:
	FVector v1;
	float Speed;
	float Speed2;
	FRotator Rotation;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetSpeed();
};
