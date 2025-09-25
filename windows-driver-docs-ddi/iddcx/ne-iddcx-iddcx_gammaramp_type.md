# IDDCX_GAMMARAMP_TYPE enumeration

## Description

A **IDDCX_GAMMARAMP_TYPE** value indicates the type of gamma ramp being set.

## Constants

### `IDDCX_GAMMARAMP_TYPE_UNINITIALIZED:0`

Indicates that an **IDDCX_GAMMARAMP_TYPE** variable has not yet been assigned a meaningful value.

### `IDDCX_GAMMARAMP_TYPE_DEFAULT:1`

The gamma ramp is the default ramp.

### `IDDCX_GAMMARAMP_TYPE_RGB256x3x16:2`

The gamma lookup table that [**pGammaRampData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_set_gammaramp) points to contains an array of [**IDDCX_GAMMARAMP_RGB256x3x16**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_gammaramp_rgb256x3x16) structures.

### `IDDCX_GAMMARAMP_TYPE_3x4_COLORSPACE_TRANSFORM:3`

The gamma lookup table that [**pGammaRampData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_set_gammaramp) points to contains an array of [**IDDCX_GAMMARAMP_3X4_COLORSPACE_TRANSFORM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_gammaramp_3x4_colorspace_transform) structures.
Available starting in Windows 11, version 22H2 September Update (IddCx version 1.10).

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_MONITOR_SET_GAMMA_RAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_gamma_ramp)

[**IDARG_IN_SET_GAMMARAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_set_gammaramp)