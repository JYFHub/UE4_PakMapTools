// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/BaseToolkit.h"

#define MY_EDITOR_API
class FPakMapToolsModuleEdModeToolkit : public FModeToolkit
{
public:

	FPakMapToolsModuleEdModeToolkit();
	
	/** FModeToolkit interface */
	virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual class FEdMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override { return ToolkitWidget; }

	/*�򿪱���Ŀ¼����*/
	FString OpenSaveDirDialog(FString title, FString defaultPath = FString());
	/*��ȡ����ѡ�����Դ����*/
	TArray<FAssetData> GetAllSelectedSource();
	/*��ȡ��Դ����������*/
	void GetDependeciesByPackageName(const FName& PackageName, TSet<FName>& AllDependencies);
	/*���Map*/
	void PakWorld(TArray<UWorld*> worlds);
private:
	FString useProjectName = TEXT("YOUPROJECTNAME");
	TSharedPtr<SWidget> ToolkitWidget;
};
