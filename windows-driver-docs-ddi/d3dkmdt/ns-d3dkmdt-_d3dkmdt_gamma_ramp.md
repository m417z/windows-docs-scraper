# D3DKMDT_GAMMA_RAMP structure

## Description

The **D3DKMDT_GAMMA_RAMP** structure contains descriptive information about a gamma lookup table and a pointer to the lookup table.

## Members

### `Type`

A [**D3DDDI_GAMMARAMP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_gammaramp_type) enumerator that specifies the format of the lookup table.

### `DataSize`

The size, in bytes, of the lookup table pointed to by **Data**.

### `Data`

[in] A union that contains one of the following ways to access the lookup table data depending on the value in the Type member:

### `Data.pRgb256x3x16`

If **Type** is equal to D3DDDI_GAMMARAMP_RGB256x3x16, this member is a pointer to a [**D3DDDI_GAMMA_RAMP_RGB256x3x16**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_rgb256x3x16) structure that contains the lookup table.

### `Data.pDxgi1`

If **Type** is equal to D3DDDI_GAMMARAMP_DXGI_1, this member is a pointer to a [**D3DDDI_GAMMA_RAMP_DXGI_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_dxgi_1) structure that contains the lookup table.

### `Data.p3x4`

If **Type** is D3DDDI_GAMMARAMP_MATRIX_3x4, this member is a pointer to a [**D3DDDI_3x4_COLORSPACE_TRANSFORM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dkmdt_3x4_colorspace_transform) structure which describes the 3 by 4 matrix color space transform to be applied, a scalar multiplier, and the lookup table. Available starting in WDDM 2.3.

### `Data.pMatrixV2`

If **Type** is equal to D3DDDI_GAMMARAMP_MATRIX_V2, this member is a pointer to a [**D3DKMDT_COLORSPACE_TRANSFORM_MATRIX_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dkmdt_colorspace_transform_matrix_v2) structure that contains the lookup table. Available starting in WDDM 2.6.

### `Data.pRaw`

This member provides an alternative way to access the lookup table data. For example, for copying the lookup table, VOID* might be more convenient than D3DDDI_GAMMA_RAMP_RGB256x3x16.

## Remarks

The **GammaRamp** member of the [**D3DKMDT_VIDPN_PRESENT_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure is a D3DKMDT_GAMMA_RAMP structure.