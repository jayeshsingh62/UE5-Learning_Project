// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPP_Object.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class LEARNINGPROJECT_API UCPP_Object : public UObject
{
	GENERATED_BODY()

private:
	int MyPrivateInteger;

public:
	UPROPERTY(BlueprintReadWrite)
	int MyPublicInteger;
	UFUNCTION(BlueprintPure)
	int GetMyPrivateInteger();
	UFUNCTION(BlueprintCallable)
	void SetMyPrivateInteger(int NewValue);
};
