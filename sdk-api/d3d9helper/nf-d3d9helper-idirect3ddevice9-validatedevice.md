# IDirect3DDevice9::ValidateDevice

## Description

Reports the device's ability to render the current texture-blending operations and arguments in a single pass.

## Parameters

### `pNumPasses` [out, retval]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a DWORD value to fill with the number of rendering passes needed to complete the desired effect through multipass rendering.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_CONFLICTINGRENDERSTATE, D3DERR_CONFLICTINGTEXTUREFILTER, D3DERR_DEVICELOST, D3DERR_DRIVERINTERNALERROR, D3DERR_TOOMANYOPERATIONS, D3DERR_UNSUPPORTEDALPHAARG, D3DERR_UNSUPPORTEDALPHAOPERATION, D3DERR_UNSUPPORTEDCOLORARG, D3DERR_UNSUPPORTEDCOLOROPERATION, D3DERR_UNSUPPORTEDFACTORVALUE, D3DERR_UNSUPPORTEDTEXTUREFILTER, D3DERR_WRONGTEXTUREFORMAT,.

## Remarks

The **IDirect3DDevice9::ValidateDevice** method should be used to validate scenarios only when other capabilities are deficient. For example, in a multistage texturing scenario, you could query the MaxTextureBlendStages and MaxSimultaneousTextures members of a [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure to determine if multistage texturing is possible on the device.

Current hardware does not necessarily implement all possible combinations of operations and arguments. You can determine whether a particular blending operation can be performed with given arguments by setting the desired blending operation, and then calling the **IDirect3DDevice9::ValidateDevice** method.

The **IDirect3DDevice9::ValidateDevice** method uses the current render states, textures, and texture-stage states to perform validation at the time of the call. Changes to these factors after the call invalidate the previous result, and the method must be called again before rendering a scene.

For best performance, call **IDirect3DDevice9::ValidateDevice** at initialization time; do not use it within a render loop.

Using diffuse iterated values, either as an argument or as an operation (D3DTA_DIFFUSED3DTOP_BLENDDIFFUSEALPHA) is rarely supported on current hardware. Most hardware can introduce iterated color data only at the last texture operation stage.

Try to specify the texture (D3DTA_TEXTURE) for each stage as the first argument, rather than the second argument.

Many cards do not support use of diffuse or scalar values at arbitrary texture stages. Often, these are available only at the first or last texture-blending stage.

Many cards do not have a blending unit associated with the first texture that is capable of more than replicating alpha to color channels or inverting the input. Therefore, your application might need to use only the second texture stage, if possible. On such hardware, the first unit is presumed to be in its default state, which has the first color argument set to D3DTA_TEXTURE with the D3DTOP_SELECTARG1 operation.

Operations on the output alpha that are more intricate than or substantially different from the color operations are less likely to be supported.

Some hardware does not support simultaneous use of D3DTA_TFACTOR and D3DTA_DIFFUSE.

Many cards do not support simultaneous use of multiple textures and mipmapped trilinear filtering. If trilinear filtering has been requested for a texture involved in multitexture blending operations and validation fails, turn off trilinear filtering and revalidate. In this case, you might want to perform multipass rendering instead.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetTextureStageState](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-gettexturestagestate)

[IDirect3DDevice9::SetTextureStageState](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settexturestagestate)