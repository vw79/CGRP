// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

#include "ChessItem.h"
#include "ChessPieceBundle.h"
#include "ChessBoardLayout.h"
#include "PieceConfig.h"
#include "ChessBoard.generated.h"

UCLASS()
class CGRP_API AChessBoard : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AChessItem> ChessTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDataTableRowHandle InitBoardLayoutRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FChessPieceBundle ChessPieceBundle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double ChessPieceElevation = 50.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double TileSize = 100.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FPieceConfig WhiteConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FPieceConfig BlackConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterial* BlackTileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterial* WhiteTileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterial* SelectionMaterial;

protected:
	APlayerController* Controller;
	FChessBoardLayout* InitBoardLayout;
	TArray<AChessItem*> ChessPieces;
	TArray<AChessItem*> ChessTiles;

	AChessItem* SpawnChessPiece(int32 x, int32 y, FChessBoardLayout* BoardLayout);
	AChessItem* SpawnChessTile(int32 x, int32 y);

	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AChessBoard();
};
