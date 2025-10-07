# D3DX10GetFeatureLevel1 function

Get a Direct3D 10.1 device interface pointer from a Direct3D 10.0 interface pointer.

## Parameters

*pDevice* \[in\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)\***

Pointer to the Direct3D 10.0 device (see the [**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device) interface).

*ppDevice* \[out\]

Type: **[**ID3D10Device1**](https://learn.microsoft.com/windows/desktop/api/D3D10_1/nn-d3d10_1-id3d10device1)\*\***

Pointer to the Direct3D 10.1 device (see the [**ID3D10Device1**](https://learn.microsoft.com/windows/desktop/api/D3D10_1/nn-d3d10_1-id3d10device1) interface).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

This function returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues). If a Direct3D 10.1 device interface can be acquired, this function succeeds and passes a pointer to the 10.1 interface using the *ppDevice* parameter. If a Direct3D 10.1 device interface cannot be acquired, this function returns E\_FAIL, and will not return anything for the *ppDevice* parameter.

## Remarks

For this function to succeed, you must have acquired the supplied [**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device) pointer using a call to the [**D3DX10CreateDevice**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10createdevice) function, the [**D3DX10CreateDeviceAndSwapChain**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10createdeviceandswapchain) function, the [**D3D10CreateDevice1**](https://learn.microsoft.com/windows/desktop/api/D3D10_1/nf-d3d10_1-d3d10createdevice1) function, or the [**D3D10CreateDeviceAndSwapChain1**](https://learn.microsoft.com/windows/desktop/api/D3D10_1/nf-d3d10_1-d3d10createdeviceandswapchain1) function.

You can only create a Direct3D 10.1 device on computers running Windows Vista Service Pack 1 or later, and with Direct3D 10.1-compatible hardware installed. This function will return E\_FAIL on any computer not meeting these requirements. However, you can call this function on any version of Windows that has the D3DX10 DLL installed.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

