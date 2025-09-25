# IDirect3DDevice9::DeletePatch

## Description

Frees a cached high-order patch.

## Parameters

### `Handle` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle of the cached high-order patch to delete.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be
D3DERR_INVALIDCALL.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DrawRectPatch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawrectpatch)

[IDirect3DDevice9::DrawTriPatch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawtripatch)

[Using Higher-Order Primitives (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/using-higher-order-primitives)