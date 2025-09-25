# _DXVADDI_VIDEOPROCESSORINPUT structure

## Description

The DXVADDI_VIDEOPROCESSORINPUT structure describes a video stream that is processed by a video processing device type.

## Members

### `pVideoProcGuid` [in]

A pointer to a GUID that represents the video processing device type.

### `VideoDesc` [in]

A [DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc) structure that describes the video stream.

### `RenderTargetFormat` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the render target for the video processing device.

## Remarks

When the D3DDDICAPS_GETVIDEOPROCESSORRTFORMATCOUNT, D3DDDICAPS_GETVIDEOPROCESSORRTFORMATS, D3DDDICAPS_GETVIDEOPROCESSORRTSUBSTREAMFORMATCOUNT, or D3DDDICAPS_GETVIDEOPROCESSORRTSUBSTREAMFORMATS [D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)-type value is sent in a call to the user-mode display driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function, the driver ignores the **RenderTargetFormat** member of DXVADDI_VIDEOPROCESSORINPUT.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc)

[DXVADDI_VIDEOPROCESSORCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videoprocessorcaps)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)