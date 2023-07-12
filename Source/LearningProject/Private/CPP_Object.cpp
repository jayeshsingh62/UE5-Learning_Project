// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Object.h"

int UCPP_Object::GetMyPrivateInteger()
{
	return MyPrivateInteger;
}

void UCPP_Object::SetMyPrivateInteger(UPARAM(ref)int& NewValue)
{
	MyPrivateInteger = NewValue;
}

void UCPP_Object::Test(UPARAM(ref)FBook& Target)
{
}
