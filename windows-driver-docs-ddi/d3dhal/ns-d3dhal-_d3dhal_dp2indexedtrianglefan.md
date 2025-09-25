# _D3DHAL_DP2INDEXEDTRIANGLEFAN structure

## Description

D3DHAL_DP2INDEXEDTRIANGLEFAN is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_INDEXEDTRIANGLEFAN, and is used to render a sequence of connected triangles using vertex indices. All of the triangles share a common vertex.

## Members

### `wV`

Specifies the indexes into the vertex buffer from which the driver obtains coordinate data for the vertices making up the triangle fan.

Although this member has only enough space to contain three indexes, this array of indexes should be treated as a variable-sized array with (**wPrimitiveCount** + 2) elements. (**wPrimitiveCount** is a member of the D3DHAL_DP2COMMAND structure.)

## Remarks

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process (**wPrimitiveCount**+2) indexes from the command buffer, in effect, processing **wPrimitiveCount** D3DHAL_DP2INDEXEDTRIANGLEFAN structures. The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

The driver should process a total of (**wPrimitiveCount** + 2) vertices from the vertex buffer, three vertices per triangle. The sequence of triangles rendered is: (**wV[**1**]**, **wV[**2**]**, **wV[**0**]**), (**wV[**2**]**, **wV[**3**]**, **wV[**0**]**), (**wV[**3**]**, **wV[**4**]**, **wV[**0**]**), ..., (**wV[wPrimitiveCount]**, **wV[wPrimitiveCount]**+1**]**, **wV[**0**]**). Notice that all of the triangles have the vertex specified in **wV[**0**]**in common.

A [D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex) structure immediately follows the command in the command buffer. The vertex buffer indexes are relative to the vertex buffer offset specified by the **dwVertexOffset** member of the [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) structure plus the base offset obtained from the **wVStart** member of the D3DHAL_DP2STARTVERTEX structure.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_INDEXEDTRIANGLEFAN command, a D3DHAL_DP2STARTVERTEX offset, and a logical list of D3DHAL_DP2INDEXEDTRIANGLEFAN structures. The driver should process five vertices from the vertex buffer, rendering a fan with three triangles defined by (v[4], v[5], v[7]), (v[5], v[6], v[7]), (v[6], v[9], v[7]).

![Figure showing a buffer with a D3DDP2OP_INDEXEDTRIANGLEFAN command, a D3DHAL_DP2STARTVERTEX offset, and a list of D3DHAL_DP2INDEXEDTRIANGLEFAN structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2tfani.png)

## See also

D3DDP2OP_INDEXEDTRIANGLEFAN

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)