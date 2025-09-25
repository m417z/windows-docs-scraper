# DXGI_SHARED_RESOURCE structure

## Description

Represents a handle to a shared resource.

## Members

### `Handle`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a shared resource.

## Remarks

To create a shared surface, pass a shared-resource handle into the [IDXGIDevice::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgidevice-createsurface) method.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)