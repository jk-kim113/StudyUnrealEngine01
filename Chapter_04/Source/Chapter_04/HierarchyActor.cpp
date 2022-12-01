// Fill out your copyright notice in the Description page of Project Settings.

#include "HierarchyActor.h"

// Sets default values
AHierarchyActor::AHierarchyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 네 개의 서브오브젝트 생성
	Root = CreateDefaultSubobject<USceneComponent>("Root");

	ChildSceneComponent = CreateDefaultSubobject<USceneComponent>("ChildSceneComponent");

	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");

	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");

	// 큐브 메시에 대한 참조 획득
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// 두 상자에 메시 연결
	if (MeshAsset.Object != nullptr)
	{
		BoxOne->SetStaticMesh(MeshAsset.Object);
		BoxTwo->SetStaticMesh(MeshAsset.Object);
	}

	RootComponent = Root;

	// 오브젝트 계층 설정
	BoxOne->AttachTo(Root);
	BoxTwo->AttachTo(ChildSceneComponent);

	ChildSceneComponent->AttachTo(Root);

	//루트에서 자식을 오프셋 및 스케일링
	ChildSceneComponent->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(250, 0, 0), FVector(0.1f)));

}

// Called when the game starts or when spawned
void AHierarchyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHierarchyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

