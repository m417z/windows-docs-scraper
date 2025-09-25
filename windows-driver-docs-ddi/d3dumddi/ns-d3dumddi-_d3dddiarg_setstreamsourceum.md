# _D3DDDIARG_SETSTREAMSOURCEUM structure

## Description

The D3DDDIARG_SETSTREAMSOURCEUM structure describes the vertex stream to bind to a user-memory buffer.

## Members

### `Stream` [in]

The index, starting from zero, for the vertex stream to bind to a user-memory buffer.

### `Stride` [in]

The size, in bytes, from one vertex to the next vertex in the stream. In contrast to the call to the [SetStreamSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsource) function, **Stride** cannot be set to zero. Because only one stream can be bound to a user memory buffer, each vertex in the stream must receive different data for processing.

The **Stride** value must be DWORD-aligned.

## Remarks

In a call to the user-mode display driver's [SetStreamSourceUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsourceum) function, a pointer to a D3DDDIARG_SETSTREAMSOURCEUM structure is passed in the *pData* parameter. The Microsoft Direct3D runtime supplies vertex data for the vertex stream through the *pUMBuffer* parameter in a call to the user-mode display driver's **SetStreamSourceUM** function.

## See also

[SetStreamSourceUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsourceum)