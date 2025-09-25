# D3D10CreateDevice function

## Description

Create a Direct3D 10.0 device that represents the display adapter.

## Parameters

### `pAdapter` [in]

Type: **[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)***

Pointer to the display adapter (see [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)) when creating a hardware device; otherwise set this parameter to **NULL**.
If **NULL** is specified when creating a hardware device, Direct3D will use the first adapter enumerated by [EnumAdapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters).

### `DriverType` [in]

Type: **[D3D10_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10misc/ne-d3d10misc-d3d10_driver_type)**

The device-driver type (see [D3D10_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10misc/ne-d3d10misc-d3d10_driver_type)). The driver type determines the type of device you will create.

### `Software` [in]

Type: **[HMODULE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved. Set to **NULL**.

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional. Device creation flags (see [D3D10_CREATE_DEVICE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_create_device_flag)) that
enable [API layers](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-api-features-layers). These flags can be bitwise OR'd together.

### `SDKVersion` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Bit flag that indicates the version of the SDK. Should always be D3D10_SDK_VERSION.

### `ppDevice` [out]

Type: **[ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)****

Address of a pointer to the device created (see [ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This example creates a reference device.

```

ID3D10Device* g_pd3dDevice = NULL;
D3D10CreateDevice( NULL, D3D10_DRIVER_TYPE_REFERENCE, NULL, 0,
    D3D10_SDK_VERSION, &g_pd3dDevice );

```

To create a device and a swap chain at the same time, see [D3D10CreateDeviceAndSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d10misc/nf-d3d10misc-d3d10createdeviceandswapchain).

The object returned by D3D10CreateDevice implements the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface and can be queried for other
interfaces the object supports. To retrieve the [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) interface of the object the following code could be used.

```

IDXGIDevice * pDXGIDevice;
hr = g_pd3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void **)&pDXGIDevice);

```

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)