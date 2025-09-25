# _DXVADDI_SAMPLEFORMAT enumeration

## Description

The DXVADDI_SAMPLEFORMAT enumeration type contains values that identify how a video frame is sampled.

## Constants

### `DXVADDI_SampleFormatMask`

The sample format mask. The first 8 (0xFF) bits of a DWORD can be used to specify input sample format.

### `DXVADDI_SampleUnknown`

The sample format is unknown.

### `DXVADDI_SampleProgressiveFrame`

The sample contains a progressive frame.

### `DXVADDI_SampleFieldInterleavedEvenFirst`

The sample contains two interleaved fields; the even field is temporally first.

### `DXVADDI_SampleFieldInterleavedOddFirst`

The sample contains two interleaved fields; the odd field is temporally first.

### `DXVADDI_SampleFieldSingleEven`

The sample contains an even interleaved field.

### `DXVADDI_SampleFieldSingleOdd`

The sample contains an odd interleaved field.

### `DXVADDI_SampleSubStream`

The sample contains a video substream.

## Remarks

One of the values of DXVADDI_SAMPLEFORMAT can be specified in the **SampleFormat** member of the [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat) structure.

## See also

[DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat)