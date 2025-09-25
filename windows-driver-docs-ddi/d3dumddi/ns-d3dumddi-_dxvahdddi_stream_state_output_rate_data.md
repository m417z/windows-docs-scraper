# _DXVAHDDDI_STREAM_STATE_OUTPUT_RATE_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_OUTPUT_RATE_DATA structure describes stream-state data that specifies the output rate of the input stream.

## Members

### `RepeatFrame` [in]

A Boolean value that specifies whether the frame rate conversion repeats or interpolates the frames. The driver refers to **RepeatFrame** only when it uses the frame rate conversion. The default value is **FALSE**, which indicates that the frame rate conversion interpolates the frames.

### `OutputRate` [in]

A [DXVAHDDDI_OUTPUT_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_output_rate)-typed value that indicates the output rate of the input stream. The default value is DXVAHDDDI_OUTPUT_RATE_NORMAL.

### `CustomRate` [in]

A [DXVAHDDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_rational) structure that specifies a fractional value that represents a custom output rate. The driver refers to **CustomRate** only when the value that is specified in **OutputRate** is DXVAHDDDI_OUTPUT_RATE_CUSTOM. The default value is 1/1.

## Remarks

The driver uses the **RepeatFrame** member to control the frame rate conversion. For example, when the driver converts from 60i to 60p, if the video processor is capable of both the inverse telecine (60i to 24p) and the frame rate conversion (24p to 60p), then the converted frames contains interpolated frames. Sometimes the interpolation results in artifacts, and the application might require to repeat the frames instead.

The **CustomRate** member must specify one of the custom rates that the driver supplied in the members of the [DXVAHDDDI_CUSTOM_RATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_custom_rate_data) structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function was called with the D3DDDICAPS_DXVAHD_GETVPCUSTOMRATES value set; otherwise, the driver's [SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate) function returns an error.

## See also

[DXVAHDDDI_CUSTOM_RATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_custom_rate_data)

[DXVAHDDDI_OUTPUT_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_output_rate)

[DXVAHDDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_rational)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)

[SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate)