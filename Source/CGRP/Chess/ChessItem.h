#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessItem.generated.h"

UCLASS(Blueprintable)
class CGRP_API AChessItem : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 BoardIndex;

protected:
	UStaticMeshComponent* MeshComponent;
	UMaterial* OriginMaterial;
	FVector OriginScale;
	FVector TargetScale;
	double ScaleSpeed = 1.0;

	virtual void BeginPlay() override;

public:
	void SetOriginMaterial(UMaterial* Material);
	void SetMaterial(UMaterial* Material);
	void ResetMaterial();
	void ScaleByFactor(double Factor, double Speed);
	virtual void Tick(float DeltaTime) override;

	AChessItem();
};
