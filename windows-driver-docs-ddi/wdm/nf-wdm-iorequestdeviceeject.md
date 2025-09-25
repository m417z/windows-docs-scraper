# IoRequestDeviceEject function

## Description

The **IoRequestDeviceEject** routine notifies the PnP manager that the device eject button was pressed.

## Parameters

### `PhysicalDeviceObject` [in]

Pointer to the PDO for the device.

## Remarks

Note that this routine reports a request for device eject, not media eject.

Typically, a PnP bus driver calls **IoRequestDeviceEject** to notify the PnP manager that a user pressed the device eject button on one of its child devices.

A driver calls this routine, rather than sending an [IRP_MN_EJECT](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-eject) request, because this routine allows the PnP manager to coordinate additional actions for the eject besides sending the IRP. For example, the PnP manager notifies user-mode and kernel-mode components that registered for notification of changes on the device.

The PnP manager directs an orderly shutdown of the device. The PnP manager:

1. Creates a list of other devices that are affected by this device being ejected.

   The PnP manager queries for the device's removal relations, ejection relations, and bus relations (child devices).
2. Determines whether the device and its related devices can be software-removed.

   The PnP manager sends [IRP_MN_QUERY_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-remove-device) IRPs to the drivers for the device and its related devices. The PnP manager also sends notifications to any user-mode and kernel-mode components that registered for device-change notification on the device or any of its related devices. If any of the drivers or user-mode components fail the query-remove, the PnP manager pops up a dialog box to notify the user that the eject failed.
3. Software-removes the device and its related devices.

   If the previous steps are successful, the PnP manager notifies registered drivers and applications that the device and its related devices are being software-removed. Then the PnP manager sends [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) IRPs to the drivers for the device and its related devices. Function and filter drivers detach from the device stack and delete their device objects for the device(s). The bus drivers retain the PDO(s) for the device(s), unless a device is physically gone and the bus driver omitted the device in its most recent response to [IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations)/**BusRelations** for the device's parent bus.
4. Directs the bus driver to eject the device (if possible).

   The PnP manager takes different steps, depending on the eject capabilities of the device:

   * Hot eject is supported.

     If the **EjectSupported** capability is set for the device, the device can be ejected when the system is running (is in the **PowerSystemWorking** state). The PnP manager sends an [IRP_MN_EJECT](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-eject) request to the bus driver for the device. Any function and filter drivers detached previously from the stack in response to the remove IRP, so the bus driver handles the eject IRP. When the bus driver completes the IRP, the PnP manager expects the device to be physically absent from the system.
   * Hot eject is not supported.

     In this case, the device is **Removable** but does not support eject. The PnP manager marks the device as not-present/not-working-properly. The PnP manager will not restart the device until a user physically removes it and reinserts it. In this case, the PnP manager does not send an **IRP_MN_EJECT**.A device's parent bus driver sets the capabilities for a device, including its eject capabilities, in response to an [IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities) request. A function or filter driver can optionally specify capabilities.

When a device is ejected, its child devices are physically removed from the system along with it.

A user-mode application can initiate a device eject. In that case, no driver calls this routine but the operating system calls the PnP manager to initiate the steps listed above.

Callers of **IoRequestDeviceEject** must be running at IRQL <= DISPATCH_LEVEL. The PnP manager performs most of its device-eject tasks listed above at IRQL = PASSIVE_LEVEL.

## See also

[IRP_MN_EJECT](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-eject)

[IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations)

[IRP_MN_QUERY_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-remove-device)

[IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device)