# IoDeleteDevice function

## Description

The **IoDeleteDevice** routine removes a device object from the system, for example, when the underlying device is removed from the system.

## Parameters

### `DeviceObject` [in]

Pointer to the device object to be deleted.

## Remarks

When handling a PnP [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) request, a PnP driver calls **IoDeleteDevice** to delete any associated device objects. See [Handling an IRP_MN_REMOVE_DEVICE Request](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-an-irp-mn-remove-device-request) for details.

A legacy driver should call this routine when it is being unloaded or when its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine encounters a fatal initialization error, such as being unable to properly initialize a physical device. This routine also is called when a driver reconfigures its devices dynamically. For example, a disk driver called to repartition a disk would call **IoDeleteDevice** to tear down the device objects representing partitions to be replaced.

A driver must release certain resources for which the driver supplied storage in its device extension before it calls **IoDeleteDevice**. For example, if the driver stores the pointer to its interrupt object(s) in the device extension, it must call [IoDisconnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodisconnectinterrupt) before calling **IoDeleteDevice**.

A driver can call **IoDeleteDevice** only once for a given device object.

When a driver calls **IoDeleteDevice**, the I/O manager deletes the target device object if there are no outstanding references to it. However, if any outstanding references remain, the I/O manager marks the device object as "delete pending" and deletes the device object when the references are released.

## See also

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[IoDisconnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodisconnectinterrupt)