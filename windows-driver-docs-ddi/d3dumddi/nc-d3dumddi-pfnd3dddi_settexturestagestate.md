# PFND3DDDI_SETTEXTURESTAGESTATE callback function

## Description

The *SetTextureStageState* function updates the state of a texture at a particular stage in a multiple-texture group.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_TEXTURESTAGESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_texturestagestate) structure that describes how to update the texture.

## Return value

*SetTextureStageState* returns S_OK or an appropriate error result if the texture is not successfully updated.

## Remarks

The user-mode display driver is not required to store colorkey values in its private allocation structure because the Microsoft Direct3D runtime always passes the appropriate colorkeying information in calls to the driver's *SetTextureStageState* function. For example, the runtime passes the following colorkey information in the indicated members of the [D3DDDIARG_TEXTURESTAGESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_texturestagestate) structure that is pointed to by *pData* to perform the indicated colorkey operation:

* D3DTSS_TEXTURECOLORKEYVAL in the **State** member and a colorkey value in the **Value** member to update the current texture's colorkey
* D3DTSS_DISABLETEXTURECOLORKEY in the **State** member and **TRUE** in the **Value** member to disable the current texture's colorkey

## See also

[D3DDDIARG_TEXTURESTAGESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_texturestagestate)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)