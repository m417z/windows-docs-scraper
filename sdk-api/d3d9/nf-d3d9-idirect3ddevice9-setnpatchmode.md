# IDirect3DDevice9::SetNPatchMode

## Description

Enable or disable N-patches.

## Parameters

### `nSegments` [in]

Type: **float**

Specifies the number of subdivision segments. If the number of segments is less than 1.0, N-patches are disabled. The default value is 0.0.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetNPatchMode](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getnpatchmode)