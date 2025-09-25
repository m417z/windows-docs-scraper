# PFND3DDDI_DEPTHFILL callback function

## Description

The **DepthFill** function fills a depth buffer with a pixel value that is specified in native format.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DEPTHFILL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_depthfill) structure that describes the parameters of the depth-fill operation.

## Return value

**DepthFill** returns one of the following values:

<|Return code|Description|
|--- |--- |
|S_OK|The depth-fill operation was successful.|
|E_OUTOFMEMORY|DepthFill could not allocate the required memory for it to complete.|

## Remarks

DirectX version 7.0 and earlier runtimes call the **DepthFill** function to fill a depth buffer (z-buffer and stencil buffer) with a pixel value that is specified in native format.

## See also

[D3DDDIARG_DEPTHFILL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_depthfill)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)