## Description

Implemented by System Effects Audio Processing Object (sAPO) audio effects to allow the caller to get the current list of effects.

## Parameters

### `effects`

Receives a pointer to an array of [AUDIO_SYSTEMEFFECT_STATE](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_systemeffect) structures representing the current list of audio effects.

### `numEffects`

Receives the number of **AUDIO_EFFECT** structures returned in *effects*.

### `event`

The HANDLE of the event that will be signaled if the list changes.

## Return value

An HRESULT.

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also