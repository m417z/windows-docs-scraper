# DXGI_MAPPED_RECT structure

## Description

Describes a mapped rectangle that is used to access a surface.

## Members

### `Pitch`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that describes the width, in bytes, of the surface.

### `pBits`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the image buffer of the surface.

## Remarks

The **DXGI_MAPPED_RECT** structure is initialized by the [IDXGISurface::Map](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgisurface-map) method.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)