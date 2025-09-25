# DXGK_BRIGHTNESS_GET callback function

## Description

The *DxgkDdiGetBrightness* function retrieves the currently active brightness level of an integrated display panel.

## Parameters

### `Context` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem.

### `Brightness` [in]

A pointer to a variable that receives the brightness level.

## Return value

*DxgkDdiGetBrightness* returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes that are defined in *Ntstatus.h*.

## Prototype

```cpp
DXGK_BRIGHTNESS_GET DxgkDdiGetBrightness;

NTSTATUS* DxgkDdiGetBrightness(
  _In_ PVOID  Context,
  _In_ PUCHAR Brightness
)
{ ... }
```

## Remarks

When the [monitor driver](https://learn.microsoft.com/windows-hardware/drivers/display/monitor-drivers) initializes, it can call the display miniport driver's *DxgkDdiGetBrightness* function to retrieve the brightness level that will be currently active for the integrated display panel.

Because the monitor driver always gets the brightness level for the integrated display panel on boot or resume and all changes in brightness go through the monitor driver, the monitor driver should always have the current brightness level cached. Therefore, when clients query for the current brightness level, the level is queried from the monitor driver and not from the display miniport driver.

*DxgkDdiGetBrightness* should be made pageable.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)