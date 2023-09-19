// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneManager.h"
#include "DroneTarget.h"
#include "TargetOrb.h"
#include "Drone.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"
#include "Kismet/KismetMathLibrary.h"

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

void ADroneManager::SpawnDrone(FVector _pos,FRotator _rotation, ADroneTarget* _target)
{
	FRotator Rotation( 0, 0, 0);
	FActorSpawnParameters SpawnInfo;
	Drones.Add(GetWorld()->SpawnActor<ADrone>(Dronetemplate[FMath::RandRange(0, Dronetemplate.Num()-1)], _pos, Rotation, SpawnInfo));
	
	FVector DroneTargetVector =_target->GetActorLocation() + UKismetMathLibrary::RandomUnitVector() * UKismetMathLibrary::RandomFloatInRange(100, 110);
	_target->DroneTarget.Add(GetWorld()->SpawnActor<ATargetOrb>(_target->TargetTemplate, DroneTargetVector, Rotation, SpawnInfo)) ;
	_target->DroneOriginTarget.Add( GetWorld()->SpawnActor<ATargetOrb>(_target->TargetTemplate, _target->GetActorLocation(), Rotation, SpawnInfo));
	_target->DroneOriginTarget.Last()->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	_target->DroneTarget.Last()->AttachToActor(_target->DroneOriginTarget.Last(), FAttachmentTransformRules::KeepWorldTransform);
	FVector rotator = (_target->DroneTarget.Last()->GetActorLocation() - _target->DroneOriginTarget.Last()->GetActorLocation());
	FRotator Temprotator = FRotator(rotator.X, rotator.Y, rotator.Z);
	Temprotator.Normalize();
	_target->DroneTarget.Last()->SetSpeed();
	Drones.Last()->SetDroneTarget(_target->DroneTarget.Last());
}

