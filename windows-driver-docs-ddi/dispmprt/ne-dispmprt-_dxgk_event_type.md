# _DXGK_EVENT_TYPE enumeration

## Description

The DXGK_EVENT_TYPE enumeration indicates the event type in a call to the display miniport driver's [DxgkDdiNotifyAcpiEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_acpi_event) function.

## Constants

### `DxgkUndefinedEvent`

Indicates that a variable of type DXGK_EVENT_TYPE has not yet been assigned a meaningful value.

### `DxgkAcpiEvent`

Indicates that the event is an ACPI event.

### `DxgkPowerStateEvent`

Indicates that the event is a power state event.

### `DxgkDockingEvent`

Indicates that the event is a docking event.

### `DxgkChainedAcpiEvent`

Indicates that the ACPI event was sent to the integrated adapter but has been redirected to the driver for the discrete adapter.

Supported by WDDM 2.1 and later drivers.

## See also

[DxgkDdiNotifyAcpiEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_acpi_event)