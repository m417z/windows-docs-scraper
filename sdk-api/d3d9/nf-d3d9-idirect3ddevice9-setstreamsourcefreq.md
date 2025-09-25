## Description

Sets the stream source frequency divider value. This may be used to draw several instances of geometry.

## Parameters

### `StreamNumber`

Type: [in] **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Stream source number.

### `Divider`

Type: [in] **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This parameter may have two different values. See remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

There are two constants defined in d3d9types.h that are designed to use with SetStreamSourceFreq: D3DSTREAMSOURCE_INDEXEDDATA and D3DSTREAMSOURCE_INSTANCEDATA. To see how to use the constants, see [Efficiently Drawing Multiple Instances of Geometry (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/efficiently-drawing-multiple-instances-of-geometry).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetStreamSourceFreq](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getstreamsourcefreq)