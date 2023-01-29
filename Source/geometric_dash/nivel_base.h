// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "nivel_base.generated.h"

class UBoxComponent;// declaracion reenviada 

UCLASS()
class GEOMETRIC_DASH_API Anivel_base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Anivel_base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Tiggers")
		UBoxComponent* disparador;// esto podemos editarlo dentro del editor 
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Tiggers")
		UBoxComponent* ubicacion_generacion;

public:
	UBoxComponent* getdidparador();
	UBoxComponent* Getubicacion_generacion();
	

};
