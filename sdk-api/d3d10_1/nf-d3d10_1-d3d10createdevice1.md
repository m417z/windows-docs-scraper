# D3D10CreateDevice1 function

## Description

Create a Direct3D 10.1 device that represents the display adapter.

## Parameters

### `pAdapter` [in]

Type: **[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)***

Pointer to the display adapter (see [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)) when creating a hardware device; otherwise set this parameter to
**NULL**. If **NULL** is specified when creating a hardware device, Direct3D will use the first adapter enumerated
by [EnumAdapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters).

### `DriverType` [in]

Type: **[D3D10_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10misc/ne-d3d10misc-d3d10_driver_type)**

The device-driver type (see [D3D10_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10misc/ne-d3d10misc-d3d10_driver_type)). The driver type determines the type of device you will create.

### `Software` [in]

Type: **[HMODULE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This is set to **NULL** except for D3D10_DRIVER_TYPE_SOFTWARE driver types.

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional. Device creation flags (see [D3D10_CREATE_DEVICE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_create_device_flag)) that
enable [API layers](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-api-features-layers). These flags can be bitwise OR'd together.

### `HardwareLevel` [in]

Type: **[D3D10_FEATURE_LEVEL1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ne-d3d10_1-d3d10_feature_level1)**

The version of hardware that is available for acceleration (see [D3D10_FEATURE_LEVEL1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ne-d3d10_1-d3d10_feature_level1)).

### `SDKVersion` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Bit flag that indicates the version of the SDK. Should be D3D10_1_SDK_VERSION, defined in D3D10.h.

### `ppDevice` [out]

Type: **[ID3D10Device1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10device1)****

Address of a pointer to the device created (see [ID3D10Device1 Interface](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10device1)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

To create a device and a swap chain at the same time, see [D3D10CreateDeviceAndSwapChain1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nf-d3d10_1-d3d10createdeviceandswapchain1).

This method requires Windows Vista Service Pack 1, Windows Server 2008, or later release of Windows.

The object returned by D3D10CreateDevice1 implements the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface
and can be queried for other
interfaces the object supports. To retrieve the [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) interface of the object the following code could be used.

```

IDXGIDevice * pDXGIDevice;
hr = g_pd3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void **)&pDXGIDevice);

```

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)