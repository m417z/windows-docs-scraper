# PFND3D11_1DDI_DESTROYVIDEOPROCESSORENUM callback function

## Description

Releases resources for the video processor enumeration object that were created through a call to the [CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum) function.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hProcessorEnum* [in]

A handle to the driver's private data for the video processor enumeration object. This handle was created by the Direct3D runtime and passed to the driver in the call to [CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum).

## See also

[CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum)