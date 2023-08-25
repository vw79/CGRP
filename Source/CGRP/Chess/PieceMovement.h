#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "PieceMovement.generated.h"

USTRUCT(Blueprintable)
struct CGRP_API FPieceMovement : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 IndexOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 RowOffset;

	FPieceMovement();
	~FPieceMovement();
};
