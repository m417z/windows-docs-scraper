# ID3DX11FFT::InverseTransform

## Description

Performs an inverse FFT.

## Parameters

### `pInputBuffer` [in]

Type: **const [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)***

Pointer to [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview) onto the input buffer.

### `ppOutputBuffer` [in, out]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)****

Pointer to a [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview) pointer. If **ppOutput* is **NULL**, then the computation will switch
between temp buffers; in addition, the last buffer written to is stored at **ppOutput*.
Otherwise, **ppOutput* is used as the output buffer (which might incur an extra copy).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the return codes described in the topic [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3DX11FFT](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11fft)