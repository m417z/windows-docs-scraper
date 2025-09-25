# _D3DHAL_DP2TRIANGLEFAN_IMM structure

## Description

One D3DHAL_DP2TRIANGLEFAN_IMM structure is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_TRIANGLEFAN_IMM, and is used to render a triangle fan.

## Members

### `dwEdgeFlags`

Specifies a bitmask that identifies which of the fan's outside edges should be rendered when the fill mode is D3DFILL_WIREFRAME. A set bit indicates that its corresponding edge should be rendered. For more information about this bitmask, see the Remarks section.

## Remarks

One D3DHAL_DP2TRIANGLEFAN_IMM structure immediately follows the D3DHAL_DP2COMMAND structure in the command buffer. The triangle fan's vertex data is DWORD-aligned immediately following the D3DHAL_DP2TRIANGLEFAN_IMM structure in the command buffer.

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process a total of **wPrimitiveCount**+2 vertices from the command buffer, three vertices per triangle, rendering **wPrimitiveCount** triangles. The sequence of triangles rendered is (**V[**1**]**, **V[**2**]**, **V[**0**]**), (**V[**2**]**, **V[**3**]**, **V[**0**]**), (**V[**3**]**, **V[**4**]**, **V[**0**]**), ..., (**V[wPrimitiveCount]**, **V[wPrimitiveCount]** + 1**]**, **V[**0**]**). The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

The driver must check the edge flag for each of the fan's outside edges when the fill mode is D3DFILL_WIREFRAME. Starting from the least significant bit of **dwEdgeFlags**, bit 0 applies to the **V[**0**]**-**V[**1**]** edge, bit 1 applies to the **V[**1**]**-**V[**2**]** edge, ..., bit **wPrimitiveCount** applies to the **V[wPrimitiveCount]**-**V[[wPrimitiveCount]**+1**]** edge, and bit (**wPrimitiveCount** + 1) applies to the **V[[wPrimitiveCount]**+1**]**-**V[**0**]** edge.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_TRIANGLEFAN_IMM command, a D3DHAL_DP2TRIANGLEFAN_IMM structure, and the vertex data. The driver should process the five vertices from the command buffer, rendering a fan with three triangles defined by (v[1], v[2], v[0]), (v[2], v[3], v[0]), (v[3], v[4], v[0]).

![Figure showing a command buffer with a D3DDP2OP_TRIANGLEFAN_IMM command, a D3DHAL_DP2TRIANGLEFAN_IMM structure, and the vertex data ](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2tfimm.png)

## See also

D3DDP2OP_TRIANGLEFAN_IMM

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)