// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSOBJ1.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FPSCharacter.h"

// Sets default values
AFPSOBJ1::AFPSOBJ1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
	SphereComp->SetupAttachment(MeshComp);


}

// Called when the game starts or when spawned
void AFPSOBJ1::BeginPlay()
{
	Super::BeginPlay();
	PlayEffects();
	
}

void AFPSOBJ1::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickupFX, GetActorLocation());
}

/* Called every frame
void AFPSOBJ1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

*/

void AFPSOBJ1::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	PlayEffects();

	AFPSCharacter* MyCharacter = Cast<AFPSCharacter>(OtherActor);
	if (MyCharacter)
	{
		MyCharacter->bIsCarryingObjective = true;

		Destroy();
	}
}

