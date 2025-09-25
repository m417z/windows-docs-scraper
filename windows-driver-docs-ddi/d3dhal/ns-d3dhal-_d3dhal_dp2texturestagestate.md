# _D3DHAL_DP2TEXTURESTAGESTATE structure

## Description

One or more D3DHAL_DP2TEXTURESTAGESTATE structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_TEXTURESTAGESTATE, and are used to set the appropriate texture stage state.

## Members

### `wStage`

Identifies the texture stage where to update the texture state. This member can be an integer in the range 0 through 7, with the highest numbered texture being closest to the frame buffer.

### `TSState`

Specifies a D3DTEXTURESTAGESTATETYPE enumerated value that specifies the texture state to be updated. DirectX 9.0 and later applications can use values in the D3DSAMPLERSTATETYPE enumeration to control the characteristics of sampler texture-related render states. In DirectX 8.0 and earlier, these sampler states were included in the D3DTEXTURESTAGESTATETYPE enumeration. The runtime maps user-mode sampler states (D3DSAMP_*Xxx*) to kernel-mode D3DTSS_*Xxx* values so that drivers are not required to process user-mode sampler states. For more information about D3DTEXTURESTAGESTATETYPE and D3DSAMPLERSTATETYPE, see the DirectX SDK documentation.

### `dwValue`

Specifies the value that the driver should update the texture state identified by **TSState** to.

## Remarks

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process **wStateCount** D3DHAL_DP2TEXTURESTAGESTATE structures from the command buffer. The value of **wStateCount** is specified in the D3DHAL_DP2COMMAND structure.

For each D3DHAL_DP2TEXTURESTAGESTATE structure, [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should update the driver's internal texture state associated with the texture at **dwStage** to reflect the new value based on **TSState**.

Drivers that do not support multitexturing should implement support for texture stage 0 only.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_TEXTURESTAGESTATE command and three D3DHAL_DP2TEXTURESTAGESTATE structures. The driver should update stages zero and three of its private texture stage state accordingly.

![Figure showing a command buffer with a D3DDP2OP_TEXTURESTAGESTATE command and three D3DHAL_DP2TEXTURESTAGESTATE structures ](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2tss.png)

## See also

D3DDP2OP_TEXTURESTAGESTATE

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)