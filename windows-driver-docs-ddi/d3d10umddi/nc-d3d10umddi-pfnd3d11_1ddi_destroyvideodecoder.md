# PFND3D11_1DDI_DESTROYVIDEODECODER callback function

## Description

Releases resources for the video decoder object that were created through a call to the [CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder) function.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDecoder* [in]

A handle to the driver's private data for the video decoder object. This handle was created by the Direct3D runtime and passed to the driver in the call to [CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder).

## See also

[CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder)