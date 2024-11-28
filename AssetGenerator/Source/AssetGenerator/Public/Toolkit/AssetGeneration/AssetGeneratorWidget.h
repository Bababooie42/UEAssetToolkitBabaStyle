#pragma once

#include "AssetDumpViewWidget.h"
#include "AssetGeneration/AssetGeneratorLocalSettings.h"
#include "Widgets/SCompoundWidget.h"

class SAssetGeneratorWidget : public SCompoundWidget {
public:
	SAssetGeneratorWidget();
	
	SLATE_BEGIN_ARGS(SAssetGeneratorWidget) {}
	SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);
protected:
	UAssetGeneratorLocalSettings* LocalSettings;
	TSharedPtr<SAssetDumpViewWidget> AssetDumpViewWidget;
	TSharedPtr<SEditableTextBox> InputDumpPathText;

	TSharedRef<SWidget> CreateAssetTypeFilterCategory();
	TSharedRef<SWidget> CreateSettingsCategory();

	static void ExpandWhitelistedAssetCategories(TSet<FTopLevelAssetPath>& WhitelistedAssetCategories);
	FString GetAssetDumpFolderPath() const;
	void UpdateDumpViewRootDirectory();
	void SetAssetDumpFolderPath(const FString& InDumpFolderPath);
	FString GetDefaultAssetDumpPath() const;
	
	FReply OnBrowseOutputPathPressed();
	FReply OnGenerateAssetsButtonPressed();
};
