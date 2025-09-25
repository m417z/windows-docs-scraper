# _D3DHAL_DP2TRIANGLESTRIP structure

## Description

One D3DHAL_DP2TRIANGLESTRIP structure is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_TRIANGLESTRIP, and is used to render the specified connected triangle strip.

## Members

### `wVStart`

Specifies the index to the vertex buffer containing coordinate data for the initial vertex of the triangle strip.

## Remarks

One D3DHAL_DP2TRIANGLESTRIP structure follows the D3DHAL_DP2COMMAND structure in the command buffer.

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process a total of (**wPrimitiveCount** + 2) vertices from the vertex buffer. The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

The triangle edges in a triangle strip are rendered in this order: (**wV[**0**]**, **wV[**1**]**, **wV[**2**]**), (**wV[**1**]**, **wV[**3**]**, **wV[**2**]**), (**wV[**2**]**, **wV[**3**]**, **wV[**4**]**), (**wV[**3**]**, **wV[**5**]**, **wV[**4**]**),...

For the last triangle in the triangle strip, however, the edges are rendered in different orders when **wPrimitiveCount**t is odd and when it is even.

* When **wPrimitiveCount** is an odd number, the last triangle's edges are rendered in this order: (**wV[wPrimitiveCount** - 1**]**, **wV[wPrimitiveCount]**, **wV[wPrimitiveCount** + 1**]**).
* When **wPrimitiveCount** is an even number, the last triangle's edges are rendered in this order: (**wV[wPrimitiveCount**- 1**]**, **wV[wPrimitiveCount** + 1**]**, **wV[wPrimitiveCount**).

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_TRIANGLESTRIP command and one D3DHAL_DP2TRIANGLESTRIP structure. The driver should process five vertices from the vertex buffer, rendering a strip of three triangles defined by (v[0], v[1], v[2]), (v[1], v[3], v[2]), (v[2], v[3], v[4]).

![Figure showing a command buffer with a D3DDP2OP_TRIANGLESTRIP command and one D3DHAL_DP2TRIANGLESTRIP structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2trist.png)

## See also

D3DDP2OP_TRIANGLESTRIP

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)