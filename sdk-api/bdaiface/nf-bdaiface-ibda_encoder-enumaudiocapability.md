# IBDA_Encoder::EnumAudioCapability

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets one of the audio formats supported by the device.

## Parameters

### `FmtIndex` [in]

The zero-based index of the audio format to retrieve. To get the number of audio formats, call [IBDA_Encoder::QueryCapabilities](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_encoder-querycapabilities).

### `MethodID` [out]

Receives a value that uniquely identifies this audio method.

### `AlgorithmType` [out]

Receives the type of encoding algorithm. The following values are defined.

| Value | Meaning |
| --- | --- |
| **PBDA_Encoder_Audio_AlgorithmType_MPEG1LayerII**<br><br>0x00000000 | MPEG-1 Layer II. |
| **PBDA_Encoder_Audio_AlgorithmType_AC3**<br><br>0x00000001 | Dolby AC3. |

### `SamplingRate` [out]

Receives the audio sampling rate, in Hz.

### `BitDepth` [out]

Receives the number of bits per audio sample.

### `NumChannels` [out]

Receives the number of audio channels.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_Encoder](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_encoder)