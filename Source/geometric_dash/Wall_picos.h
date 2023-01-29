// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "picos.h"
#include "Wall_picos.generated.h"

/**
 * 
 */
UCLASS()
class GEOMETRIC_DASH_API AWall_picos : public Apicos
{
	GENERATED_BODY()

public:
	AWall_picos();// pico de pared que es nuestro constructor 

protected:
	virtual void BeginPlay()override;


public:
	virtual void Tick(float DeltaTime) override;

	
};
