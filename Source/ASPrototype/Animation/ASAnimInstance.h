// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Game/ASGameMode.h"
#include "Animation/AnimInstance.h"
#include "Character/ASCharacterBase.h" //����
#include "ASAnimInstance.generated.h"
/**
 * 
 */
UCLASS()
class ASPROTOTYPE_API UASAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UASAnimInstance();
	State state;
	void StateHandler(State NewState);

	void SwitchSnipAnim();

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
	TObjectPtr<class ACharacter> Owner; //Animinstance�� ����ϰ� �ִ� �ɸ��Ϳ� ���� ���� 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
	TObjectPtr<class UCharacterMovementComponent> Movement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	bool bIsIdle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float GroundSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float MoveThreadshold; //�Ӱ谪 (Ư����ġ�� �ö󰡸� ������)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	bool bIsRunning;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	bool bIsJumping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	bool bIsFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	bool bIsHurt;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float JumpeThreadshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	bool DoSniping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	FVector OwnerLocation;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	//class AASCharacterBase* Actor;

	//trigger ���� 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	FRotator ControlRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float LookAtPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float LookAtYaw;
};
