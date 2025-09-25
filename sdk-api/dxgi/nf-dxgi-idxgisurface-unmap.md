# IDXGISurface::Unmap

## Description

Invalidate the pointer to the surface retrieved by [IDXGISurface::Map](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgisurface-map) and re-enable GPU access to the resource.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)