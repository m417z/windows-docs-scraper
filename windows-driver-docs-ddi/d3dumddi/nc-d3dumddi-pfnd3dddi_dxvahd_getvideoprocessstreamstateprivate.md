# PFND3DDDI_DXVAHD_GETVIDEOPROCESSSTREAMSTATEPRIVATE callback function

## Description

The *GetVideoProcessStreamStatePrivate* function retrieves the private stream-state data for a video processor.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

*hDevice* [in]

A handle to the display device (graphics context).

*pData* [in, out]

A pointer to a [D3DDDIARG_DXVAHD_GETVIDEOPROCESSSTREAMSTATEPRIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_getvideoprocessstreamstateprivate) structure that describes the private stream-state data to retrieve.

## Return value

The *GetVideoProcessStreamStatePrivate* function returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The stream-state data is successfully retrieved.|
|E_OUTOFMEMORY|GetVideoProcessStreamStatePrivate could not allocate the required memory for it to complete.|

## See also

[D3DDDIARG_DXVAHD_GETVIDEOPROCESSSTREAMSTATEPRIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_getvideoprocessstreamstateprivate)