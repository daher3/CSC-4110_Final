// Fill out your copyright notice in the Description page of Project Settings.


#include "UHealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CryptRaiderGameMode.h"

// Sets default values for this component's properties
UUHealthComponent::UUHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UUHealthComponent::DamageTaken);

	CryptRaiderGameMode = Cast<ACryptRaiderGameMode>(UGameplayStatics::GetGameMode(this));
	
}


// Called every frame
void UUHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UUHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* Instigator, AActor* DamageCauser)
{
	if (Damage <= 0.f) return;

	Health -= Damage;
	UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);

	if (Health <= 0 && CryptRaiderGameMode)
	{
			UE_LOG(LogTemp, Warning, TEXT("Character should be dead"));
			CryptRaiderGameMode->ActorDied(DamagedActor);
	}
}