# DXGK_BRIGHTNESS_GET_CAPS callback function

## Description

Retrieves brightness control capabilities of an integrated display panel.

## Parameters

### `Context` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `BrightnessCaps` [in]

A pointer to a [DXGK_BRIGHTNESS_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_caps) structure that represents the brightness control capabilities of the display panel.

## Return value

Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes that are defined in Ntstatus.h.

## Prototype

```cpp
DXGK_BRIGHTNESS_GET_CAPS DxgkDdiGetBrightnessCaps;

NTSTATUS* DxgkDdiGetBrightnessCaps(
  _In_ PVOID                Context,
  _In_ DXGK_BRIGHTNESS_CAPS *BrightnessCaps
)
{ ... }
```

## Remarks

This function lets the display miniport driver independently indicate its support for adaptive brightness control and/or smooth brightness control.

If the hardware includes an ambient light sensor, it must support smooth brightness control. The display miniport driver, not an embedded controller, must control the smooth brightness functioning of the integrated display panel.

If the driver is started by a Plug and Play (PnP) event, it must transition smoothly from the initial brightness level set by firmware to the level set by the operating system. If additional devices are connected to the system, they must not affect the driver's ability to perform smooth brightness control on the integrated display panel.

The driver must continue to support smooth brightness control even if adaptive brightness control is initiated.

This function should be made pageable.

## See also

[DXGK_BRIGHTNESS_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_caps)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)