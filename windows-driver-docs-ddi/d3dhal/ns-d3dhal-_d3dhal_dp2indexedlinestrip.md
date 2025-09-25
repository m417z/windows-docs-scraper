# _D3DHAL_DP2INDEXEDLINESTRIP structure

## Description

D3DHAL_DP2INDEXEDLINESTRIP is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_INDEXEDLINESTRIP, and is used to render a sequence of connected line segments using vertex indices.

## Members

### `wV`

Specifies the indexes into the vertex buffer from which the driver obtains coordinate data for the vertices making up the line strip.

Although this member has only enough space to hold two indexes, this array of indexes should be treated as a variable-sized array with (**wPrimitiveCount**+ 1) elements. (**wPrimitiveCount** is a member of the D3DHAL_DP2COMMAND structure.)

## Remarks

Indexed line strips rendered with vertex buffers are specified using D3DHAL_DP2INDEXEDLINESTRIP. The number of line segments to process is specified by the **wPrimitiveCount** member of D3DHAL_DP2COMMAND. The sequence of line segments rendered is: (**wV[**0**]**, **wV[**1**]**), (**wV[**1**]**, **wV[**2**]**), (**wV[**2**]**, **wV[**3**]**), ..., (**wVStart[wPrimitiveCount** -1**]**, **wVStart[wPrimitiveCount]**).

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process (**wPrimitiveCount**+1) indexes from the command buffer, in effect processing **wPrimitiveCount** D3DHAL_DP2INDEXEDLINESTRIP structures. The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

A [D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex) structure immediately follows the command in the command buffer. The vertex buffer indexes are relative to the vertex buffer offset specified by the **dwVertexOffset** member of the [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) structure plus the base offset obtained from the **wVStart** member of the D3DHAL_DP2STARTVERTEX structure.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_INDEXEDLINESTRIP command, a D3DHAL_DP2STARTVERTEX offset, and a list of D3DHAL_DP2INDEXEDLINESTRIP structures. The driver should process four vertices from the vertex buffer, rendering three connected line segments defined by (v[8], v[4]), (v[4], v[7]), (v[7], v[6]).

![Figure showing a buffer with a D3DDP2OP_INDEXEDLINESTRIP command, a D3DHAL_DP2STARTVERTEX offset, and a list of D3DHAL_DP2INDEXEDLINESTRIP structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2lstri.png)

## See also

D3DDP2OP_INDEXEDLINESTRIP

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)