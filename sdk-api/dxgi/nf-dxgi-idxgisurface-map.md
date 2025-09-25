# IDXGISurface::Map

## Description

Get a pointer to the data contained in the surface, and deny GPU access to the surface.

## Parameters

### `pLockedRect` [out]

Type: **[DXGI_MAPPED_RECT](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_mapped_rect)***

A pointer to the surface data (see [DXGI_MAPPED_RECT](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_mapped_rect)).

### `MapFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

CPU read-write flags. These flags can be combined with a logical OR.

* DXGI_MAP_READ - Allow CPU read access.
* DXGI_MAP_WRITE - Allow CPU write access.
* DXGI_MAP_DISCARD - Discard the previous contents of a resource when it is mapped.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

Use **IDXGISurface::Map** to access a surface from the CPU. To release a mapped surface (and allow GPU access) call [IDXGISurface::Unmap](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgisurface-unmap).

## See also

[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)