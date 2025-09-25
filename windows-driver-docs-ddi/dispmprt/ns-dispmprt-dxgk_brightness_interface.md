# DXGK_BRIGHTNESS_INTERFACE structure

## Description

The **DXGK_BRIGHTNESS_INTERFACE** structure contains pointers to the kernel-mode display driver's (KMD) functions for Version 1 of the Panel Brightness Control Interface.

## Members

### `Size`

[in] The size, in bytes, of this structure.

### `Version`

[in] The version number of the brightness interface. Must be **DXGK_BRIGHTNESS_INTERFACE_VERSION_1** for this structure. Version number constants are defined in *Dispmprt.h*.

### `Context`

[out] A pointer to a private context block.

### `InterfaceReference`

[out] A pointer to an interface reference function that is implemented by the KMD.

### `InterfaceDereference`

[out] A pointer to an interface dereference function that is implemented by the KMD.

### `GetPossibleBrightness`

[out] A pointer to the KMD's [DxgkDdiGetPossibleBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_possible) function.

### `SetBrightness`

[out] A pointer to the KMD's [DxgkDdiSetBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set) function.

### `GetBrightness`

[out] A pointer to the KMD's [DxgkDdiGetBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get) function.

## Remarks

A kernel-mode component such as *Dxgkrnl* that must use the brightness interface initiates a call to the KMD's [DxgkDdiQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) function to retrieve the interface and passes a GUID_DEVINTERFACE_BRIGHTNESS in the **InterfaceType** member of the [QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_query_interface) structure that the **QueryInterface** parameter points to.

For more information, see [Supporting brightness controls on integrated display panels](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-brightness-controls-on-integrated-display-panels).

## See also

[DXGK_BRIGHTNESS_INTERFACE_3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_brightness_interface_3)

[DXGK_BRIGHTNESS_INTERFACE_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_brightness_interface_2)

[DxgkDdiGetBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get)

[DxgkDdiGetPossibleBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_possible)

[DxgkDdiQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface)

[DxgkDdiSetBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set)

[QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_query_interface)