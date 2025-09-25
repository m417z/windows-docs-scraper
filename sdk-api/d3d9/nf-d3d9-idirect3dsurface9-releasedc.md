# IDirect3DSurface9::ReleaseDC

## Description

Release a device context handle.

## Parameters

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a device context.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if the argument is invalid.

## Remarks

An hdc is a Windows resource. It must be released after use so Windows can return it to the pool of available resources.

This method will release only the device context returned by [IDirect3DSurface9::GetDC](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-getdc). Otherwise, this method will fail.

## See also

[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)

[IDirect3DSurface9::GetDC](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-getdc)