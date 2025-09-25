# D3D10CreateDeviceAndSwapChain function

## Description

Create a Direct3D 10.0 device and a swap chain.

## Parameters

### `pAdapter` [in]

Type: **[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)***

Pointer to a [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter).

### `DriverType` [in]

Type: **[D3D10_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10misc/ne-d3d10misc-d3d10_driver_type)**

The type of driver for the device. See [D3D10_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10misc/ne-d3d10misc-d3d10_driver_type).

### `Software` [in]

Type: **[HMODULE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the DLL that implements a software rasterizer. Must be **NULL** if DriverType is non-software. The HMODULE of a DLL can be obtained with [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya), [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa), or [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea).

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional. Device creation flags (see [D3D10_CREATE_DEVICE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_create_device_flag)) that enable [API layers](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-api-features-layers). These flags can be bitwise OR'd together.

### `SDKVersion` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Bit flag that indicates the version of the SDK. Should be D3D10_SDK_VERSION, defined in d3d10.h.

### `pSwapChainDesc` [in]

Type: **[DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc)***

Description of the swap chain. See [DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc).

### `ppSwapChain` [out]

Type: **[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)****

Address of a pointer to an [IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain).

### `ppDevice` [out]

Type: **[ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)****

Address of a pointer to an [ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device) that will receive the newly created device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

To create a device without creating a swap chain, see [D3D10CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d10misc/nf-d3d10misc-d3d10createdevice).

**Note** If you call this API in a Session 0 process, it returns [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)