# _D3DDDIARG_TEXTURESTAGESTATE structure

## Description

The D3DDDIARG_TEXTURESTAGESTATE structure describes how to update a texture at a particular stage in a multiple-texture group.

## Members

### `Stage` [in]

The stage in a multiple-texture group that indicates the texture to be updated. This member can be an integer in the range from 0 through 7, with the highest numbered texture being closest to the frame buffer.

### `State` [in]

A D3DDDITEXTURESTAGESTATETYPE-typed value that indicates the texture state to be updated.

Microsoft DirectX 9.0 and later applications can use values in the D3DSAMPLERSTATETYPE enumeration type to control the characteristics of sampler texture-related render states. In DirectX 8.0 and earlier, these sampler states were included in the D3DTEXTURESTAGESTATETYPE enumeration. The runtime maps sampler states (D3DSAMP_*Xxx*) to D3DDDITSS_*Xxx* values so that drivers are not required to process sampler states. For more information about D3DTEXTURESTAGESTATETYPE and D3DSAMPLERSTATETYPE, see the DirectX SDK documentation.

For a definition of each value, see the corresponding value of D3DTEXTURESTAGESTATETYPE or D3DSAMPLERSTATETYPE.

The following texture states are used exclusively by user-mode display drivers for texture colorkeying:

| **Value** | **Meaning** |
|:--|:--|
| D3DDDITSS_DISABLETEXTURECOLORKEY (33) | Disable the current texture's colorkey. The Value member is set to TRUE to disable. |
| D3DDDITSS_TEXTURECOLORKEYVAL (34) | Update the colorkey for the current texture. The Valuemember is set to the colorkey value. |

### `Value` [in]

The value to which the driver should update the texture state that is identified by the **Stage** and **State** members. For more information about values that can be updated for each texture state, see the definitions of the corresponding texture state in the D3DTEXTURESTAGESTATETYPE or D3DSAMPLERSTATETYPE enumeration type in the DirectX SDK documentation.

## See also

[SetTextureStageState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_settexturestagestate)