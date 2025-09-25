# _HDAUDIO_CODEC_TRANSFER structure

## Description

The HDAUDIO_CODEC_TRANSFER structure specifies a codec command and the response to that command.

## Members

### `Output`

Specifies a codec command for the HD Audio bus driver to output to a codec that is attached to the HD Audio controller. This member is a structure of type [HDAUDIO_CODEC_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_command). Before calling the [TransferCodecVerbs](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs) routine, the caller writes a codec command to this member.

### `Input`

Specifies the response to the codec command. This member is a structure of type [HDAUDIO_CODEC_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_response). The HD Audio bus driver retrieves the response to the codec command that is contained in the **Output** member and writes the response into the **Input** member.

## Remarks

This structure is used by the **TransferCodecVerbs** routine:

* At entry, the **Output** member contains a codec command from the caller.
* Upon return, the **Input** member contains the response to the codec command.

## See also

[HDAUDIO_CODEC_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_command)

[HDAUDIO_CODEC_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_response)

[TransferCodecVerbs](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs)