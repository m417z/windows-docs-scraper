# _D3DHAL_DP2SETSTREAMSOURCE2 structure

## Description

 DirectX 9.0 and later versions only.

The D3DHAL_DP2SETSTREAMSOURCE2 structure is used to bind a portion of a vertex stream source to a vertex buffer for [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwStream`

Specifies the stream being bound. It has a value between zero and the maximum number of streams specified by the driver.

### `dwVBHandle`

Specifies the vertex buffer handle. It is legal for the vertex buffer handle to be zero, in which case the stream is no longer bound to a vertex buffer.

### `dwOffset`

Specifies the offset of the first vertex size in bytes.

### `dwStride`

Specifies the vertex size in bytes.

## See also

D3DDP2OP_SETSTREAMSOURCE2

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)