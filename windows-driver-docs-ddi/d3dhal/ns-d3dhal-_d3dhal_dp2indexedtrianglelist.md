# _D3DHAL_DP2INDEXEDTRIANGLELIST structure

## Description

One or more D3DHAL_DP2INDEXEDTRIANGLELIST structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_INDEXEDTRIANGLELIST, and are used to render a sequence of unconnected triangles using vertex indices.

## Members

### `wV1`

Specifies the index into the vertex buffer location containing coordinate data for the first vertex of the triangle.

### `wV2`

Specifies the index to the vertex buffer location containing coordinate data for the second vertex of the triangle.

### `wV3`

Specifies the index to the vertex buffer location containing coordinate data for the third vertex of the triangle.

### `wFlags`

Specifies the flags that describe how the driver should render the triangle. This member can be a bitwise OR of the following values:

| **Flag** | **Meaning** |
|:--|:--|
| D3DTRIFLAG_EDGEENABLE1 | The driver should render the triangle edge between **wV1** and **wV2** when the fill mode is D3DFILL_WIREFRAME. |
| D3DTRIFLAG_EDGEENABLE2 | The driver should render the triangle edge between **wV2** and **wV3** when the fill mode is D3DFILL_WIREFRAME. |
| D3DTRIFLAG_EDGEENABLE3 | The driver should render the triangle edge between **wV3** and **wV1** when the fill mode is D3DFILL_WIREFRAME. |
| D3DTRIFLAG_EDGEENABLETRIANGLE | The driver should render all triangle edges when the fill mode is D3DFILL_WIREFRAME. |

## Remarks

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process **wPrimitiveCount** * 3 indexes from the command buffer, processing **wPrimitiveCount** D3DHAL_DP2INDEXEDTRIANGLELIST structures. The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

The driver should process a total of **wPrimitiveCount***3 vertices from the vertex buffer, three vertices per triangle, for the current command. The sequence of triangles rendered is (**wV1**₀, **wV2**₀, **wV3**₀), (**wV1**₁, **wV2**₁, **wV3**₁), ..., (**wV1**ₙ, **wV2**ₙ, **wV3**ₙ), where n equals (**wPrimitiveCount**- 1). The driver should calculate the vertex locations based on the current command as follows:

* When the command is D3DDP2OP_INDEXEDTRIANGLELIST, the indexes into the vertex buffer are relative to the vertex buffer offset specified by the dwVertexOffset member of the [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) structure.

* When the command is D3DDP2OP_INDEXEDTRIANGLELIST2, there is a [D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex) structure that immediately follows the command in the command buffer. The indexes into the vertex buffer are relative to the vertex buffer offset specified by dwVertexOffset plus the base offset obtained from the wVStart member of the D3DHAL_DP2STARTVERTEX structure.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_INDEXEDTRIANGLELIST command and two D3DHAL_DP2INDEXEDTRIANGLELIST structures. The driver should draw two triangles âˆ’ with all edges enabled âˆ’ using the following six vertices from the vertex buffer: (v[3], v[4], v[5]), (v[0], v[1], v[2]).

![Figure showing a command buffer with a D3DDP2OP_INDEXEDTRIANGLELIST command and two D3DHAL_DP2INDEXEDTRIANGLELIST structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2tlsi.png)
Similarly, the following figure shows a portion of a sample command buffer containing a D3DDP2OP_INDEXEDTRIANGLELIST2 command, a D3DHAL_DP2STARTVERTEX offset, and two D3DHAL_DP2INDEXEDTRIANGLELIST structures. The driver should process six vertices from the vertex buffer, rendering two triangles defined by (v[5], v[6], v[7]), (v[2], v[3], v[4]).

![Figure showing a buffer with a D3DDP2OP_INDEXEDTRIANGLELIST2 command, a D3DHAL_DP2STARTVERTEX offset, and two D3DHAL_DP2INDEXEDTRIANGLELIST structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2tls2i.png)

## See also

D3DDP2OP_INDEXEDTRIANGLELIST

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)