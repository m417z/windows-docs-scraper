# IDARG_IN_SET_GAMMARAMP structure

## Description

The OS passes an **IDARG_IN_SET_GAMMARAMP** structure to [**EVT_IDD_CX_MONITOR_SET_GAMMA_RAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_gamma_ramp) with input information about the gamma ramp being set.

## Members

### `Type`

[in] A [**IDDCX_GAMMARAMP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_gammaramp_type) value that specifies the type of gamma ramp being set.

### `GammaRampSizeInBytes`

[in] Size in bytes of the provided gamma ramp data that **pGammaRampData** points to. Set to zero for [**IDDCX_GAMMARAMP_TYPE_DEFAULT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_gammaramp_type).

### `pGammaRampData`

[in] Pointer to the gamma ramp data to set. The driver should cast this field based on the gamma ramp **Type**. **pGammaRampData** is set to NULL for [**IDDCX_GAMMARAMP_TYPE_DEFAULT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_gammaramp_type).

## See also

[**EVT_IDD_CX_MONITOR_SET_GAMMA_RAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_gamma_ramp)

[**IDDCX_GAMMARAMP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_gammaramp_type)