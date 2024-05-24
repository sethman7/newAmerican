// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BT/BTTask_FindLastKnownPostion.h"
#include "AI/ASAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemy/ASEnemyBase.h"

EBTNodeResult::Type UBTTask_FindLastKnownPostion::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	AASAIController* AI = Cast<AASAIController>(ControllingPawn->GetController());

	//�ι� ���� 
	if (AI->GetBB_EnableRoaming()==true)
	{
		//LastKnownPosition �������� ���� ��ġ ��� 
		AI->FindNearLocation(AI->LastKnownPosition,1000.0f);
		return EBTNodeResult::Succeeded;
	}

	switch (AI->Alertlvl)
	{
	case AlertLvl::Low:
		AI->SetBB_LastKnownPosition(AI->LastKnownPosition);
		break;

	case AlertLvl::Medium:
		AI->FindNearLocation(AI->LastKnownPosition, 400.0f);
		break;
	case AlertLvl::High:
		AI->FindNearLocation(AI->LastKnownPosition, 400.0f);
		break;
	default:
		break;
	}
	
	return EBTNodeResult::Succeeded;
}
