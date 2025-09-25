# IDirect3DDevice9::SetPixelShaderConstantF

## Description

Sets a floating-point shader constant.

## Parameters

### `StartRegister` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Register number that will contain the first constant value.

### `pConstantData` [in]

Type: **const float***

Pointer to an array of constants.

### `Vector4fCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of four float vectors in the array of constants.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be
D3DERR_INVALIDCALL.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetPixelShaderConstantF](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getpixelshaderconstantf)