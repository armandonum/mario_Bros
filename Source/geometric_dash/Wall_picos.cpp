// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall_picos.h"


AWall_picos::AWall_picos()
{

	PrimaryActorTick.bCanEverTick = true;
}
void AWall_picos::BeginPlay()
{


	Super::BeginPlay();

	this->GetRootComponent()->ComponentVelocity = FVector(0, 25, 0);// velocidad del componente 
	//y de la componente raiz en 25 en el eje y 
}


void AWall_picos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + FVector(0, 350 * DeltaTime, 0), true);//movemos al actor usando su ubicacion actual
	// añadiendole solo el eje y para que se mueva en 2d 
}