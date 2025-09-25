## Description

The **DXGK_BRIGHTNESS_INTERFACE_3** structure contains pointers to the kernel-mode display driver's (KMD) functions for Version 3 of the Panel Brightness Control Interface.

## Members

### `Size` [in]

The size, in bytes, of this structure.

### `Version` [in]

The version number of the brightness interface. Must be set to **DXGK_BRIGHTNESS_INTERFACE_VERSION_3**. Version number constants are defined in *Dispmprt.h*.

### `Context` [out]

A pointer to a private context block.

### `InterfaceReference` [out]

A pointer to an interface reference function that is implemented by the KMD.

### `InterfaceDereference` [out]

A pointer to an interface dereference function that is implemented by the KMD.

### `SetBrightness` [out]

A pointer to the KMD's [DxgkDdiSetBrightness3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_3) function.

### `GetBrightness` [out]

A pointer to the KMD's [DxgkDdiGetBrightness3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_3) function.

### `GetBrightnessCaps` [out]

A pointer to the KMD's [DxgkDdiGetBrightnessCaps3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_caps_3) function. This function is available starting with Windows 10.

### `GetNitRanges` [out]

A pointer to the KMD's [DxgkDdiGetNitRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_nit_ranges) function. This function is available starting with Windows 10.

### `SetBacklightOptimization` [out]

A pointer to the KMD's [DxgkBrightnessSetBacklightOptimization3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_backlight_optimization_3) function. This function is available starting with Windows 10.

## Remarks

Version 3 is used by Windows Display Driver Model (WDDM) 2.4 and later KMDs that support multiple displays that can be set to calibrated nit-based brightness levels.

A kernel-mode component such as *Dxgkrnl* that must use the brightness interface initiates a call to the KMD's [DxgkDdiQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) function to retrieve the interface and passes a GUID_DEVINTERFACE_BRIGHTNESS_3 in the **InterfaceType** member of the [QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_query_interface) structure that the **QueryInterface** parameter points to.

For more information, see [Supporting brightness controls on integrated display panels](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-brightness-controls-on-integrated-display-panels).

## See also

[DXGK_BRIGHTNESS_INTERFACE_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_brightness_interface_2)

[DXGK_BRIGHTNESS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_brightness_interface)

[DxgkDdiGetBrightness3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_3)

[DxgkDdiGetPossibleBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_possible)

[DxgkddiQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface)

[DxgkDdiSetBrightness3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_3)

[QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_query_interface)