# PFND3D11_1DDI_CALCPRIVATEVIDEOPROCESSORENUMSIZE callback function

## Description

Returns the number of bytes that the driver requires to store private data for the video processor enumeration state.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pProcessorEnum* [in]

A pointer to a [D3D11_1DDIARG_CREATEVIDEOPROCESSORENUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessorenum) structure that describes the video processor enumeration object that was created through the [CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum) function.

## Return value

The required number of bytes for the video processor enumeration state.

## Remarks

This function is not expected to fail.

## See also

[CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum)

[D3D11_1DDIARG_CREATEVIDEOPROCESSORENUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessorenum)