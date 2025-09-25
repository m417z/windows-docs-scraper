# _D3DHAL_DP2VIEWPORTINFO structure

## Description

The D3DHAL_DP2VIEWPORTINFO structure is used to inform guard-band aware drivers of the view clipping rectangle. The clipping rectangle is specified by the members **dwX**, **dwY**, **dwWidth** and **dwHeight**.

## Members

### `dwX`

### `dwY`

Specify the location, in screen coordinates, of the upper-left corner of the subrectangle.

### `dwWidth`

### `dwHeight`

Specify the width and height, respectively, of the subrectangle where the application is rendering. These members are specified in screen coordinates.

## Remarks

The [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback parses a D3DHAL_DP2VIEWPORTINFO structure from the command buffer and updates the driver's viewport description when [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) is set to D3DDP2OP_VIEWPORTINFO.

One D3DHAL_DP2VIEWPORTINFO structure follows the D3DHAL_DP2COMMAND structure in the command buffer.

The driver should update the viewport portion of its internal rendering context with the location and size values specified in this structure. The driver can use this information to perform guard band clipping.

Subguard-band drivers should ignore and skip over these instructions and continue processing the rest of the command buffer.

## See also

D3DDP2OP_VIEWPORTINFO

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)