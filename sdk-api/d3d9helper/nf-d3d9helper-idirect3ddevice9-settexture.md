# IDirect3DDevice9::SetTexture

## Description

Assigns a texture to a stage for a device.

## Parameters

### `Stage` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero based sampler number. Textures are bound to samplers; samplers define sampling state such as the filtering mode and the address wrapping mode. Textures are referenced differently by the programmable and the fixed function pipeline:

* Programmable shaders reference textures using the sampler number. The number of samplers available to a programmable shader is dependent on the shader version. For vertex shaders, see [Sampler (Direct3D 9 asm-vs)](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-vs-registers-sampler). For pixel shaders see [Sampler (Direct3D 9 asm-ps)](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-ps-registers-sampler).
* The fixed function pipeline on the other hand, references textures by texture stage number. The maximum number of samplers is determined from two caps: MaxSimultaneousTextures and MaxTextureBlendStages of the [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure.

There are two other special cases for stage/sampler numbers.

* A special number called D3DDMAPSAMPLER is used for [Displacement Mapping (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/displacement-mapping).
* A programmable vertex shader uses a special number defined by a [D3DVERTEXTEXTURESAMPLER](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvertextexturesampler) when accessing [Vertex Textures in vs_3_0 (DirectX HLSL)](https://learn.microsoft.com/windows/desktop/direct3d9/vertex-textures-in-vs-3-0).

### `pTexture` [in]

Type: **[IDirect3DBaseTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9)***

Pointer to an [IDirect3DBaseTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9) interface, representing the texture being set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

**SetTexture** is not allowed if the texture is created with a pool type of D3DPOOL_SCRATCH. **SetTexture** is not allowed with a pool type of D3DPOOL_SYSTEMMEM texture unless DevCaps is set with D3DDEVCAPS_TEXTURESYSTEMMEMORY.

## See also

[GetTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-gettexture)

[GetTextureStageState](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-gettexturestagestate)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[SetTextureStageState](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settexturestagestate)