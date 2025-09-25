# D3DDDI_GAMMARAMP_TYPE enumeration

## Description

The **D3DDDI_GAMMARAMP_TYPE** enumeration indicates the type of gamma ramp used in a video present path.

## Constants

### `D3DDDI_GAMMARAMP_UNINITIALIZED`

Indicates that a variable of type **D3DDDI_GAMMARAMP_TYPE** has not yet been assigned a meaningful value.

### `D3DDDI_GAMMARAMP_DEFAULT`

Indicates the default gamma ramp should be used.

### `D3DDDI_GAMMARAMP_RGB256x3x16`

Indicates that the gamma lookup table contains three arrays, one each for the red, green, and blue color channels. Each array has 256 16-bit values.

### `D3DDDI_GAMMARAMP_DXGI_1`

Indicates that the gamma lookup table is described by a [**D3DDDI_GAMMA_RAMP_DXGI_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_dxgi_1) structure.

### `D3DDDI_GAMMARAMP_MATRIX_3x4`

Indicates that the color space transform is defined by a D3DDDI_3X4_COLORSPACE_TRANSFORM structure.

### `D3DDDI_GAMMARAMP_MATRIX_V2`

Indicates that the color space transform is defined by a D3DKMDT_COLORSPACE_TRANSFORM_MATRIX_V2 structure.

## Remarks

The **GammaRamp** member of the [**D3DKMDT_VIDPN_PRESENT_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure is a [**D3DKMDT_GAMMA_RAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_gamma_ramp) structure. The **Type** member of the D3DKMDT_GAMMA_RAMP structure is a D3DDDI_GAMMARAMP_TYPE value.

## See also

[**D3DKMDT_COLOR_BASIS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_color_basis)