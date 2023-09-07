// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DroneManager.generated.h"

class ADrone;
class ADroneTarget;
class ATargetOrb;
UCLASS()
class AREIALDRONES_API ADroneManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADroneManager();
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<ADrone>> Dronetemplate;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	TArray<ATargetOrb*> m_TargetOrbs;
public:
	UPROPERTY(EditAnywhere)
	ADrone* Drone;
	UPROPERTY(EditAnywhere)
	ADroneTarget* Target;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetTargetOrbs(TArray<ATargetOrb*> TargetOrbs);
	UFUNCTION(BlueprintCallable)
	void SpawnDrone(FVector _pos,FRotator _rotation);
};
