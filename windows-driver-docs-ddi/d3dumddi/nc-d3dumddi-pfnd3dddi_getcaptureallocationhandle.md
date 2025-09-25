# PFND3DDDI_GETCAPTUREALLOCATIONHANDLE callback function

## Description

The *GetCaptureAllocationHandle* function maps the given capture resource handle to a kernel-mode allocation handle.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_GETCAPTUREALLOCATIONHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaptureallocationhandle) structure that describes parameters for retrieving an allocation handle from a capture resource handle.

## Return value

*GetCaptureAllocationHandle* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The given resource is in GPU-accessible memory.|
|E_OUTOFMEMORY|GetCaptureAllocationHandle could not allocate the required memory for it to complete.|

## See also

[D3DDDIARG_GETCAPTUREALLOCATIONHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaptureallocationhandle)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)