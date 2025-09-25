# DXVA2_SampleFormat enumeration

## Description

Describes the content of a video sample. These flags are used in the [DXVA2_ExtendedFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_extendedformat) structure.

## Constants

### `DXVA2_SampleFormatMask:0xff`

Bitmask to validate flag values. This value is not a valid flag.

### `DXVA2_SampleUnknown:0`

Unknown format. Default to DXVA2_SampleProgressiveFrame.

### `DXVA2_SampleProgressiveFrame:2`

The sample contains a progressive (non-interlaced) frame.

### `DXVA2_SampleFieldInterleavedEvenFirst:3`

The sample contains two interleaved fields. The even field should be displayed first.

### `DXVA2_SampleFieldInterleavedOddFirst:4`

The sample contains two interleaved fields. The odd field should be displayed first.

### `DXVA2_SampleFieldSingleEven:5`

The sample contains a single even field.

### `DXVA2_SampleFieldSingleOdd:6`

The sample contains a single odd field.

### `DXVA2_SampleSubStream:7`

The sample contains a video substream frame. Use this value for substream mixing.

## Remarks

This enumeration is equivalent to the **DXVA_SampleFormat** enumeration used in DXVA 1.0.

The following table shows the mapping from [MFVideoInterlaceMode](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideointerlacemode) enumeration values, which are used in Media Foundation media types, to **DXVA2_SampleFormat** values.

| MFVideoInterlaceMode Value | DXVA2_SampleFormat Value |
| --- | --- |
| MFVideoInterlace_Unknown | DXVA2_SampleUnknown. |
| MFVideoInterlace_Progressive | DXVA2_SampleProgressiveFrame. |
| MFVideoInterlace_FieldInterleavedUpperFirst | DXVA2_SampleFieldInterleavedEvenFirst |
| MFVideoInterlace_FieldInterleavedLowerFirst | DXVA2_SampleFieldInterleavedOddFirst. |
| MFVideoInterlace_FieldSingleUpper | DXVA2_SampleFieldSingleEven. |
| MFVideoInterlace_FieldSingleLower | DXVA2_SampleFieldSingleOdd. |
| MFVideoInterlace_MixedInterlaceOrProgressive | No exact match. Use DXVA2_SampleFieldInterleavedEvenFirst as an initial value, then use the interlace flags from the media samples. For more information, see [Video Interlacing](https://learn.microsoft.com/windows/desktop/medfound/video-interlacing). |

With the exception of MFVideoInterlace_MixedInterlaceOrProgressive, each pair of corresponding enumeration values has the same numeric value.

The value DXVA2_SampleSubStream has no equivalent in the [MFVideoInterlaceMode](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideointerlacemode) enumeration.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)