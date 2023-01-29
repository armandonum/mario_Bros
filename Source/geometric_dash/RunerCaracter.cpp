// Fill out your copyright notice in the Description page of Project Settings.


#include "RunerCaracter.h"


#include"Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include"GameFramework/CharacterMovementComponent.h"

#include"picos.h"
#include"Wall_picos.h"
#include"Engine.h"

// Sets default values
ARunerCaracter::ARunerCaracter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	GetCapsuleComponent()->SetCollisionResponseToChannel
	(ECC_GameTraceChannel1, ECR_Overlap);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	vista_de_camara = CreateDefaultSubobject<UCameraComponent>(TEXT("vista de la camar"));
	vista_de_camara->bUsePawnControlRotation = false;


	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);

	
	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.8f; //aire control 
	GetCharacterMovement()->JumpZVelocity = 1000.0f;//velocidad de salto  
	GetCharacterMovement()->GroundFriction = 3.0f;// friccion con el suelo 
	GetCharacterMovement()->MaxWalkSpeed = 600.0f; // velocidad maxima de la caminata
	GetCharacterMovement()->MaxFlySpeed = 600.0f;// velocidad maxima de vuelo 



	temp_pos = GetActorLocation();
	zPosicion = temp_pos.Z + 300.f;

}

// Called when the game starts or when spawned
void ARunerCaracter::BeginPlay()
{
	Super::BeginPlay();


	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ARunerCaracter::OnOverlapBegin);

	can_Movi = true;
	
}

// Called every frame
void ARunerCaracter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	temp_pos = GetActorLocation();// obtenemos la ubicacion actual
	temp_pos.X -= 850.0f; // restamos a la posicion 850
	temp_pos.Z = zPosicion;// laposicion z seguira siendo la que tenemos aqui 

	vista_de_camara->SetWorldLocation(temp_pos);// se establece la ubicacion mundial de la camara 
	//a la que pasamos la posocion temporal
}

// Called to bind functionality to input
void ARunerCaracter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);// componente de entrada de reproduccion

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);


	PlayerInputComponent->BindAxis("MoveRight", this, &ARunerCaracter::mover_adelabte);

}


void ARunerCaracter::mover_adelabte(float valor)
{
	if (can_Movi) {

		AddMovementInput(FVector(0, 1, 0.0f),valor);

	}
}

void ARunerCaracter::restaurar_nivel() {


	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));

}
void ARunerCaracter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* otroActor, UPrimitiveComponent* otroComponente, int32 otroBody, bool bFromSweep,
	const FHitResult& SweepResult) 

{
	if (otroActor != nullptr)
	{
		Apicos* Wall_picos = Cast<AWall_picos>(otroActor);
		Apicos* picos = Cast<Apicos>(otroActor);

		if (Wall_picos || picos) {
			GetMesh()->Deactivate();
			GetMesh()->SetVisibility(false);

			can_Movi = false;
			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &ARunerCaracter::restaurar_nivel, 2.f, false);// cuando el jugador colisiones con cualquiera 
			// de los picos el nievl se reiniciara 
		}

	}

}

