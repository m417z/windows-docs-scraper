# D3DX10CreateDevice function

Create the best Direct3D 10 device that represents the display adapter. If a Direct3D 10.1-compatible device can be created, it will be possible to acquire an [**ID3D10Device1 Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10_1/nn-d3d10_1-id3d10device1) pointer from the returned device interface pointer.

## Parameters

*pAdapter* \[in\]

Type: **[**IDXGIAdapter**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiadapter)\***

Pointer to the display adapter (see the [**IDXGIAdapter**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiadapter) interface) when creating a hardware device; otherwise set this parameter to **NULL**. If **NULL** is specified when creating a hardware device, Direct3D will use the first adapter enumerated by the [**IDXGIFactory**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgifactory) interface.

*DriverType* \[in\]

Type: **[**D3D10\_DRIVER\_TYPE**](https://learn.microsoft.com/windows/desktop/api/D3D10misc/ne-d3d10misc-d3d10_driver_type)**

The device-driver type (see the [**D3D10\_DRIVER\_TYPE**](https://learn.microsoft.com/windows/desktop/api/D3D10misc/ne-d3d10misc-d3d10_driver_type) enumeration). The driver type determines the type of device you will create.

*Software* \[in\]

Type: **[**HMODULE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to a loaded module that implements a software driver (such as D3D10Ref.dll). To get a handle, call the [GetModuleHandle](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlea) function.

*Flags* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Device creation flags (see the [**D3D10\_CREATE\_DEVICE\_FLAG**](https://learn.microsoft.com/windows/desktop/api/D3D10/ne-d3d10-d3d10_create_device_flag) enumeration) that enable [API layers](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-programming-guide-api-features-layers). These flags can be bitwise OR'd together.

*ppDevice* \[out\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)\*\***

Address of a pointer to the device created (see the [**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device) interface).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

This function returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This function attempts to create the best device for the hardware. First, the function attempts to create a 10.1 device. If a 10.1 device cannot be created, the function attempts to create a 10.0 device. If neither device is successfully created, the function returns E\_FAIL.

If your application needs to create only a 10.1 device, or a 10.0 device only, use the following functions instead:

- Use the [**D3D10CreateDevice**](https://learn.microsoft.com/windows/desktop/api/D3D10Misc/nf-d3d10misc-d3d10createdevice) function to create a Direct3D 10.0 device only.
- Use the [**D3D10CreateDevice1**](https://learn.microsoft.com/windows/desktop/api/D3D10_1/nf-d3d10_1-d3d10createdevice1) function to create a Direct3D 10.1 device only.
- Use the [**D3DX10GetFeatureLevel1**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10getfeaturelevel1) function to get an [**ID3D10Device1**](https://learn.microsoft.com/windows/desktop/api/D3D10_1/nn-d3d10_1-id3d10device1) interface pointer from an [**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device) interface pointer.

A Direct3D 10.1 device can only be created on computers running Windows Vista Service Pack 1 or later, and with Direct3D 10.1-compatible hardware installed. However, it is legal to call this function on computers running any version of Windows that has the D3DX10 DLL installed.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

