# PFND3DDDI_DXVAHD_SETVIDEOPROCESSBLTSTATE callback function

## Description

The *SetVideoProcessBltState* function sets the state of a bit-block transfer (bitblt) for a video processor.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

*hDevice* [in]

A handle to the display device (graphics context).

*pData* [in]

A pointer to a [D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate) structure that describes how to change the bitblt state.

## Return value

*SetVideoProcessBltState* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The bitblt state is successfully set.|
|E_OUTOFMEMORY|SetVideoProcessBltState could not allocate the required memory for it to complete.|

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate)