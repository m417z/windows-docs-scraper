# IDirect3DDevice9::SetPixelShaderConstantB

## Description

Sets a Boolean shader constant.

## Parameters

### `StartRegister` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Register number that will contain the first constant value.

### `pConstantData` [in]

Type: **const [BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to an array of constants.

### `BoolCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of boolean values in the array of constants.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be
D3DERR_INVALIDCALL.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetPixelShaderConstantB](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getpixelshaderconstantb)