# _D3DKMDT_3X4_COLORSPACE_TRANSFORM structure

## Description

Structure to describe the three programmable sub-stages of the 3 by 4 matrix color space transform.

## Members

### `ColorMatrix3x4` [in]

A 3x3 matrix and 3x1 addition to be applied to each pixel, stored in row-major order. Transforms colors within CIEXYZ.

### `ScalarMultiplier` [in]

A scalar to be multiplied into each element of ColorMatrix3x4.

### `LookupTable1D` [in]

1D look-up table. Transforms colors within the color space specified by [DXGK_SET_TIMING_PATH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_path_info).

## Remarks

## See also