# DXGKDDI_LINK_DEVICE callback function

## Description

The optional *DxgkDdiLinkDevice* function queries the display miniport driver for information on the linked adapter configuration.

## Parameters

### `PhysicalDeviceObject` [in]

A pointer to a physical device object (PDO) that identifies a display adapter.

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem.

### `LinkedDevice` [in, out]

A pointer to a [LINKED_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_linked_device) structure that contains information on the linked display adapter configuration.

## Return value

*DxgkDdiLinkDevice* returns STATUS_SUCCESS, or an appropriate error code if information on the linked adapter configuration cannot be obtained.

## Remarks

The *DxgkDdiLinkDevice* function should be implemented by drivers of display adapters that support linked display adapters.

If this function is provided, the operating system will query the display miniport driver for the linked adapter configuration immediately after a call is made to [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device).

If the operating system does not enumerate all the expected display adapters in the structure pointed to by *LinkedDevice*, the system will start in VGA mode.

The driver can enumerate only one leading link in the chain of linked display adapters.

Plug and Play or power events cause the leading linked adapter to power up or start after the remaining linked adapters, or, conversely, such events cause the leading linked adapter to power down or to be disabled before the remaining linked adapters.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[LINKED_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_linked_device)