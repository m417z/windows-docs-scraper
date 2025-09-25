# PFND3DDDI_SETSTREAMSOURCE callback function

## Description

The *SetStreamSource* function binds a portion of a vertex stream source to a vertex buffer.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETSTREAMSOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setstreamsource) structure that specifies the portion of the vertex stream source to bind.

## Return value

*SetStreamSource* returns S_OK or an appropriate error result if the portion of the vertex stream source is not successfully bound.

## Remarks

The Microsoft Direct3D runtime calls the user-mode display driver's *SetStreamSource* function to store vertex data of multiple vertex formats in a single vertex data stream. The runtime notifies the driver of where vertex data of a particular format is located in the vertex data stream by supplying the stream offset, in bytes, to the beginning of that vertex data.

## See also

[D3DDDIARG_SETSTREAMSOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setstreamsource)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)