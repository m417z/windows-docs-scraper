# IDirect3DDevice9::GetTextureStageState

## Description

Retrieves a state value for an assigned texture.

## Parameters

### `Stage` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Stage identifier of the texture for which the state is retrieved. Stage identifiers are zero-based. Devices can have up to eight set textures, so the maximum value allowed for Stage is 7.

### `Type` [in]

Type: **[D3DTEXTURESTAGESTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturestagestatetype)**

Texture state to retrieve. This parameter can be any member of the [D3DTEXTURESTAGESTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturestagestatetype) enumerated type.

### `pValue` [out, retval]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer a variable to fill with the retrieved state value. The meaning of the retrieved value is determined by the Type parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

This method will not return device state for a device that is created using D3DCREATE_PUREDEVICE. If you want to use this method, you must create your device with any of the other flag values in [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate)."

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-gettexture)

[IDirect3DDevice9::SetTexture](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settexture)

[IDirect3DDevice9::SetTextureStageState](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settexturestagestate)