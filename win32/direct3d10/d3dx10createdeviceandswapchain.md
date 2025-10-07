# D3DX10CreateDeviceAndSwapChain function

Create the best Direct3D device and a swap chain.

## Parameters

*pAdapter* \[in\]

Type: **[**IDXGIAdapter**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiadapter)\***

Pointer to a [**IDXGIAdapter**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiadapter).

*DriverType* \[in\]

Type: **[**D3D10\_DRIVER\_TYPE**](https://learn.microsoft.com/windows/desktop/api/D3D10misc/ne-d3d10misc-d3d10_driver_type)**

The type of driver for the device. See [**D3D10\_DRIVER\_TYPE**](https://learn.microsoft.com/windows/desktop/api/D3D10misc/ne-d3d10misc-d3d10_driver_type).

*Software* \[in\]

Type: **[**HMODULE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to the DLL that implements a software rasterizer. Must be **NULL** if DriverType is non-software. The HMODULE of a DLL can be obtained with [LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya), [LoadLibraryEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexa), or [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea).

*Flags* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Optional. Device creation flags (see [**D3D10\_CREATE\_DEVICE\_FLAG**](https://learn.microsoft.com/windows/desktop/api/D3D10/ne-d3d10-d3d10_create_device_flag)) that enable [API layers](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-programming-guide-api-features-layers). These flags can be bitwise OR'd together.

*pSwapChainDesc* \[in\]

Type: **[**DXGI\_SWAP\_CHAIN\_DESC**](https://learn.microsoft.com/windows/win32/api/dxgi/ns-dxgi-dxgi_swap_chain_desc)\***

Description of the swap chain. See [**DXGI\_SWAP\_CHAIN\_DESC**](https://learn.microsoft.com/windows/win32/api/dxgi/ns-dxgi-dxgi_swap_chain_desc).

*ppSwapChain* \[out\]

Type: **[**IDXGISwapChain**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiswapchain)\*\***

Address of a pointer to an [**IDXGISwapChain**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiswapchain).

*ppDevice* \[out\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)\*\***

Address of a pointer to an [**ID3D10Device Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device) that will receive the newly created device.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

To create the best device, this method implements more than one device creation option. First, the method attempts to create a 10.1 device (and swap chain). If that fails, the method attempts to create a 10.0 device. If that fails, the method will fail. If your application needs to create only a 10.1 device, or a 10.0 device only, use these APIs instead:

- Use [**D3D10CreateDeviceAndSwapChain**](https://learn.microsoft.com/windows/desktop/api/D3D10Misc/nf-d3d10misc-d3d10createdeviceandswapchain) to create a Direct3D 10.0 (only) device and swap chain.
- Use [**D3D10CreateDeviceAndSwapChain1**](https://learn.microsoft.com/windows/desktop/api/D3D10_1/nf-d3d10_1-d3d10createdeviceandswapchain1) to create a Direct3D 10.1 (only) device and swap chain.

This method requires Windows Vista Service Pack 1.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

