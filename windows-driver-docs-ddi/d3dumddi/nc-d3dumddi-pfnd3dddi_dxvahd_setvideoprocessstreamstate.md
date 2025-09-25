# PFND3DDDI_DXVAHD_SETVIDEOPROCESSSTREAMSTATE callback function

## Description

The *SetVideoProcessStreamState* function sets the stream state for a video processor.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

*hDevice* [in]

A handle to the display device (graphics context).

*pData* [in]

A pointer to a [D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessstreamstate) structure that describes how to change the stream state.

## Return value

The *SetVideoProcessStreamState* function returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The stream state is successfully set.|
|E_OUTOFMEMORY|SetVideoProcessStreamState could not allocate the required memory for it to complete.|

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessstreamstate)