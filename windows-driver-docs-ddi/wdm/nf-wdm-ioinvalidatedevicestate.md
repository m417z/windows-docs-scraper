# IoInvalidateDeviceState function

## Description

The **IoInvalidateDeviceState** routine notifies the PnP manager that some aspect of the PnP state of a device has changed.

## Parameters

### `PhysicalDeviceObject` [in]

Pointer to the PDO for the device.

## Remarks

Drivers call this routine to indicate that something has changed with respect to one of the following aspects of a device's PnP state:

PNP_DEVICE_DISABLED

PNP_DEVICE_DONT_DISPLAY_IN_UI

PNP_DEVICE_FAILED

PNP_DEVICE_NOT_DISABLEABLE

PNP_DEVICE_REMOVED

PNP_DEVICE_RESOURCE_REQUIREMENTS_CHANGED

For descriptions of the preceding constants, see [PNP_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-an-irp-mn-surprise-removal-request#about-pnpdevicestate).

In response to this routine, the PnP manager sends an [IRP_MN_QUERY_PNP_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-pnp-device-state) request to the device stack, to determine the current PnP state of the device.

## See also

[IRP_MN_QUERY_PNP_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-pnp-device-state)

[PNP_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-an-irp-mn-surprise-removal-request#about-pnpdevicestate)