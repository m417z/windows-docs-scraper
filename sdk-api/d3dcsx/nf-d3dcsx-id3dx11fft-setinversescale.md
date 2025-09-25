# ID3DX11FFT::SetInverseScale

## Description

Sets the scale used for inverse transforms.

## Parameters

### `InverseScale` [in]

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Scale used for inverse transforms. Setting *InverseScale* to 0 causes the default value of 1/N to be used,
where N is the product of the transformed dimension lengths.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the return codes described in the topic [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**SetInverseScale** sets the scale used by [ID3DX11FFT::InverseTransform](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nf-d3dcsx-id3dx11fft-inversetransform).

## See also

[ID3DX11FFT](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11fft)