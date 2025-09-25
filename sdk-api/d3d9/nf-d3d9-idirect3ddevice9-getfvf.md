# IDirect3DDevice9::GetFVF

## Description

Gets the fixed vertex function declaration.

## Parameters

### `pFVF` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A DWORD pointer to the fixed function vertex type. For more information, see [D3DFVF](https://learn.microsoft.com/windows/desktop/direct3d9/d3dfvf).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be
D3DERR_INVALIDCALL.

## Remarks

The fixed vertex function declaration is a set of FVF flags that determine how vertices processed by the fixed function pipeline will be used.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetFVF](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setfvf)