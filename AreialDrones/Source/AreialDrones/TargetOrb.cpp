// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetOrb.h"
#include "Kismet/KismetMathLibrary.h" 

// Sets default values
ATargetOrb::ATargetOrb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATargetOrb::BeginPlay()
{
	Super::BeginPlay();
	FVector temp = UKismetMathLibrary::RandomUnitVector();
	Rotation.Yaw = FMath::Clamp(temp.X, 0, 180);
	Rotation.Roll = FMath::Clamp(temp.Y, 0, 180);
	Rotation.Pitch = temp.Z;
	//SetActorRotation(Rotation);
	Speed = UKismetMathLibrary::RandomFloatInRange(50,70);
	v1 = GetActorLocation();

}

// Called every frame
void ATargetOrb::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
	
	//SetActorRelativeLocation(v);
	//SetActorRelativeRotation(GetActorRotation() + FRotator(0, DeltaTime,0) );
}

void ATargetOrb::SetSpeed()
{
	Speed2 = FVector::Distance(GetActorLocation(), v1);
	v1 = GetActorLocation();
}

