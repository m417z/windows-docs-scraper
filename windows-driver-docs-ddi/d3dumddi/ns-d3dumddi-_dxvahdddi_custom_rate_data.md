# _DXVAHDDDI_CUSTOM_RATE_DATA structure

## Description

The DXVAHDDDI_CUSTOM_RATE_DATA structure describes the video content that a decode device processes.

## Members

### `CustomRate`

 [in] A [DXVAHDDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_rational) structure that specifies a fractional value that represents the input and output frame rate.

### `OutputFrames` [in]

The number of frames that the driver outputs.

### `InputInterlaced` [in]

A Boolean value that specifies whether the input stream is progressive (frame) or interlaced (field).

### `InputFramesOrFields` [in]

The number of the input frames or fields.

## Remarks

The driver can expose custom rates for the frame rate conversion or the inverse telecine. For example, the driver can provide the following information in the members of DXVAHDDDI_CUSTOM_RATE_DATA for the indicated operation:

## See also

[DXVAHDDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_rational)