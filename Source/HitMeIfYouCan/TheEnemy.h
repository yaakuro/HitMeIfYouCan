// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TheEnemy.generated.h"

UCLASS()
class HITMEIFYOUCAN_API ATheEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATheEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent*	Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector VerticalOffset;
};
