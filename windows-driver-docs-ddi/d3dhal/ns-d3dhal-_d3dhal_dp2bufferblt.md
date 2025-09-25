# _D3DHAL_DP2BUFFERBLT structure

## Description

 DirectX 8.0 and later versions only.

D3DHAL_DP2BUFFERBLT is used for vertex or index buffer blts when [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) responds to the D3DDP2OP_BUFFERBLT command token.

## Members

### `dwDDDestSurface`

Specifies the handle to the destination vertex or index buffer.

### `dwDDSrcSurface`

Specifies the handle to the source vertex or index buffer.

### `dwOffset`

Specifies the offset, in bytes, of the destination buffer the copy should be directed into.

### `rSrc`

Specifies what range of the source buffer should be copied. This is a D3DRANGE structure, which is described in the Microsoft Windows SDK documentation, and contains a UINT offset in bytes and a UINT size in bytes.

### `dwFlags`

Unused.

## Remarks

The [CreateD3DBuffer](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurface) callback creates the small integer handles to the vertex or index buffers that can be used as source and destination buffers for buffer blts.

See Remarks for [D3DHAL_DP2TEXBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2texblt).

## See also

[CreateD3DBuffer](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurface)

D3DDP2OP_BUFFERBLT

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)