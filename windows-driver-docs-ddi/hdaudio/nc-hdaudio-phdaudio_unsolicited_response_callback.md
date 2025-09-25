# PHDAUDIO_UNSOLICITED_RESPONSE_CALLBACK callback function

## Description

HDAudio codec unsolicited response callback function. **PHDAUDIO_UNSOLICITED_RESPONSE_CALLBACK** is used by the [PREGISTER_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback) callback function.

## Parameters

### `unnamedParam1`

**Context** - This is the callbackContext value that was passed previously to [PREGISTER_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback).

### `unnamedParam2`

**HDAudioCodecResponse** - This is a structure of type [HDAUDIO_CODEC_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_response) that specifies the codec's response to the command. This structure is passed by value.

## Remarks

The HD Audio bus driver calls the callback routine at PASSIVE_LEVEL.

## See also

[hdaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/)