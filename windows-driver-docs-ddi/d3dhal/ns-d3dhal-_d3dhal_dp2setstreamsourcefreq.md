# _D3DHAL_DP2SETSTREAMSOURCEFREQ structure

## Description

 DirectX 9.0 and later versions only.

The D3DHAL_DP2SETSTREAMSOURCEFREQ structure is used to set the frequency divisor of a stream source that is bound to a vertex buffer for [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwStream`

Specifies the data stream, in the range from 0 to the maximum number of streams -1, whose frequency is being modified.

### `dwDivider`

Specifies the frequency divisor, which is the number of vertices after which data from the given stream is fetched into the vertex shader. This number can be greater than zero and at most 2^16-1 (WORD).

## Remarks

A driver is requested to set a stream's frequency divisor through the D3DDP2OP_SETSTREAMSOURCEFREQ operation code.

A driver for a device that supports vertex shader version 3.0 and later can implement stream frequency division. For more information, see [Modifying Vertex Stream Frequency](https://learn.microsoft.com/windows-hardware/drivers/display/modifying-vertex-stream-frequency).

## See also

D3DDP2OP_SETSTREAMSOURCEFREQ

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)