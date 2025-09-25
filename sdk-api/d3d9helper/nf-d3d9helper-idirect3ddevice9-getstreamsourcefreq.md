## Description

Gets the stream source frequency divider value.

## Parameters

### `StreamNumber`

Type: [in] **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Stream source number.

### `Divider`

Type: [out] **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Returns the frequency divider value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

Vertex shaders can now be invoked more than once per vertex. See [Drawing Non-Indexed Geometry](https://learn.microsoft.com/windows/desktop/direct3d9/efficiently-drawing-multiple-instances-of-geometry).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetStreamSourceFreq](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setstreamsourcefreq)