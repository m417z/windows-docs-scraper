# ID3DX11FFT::AttachBuffersAndPrecompute

## Description

Attaches buffers to an FFT context and performs any required precomputations.

## Parameters

### `NumTempBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of buffers in *ppTempBuffers*.

### `ppTempBuffers` [in]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)***

A pointer to an array of [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview) pointers for the temporary buffers to attach. The FFT object might use these temporary buffers for its algorithm.

### `NumPrecomputeBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of buffers in *ppPrecomputeBuffers*.

### `ppPrecomputeBufferSizes` [in]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)***

A pointer to an array of [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview) pointers for the precompute buffers to attach. The FFT object might store precomputed data in these buffers.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the return codes described in the topic [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The [D3DX11_FFT_BUFFER_INFO](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ns-d3dcsx-d3dx11_fft_buffer_info) structure is initialized by a call to one of the create-FFT functions
(for example, [D3DX11CreateFFT](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nf-d3dcsx-d3dx11createfft)). For more create-FFT functions, see [D3DCSX 11 Functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3dcsx11-functions).

Use the info in [D3DX11_FFT_BUFFER_INFO](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ns-d3dcsx-d3dx11_fft_buffer_info) to allocate raw buffers of the specified (or larger) sizes and then call the **AttachBuffersAndPrecompute** to register the buffers with the FFT object.

Although you can share temporary buffers between multiple
device contexts, we recommend not to concurrently execute multiple FFT objects that share temporary buffers.

Some FFT algorithms benefit from precomputing sin and cos. The FFT object might store precomputed data in the user-supplied precompute buffers.

## See also

[ID3DX11FFT](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11fft)