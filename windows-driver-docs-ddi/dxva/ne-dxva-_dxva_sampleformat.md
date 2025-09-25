# _DXVA_SampleFormat enumeration

## Description

The DXVA_SampleFormat enumeration type describes the format of data that the input sample contains.

## Constants

### `DXVA_SampleFormatMask`

Specifies the sample format mask. The first 8 (0x000000FF) bits of a DWORD can be used to specify input sample format.

### `DXVA_SampleUnknown`

Specifies that the sample format is unknown.

### `DXVA_SamplePreviousFrame`

Specifies that the sample contains the previous output frame.

### `DXVA_SampleProgressiveFrame`

Specifies that the sample contains a progressive frame.

### `DXVA_SampleFieldInterleavedEvenFirst`

Specifies that the sample contains two interleaved fields; the even field is temporally first.

### `DXVA_SampleFieldInterleavedOddFirst`

Specifies that the sample contains two interleaved fields; the odd field is temporally first.

### `DXVA_SampleFieldSingleEven`

Specifies that the sample contains an even interleaved field.

### `DXVA_SampleFieldSingleOdd`

Specifies that the sample contains an odd interleaved field.

### `DXVA_SampleSubStream`

Windows Server 2003 SP1 and later and Windows XP SP2 and later versions only.

Specifies that the sample contains a video substream.

## See also

[DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat)

[DXVA_VideoSample](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videosample)

[DXVA_VideoSample2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videosample2)