// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DroneTarget.generated.h"
class ATargetOrb;
UCLASS()
class AREIALDRONES_API ADroneTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADroneTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float offset = 50;
	float NumTargets = 30;
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ATargetOrb> TargetTemplate;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	FVector DroneTargetVector1;
	UPROPERTY(VisibleAnywhere)
	FVector DroneTargetVector2;
	UPROPERTY(VisibleAnywhere)
	FVector DroneTargetVector3;
	UPROPERTY(EditAnywhere)
	TArray< ATargetOrb* > DroneTarget;
	TArray< ATargetOrb* > DroneOriginTarget;
};
