# DXGK_BRIGHTNESS_INTERFACE_2 structure

## Description

The **DXGK_BRIGHTNESS_INTERFACE_2** structure contains pointers to functions in the Panel Brightness Control Interface Version 2. Used by WDDM 1.2 and later kernel-mode display miniport drivers (KMDs) that support adaptive and smooth brightness control.

## Members

### `Size` [in]

The size, in bytes, of this structure.

### `Version` [in]

The version number of the brightness interface. Must be set to **DXGK_BRIGHTNESS_INTERFACE_VERSION_2** for this structure.Version number constants are defined in *Dispmprt.h*.

### `Context` [in]

A pointer to a private context block.

### `InterfaceReference` [out]

Pointer to a KMD-implemented interface reference function.

### `InterfaceDereference` [out]

Pointer to a KMD-implemented interface dereference function.

### `GetPossibleBrightness` [out]

A pointer to KMD's [**DxgkDdiGetPossibleBrightness**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_possible) function.

### `SetBrightness` [out]

A pointer to KMD's [**DxgkDdiSetBrightness**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set) function.

### `GetBrightness` [out]

A pointer to KMD's [**DxgkDdiGetBrightness**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get) function.

### `GetBrightnessCaps` [out]

A pointer to KMD's [**DxgkDdiGetBrightnessCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_caps) function. This function is available starting with Windows 8.

### `SetBrightnessState` [out]

A pointer to KMD's [**DxgkDdiSetBrightnessState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_state) function. This function is available starting with Windows 8.

### `SetBacklightOptimization` [out]

A pointer to KMD's [**DxgkDdiSetBacklightOptimization**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_backlight_optimization) function. This function is available starting with Windows 8.

### `GetBacklightReduction` [out]

A pointer to KMD's [**DxgkDdiGetBacklightReduction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_backlight_reduction) function. This function is available starting with Windows 8.

## Remarks

This structure provides additional members, beyond those in the [**DXGK_BRIGHTNESS_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_brightness_interface) interface, that point to driver-implemented functions that control, measure, and optimize display panel brightness and allow smooth brightness control.

For more information, see [Supporting brightness controls on integrated display panels](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-brightness-controls-on-integrated-display-panels).

## See also

[**DXGK_BRIGHTNESS_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_brightness_interface)