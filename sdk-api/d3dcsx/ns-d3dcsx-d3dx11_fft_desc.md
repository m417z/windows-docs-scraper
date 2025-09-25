# D3DX11_FFT_DESC structure

## Description

Describes an FFT.

## Members

### `NumDimensions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of dimension in the FFT.

### `ElementLengths`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[D3DX11_FFT_MAX_DIMENSIONS]**

Length of each dimension in the FFT.

### `DimensionMask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of [D3DX11_FFT_DIM_MASK](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_fft_dim_mask) flags indicating the dimensions to transform.

### `Type`

Type: **[D3DX11_FFT_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_fft_data_type)**

[D3DX11_FFT_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_fft_data_type) flag indicating the type of data being transformed.

## See also

[D3DCSX 11 Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3dcsx11-structures)