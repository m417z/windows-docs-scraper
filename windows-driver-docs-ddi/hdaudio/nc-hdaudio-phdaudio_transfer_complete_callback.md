# PHDAUDIO_TRANSFER_COMPLETE_CALLBACK callback function

## Description

HDAudio codec transfer complete callback function. **PHDAUDIO_TRANSFER_COMPLETE_CALLBACK** is used by the [PTRANSFER_CODEC_VERBS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs) callback function.

## Parameters

### `unnamedParam1`

**Context** - This is the same context value that was specified previously in the [PTRANSFER_CODEC_VERBS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs) routine's callbackContext parameter.

### `unnamedParam2`

**pHDAudioCodecTransfer** - A pointer to the codecTransfer array element that contains the codec command and the response that triggered the callback.

## Remarks

For more information, see [PTRANSFER_CODEC_VERBS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs).

## See also

[hdaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/)