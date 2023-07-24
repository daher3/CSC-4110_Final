// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTrap.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABaseTrap::ABaseTrap()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	TrapMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Trap Mesh"));
	RootComponent = TrapMesh;


	ProjectileSpawnPoint1 = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile SpawnPoint 1"));
	ProjectileSpawnPoint1->SetupAttachment(TrapMesh);

	ProjectileSpawnPoint2 = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile SpawnPoint 2"));
	ProjectileSpawnPoint2->SetupAttachment(TrapMesh);

	ProjectileSpawnPoint3 = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile SpawnPoint 3"));
	ProjectileSpawnPoint3->SetupAttachment(TrapMesh);

	ProjectileSpawnPoint4 = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile SpawnPoint 4"));
	ProjectileSpawnPoint4->SetupAttachment(TrapMesh);

}

// Called every frame
void ABaseTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABaseTrap::Fire()
{
	FVector Location;
	FRotator Rotation;

	// Spawn projectile from spawn point 1
	Location = ProjectileSpawnPoint1->GetComponentLocation();
	Rotation = ProjectileSpawnPoint1->GetComponentRotation();
	AProjectile* Projectile1 = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	if (Projectile1)
	{
		Projectile1->SetOwner(this);
	}

	// Spawn projectile from spawn point 2
	Location = ProjectileSpawnPoint2->GetComponentLocation();
	Rotation = ProjectileSpawnPoint2->GetComponentRotation();
	AProjectile* Projectile2 = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	if (Projectile2)
	{
		Projectile2->SetOwner(this);
	}

	// Spawn projectile from spawn point 3
	Location = ProjectileSpawnPoint3->GetComponentLocation();
	Rotation = ProjectileSpawnPoint3->GetComponentRotation();
	AProjectile* Projectile3 = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	if (Projectile3)
	{
		Projectile3->SetOwner(this);
	}

	// Spawn projectile from spawn point 4
	Location = ProjectileSpawnPoint4->GetComponentLocation();
	Rotation = ProjectileSpawnPoint4->GetComponentRotation();
	AProjectile* Projectile4 = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	if (Projectile4)
	{
		Projectile4->SetOwner(this);
	}
}


// void ABaseTrap::Fire()
// {
// 		FVector Location = ProjectileSpawnPoint->GetComponentLocation();
// 		FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();

// 		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
// 		if (Projectile)
// 		{
// 			Projectile->SetOwner(this);
// 		}
// }