## Description

The **IDDCX_GAMMARAMP_3X4_COLORSPACE_TRANSFORM** structure contains a 3x4 color space gamma ramp for a monitor.

## Members

### `MatrixEnabled`

A Boolean value. If set TRUE, **ColorMatrix3x4** contains a valid matrix and **ScalarMultiplier** contains a valid value, both of which should be applied.

### `ColorMatrix3x4[3]`

A 3x3 matrix and 3x1 addition to be applied to each pixel, stored in row-major order. Transforms colors within CIEXYZ.

### `ScalarMultiplier`

A scalar to be multiplied into each element of **ColorMatrix3x4**.

### `LutEnabled`

A Boolean value. If set TRUE, **LookupTable1D** contains a valid table that should be applied.

### `LookupTable1D[4096]`

A one-dimensional look-up table of [**IDDCX_RGB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_rgb) structures that transform colors within the color space specified by [**IDDCX_PATH2::WireFormatInfo.ColorSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_path2).

## Remarks

The gamma lookup table can contain a 3x4 matrix, a scalar multiplier and a LUT. This value is only specified for console drivers.

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_MONITOR_SET_GAMMA_RAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_gamma_ramp)

[**IDARG_IN_SET_GAMMARAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_set_gammaramp)

[**IDDCX_RGB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_rgb)