// Fill out your copyright notice in the Description page of Project Settings.


#include "TheEnemySpawner.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ATheEnemySpawner::ATheEnemySpawner()
	: NumberOfEnemies(3)
	, SpawnTime(2.0f)
	, HalfHorizontalOffset(500.0)
	, HalfVerticalOffset(300.0f)
	, HalfDepthOffset(300.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATheEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ATheEnemySpawner::HandleTimerFinished, SpawnTime, true);
}

// Called every frame
void ATheEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATheEnemySpawner::HandleTimerFinished()
{
	for(int i = 0; i < NumberOfEnemies; ++i)
	{
		float HorizontalOffset = UKismetMathLibrary::RandomFloatInRange(-HalfHorizontalOffset, HalfHorizontalOffset);
		float VerticalOffset = UKismetMathLibrary::RandomFloatInRange(-HalfVerticalOffset, HalfVerticalOffset);
		float DepthOffset = UKismetMathLibrary::RandomFloatInRange(-HalfDepthOffset, HalfDepthOffset);
		FVector Location = GetActorLocation();
		Location.X += DepthOffset;
		Location.Y += HorizontalOffset;
		Location.Z += VerticalOffset;

		GetWorld()->SpawnActor<ATheEnemy>(TheEnemyClass, Location, FRotator::ZeroRotator);
	}
}

