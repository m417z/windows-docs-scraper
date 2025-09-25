# _D3DHAL_DP2RENDERSTATE structure

## Description

One or more D3DHAL_DP2RENDERSTATE structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_RENDERSTATE, and are used to set the appropriate render state.

## Members

### `RenderState`

Specifies a D3DRENDERSTATETYPE enumerated type that indicates the render state to be updated. Render states that are requested at the application level are described in the DirectX SDK documentation. Render states that are exclusively used by drivers are described in [D3DRENDERSTATETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ne-d3d9types-_d3drenderstatetype).

### `dvState`

Specifies the value that the driver should update the render state identified by the **RenderState** member with. This member is valid when **RenderState** requires a D3DVALUE.

### `dwState`

Specifies the value that the driver should update the render state identified by **RenderState** to. This member is valid when **RenderState** requires a DWORD.

## Remarks

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process **wStateCount** D3DHAL_DP2RENDERSTATE structures from the command buffer. The value of **wStateCount** is specified in the D3DHAL_DP2COMMAND structure.

For each D3DHAL_DP2RENDERSTATE structure, [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should update the driver's private render state and the render state array that the **lpdwRStates** member of [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) points to. The element to be updated in the public render state array is **lpdwRStates[RenderState]**.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_RENDERSTATE command and two D3DHAL_DP2RENDERSTATE structures. The driver should update **lpdwRStates**[D3DRENDERSTATE_FILLMODE] to be D3DFILL_SOLID and **lpdwRStates**[D3DRENDERSTATE_SHADEMODE] to be D3DSHADE_GOURAUD. The driver should also update its private state accordingly.

![Figure showing a command buffer with a D3DDP2OP_RENDERSTATE command and two D3DHAL_DP2RENDERSTATE structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2rs.png)
Although render states whose values are Boolean in type are documented as only accepting **TRUE**(1) and **FALSE**(0) the runtime does not validate this and accepts any subzero value as true. The sample driver interprets this strictly and does interpret values other than 1 as being **TRUE**. However, because the runtime does not offer validation, your driver should interpret 0 as **FALSE** and any other subzero value as **TRUE**. In this respect your driver should not mimic the behavior of the supplied sample driver.

## See also

D3DDP2OP_RENDERSTATE

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3DRENDERSTATETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ne-d3d9types-_d3drenderstatetype)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)