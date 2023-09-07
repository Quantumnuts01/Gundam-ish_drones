// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneManager.h"
#include "DroneTarget.h"
#include "TargetOrb.h"
#include "Drone.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"

// Sets default values
ADroneManager::ADroneManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADroneManager::BeginPlay()
{
	Super::BeginPlay();
	//for (int i = 0; i < 10 ; i++)
	//{
	//SpawnDrone();
	//}
}

// Called every frame
void ADroneManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADroneManager::SetTargetOrbs(TArray<ATargetOrb*> TargetOrbs)
{
	m_TargetOrbs = TargetOrbs;
}

void ADroneManager::SpawnDrone(FVector _pos,FRotator _rotation)
{
	FRotator Rotation( 100.0f, 900.0f, 1000.0f);
	FActorSpawnParameters SpawnInfo;
	Drone = GetWorld()->SpawnActor<ADrone>(Dronetemplate[FMath::RandRange(0, Dronetemplate.Num()-1)], _pos, Rotation, SpawnInfo);
	Drone->SetDroneTarget(Target->DroneTarget[FMath::RandRange(0, Target->DroneTarget.Num()-1)]);
}

