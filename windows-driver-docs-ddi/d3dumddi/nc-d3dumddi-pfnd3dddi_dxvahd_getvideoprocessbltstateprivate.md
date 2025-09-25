# PFND3DDDI_DXVAHD_GETVIDEOPROCESSBLTSTATEPRIVATE callback function

## Description

The *GetVideoProcessBltStatePrivate* function retrieves the state data of a private bit-block transfer (bitblt) for a video processor.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

*hDevice* [in]

A handle to the display device (graphics context).

*pData* [in, out]

A pointer to a [D3DDDIARG_DXVAHD_GETVIDEOPROCESSBLTSTATEPRIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_getvideoprocessbltstateprivate) structure that describes the private bitblt state data to retrieve.

## Return value

The *GetVideoProcessBltStatePrivate* function returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The bitblt state data is successfully retrieved.|
|E_OUTOFMEMORY|GetVideoProcessBltStatePrivate could not allocate the required memory for it to complete.|

## See also

[D3DDDIARG_DXVAHD_GETVIDEOPROCESSBLTSTATEPRIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_getvideoprocessbltstateprivate)