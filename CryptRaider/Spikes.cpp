// Fill out your copyright notice in the Description page of Project Settings.


#include "Spikes.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpikes::ASpikes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMeshComp;

	// Set the collision channel to Pawn, so it can deal damage to the player character.
	StaticMeshComp->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	StaticMeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StaticMeshComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	StaticMeshComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

}

// Called when the game starts or when spawned
void ASpikes::BeginPlay()
{
	Super::BeginPlay();
	StaticMeshComp->OnComponentHit.AddDynamic(this, &ASpikes::OnHit);
}

// Called every frame
void ASpikes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpikes::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor->IsA(APawn::StaticClass()) && OtherActor != this)
	{
		APawn* OtherPawn = Cast<APawn>(OtherActor);
		AController* MyOwnerInstigator = GetInstigatorController();
		UClass* DamageTypeClass = UDamageType::StaticClass();
		UGameplayStatics::ApplyDamage(OtherPawn, Damage, MyOwnerInstigator, this, DamageTypeClass);

		if (HitSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
		}
	}
}