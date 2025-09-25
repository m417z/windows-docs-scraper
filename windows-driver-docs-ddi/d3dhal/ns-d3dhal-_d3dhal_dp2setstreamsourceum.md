# _D3DHAL_DP2SETSTREAMSOURCEUM structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2SETSTREAMSOURCEUM structure is used to bind a vertex stream source to a user memory buffer for [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwStream`

Specifies the stream being bound. For DirectX 8.0 it is always zero.

### `dwStride`

Specifies the vertex size in bytes.

## Remarks

In addition to binding a stream to a vertex buffer, it is possible for the vertex data of stream zero to be supplied in a user memory (UM) buffer. In this case, another DP2 token is used to notify the driver of stream binding. That token is D3DDP2OP_SETSTREAMSOURCEUM.

DirectX 8.0 does not support multiple vertex streams with user supplied buffers rather than vertex buffers. Additionally, it is not possible to mix user memory buffers with vertex buffers. When a user memory buffer is supplied, it is guaranteed to be stream zero and to be the only stream that should be accessed by subsequent drawing primitives. It is possible that other streams have non-NULL vertex buffers bound to them at the time when a user memory buffer is bound to stream. However, those other streams must be ignored by the driver and hardware.

The actual user memory pointer to the vertex data should be extracted from the [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) passed when actually drawing primitives.

## See also

D3DDP2OP_SETSTREAMSOURCEUM

[D3DHAL_DP2SETSTREAMSOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2setstreamsource)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)