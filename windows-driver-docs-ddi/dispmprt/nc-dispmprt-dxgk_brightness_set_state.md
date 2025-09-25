# DXGK_BRIGHTNESS_SET_STATE callback function

## Description

Enables smooth brightness control on an integrated display panel.

## Parameters

### `Context` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `BrightnessState` [in]

A pointer to a [DXGK_BRIGHTNESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_state) structure that indicates that the display miniport driver should enable the smooth brightness control for the integrated display panel.

## Return value

Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes that are defined in Ntstatus.h.

## Remarks

For the operating system to be able to adjust screen brightness smoothly, starting with Windows 8 the display miniport driver must report 10 brightness levels, expressed from 0 to 100 percent. At a level of zero percent, the screen contents should be barely visible to the user. A level of 100 percent is the maximum brightness that the integrated display panel can produce. The driver and hardware can support finer brightness control for internal operations.

When the [DxgkDdiSetBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set) function is called, the driver should select an appropriate slope to provide a smooth brightness transition based on panel characteristics, but any transition must complete in under 500 milliseconds.

This function should be made pageable.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiSetBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set)