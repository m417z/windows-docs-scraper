# _D3DHAL_DP2INDEXEDLINELIST structure

## Description

D3DHAL_DP2INDEXEDLINELIST is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_INDEXEDLINELIST, and is used to render the lines using vertex indices.

## Members

### `wV1`

Specifies the index into the vertex buffer, identifying the first endpoint of the line.

### `wV2`

Specifies the index into the vertex buffer, identifying the second endpoint of the line.

## Remarks

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process (**wPrimitiveCount** * 2) indexes from the command buffer, in effect processing **wPrimitiveCount** D3DHAL_DP2INDEXEDLINELIST structures. The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

The driver should process a total of (**wPrimitiveCount** * 2) vertices from the vertex buffer, two vertices per line. The sequence of lines rendered is (**wV1**₀, **wV2**₀), (**wV1**₁, **wV2**₁), ..., (**wV1**ₙ,**wV2**ₙ), where n equals (**wPrimitiveCount**- 1). The driver should interpret the vertex buffer indexes based on the current command as follows:

* When the command is D3DDP2OP_INDEXEDLINELIST, the vertex buffer indexes are relative to the vertex buffer offset specified by the **dwVertexOffset** member of the [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) structure.
* When the command is D3DDP2OP_INDEXEDLINELIST2, a [D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex) structure immediately follows it and precedes the D3DHAL_DP2INDEXEDLINELIST structure(s) in the command buffer. The vertex buffer indexes are relative to the vertex buffer offset specified by **dwVertexOffset** plus the base offset obtained from the **wVStart** member of the D3DHAL_DP2STARTVERTEX structure.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_INDEXEDLINELIST command and two D3DHAL_DP2INDEXEDLINELIST structures. The driver should draw two lines using the following four vertices from the vertex buffer: (v[0], v[4]), (v[5], v[6]).

![Figure showing a command buffer with a D3DDP2OP_INDEXEDLINELIST command and two D3DHAL_DP2INDEXEDLINELIST structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2llsti.png)
Similarly, the following figure shows a portion of a sample command buffer containing a D3DDP2OP_INDEXEDLINELIST2 command, a D3DHAL_DP2STARTVERTEX offset, and two D3DHAL_DP2INDEXEDLINELIST structures. The driver should process four vertices from the vertex buffer, rendering two lines defined by (v[3], v[7]), (v[8], v[9]).

![Figure showing a command buffer with a D3DDP2OP_INDEXEDLINELIST2 command, a D3DHAL_DP2STARTVERTEX offset, and two D3DHAL_DP2INDEXEDLINELIST structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2ll2i.png)

## See also

D3DDP2OP_INDEXEDLINELIST

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)