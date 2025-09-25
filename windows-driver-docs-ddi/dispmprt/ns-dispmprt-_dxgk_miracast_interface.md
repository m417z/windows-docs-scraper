# _DXGK_MIRACAST_INTERFACE structure

## Description

Contains pointers to functions in the [Wireless display (Miracast) interface](https://learn.microsoft.com/windows-hardware/drivers/display/wireless-displays--miracast-#miracast-reference) that the display miniport driver implements to create, destroy, query, and control Miracast device resources.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The version number of the Miracast interface. Version number constants are defined in Dispmprt.h (for example, DXGK_MIRACAST_DISPLAY_INTERFACE_VERSION_1).

### `Context`

A pointer to a context that is provided by the display miniport driver.

### `InterfaceReference`

A pointer to an interface reference function that is implemented by the display miniport driver.

### `InterfaceDereference`

A pointer to an interface dereference function that is implemented by the display miniport driver.

### `DxgkDdiMiracastQueryCaps`

A pointer to the display miniport driver's [DxgkDdiMiracastQueryCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_query_caps) function.

### `DxgkDdiMiracastCreateContext`

A pointer to the display miniport driver's [DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context) function.

### `DxgkDdiMiracastIoControl`

A pointer to the display miniport driver's [DxgkDdiMiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_handle_io_control) function.

### `DxgkDdiMiracastDestroyContext`

A pointer to the display miniport driver's [DxgkDdiMiracastDestroyContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_destroy_context) function.

## Remarks

When the graphics adapter is started, the Microsoft DirectX graphics kernel subsystem calls the display miniport driver's [DxgkDdiQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) function to retrieve the interface.

If the driver does not support Miracast displays, it should fail the query for this interface.

If the driver supports Miracast displays, then it must also support High-bandwidth Digital Content Protection (HDCP).

For more info on how to use the Miracast interface, see [WDDM display miniport driver tasks to support Miracast wireless displays](https://learn.microsoft.com/windows-hardware/drivers/display/wddm-display-miniport-driver-tasks-to-support-miracast-wireless-displays).

## See also

[DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context)

[DxgkDdiMiracastDestroyContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_destroy_context)

[DxgkDdiMiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_handle_io_control)

[DxgkDdiMiracastQueryCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_query_caps)

[DxgkDdiQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface)