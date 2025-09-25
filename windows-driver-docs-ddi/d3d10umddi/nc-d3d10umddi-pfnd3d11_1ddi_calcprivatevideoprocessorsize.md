# PFND3D11_1DDI_CALCPRIVATEVIDEOPROCESSORSIZE callback function

## Description

Returns the number of bytes that the driver requires to store private data for the video processor state.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pVideoProcessor* [in]

A pointer to a [D3D11_1DDIARG_CREATEVIDEOPROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessor) structure that describes the video processor.

## Return value

The required number of bytes for the video processor state.

## Remarks

This function is not expected to fail.

## See also

[D3D11_1DDIARG_CREATEVIDEOPROCESSOROUTPUTVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessoroutputview)