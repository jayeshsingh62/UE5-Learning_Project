// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_Object.generated.h"


/**
 * 
 */


UENUM(BlueprintType)
enum FruitList
{

};

USTRUCT(BlueprintType)
struct FBook
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString Name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int NumberOfPages;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Rating;
};
UCLASS(Blueprintable)
class LEARNINGPROJECT_API UCPP_Object : public UObject
{
	GENERATED_BODY()

private:
	int MyPrivateInteger;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MyPublicInteger;
	UFUNCTION(BlueprintPure)
	int GetMyPrivateInteger();
	UFUNCTION(BlueprintCallable)
	void SetMyPrivateInteger(UPARAM(ref)int& NewValue);
	UFUNCTION(BlueprintCallable)
		static void Test(UPARAM(ref)FBook& Target, UObject* Context);
};
