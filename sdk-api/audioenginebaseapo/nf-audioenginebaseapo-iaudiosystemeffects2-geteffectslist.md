# IAudioSystemEffects2::GetEffectsList

## Description

The GetEffectsList method is used for retrieving the list of audio processing effects that are currently active, and stores an event to be signaled if the list changes.

## Parameters

### `ppEffectsIds` [out]

Pointer to the list of GUIDs that represent audio processing effects. The caller is responsible for freeing this memory by calling CoTaskMemFree.

### `pcEffects` [out]

A count of the audio processing effects in the list.

### `Event` [in]

The HANDLE of the event that will be signaled if the list changes.

## Return value

The **GetEffectsList** method returns S_OK, If the method call is successful. If there are no effects in the list, the function still succeeds, *ppEffectsIds* returns a NULL pointer, and *pcEffects* returns a count of 0.

## Remarks

The APO signals the specified event when the list of audio processing effects changes from the list that was returned by **GetEffectsList**. The APO uses this event until either **GetEffectsList** is called again, or the APO is destroyed. The passed handle can be NULL, in which case the APO stops using any previous handle and does not signal an event.

An APO implements this method to allow Windows to discover the current effects applied by the APO. The list of effects may depend on the processing mode that the APO initialized, and on any end user configuration. The processing mode is indicated by the *AudioProcessingMode* member of [APOInitSystemEffects2](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitsystemeffects2).

APOs should identify effects using GUIDs defined by Windows, such as AUDIO_EFFECT_TYPE_ACOUSTIC_ECHO_CANCELLATION. An APO should only define and return a custom GUID in rare cases where the type of effect is clearly different from the ones defined by Windows.

## See also

[APOInitSystemEffects2](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitsystemeffects2)

[IAudioSystemEffects2](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nn-audioenginebaseapo-iaudiosystemeffects2)