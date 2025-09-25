# _HDAUDIO_CODEC_COMMAND structure

## Description

The HDAUDIO_CODEC_COMMAND structure specifies a codec command.

## Members

### `Verb8`

Specifies an 8-bit payload command format. The members in the following table are part of the Verb8 structure.

### `Verb8.Data`

Specifies an 8-bit data payload value for the 8-bit payload command format.

### `Verb8.VerbId`

Specifies a 12-bit verb identifier for the 8-bit payload command format.

### `Verb8.Node`

Specifies an 8-bit node identifier for the 8-bit payload command format.

### `Verb8.CodecAddress`

Specifies a 4-bit codec address for the 8-bit payload command format.

### `Verb16`

Specifies an 16-bit payload command format. The members in the following table are part of the Verb16 structure.

### `Verb16.Data`

Specifies an 16-bit data payload value for the 16-bit payload command format.

### `Verb16.VerbId`

Specifies a 4-bit verb identifier for the 16-bit payload command format.

### `Verb16.Node`

Specifies an 8-bit node identifier for the 16-bit payload command format.

### `Verb16.CodecAddress`

Specifies a 4-bit codec address for the 16-bit payload command format.

### `Command`

Specifies a 32-bit codec command that contains payload data, a verb identifier, a node identifier, and a codec address.

## Remarks

Clients call the [TransferCodecVerbs](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs) routine to pass commands to codecs. The commands are in the [HDAUDIO_CODEC_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_transfer) structures that clients pass to this routine as call parameters. Before calling **TransferCodecVerbs**, function drivers can use the HDAUDIO_CODEC_COMMAND structure to encode the codec commands.

The validity of individual members depends on the type of command sent.

## See also

[HDAUDIO_CODEC_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_transfer)

[TransferCodecVerbs](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs)