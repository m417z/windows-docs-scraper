## Description

Implemented by System Effects Audio Processing Object (sAPO) audio effects to allow the caller to set the state of effects.

## Parameters

### `effectId`

The GUID identifier for an audio effect. Audio effect GUIDs are defined in [ksmedia.h](https://learn.microsoft.com/windows-hardware/drivers/audio/ksmedia-h).

### `state`

A value from the [AUDIO_SYSTEMEFFECT_STATE](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ne-audioengineextensionapo-audio_systemeffect_state) enumerating specifying the state to set.

## Return value

An HRESULT.

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also