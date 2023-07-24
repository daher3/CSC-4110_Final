// Fill out your copyright notice in the Description page of Project Settings.


#include "ArrowWall.h"
#include "CryptRaiderCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "TriggerComponent.h"
#include "NewArrowWallTrigger.h"



void AArrowWall::BeginPlay()
{
    Super::BeginPlay();

    NewTrigger = FindComponentByClass<UNewArrowWallTrigger>();
    Character = Cast<ACryptRaiderCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &AArrowWall::CheckFireCondition, FireRate, true);
    
}


void AArrowWall::CheckFireCondition()
{
    //UE_LOG(LogTemp, Warning, TEXT("Check fire condition is being called"));
    if (Character == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Character is null"));
        return;
    }
    if(NewTrigger->ShouldArrowWallFire())
    {    
    AArrowWall::Fire();
    }
}

void AArrowWall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // if (InFireRange())
    // {
    // // If it is in range, rotate the turret to tank
    // //RotateTurret(Tank->GetActorLocation());
    // }   

}

bool AArrowWall::InFireRange()
{
    if (Character)
    {
        float Distance = FVector::Dist(GetActorLocation(), Character->GetActorLocation());
        if (Distance <= FireRange)
        {
            return true;
        }
    }
    return true; 
}