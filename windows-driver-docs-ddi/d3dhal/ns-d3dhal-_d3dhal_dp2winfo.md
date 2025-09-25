# _D3DHAL_DP2WINFO structure

## Description

The D3DHAL_DP2WINFO structure is used to inform the driver of the w-range to be used for w-buffering.

## Members

### `dvWNear`

### `dvWFar`

Specify the near and far limit of the w-buffer, respectively. These members can be any valid floating-point values.

## Remarks

The [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback parses a D3DHAL_DP2WINFO structure from the command buffer and updates the driver's scaling parameters for w-buffering when [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) is set to D3DDP2OP_WINFO.

One D3DHAL_DP2WINFO structure follows the D3DHAL_DP2COMMAND structure in the command buffer.

The driver should update the w-buffer portion of its internal rendering context with the w-ranges specified in this structure. The driver can use this information to scale the w-buffer.

Video adapters that do not support this feature should ignore and skip over these instructions and continue processing the rest of the command buffer.

## See also

D3DDP2OP_WINFO

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)