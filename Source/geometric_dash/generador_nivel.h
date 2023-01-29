// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "generador_nivel.generated.h"

class Anivel_base;

UCLASS()
class GEOMETRIC_DASH_API Agenerador_nivel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Agenerador_nivel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UFUNCTION()
		void generar_nivel(bool IsFirst);
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* otroActor, UPrimitiveComponent* otroComponente, int32 otroBody, bool bFromSweep,
			const FHitResult& SweepResult);


protected:

	APawn* player;
	UPROPERTY(EditAnywhere)
		TSubclassOf<Anivel_base> nivel1;

	UPROPERTY(EditAnywhere)
		TSubclassOf<Anivel_base> nivel2;

	UPROPERTY(EditAnywhere)
		TSubclassOf<Anivel_base> nivel3;

	UPROPERTY(EditAnywhere)
		TSubclassOf<Anivel_base> nivel4;

	UPROPERTY(EditAnywhere)
		TSubclassOf<Anivel_base> nivel5;

	UPROPERTY(EditAnywhere)
		TSubclassOf<Anivel_base> nivel6;

	UPROPERTY(EditAnywhere)
		TSubclassOf<Anivel_base> nivel7;



	TArray<Anivel_base*> lista_niveles;

public:
	int nivel_aleatorio;

	FVector SpawnLocation = FVector();
	FRotator SpawnRotation = FRotator();
	FActorSpawnParameters Spawninfo = FActorSpawnParameters();
};
