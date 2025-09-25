## Description

Creates an instance of [IDirect3DSurface](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3dsurface) from an [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface).

## Parameters

### `dxgiSurface` [in]

Type: **[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)\***

The [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface) to create the IDirect3D11Surface from.

## Return value

Type: **[IDirect3DSurface](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3dsurface)\^**

Returns the created [IDirect3DSurface](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3dsurface) instance.

## Remarks

While we recommend [C++/WinRT](https://learn.microsoft.com/windows/uwp/cpp-and-winrt-apis/), if you're using C++/CX, then you should use this function. Otherwise, you should use the [CreateDirect3D11SurfaceFromDXGISurface](https://learn.microsoft.com/windows/desktop/api/windows.graphics.directx.direct3d11.interop/nf-windows-graphics-directx-direct3d11-interop-createdirect3d11devicefromdxgidevice) function instead.

## See also