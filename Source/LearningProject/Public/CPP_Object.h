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
	int MyPublicInteger;
	int GetMyPrivateInteger();
	void SetMyPrivateInteger();
};
