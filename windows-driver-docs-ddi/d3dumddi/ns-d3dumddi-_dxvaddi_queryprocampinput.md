# _DXVADDI_QUERYPROCAMPINPUT structure

## Description

The DXVADDI_QUERYPROCAMPINPUT structure describes a ProcAmp control property on a video stream that range information is requested for.

## Members

### `pVideoProcGuid` [in]

A pointer to a GUID that represents the video processing device type.

### `VideoDesc` [in]

A [DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc) structure that describes the video stream.

### `RenderTargetFormat` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the render target for the video processing device.

### `ProcAmpCap` [in]

A ProcAmp control property that range information is requested for. The ProcAmp control property can be one of the members of the [DXVADDI_PROCAMPVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_procampvalues) structure.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[DXVADDI_PROCAMPVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_procampvalues)

[DXVADDI_VALUERANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_valuerange)

[DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)