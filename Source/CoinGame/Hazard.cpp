// Fill out your copyright notice in the Description page of Project Settings.


#include "Hazard.h"
#include "GameFramework/Character.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"

AHazard::AHazard()
{
	PrimaryActorTick.bCanEverTick = false;
	HazardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HazardMesh"));
	RootComponent = HazardMesh;

	HazardMesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));
}

void AHazard::BeginPlay()
{
	Super::BeginPlay();
	HazardMesh->OnComponentHit.AddDynamic(this, &AHazard::OnHazardHit);
}

void AHazard::OnHazardHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	const FHitResult& Hit)
{
	if (ACharacter* Character = Cast<ACharacter>(OtherActor))
	{
		const float Now = GetWorld()->GetTimeSeconds();

		if (LastLaunchTime + LaunchCooldown > Now)
		{
			return;
		}

		LastLaunchTime = Now;

		FVector HazardLocation = GetActorLocation();
		FVector CharacterLocation = Character->GetActorLocation();

		FVector LaunchDirection = CharacterLocation - HazardLocation;

		LaunchDirection = LaunchDirection.GetSafeNormal2D();

		FVector LaunchVelocity = LaunchDirection * HorizontalLaunchSpeed;
		LaunchVelocity.Z += VerticalLaunchSpeed;
		Character->LaunchCharacter(LaunchVelocity, true, true);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s hit by %s"), *GetName(), *Character->GetName()));
		}
		UE_LOG(LogTemp, Warning, TEXT("%s hit by %s"), *GetName(), *Character->GetName());
		DrawDebugDirectionalArrow(GetWorld(), HazardLocation, CharacterLocation, 50.f, FColor::Red, false, 2.f, 0, 3.f);
	}
}