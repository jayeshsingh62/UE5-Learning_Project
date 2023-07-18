// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Character.h"

// Sets default values
ACPP_Character::ACPP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyIntegerArray = { 10,20,30,40 };
}

// Called when the game starts or when spawned
void ACPP_Character::BeginPlay()
{
	Super::BeginPlay();
	TestBPFunc(100);
	MyIntegerArray.Reserve(6);
	MyIntegerArray.Add(50);
	MyIntegerArray.Emplace(60);
	MyIntegerArray.Remove(10);
	MyIntegerArray.RemoveAt(0);

	MyMap.Add("Pi", 3.14);
	MyMap.Add("Num1", 12.34);
	UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(MyMap["Num1"]));

	for (auto& i : MyIntegerArray)
	{
		UKismetSystemLibrary::PrintString(this, FString::FromInt(i));
	}

	for (auto& i : MyMap)
	{
		FString temp = i.Key;
		temp.Append(" : ");
		temp.Append(FString::SanitizeFloat(i.Value));
		UKismetSystemLibrary::PrintString(this, temp);

		if (ActorToSpawn)
		{
			auto temp = GetWorld()->SpawnActor<ACPP_InteractionActor>(ActorToSpawn);
			auto temp1 = GetWorld()->SpawnActorDeferred<ACPP_InteractionActor>(ActorToSpawn, FTransform());
			temp1->number = 100;
			temp1->FinishSpawning(FTransform());
		}		
	}

	auto temp2 = GetCharacterMovement();
	temp2->SetMovementMode(EMovementMode::MOVE_Flying, 0);
}

// Called every frame
void ACPP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ACPP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_Character::RemovePickup()
{
	auto temp = UGameplayStatics::GetPlayerCameraManager(this, 0);
	TArray<AActor*> Ignore;
	FHitResult Hit;
	UKismetSystemLibrary::LineTraceSingle(this, temp->GetCameraLocation(), temp->GetCameraLocation() + (temp->GetActorForwardVector() * 50000), ETraceTypeQuery::TraceTypeQuery1, 0, Ignore, EDrawDebugTrace::ForDuration, Hit, true);
	if (Hit.GetActor()) 
	{
		if (Cast<IMyInterface>(Hit.GetActor())) 
		{
			auto TEMP = Cast<IMyInterface>(Hit.GetActor());
			TEMP->Destruct();
		}
	}
}

void ACPP_Character::TestBPNativeFunc_Implementation(float x)
{
	UKismetSystemLibrary::PrintString(this, "C++ implementation called");
}
