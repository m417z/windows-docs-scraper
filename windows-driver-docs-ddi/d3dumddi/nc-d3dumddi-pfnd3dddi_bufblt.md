# PFND3DDDI_BUFBLT callback function

## Description

The **BufBlt** function performs a bit-block transfer (bitblt) operation from a source vertex or index buffer to a destination vertex or index buffer.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_BUFFERBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_bufferblt) structure that describes the parameters of the buffer bitblt operation.

## Return value

**BufBlt** returns S_OK or an appropriate error result if the buffer bitblt operation is not successfully performed.

## See also

[D3DDDIARG_BUFFERBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_bufferblt)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)