# IDirect3DDevice9::SetSamplerState

## Description

Sets the sampler state value.

## Parameters

### `Sampler` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The sampler stage index. For more info about sampler stage, see [Sampling Stage Registers in vs_3_0 (DirectX HLSL)](https://learn.microsoft.com/windows/desktop/direct3d9/vertex-textures-in-vs-3-0).

### `Type` [in]

Type: **[D3DSAMPLERSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsamplerstatetype)**

This parameter can be any member of the [D3DSAMPLERSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsamplerstatetype) enumerated type.

### `Value` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

State value to set. The meaning of this value is determined by the Type parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetSamplerState](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getsamplerstate)