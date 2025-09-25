# PFND3D11_1DDI_DESTROYVIDEOPROCESSORINPUTVIEW callback function

## Description

Releases resources for the video processor input view that were created through a call to the [CreateVideoProcessorInputView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorinputview) function.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hView* [in]

A handle to the driver's private data for the video processor input view. This handle was created by the Direct3D runtime and passed to the driver in the call to [CreateVideoProcessorInputView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorinputview).