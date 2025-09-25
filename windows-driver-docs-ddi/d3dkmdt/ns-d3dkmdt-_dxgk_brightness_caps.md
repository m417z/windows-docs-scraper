# _DXGK_BRIGHTNESS_CAPS structure

## Description

Identifies brightness control capabilities of an integrated display panel that the display miniport driver provides through a call to its [DxgkDdiGetBrightnessCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_caps) function. Used by Windows Display Driver Model (WDDM) 1.2 and later display miniport drivers.

## Members

### `SmoothBrightness` [in]

If set, the integrated display panel supports smooth brightness control.

Setting this member is equivalent to setting the first bit of a 32-bit value (0x00000001).

### `AdaptiveBrightness` [in]

If set, the integrated display panel supports adaptive brightness control.

Setting this member is equivalent to setting the second bit of a 32-bit value (0x00000002).

### `NitsBrightness` [in]

Nit-based brightness support. If **NitsBrightness** is set, then the display brightness is calibrated to correspond to absolute brightness levels measured in nits. Calibrated data provided to the Display Driver by OEMs should be taken with an On Pixel Ratio (OPR) percentage of 100% where each pixel is set to an RGB value of (255, 255, 255) or floating point equivalent.

If **NitsBrightness** is not set, then the OS will interpret all values that are defined in nits/millinits, for example [DXGK_BRIGHTNESS_NIT_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_nit_range), as uncalibrated thousandths of a percent of the maximum brightness level.

### `Reserved` [in]

This member is reserved and should be set to zero.
Setting this member is equivalent to setting the remaining 30 bits (0xFFFFFFFC) of a 32-bit value to zeros.

### `Value` [in]

A member in the union that **DXGK_BRIGHTNESS_CAPS** contains that can hold one 32-bit value that identifies information about the display miniport driver's brightness control capabilities.

## Remarks

Do not assume that the **SmoothBrightness** members of [DXGK_BRIGHTNESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_state) and **DXGK_BRIGHTNESS_CAPS** are the same. **DXGK_BRIGHTNESS_STATE**.**SmoothBrightness** is used to enable smooth brightness control on an integrated display panel. **DXGK_BRIGHTNESS_CAPS**.**SmoothBrightness** is used to query smooth brightness control capabilities of the integrated display panel.

## See also

[DXGK_BRIGHTNESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_state)

[DxgkDdiGetBrightnessCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_caps)