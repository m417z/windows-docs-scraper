# _DXGK_BRIGHTNESS_STATE structure

## Description

Used to enable smooth brightness control for an integrated display panel. The display miniport driver must enable smooth brightness control when its [DxgkDdiSetBrightnessState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_state) function is called and *BrightnessState*->**SmoothBrightness** is set to 1.Used by Windows Display Driver Model (WDDM) 1.2 and later display miniport drivers.

## Members

### `SmoothBrightness` [in]

If set, the display miniport driver must enable smooth brightness control on the display panel.

Setting this member is equivalent to setting the first bit of a 32-bit value (0x00000001).

### `Reserved` [in]

This member is reserved and should be set to zero.
Setting this member is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of a 32-bit value to zeros.

### `Value` [in]

A member in the union that **DXGK_BRIGHTNESS_STATE** contains that can hold one 32-bit value that identifies information about whether the display miniport driver must support smooth brightness control.

## Remarks

Do not assume that the **SmoothBrightness** members of **DXGK_BRIGHTNESS_STATE** and [DXGK_BRIGHTNESS_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_caps) are the same. **DXGK_BRIGHTNESS_STATE**.**SmoothBrightness** is used to enable smooth brightness control on an integrated display panel. **DXGK_BRIGHTNESS_CAPS**.**SmoothBrightness** is used to query smooth brightness control capabilities of the display panel.

## See also

[DxgkDdiSetBrightnessState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_state)