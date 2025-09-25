# D3DX11CreateFFT2DComplex function

## Description

Creates an [ID3DX11FFT](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11fft) COM interface object.

## Parameters

### `pDeviceContext`

Type: **[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)***

A pointer to the [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) interface to use for the FFT.

### `X`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of the first dimension of the FFT.

### `Y`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of the second dimension of the FFT.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that affect the behavior of the FFT, can be 0 or a combination of flags from [D3DX11_FFT_CREATE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_fft_create_flag).

### `pBufferInfo` [out]

Type: **[D3DX11_FFT_BUFFER_INFO](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ns-d3dcsx-d3dx11_fft_buffer_info)***

A pointer to a [D3DX11_FFT_BUFFER_INFO](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ns-d3dcsx-d3dx11_fft_buffer_info) structure that receives the buffer requirements to execute the FFT algorithms. Use this info to allocate raw buffers of the specified (or larger) sizes and then call the [ID3DX11FFT::AttachBuffersAndPrecompute](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nf-d3dcsx-id3dx11fft-attachbuffersandprecompute) method to register the buffers with the FFT object.

### `ppFFT` [out]

Type: **[ID3DX11FFT](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11fft)****

A pointer to a variable that receives a pointer to the [ID3DX11FFT](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11fft) interface for the created FFT object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[D3DCSX 11 Functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3dcsx11-functions)