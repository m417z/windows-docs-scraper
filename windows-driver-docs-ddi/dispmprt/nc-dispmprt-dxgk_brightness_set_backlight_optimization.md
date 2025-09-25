# DXGK_BRIGHTNESS_SET_BACKLIGHT_OPTIMIZATION callback function

## Description

Called by the Microsoft DirectX graphics kernel subsystem to set the level of optimization that the display miniport driver uses to control the brightness of an integrated display panel.

## Parameters

### `Context` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `OptimizationLevel` [in]

A value of type [DXGK_BACKLIGHT_OPTIMIZATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_backlight_optimization_level) that indicates the optimization level of brightness control.

## Return value

Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes that are defined in Ntstatus.h.

## Remarks

The display miniport driver can dynamically change the backlight optimization level of the integrated display panel based upon the current content on the screen.

The driver must respond to requests from the operating system to change the backlight optimization level in the *OptimizationLevel* parameter. Such requests are based upon system state changes.

After the driver has enabled adaptive brightness on the display panel in response to a call to the [DxgkDdiSetBrightnessState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_state) function, it must not disable adaptive brightness.

When the driver transitions from one backlight optimization level to another, it should make a gradual transition in brightness settings of the integrated display panel. An important example of this type of transition is when a user adjusts video playback controls and the operating system responds by resetting the value of *OptimizationLevel* from **DxgkBacklightOptimizationDynamic** to **DxgkBacklightOptimizationDesktop**.

Connecting additional display devices to the system must not compromise the ability of the driver to perform adaptive brightness control on the integrated display panel.

This function should be made pageable.

## See also

[DXGK_BACKLIGHT_OPTIMIZATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_backlight_optimization_level)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiSetBrightnessState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_state)