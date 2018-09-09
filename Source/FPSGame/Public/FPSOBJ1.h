// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSOBJ1.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UParticleSystem;

UCLASS()
class FPSGAME_API AFPSOBJ1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSOBJ1();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	UParticleSystem* PickupFX;

	void PlayEffects();

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	
	
};
