// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneTarget.h"
#include "TargetOrb.h"
#include "Kismet/KismetMathLibrary.h" 
#include "Math/UnrealMathUtility.h"

// Sets default values
ADroneTarget::ADroneTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADroneTarget::BeginPlay()
{
	Super::BeginPlay();
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	for (size_t i = 0; i < NumTargets; i++)
	{
		FVector DroneTargetVector = UKismetMathLibrary::RandomUnitVector() * UKismetMathLibrary::RandomFloatInRange(100, 110) + GetActorLocation();
		DroneTarget.Add(GetWorld()->SpawnActor<ATargetOrb>(TargetTemplate, DroneTargetVector, Rotation, SpawnInfo)) ;
		DroneOriginTarget.Add( GetWorld()->SpawnActor<ATargetOrb>(TargetTemplate, GetActorLocation(), Rotation, SpawnInfo));
		DroneOriginTarget[i]->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
		DroneTarget[i]->AttachToActor(DroneOriginTarget[i], FAttachmentTransformRules::KeepWorldTransform);
		FVector rotator = (DroneTarget[i]->GetActorLocation() - DroneOriginTarget[i]->GetActorLocation());
		FRotator Temprotator = FRotator(rotator.X, rotator.Y, rotator.Z);
		Temprotator.Normalize();
		DroneTarget[i]->SetSpeed();
	}
	
	
}

// Called every frame
void ADroneTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (offset < 0)
	{
		offset = 50;
	}
	for (size_t i = 0; i < NumTargets; i++)
	{
		FVector temp = DroneTarget[i]->GetActorLocation();
		FRotator TempRotator = DroneOriginTarget[i]->GetActorRotation();
		INT64 TempInt = (DeltaTime * abs(DeltaTime + DroneTarget[i]->GetActorRotation().Roll - DroneOriginTarget[i]->GetActorRotation().Roll));
		TempRotator.Roll += DeltaTime * DroneTarget[i]->Speed;
		TempRotator.Yaw += DeltaTime * DroneTarget[i]->Speed;
		DroneOriginTarget[i]->SetActorRotation(TempRotator);
		
		DroneTarget[i]->SetActorRotation(UKismetMathLibrary::FindLookAtRotation(DroneTarget[i]->GetActorLocation(), temp ));
		DroneTarget[i]->SetSpeed();
	}
	//FVector d = GetActorLocation();
	//d.X += DeltaTime * 30;
	//SetActorLocation(d);
	
}

