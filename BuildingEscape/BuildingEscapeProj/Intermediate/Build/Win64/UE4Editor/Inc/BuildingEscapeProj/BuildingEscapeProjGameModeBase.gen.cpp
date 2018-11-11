// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "BuildingEscapeProjGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBuildingEscapeProjGameModeBase() {}
// Cross Module References
	BUILDINGESCAPEPROJ_API UClass* Z_Construct_UClass_ABuildingEscapeProjGameModeBase_NoRegister();
	BUILDINGESCAPEPROJ_API UClass* Z_Construct_UClass_ABuildingEscapeProjGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_BuildingEscapeProj();
// End Cross Module References
	void ABuildingEscapeProjGameModeBase::StaticRegisterNativesABuildingEscapeProjGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ABuildingEscapeProjGameModeBase_NoRegister()
	{
		return ABuildingEscapeProjGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_ABuildingEscapeProjGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_BuildingEscapeProj,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "BuildingEscapeProjGameModeBase.h" },
				{ "ModuleRelativePath", "BuildingEscapeProjGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ABuildingEscapeProjGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ABuildingEscapeProjGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABuildingEscapeProjGameModeBase, 42698785);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABuildingEscapeProjGameModeBase(Z_Construct_UClass_ABuildingEscapeProjGameModeBase, &ABuildingEscapeProjGameModeBase::StaticClass, TEXT("/Script/BuildingEscapeProj"), TEXT("ABuildingEscapeProjGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABuildingEscapeProjGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
