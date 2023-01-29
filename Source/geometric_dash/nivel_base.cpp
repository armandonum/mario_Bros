// Fill out your copyright notice in the Description page of Project Settings.


#include "nivel_base.h"

#include"Components/BoxComponent.h"

// Sets default values
Anivel_base::Anivel_base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Anivel_base::BeginPlay()
{
	Super::BeginPlay();
	
	if (disparador != nullptr) {
		disparador->bHiddenInGame = true;
	}

}

// Called every frame
void Anivel_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UBoxComponent* Anivel_base::getdidparador()
{
	return disparador;
}

UBoxComponent* Anivel_base::Getubicacion_generacion()
{
	return ubicacion_generacion;
}

