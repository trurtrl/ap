// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AudioActor.h"
#include "ExtendedAudioComponent.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "AudioPlayer.generated.h"

/**
 * 
 */
UCLASS()
class AUDIOPLAYER_API UAudioPlayer : public UObject
{
	GENERATED_BODY()
	
public:

	UAudioPlayer(const FObjectInitializer & ObjectInitializer);

	//	returns AudioComponent's index in array
	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	int32 PlaySound(USoundBase* soundBase, bool bLooping);

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	void Repeat(int32 recordID);

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	void Stop(int32 recordID);

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	void Pause(int32 recordID);

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	void FadeIn(float FadeInDuration);

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	void FadeOut(float FadeOutDuration);

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	UExtendedAudioComponent* GetAudioComponent(int32 recordID) const;

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	bool IsAudioMuted() const;

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	float GetVolumeInSettings() const;

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	void AudioVolumeChanged(float NewVolume);

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	void AudioMutedChanged(bool bMuted);

	UFUNCTION(BlueprintCallable, Category = "Audio|Components|Audio")
	void SetVolumeMultiplier(float newMuptiplier);


private:

	UPROPERTY(meta = (DisplayName = "Audio Actor"))
	AAudioActor* m_AudioActor;

	void SpawnAudioActor();
	
	//	Volume
	float m_VolumeInSettings;
	float m_VolumeMin;
	float m_VolumeMax;

	bool m_AudioMuted;

	void SetVolume(float newVolume);

	//	Fade in\out
	FTimerHandle m_FadeTimerHandle;

	float m_FadeDuration;
	float m_FadeDeltaTime;
	float m_FadeTimeElapsed;

	//	defines process Fade In or Out
	bool m_FadeIn;

	void FadeExec(bool bFadeIn, float FadeDuration);
	void FadeVolume();

};