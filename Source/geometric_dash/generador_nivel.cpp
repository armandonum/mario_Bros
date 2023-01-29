// Fill out your copyright notice in the Description page of Project Settings.


#include "generador_nivel.h"

#include"nivel_base.h"
#include"Engine.h"
#include"Components/BoxComponent.h"

// Sets default values
Agenerador_nivel::Agenerador_nivel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Agenerador_nivel::BeginPlay()
{
	Super::BeginPlay();
	generar_nivel(true);
	//generar_nivel(false);
	//generar_nivel(false);
	//generar_nivel(false);




}

// Called every frame
void Agenerador_nivel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Agenerador_nivel::generar_nivel(bool IsFirst)// Aqui es donde sucedera la generacion de niveles 
{
	SpawnLocation = FVector(0, 1000, 0);
	SpawnRotation = FRotator(0, 90, 0);


	if (!IsFirst)
	{
		Anivel_base* last_nivel = lista_niveles.Last();
		SpawnLocation = last_nivel->Getubicacion_generacion()->GetComponentTransform().GetTranslation();
	}
	nivel_aleatorio = FMath::RandRange(1,7);
	Anivel_base* nuevoNivel = nullptr;

	if (nivel_aleatorio == 1)
	{

		nuevoNivel = GetWorld()->SpawnActor<Anivel_base>(nivel1, SpawnLocation, SpawnRotation, Spawninfo);

	}
	if (nivel_aleatorio == 2)
	{

		nuevoNivel = GetWorld()->SpawnActor<Anivel_base>(nivel2, SpawnLocation, SpawnRotation, Spawninfo);

	}
	if (nivel_aleatorio == 3)
	{

		nuevoNivel = GetWorld()->SpawnActor<Anivel_base>(nivel3, SpawnLocation, SpawnRotation, Spawninfo);

	}
	if (nivel_aleatorio == 4)
	{

		nuevoNivel = GetWorld()->SpawnActor<Anivel_base>(nivel4, SpawnLocation, SpawnRotation, Spawninfo);

	}
	if (nivel_aleatorio == 5)
	{

		nuevoNivel = GetWorld()->SpawnActor<Anivel_base>(nivel5, SpawnLocation, SpawnRotation, Spawninfo);

	}
	if (nivel_aleatorio == 6)
	{

		nuevoNivel = GetWorld()->SpawnActor<Anivel_base>(nivel7, SpawnLocation, SpawnRotation, Spawninfo);

	}
	if (nivel_aleatorio == 7)
	{

		nuevoNivel = GetWorld()->SpawnActor<Anivel_base>(nivel7, SpawnLocation, SpawnRotation, Spawninfo);

	}


	if (nuevoNivel)


	{
		if (nuevoNivel->getdidparador())
		{
			nuevoNivel->getdidparador()->OnComponentBeginOverlap.AddDynamic(this, &Agenerador_nivel::OnOverlapBegin);// para la colision

		}
	}


	lista_niveles.Add(nuevoNivel);
	if (lista_niveles.Num() > 5)
	{
		lista_niveles.RemoveAt(0);

	}



}

void Agenerador_nivel::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* otroActor, UPrimitiveComponent* otroComponente, int32 otroBody, bool bFromSweep, const FHitResult& SweepResult)
{

	generar_nivel(false);
}

