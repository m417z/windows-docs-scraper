# D3D11CreateDevice function

## Description

Creates a device that represents the display adapter.

## Parameters

### `pAdapter` [in, optional]

Type: **[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)***

A pointer to the video adapter to use when creating a [device](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-intro). Pass **NULL** to use the default adapter, which is the first adapter that is enumerated by [IDXGIFactory1::EnumAdapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters).

**Note** Do not mix the use of DXGI 1.0 ([IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory)) and DXGI 1.1 ([IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1)) in an application. Use **IDXGIFactory** or **IDXGIFactory1**, but not both in an application.

### `DriverType`

Type: **[D3D_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type)**

The [D3D_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type), which represents the driver type to create.

### `Software`

Type: **[HMODULE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a DLL that implements a software rasterizer.
If *DriverType* is *D3D_DRIVER_TYPE_SOFTWARE*,
*Software* must not be **NULL**. Get the handle by
calling [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya),
[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) ,
or [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea).

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The runtime [layers](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers) to enable (see [D3D11_CREATE_DEVICE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag));
values can be bitwise OR'd together.

### `pFeatureLevels` [in, optional]

Type: **const [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)***

A pointer to an array of [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)s, which determine the order of feature levels to attempt to create.
If *pFeatureLevels* is set to **NULL**,
this function uses the following array of feature levels:

```
{
    D3D_FEATURE_LEVEL_11_0,
    D3D_FEATURE_LEVEL_10_1,
    D3D_FEATURE_LEVEL_10_0,
    D3D_FEATURE_LEVEL_9_3,
    D3D_FEATURE_LEVEL_9_2,
    D3D_FEATURE_LEVEL_9_1,
};
```

**Note** If the Direct3D 11.1 runtime is present on the computer and *pFeatureLevels* is set to **NULL**, this function won't create a [D3D_FEATURE_LEVEL_11_1](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level) device. To create a **D3D_FEATURE_LEVEL_11_1** device, you must explicitly provide a **D3D_FEATURE_LEVEL** array that includes **D3D_FEATURE_LEVEL_11_1**. If you provide a **D3D_FEATURE_LEVEL** array that contains **D3D_FEATURE_LEVEL_11_1** on a computer that doesn't have the Direct3D 11.1 runtime installed, this function immediately fails with E_INVALIDARG.

### `FeatureLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in *pFeatureLevels*.

### `SDKVersion`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The SDK version; use *D3D11_SDK_VERSION*.

### `ppDevice` [out, optional]

Type: **[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)****

Returns the address of a pointer to an [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device) object that represents the device created. If this parameter is **NULL**, no ID3D11Device will be returned.

### `pFeatureLevel` [out, optional]

Type: **[D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)***

If successful, returns the first [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level) from the *pFeatureLevels* array which succeeded. Supply **NULL** as an input if you don't need to determine which feature level is supported.

### `ppImmediateContext` [out, optional]

Type: **[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)****

Returns the address of a pointer to an [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) object that represents the device context. If this parameter is **NULL**, no ID3D11DeviceContext will be returned.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method can return one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

This method returns E_INVALIDARG if you set the *pAdapter* parameter to a non-**NULL** value and the *DriverType* parameter to the D3D_DRIVER_TYPE_HARDWARE value.

This method returns [DXGI_ERROR_SDK_COMPONENT_MISSING](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if you specify [D3D11_CREATE_DEVICE_DEBUG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag) in *Flags* and the incorrect version of the [debug layer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers) is installed on your computer. Install the latest Windows SDK to get the correct version.

## Remarks

This entry-point is supported by the Direct3D 11 runtime, which is available on Windows 7, Windows Server 2008 R2, and as an update to
Windows Vista (KB971644).

To create a Direct3D 11.1 device ([ID3D11Device1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11device1)), which is available on Windows 8, Windows Server 2012, and Windows 7 and Windows Server 2008 R2 with the [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7) installed, you first create a [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device) with this function, and then call the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method on the **ID3D11Device** object to obtain the **ID3D11Device1** interface.

To create a Direct3D 11.2 device ([ID3D11Device2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11device2)), which is available on Windows 8.1 and Windows Server 2012 R2, you first create a [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device) with this function, and then call the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method on the **ID3D11Device** object to obtain the **ID3D11Device2** interface.

Set *ppDevice* and *ppImmediateContext* to **NULL** to determine which feature level is supported by looking
at *pFeatureLevel* without creating a device.

For an example, see [How To: Create a Device and Immediate Context](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-initialize); to create a device and a swap chain at the same time,
use [D3D11CreateDeviceAndSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdeviceandswapchain).

If you set the *pAdapter* parameter to a non-**NULL** value, you must also set the *DriverType* parameter to the D3D_DRIVER_TYPE_UNKNOWN value. If you set the *pAdapter* parameter to a non-**NULL** value and the *DriverType* parameter to the D3D_DRIVER_TYPE_HARDWARE value, **D3D11CreateDevice** returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) of E_INVALIDARG.

|  |
| --- |
| Differences between Direct3D 10 and Direct3D 11:<br><br>In Direct3D 10, the presence of *pAdapter* dictated which adapter to use and the *DriverType* could mismatch what the adapter was.<br><br>In Direct3D 11, if you are trying to create a hardware or a software device, set *pAdapter* != **NULL** which constrains the other inputs to be:<br><br>* *DriverType* must be D3D_DRIVER_TYPE_UNKNOWN<br>* *Software* must be **NULL**.<br><br>On the other hand, if *pAdapter* == **NULL**, the *DriverType* cannot be set to D3D_DRIVER_TYPE_UNKNOWN; it can be set to either:<br><br>* If *DriverType* == D3D_DRIVER_TYPE_SOFTWARE, *Software* cannot be **NULL**.<br>* If *DriverType* == D3D_DRIVER_TYPE_HARDWARE, the adapter used will be the default adapter, which is the first adapter that is enumerated by [IDXGIFactory1::EnumAdapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters) |

The function signature PFN_D3D11_CREATE_DEVICE is provided as a typedef, so that you can use dynamic linking techniques ([GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)) instead of statically linking.

**Windows Phone 8:** This API is supported.

**Windows Phone 8.1:** This API is supported.

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-functions)