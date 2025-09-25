# _DXVAHDDDI_STREAM_STATE_FRAME_FORMAT_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_FRAME_FORMAT_DATA structure describes data that specifies the frame format of the input.

## Members

### `FrameFormat` [in]

A [DXVAHDDDI_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_frame_format)-typed value that indicates the frame format of the input stream. The default value is DXVAHDDDI_FRAME_FORMAT_PROGRESSIVE, which indicates progressive format.

## Remarks

The Direct3D runtime specifies the DXVAHDDDI_STREAM_STATE_FRAME_FORMAT state in the **State** member of the [D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessstreamstate) structure in a call to the driver's [SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate) function to set the frame format of the input stream.

The driver might not set the DXVAHDDDI_INPUT_FORMAT_CAPS_RGB_INTERLACED value in the **InputFormatCaps** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPDEVCAPS value set. If so and if the input stream is RGB format type, the interlaced frame format is ignored and assumed to be progressive.

The driver also might not set the DXVAHDDDI_INPUT_FORMAT_CAPS_PALETTE_INTERLACED value in the **InputFormatCaps** member of DXVAHDDDI_VPDEVCAPS. If so and if the input stream is palettized format type, the interlaced frame format is ignored and assumed to be progressive.

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessstreamstate)

[DXVAHDDDI_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_frame_format)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)

[SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate)