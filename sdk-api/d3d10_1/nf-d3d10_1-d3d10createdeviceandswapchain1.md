# D3D10CreateDeviceAndSwapChain1 function

## Description

Create a Direct3D 10.1 device and a swap chain.

## Parameters

### `pAdapter` [in]

Type: **[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)***

Pointer to a [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter).

### `DriverType` [in]

Type: **[D3D10_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10misc/ne-d3d10misc-d3d10_driver_type)**

The type of driver for the device. See [D3D10_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10misc/ne-d3d10misc-d3d10_driver_type).

### `Software` [in]

Type: **[HMODULE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the DLL that implements a software rasterizer. Must be **NULL** if DriverType is non-software.
The HMODULE of a DLL can be obtained with [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya),
[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa),
or [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea).

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

### `pSwapChainDesc` [in]

Type: **[DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc)***

Description of the swap chain. See [DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc).

### `ppSwapChain` [out]

Type: **[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)****

Address of a pointer to an [IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain).

### `ppDevice` [out]

Type: **[ID3D10Device1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10device1)****

Address of a pointer to an [ID3D10Device1 Interface](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10device1) that will receive the newly created device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

To create a device without creating a swap chain, see [D3D10CreateDevice1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nf-d3d10_1-d3d10createdevice1).

This method requires Windows Vista Service Pack 1, Windows Server 2008, or later release of Windows.

**Note** If you call this API in a Session 0 process, it returns [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)