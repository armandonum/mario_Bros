// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RunerCaracter.generated.h"

UCLASS()
class GEOMETRIC_DASH_API ARunerCaracter : public ACharacter
{
	GENERATED_BODY()


		UPROPERTY(VisibleAnywhere)
		class UCameraComponent* vista_de_camara;
public:
	// Sets default values for this character's properties
	ARunerCaracter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	void mover_adelabte(float valor);


public:

	class UCameraComponent* Getvista_de_camaraComponent() const
	{
		return vista_de_camara;
	}


	void restaurar_nivel();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* otroActor, UPrimitiveComponent* otroComponente, int32 otroBody, bool bFromSweep,
			const FHitResult& SweepResult);

private:
	float zPosicion;
	FVector temp_pos = FVector();
	bool can_Movi;






};
