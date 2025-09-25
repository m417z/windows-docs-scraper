## Description

Represents a System Effects Audio Processing Object (sAPO) audio effect.

## Members

### `id`

The GUID identifier for an audio effect. Audio effect GUIDs are defined in [ksmedia.h](https://learn.microsoft.com/windows-hardware/drivers/audio/ksmedia-h).

### `canSetState`

A boolean value specifying whether the effect state can be modified.

### `state`

A member of the [AUDIO_SYSTEMEFFECT_STATE](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ne-audioengineextensionapo-audio_systemeffect_state) enumeration specifying the state of the audio effect.

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also