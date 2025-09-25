# D3D12CreateDevice function

## Description

Creates a device that represents the display adapter.

## Parameters

### `pAdapter` [in, optional]

Type: **IUnknown***

A pointer to the video adapter to use when creating a [device](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-intro).
Pass **NULL** to use the default adapter, which is the first adapter that is enumerated by [IDXGIFactory1::EnumAdapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters).

**Note** Don't mix the use of DXGI 1.0 ([IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory)) and DXGI 1.1 ([IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1)) in an application.
Use **IDXGIFactory** or **IDXGIFactory1**, but not both in an application.

### `MinimumFeatureLevel`

Type: **[D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)**

The minimum [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level) required for successful device creation.

### `riid` [in]

Type: ****REFIID****

The globally unique identifier (**GUID**) for the device interface.
This parameter, and *ppDevice*, can be addressed with the single macro
[IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args).

### `ppDevice` [out, optional]

Type: ****void******

A pointer to a memory block that receives a pointer to the device. Pass **NULL** to test if device creation would succeed, but to not actually create the device. If **NULL** is passed and device creation would succeed, **S_FALSE** is returned.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method can return one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

Possible return values include those documented for [CreateDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-createdxgifactory1) and [IDXGIFactory::EnumAdapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters).
If **ppDevice** is **NULL** and the function succeeds, **S_FALSE** is returned, rather than **S_OK**.

## Remarks

Direct3D 12 devices are singletons per adapter. If a Direct3D 12 device already exists in the current process for a given adapter, then a subsequent call to **D3D12CreateDevice** returns the existing device. If the current Direct3D 12 device is in a removed state (that is, [ID3D12Device::GetDeviceRemovedReason](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getdeviceremovedreason) returns a failing HRESULT), then **D3D12CreateDevice** fails instead of returning the existing device. The sameness of two adapters (that is, they have the same identity) is determined by comparing their LUIDs, not their pointers.

In order to be sure to pick up the first adapter that supports D3D12, use the following code.

``` syntax
void GetHardwareAdapter(IDXGIFactory4* pFactory, IDXGIAdapter1** ppAdapter)
{
    *ppAdapter = nullptr;
    for (UINT adapterIndex = 0; ; ++adapterIndex)
    {
        IDXGIAdapter1* pAdapter = nullptr;
        if (DXGI_ERROR_NOT_FOUND == pFactory->EnumAdapters1(adapterIndex, &pAdapter))
        {
            // No more adapters to enumerate.
            break;
        }

        // Check to see if the adapter supports Direct3D 12, but don't create the
        // actual device yet.
        if (SUCCEEDED(D3D12CreateDevice(pAdapter, D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
        {
            *ppAdapter = pAdapter;
            return;
        }
        pAdapter->Release();
    }
}

```

The function signature PFN_D3D12_CREATE_DEVICE is provided as a typedef, so that you can use dynamic linking techniques ([GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)) instead of statically linking.

The **REFIID**, or **GUID**, of the interface to a device can be obtained by using the `__uuidof()` macro.
For example, `__uuidof`([ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)) will get the **GUID** of the interface to a device.

#### Examples

Create a hardware based device, unless instructed to create a WARP software device.

```cpp
ComPtr<IDXGIFactory4> factory;
ThrowIfFailed(CreateDXGIFactory1(IID_PPV_ARGS(&factory)));

if (m_useWarpDevice)
{
    ComPtr<IDXGIAdapter> warpAdapter;
    ThrowIfFailed(factory->EnumWarpAdapter(IID_PPV_ARGS(&warpAdapter)));

    ThrowIfFailed(D3D12CreateDevice(
        warpAdapter.Get(),
        D3D_FEATURE_LEVEL_11_0,
        IID_PPV_ARGS(&m_device)
        ));
}
else
{
    ComPtr<IDXGIAdapter1> hardwareAdapter;
    GetHardwareAdapter(factory.Get(), &hardwareAdapter);

    ThrowIfFailed(D3D12CreateDevice(
        hardwareAdapter.Get(),
        D3D_FEATURE_LEVEL_11_0,
        IID_PPV_ARGS(&m_device)
        ));
}

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-functions)

[Working Samples](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples)