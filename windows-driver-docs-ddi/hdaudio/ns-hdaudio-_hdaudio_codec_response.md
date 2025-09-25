# _HDAUDIO_CODEC_RESPONSE structure

## Description

The HDAUDIO_CODEC_RESPONSE structure specifies either a response to a codec command or an unsolicited response from a codec.

## Members

### `Unsolicited`

Specifies a 32-bit unsolicited response value that consists of a 26-bit response value and a 6-bit tag value.

### `Unsolicited.Response`

Specifies a 21-bit unsolicited response value.

### `Unsolicited.SubTag`

Specifies a 5-bit SubTag.

### `Unsolicited.Tag`

Specifies a 6-bit tag value for an unsolicited response.

### `Response`

Specifies a response value.

#### `SDataIn`

Specifies the 4-bit codec address (SDI line) of the codec that generates the response.

### `IsUnsolicitedResponse`

Specifies whether the response is unsolicited. If 1, the response is unsolicited. If 0, the response is solicited (that is, a response to a codec command).

### `HasFifoOverrun`

Specifies whether a FIFO overrun occurred in the response input ring buffer (RIRB). If 1, a FIFO overrun occurred. If 0, a FIFO overrun did not occur.

### `IsValid`

Specifies whether the response is valid. If 1, the response is valid. If 0, it is not valid.

### `CompleteResponse`

Specifies a complete, 64-bit response summary that consists of a 32-bit response, 4-bit codec address, three status bits, and 25 unused bits (set to zero). This value is mostly used in debug messages.

## Remarks

After calling the [TransferCodecVerbs](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs) routine, function drivers can use the HDAUDIO_CODEC_RESPONSE structure to decode the responses to their codec commands. The commands are contained in the HDAUDIO_CODEC_TRANSFER structures that clients pass to this routine as call parameters.

The callback for the [RegisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback) routine also uses the HDAUDIO_CODEC_RESPONSE structure.

Most members of this structure contain hardware-generated values that the bus driver copies directly from the corresponding RIRB entry. The two exceptions are the values of the **IsValid** and **HasFifoOverrun** members, which the bus driver software writes to the structure to indicate the error status of the response. For information about the RIRB entry format, see the Intel High Definition Audio Specification at the [Intel HD Audio](https://go.microsoft.com/fwlink/p/?linkid=42508) website.

If **IsValid**=0, one of the following has occurred:

* If **HasFifoOverrun**=1, the RIRB FIFO overflowed.
* If **HasFifoOverrun**=0, the codec failed to respond.

The unnamed 25-bitfield between the **UnsolicitedResponse** and **HasFifoOverrun** members is reserved for future expansion. The HD Audio bus controller currently writes zeros to this field.

## See also

[HDAUDIO_CODEC_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_transfer)

[RegisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback)

[TransferCodecVerbs](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs)