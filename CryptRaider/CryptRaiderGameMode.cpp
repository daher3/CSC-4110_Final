// Copyright Epic Games, Inc. All Rights Reserved.

#include "CryptRaiderGameMode.h"
#include "CryptRaiderCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "WinTriggerComponent.h"
#include "UObject/ConstructorHelpers.h"

ACryptRaiderGameMode::ACryptRaiderGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	Character = Cast<ACryptRaiderCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	PrimaryActorTick.bCanEverTick = true;
}



void ACryptRaiderGameMode::BeginPlay()
{
	 UE_LOG(LogTemp, Warning, TEXT("BeginPlay for Gamemode called"));
    // Implementation code goes here
    Super::BeginPlay(); // Call the parent class's BeginPlay if necessary

}

void ACryptRaiderGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    // Get the player character and cast it to ACryptRaiderCharacter
    Character = Cast<ACryptRaiderCharacter>(NewPlayer->GetPawn());
    if (Character == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Character is null in PostLogin"));
        return;
    }

}

void ACryptRaiderGameMode::ActorDied(AActor *DeadActor)
{

if (Character == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Character is null in ActorDied"));
        return;
}

if (DeadActor == Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Dead Character event is being called"));
	DeadCharacter();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PlayerController)
        {
            PlayerController->DisableInput(PlayerController);
        }
}

}

