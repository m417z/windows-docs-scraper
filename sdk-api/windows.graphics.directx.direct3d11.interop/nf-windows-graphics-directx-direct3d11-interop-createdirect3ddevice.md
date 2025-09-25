## Description

Creates an instance of [IDirect3DDevice](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3ddevice) from an [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice).

## Parameters

### `dxgiDevice` [in]

Type: **[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice)\***

The [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) to create the Direct3DDevice from.

## Return value

Type: **[IDirect3DDevice](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3ddevice)\^**

Returns the created [IDirect3DDevice](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3ddevice) instance.

## Remarks

While we recommend [C++/WinRT](https://learn.microsoft.com/windows/uwp/cpp-and-winrt-apis/), if you're using C++/CX, then you should use this function. Otherwise, you should use the [CreateDirect3D11DeviceFromDXGIDevice](https://learn.microsoft.com/windows/desktop/api/windows.graphics.directx.direct3d11.interop/nf-windows-graphics-directx-direct3d11-interop-createdirect3d11devicefromdxgidevice) function instead.

## See also