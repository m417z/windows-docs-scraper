# PFND3DDDI_SETDECODERENDERTARGET callback function

## Description

The *SetDecodeRenderTarget* function sets the render target surface for decoding operations.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETDECODERENDERTARGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setdecoderendertarget) structure that describes the decode render target surface.

## Return value

*SetDecodeRenderTarget* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The render target surface is successfully set.|
|E_OUTOFMEMORY|SetDecodeRenderTarget could not allocate the required memory for it to complete.|

## Remarks

The *SetDecodeRenderTarget* function can be called only outside of a [DecodeBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodebeginframe)/[DecodeEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeendframe) block.

Decode render targets are always created atomically through calls to the [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function, where all of the decode buffers are indexes within a single resource. All decode render targets are created by setting the [D3DDDI_RESOURCEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags).**DecodeRenderTarget** bit-field flag in the **Flags** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure.

## See also

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource)

[D3DDDIARG_SETDECODERENDERTARGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setdecoderendertarget)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[D3DDDI_RESOURCEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags)

[DecodeBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodebeginframe)

[DecodeEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeendframe)