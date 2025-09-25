# _D3DHAL_DP2INDEXEDTRIANGLESTRIP structure

## Description

One or more D3DHAL_DP2INDEXEDTRIANGLESTRIP structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_INDEXEDTRIANGLESTRIP, and are used to render strips of connected triangles using vertex indices.

## Members

### `wV`

Specifies the index into the vertex buffer containing coordinate data for the first vertex of the triangle strip.

Although this member has only enough space to contain three indexes, this array of indexes should be treated as a variable-sized array with (**wPrimitiveCount** + 2) elements. (**wPrimitiveCount** is a member of the D3DHAL_DP2COMMAND structure.)

## Remarks

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process (**wPrimitiveCount**+2) indexes from the command buffer, in effect, processing **wPrimitiveCount** D3DHAL_DP2INDEXEDTRIANGLESTRIP structures.

The triangle edges in a triangle strip are rendered in this order: (**wV[**0**]**, **wV[**1**]**, **wV[**2**]**), (**wV[**1**]**, **wV[**3**]**, **wV[**2**]**), (**wV[**2**]**, **wV[**3**]**, **wV[**4**]**), (**wV[**3**]**, **wV[**5**]**, **wV[**4**]**),...

For the last triangle in the triangle strip, however, the edges are rendered in different orders when **wPrimitiveCount**t is odd and when it is even.

* When **wPrimitiveCount** is an odd number, the last triangle's edges are rendered in this order: (**wV[wPrimitiveCount** - 1**]**, **wV[wPrimitiveCount]**, **wV[wPrimitiveCount**+ 1**]**).
* When **wPrimitiveCount** is an even number, the last triangle's edges are rendered in this order: (**wV[wPrimitiveCount**- 1**]**, **wV[wPrimitiveCount**+1**]**, **wV[wPrimitiveCount**).

A [D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex) structure immediately follows the command in the command buffer. The vertex buffer indexes are relative to the vertex buffer offset specified by the **dwVertexOffset** member of the [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) structure plus the base offset obtained from the **wVStart** member of the D3DHAL_DP2STARTVERTEX structure.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_INDEXEDTRIANGLESTRIP command, a D3DHAL_DP2STARTVERTEX offset of zero, and a logical list of D3DHAL_DP2INDEXEDTRIANGLESTRIP structures. The driver should process five vertices from the vertex buffer, rendering a strip of three triangles defined by (v[1], v[3], v[6]), (v[3], v[4], v[6]), (v[6], v[4], v[5]).

![Figure showing a buffer with a D3DDP2OP_INDEXEDTRIANGLESTRIP command, a D3DHAL_DP2STARTVERTEX offset of zero, and a logical list of D3DHAL_DP2INDEXEDTRIANGLESTRIP structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2tstrp.png)

## See also

D3DDP2OP_INDEXEDTRIANGLESTRIP

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)