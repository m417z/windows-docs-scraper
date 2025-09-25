# CreateDirect3D11SurfaceFromDXGISurface function

## Description

Creates an instance of [IDirect3DSurface](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3dsurface) from an [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface).

## Parameters

### `dxgiSurface` [in]

Type: **[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)\***

The [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface) to create the IDirect3D11Surface from.

### `graphicsSurface` [out]

Type: **[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)\*\***

An [IDirect3DSurface](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3dsurface) instance that wraps the [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface).

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

While we recommend [C++/WinRT](https://learn.microsoft.com/windows/uwp/cpp-and-winrt-apis/), if you're using C++/CX then you should call [CreateDirect3DSurface](https://learn.microsoft.com/windows/win32/api/windows.graphics.directx.direct3d11.interop/nf-windows-graphics-directx-direct3d11-interop-createdirect3dsurface) instead of **CreateDirect3D11DeviceFromDXGIDevice**. If you're using WRL then **CreateDirect3D11DeviceFromDXGIDevice** can be used as shown in this code example.

```cpp
using namespace Microsoft::WRL;
ComPtr<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> surface;
ComPtr<IInspectable> inspectableSurface;
If (SUCCEEDED(CreateDirect3D11SurfaceFromDXGISurface(dxgiSurface, &inspectableSurface))
{
    hr = inspectableSurface.As(&surface);
}
```

## See also

[Core functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-functions)