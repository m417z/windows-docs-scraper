# IBDA_Encoder::EnumVideoCapability

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets one of the video formats supported by the device.

## Parameters

### `FmtIndex` [in]

The zero-based index of the video format to retrieve. To get the number of video formats, call [IBDA_Encoder::QueryCapabilities](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_encoder-querycapabilities).

### `MethodID` [out]

Receives a value that uniquely identifies this video method.

### `AlgorithmType` [out]

Receives the type of encoding algorithm. The following values are defined.

| Value | Meaning |
| --- | --- |
| **PBDA_Encoder_Video_MPEG2PartII**<br><br>0x00000000 | MPEG-2, Part 2. |
| **PBDA_Encoder_Video_MPEG4Part10**<br><br>0x00000001 | MPEG-4, Part 10. |
| **PBDA_Encoder_Video_AVC**<br><br>0x00000001 | AVC video. |
| **PBDA_Encoder_Video_H264**<br><br>0x00000001 | H.264 video. |

### `VerticalSize` [out]

Receives the vertical_size_value field.

### `HorizontalSize` [out]

Receives the horizontal_size_value field.

### `AspectRatio` [out]

Receives the aspect_ratio_information field.

### `FrameRateCode` [out]

Receives the frame_rate_code field.

### `ProgressiveSequence` [out]

Receives the progressive_sequence field.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *VerticalSize*, *HorizontalSize*, *AspectRatio*, *FrameRateCode*, and *ProgressiveSequence* parameters are interpreted according to the ANSI/SCTE 43 2005 standard.

## See also

[IBDA_Encoder](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_encoder)