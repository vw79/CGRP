#include "CameraTransition.h"
#include "Blueprint/UserWidget.h"

void ACameraTransition::CameraMovement(
    float DeltaTime,
    FVector TargetLocation, FRotator TargetRotation
) {
    AActor* camera = this->Camera;
    // Move camera location to target location
    camera->SetActorLocation(
        FMath::Lerp(
            camera->GetActorLocation(),
            TargetLocation,
            DeltaTime * this->MovementSpeed
        )
    );
    camera->SetActorRotation(
        FMath::RInterpTo(
            camera->GetActorRotation(),
            TargetRotation,
            DeltaTime, this->RotationSpeed
        )
    );
}

// Sets default values
ACameraTransition::ACameraTransition()
{
}

// Called when the game starts or when spawned
void ACameraTransition::BeginPlay()
{
    Super::BeginPlay();

};

// Called every frame
void ACameraTransition::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

};
