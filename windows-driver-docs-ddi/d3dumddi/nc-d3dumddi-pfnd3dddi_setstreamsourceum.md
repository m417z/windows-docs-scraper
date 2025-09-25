# PFND3DDDI_SETSTREAMSOURCEUM callback function

## Description

The *SetStreamSourceUM* function binds a vertex stream source to a user memory buffer.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETSTREAMSOURCEUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setstreamsourceum) structure that specifies the vertex stream source to bind.

### `unnamedParam3`

*pUMBuffer* [in]

A pointer to the user-memory buffer that supplies the vertex data for the vertex stream source.

## Return value

*SetStreamSourceUM* returns S_OK or an appropriate error result if the vertex stream source is not successfully bound.

## See also

[D3DDDIARG_SETSTREAMSOURCEUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setstreamsourceum)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)