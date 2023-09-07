// Fill out your copyright notice in the Description page of Project Settings.


#include "Drone.h"
#include "TargetOrb.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ADrone::ADrone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADrone::BeginPlay()
{
	Super::BeginPlay();
	StartPos = GetActorLocation();
}

void ADrone::MoveToward(FVector goal, float DeltaTime)
{
	FVector v = goal - GetActorLocation();
	v.Normalize();
	m_timer += DeltaTime;
	SetActorLocation(GetActorLocation() + v * DeltaTime * 700);

	SetActorRotation(UKismetMathLibrary::FindLookAtRotation(goal, GetActorLocation()));
}

// Called every frame
void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector TargetPos = m_DroneTarget->GetActorLocation();
	//switch (m_DroneState)
	//{
	//case ADrone::TOGETHER:
	//	break;
	//case ADrone::SPLIT:
	//	break;
	//case ADrone::ONTARGET:
	//	break;
	//default:
	//	break;
	//}
	if (m_DroneTarget && FVector::Distance(GetActorLocation(), TargetPos) > 100)
	{
		MoveToward(TargetPos, DeltaTime);
	}
	else
	{
		SetActorLocation(TargetPos);
		SetActorRotation(m_DroneTarget->GetActorRotation());
	}

}

void ADrone::SetDroneTarget(ATargetOrb* DroneTarget)
{
	m_DroneTarget = DroneTarget;
}

