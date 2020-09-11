// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TheEnemy.h"
#include "TheEnemySpawner.generated.h"

UCLASS()
class HITMEIFYOUCAN_API ATheEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATheEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void HandleTimerFinished();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NumberOfEnemies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ATheEnemy> TheEnemyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HalfHorizontalOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HalfVerticalOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HalfDepthOffset;

	FTimerHandle TimerHandle;
};
