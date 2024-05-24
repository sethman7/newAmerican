// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_Lvl1_Noise.generated.h"

/**
 * 
 */
UCLASS()
class ASPROTOTYPE_API UAnimNotify_Lvl1_Noise : public UAnimNotify
{
	GENERATED_BODY()

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference);
	class ASoundSender* AudioObject;
};
