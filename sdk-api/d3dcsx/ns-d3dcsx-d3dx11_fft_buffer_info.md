# D3DX11_FFT_BUFFER_INFO structure

## Description

Describes buffer requirements for an FFT.

## Members

### `NumTempBufferSizes`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of temporary buffers needed.
Allowed range is 0 to **D3DX11_FFT_MAX_TEMP_BUFFERS**.

### `TempBufferFloatSizes`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[D3DX11_FFT_MAX_TEMP_BUFFERS]**

Minimum sizes (in FLOATs) of temporary buffers.

### `NumPrecomputeBufferSizes`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of precompute buffers required.
Allowed range is 0 to **D3DX11_FFT_MAX_PRECOMPUTE_BUFFERS**.

### `PrecomputeBufferFloatSizes`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[D3DX11_FFT_MAX_PRECOMPUTE_BUFFERS]**

Minimum sizes (in FLOATs) for precompute buffers.

## Remarks

The **D3DX11_FFT_BUFFER_INFO** structure is initialized by a call to one of the create-FFT functions
(for example, [D3DX11CreateFFT](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nf-d3dcsx-d3dx11createfft)).
For more create-FFT functions, see [D3DCSX 11 Functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3dcsx11-functions).

Use the info in **D3DX11_FFT_BUFFER_INFO** to allocate raw buffers of the specified (or larger) sizes and then call the [ID3DX11FFT::AttachBuffersAndPrecompute](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nf-d3dcsx-id3dx11fft-attachbuffersandprecompute) method to register the buffers with the FFT object.

Some FFT algorithms benefit from precomputing sin and cos. The FFT object might store precomputed data in the user-supplied buffers.

## See also

[D3DCSX 11 Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3dcsx11-structures)