# _DXGK_BACKLIGHT_INFO structure

## Description

Contains the current level of backlight reduction that is applied to the integrated display panel. Used by Windows Display Driver Model (WDDM) 1.2 and later display miniport drivers that support adaptive brightness control.

## Members

### `BacklightUsersetting` [out]

The absolute brightness level in hardware that corresponds to the current percent brightness level requested by the operating system.

This member can range in value from 0 to 65535.

### `BacklightEffective` [out]

The absolute brightness level in hardware that is currently set by the display miniport drive for adaptive brightness control.

This member can range in value from 0 to 65535.

### `GammaRamp` [out]

A [D3DDDI_GAMMA_RAMP_RGB256x3x16](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_rgb256x3x16) structure that contains a description of a gamma lookup table.
This lookup table represents the gamma ramp that has been optimized for backlight display by the display miniport driver from a gamma ramp set by an application.

## Remarks

For more information about the use of this structure, see Remarks of the [DxgkDdiGetBacklightReduction](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_backlight_reduction) function.

## See also

[D3DDDI_GAMMA_RAMP_RGB256x3x16](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_rgb256x3x16)

[DxgkDdiGetBacklightReduction](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_backlight_reduction)