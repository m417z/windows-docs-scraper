## Description

The **IDDCX_GAMMARAMP_RGB256x3x16** structure contains an RGB gamma ramp for a monitor.

## Members

### `Red[256]`

An array of 16-bit values that specify the gamma function for the red color channel.

### `Green[256]`

An array of 16-bit values that specify the gamma function for the green color channel.

### `Blue[256]`

An array of 16-bit values that specify the gamma function for the blue color channel.

## Remarks

**IDDCX_GAMMARAMP_RGB256x3x16** has three arrays, one each for the red, green, and blue color channels. Each array has 256 16-bit values.

## See also

[**EVT_IDD_CX_MONITOR_SET_GAMMA_RAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_gamma_ramp)

[**IDARG_IN_SET_GAMMARAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_set_gammaramp)