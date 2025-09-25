# CreateDirect3D11DeviceFromDXGIDevice function

## Description

Creates an instance of [IDirect3DDevice](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3ddevice) from an [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice).

## Parameters

### `dxgiDevice` [in]

Type: **[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice)\***

The [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) to create the Direct3DDevice from.

### `graphicsDevice` [out]

Type: **[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)\*\***

A Direct3DDevice instance that wraps the DXGIDevice.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

While we recommend [C++/WinRT](https://learn.microsoft.com/windows/uwp/cpp-and-winrt-apis/), if you're using C++/CX then you should call [CreateDirect3DDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice) instead of **CreateDirect3D11DeviceFromDXGIDevice**. If you're using WRL then **CreateDirect3D11DeviceFromDXGIDevice** can be used as shown in this code example.

```cpp
using namespace Microsoft::WRL;
ComPtr<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice> device;
ComPtr<IInspectable> inspectableSurface;
If (SUCCEEDED(CreateDirect3D11DeviceFromDXGIDevice(dxgiDevice, &inspectableSurface))
{
    hr = inspectableSurface.As(&device);
}
```

## See also

[Core functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-functions)