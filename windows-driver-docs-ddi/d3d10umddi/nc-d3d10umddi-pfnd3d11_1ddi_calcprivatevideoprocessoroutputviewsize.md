# PFND3D11_1DDI_CALCPRIVATEVIDEOPROCESSOROUTPUTVIEWSIZE callback function

## Description

Returns the number of bytes that the driver requires to store private data for the video processor output view state.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pView* [in]

A pointer to a [D3D11_1DDIARG_CREATEVIDEOPROCESSOROUTPUTVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessoroutputview) structure that describes the video processor output view.

## Return value

The required number of bytes for the video processor output view state.

## Remarks

The runtime will validate the members of the [D3D11_1DDIARG_CREATEVIDEOPROCESSOROUTPUTVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessoroutputview) structure before it calls this function. In particular, the runtime verifies that the specified view is supported as a video processor output format and the **D3D11_DDI_BIND_RENDER_TARGET** flag is set.

This function is not expected to fail.

## See also

[D3D11_1DDIARG_CREATEVIDEOPROCESSOROUTPUTVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessoroutputview)