# ID3DX11FFT::SetForwardScale

## Description

Sets the scale used for forward transforms.

## Parameters

### `ForwardScale` [in]

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The scale to use for forward transforms. Setting *ForwardScale* to 0 causes the default values of 1 to be used.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the return codes described in the topic [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**SetForwardScale** sets the scale used by [ID3DX11FFT::ForwardTransform](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nf-d3dcsx-id3dx11fft-forwardtransform).

## See also

[ID3DX11FFT](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11fft)