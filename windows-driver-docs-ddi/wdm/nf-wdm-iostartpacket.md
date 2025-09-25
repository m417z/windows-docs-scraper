# IoStartPacket function (wdm.h)

## Description

The **IoStartPacket** routine calls the driver's [StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine with the given IRP or inserts the IRP into the device queue associated with the given device object if the device is already busy.

## Parameters

### `DeviceObject` [in]

Pointer to the target device object for the IRP.

### `Irp` [in]

Pointer to the IRP to be processed.

### `Key` [in, optional]

Pointer to a value that determines where to insert the packet into the device queue. If this is zero, the packet is inserted at the tail of the device queue.

### `CancelFunction` [in, optional]

Specifies the entry point for a driver-supplied [Cancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterextensionrequest-cancel) routine.

## Remarks

If the driver is already busy processing a request for the target device object, then the packet is queued in the device queue. Otherwise, this routine calls the driver's *StartIo* routine with the specified IRP.

If a non-NULL *CancelFunction* pointer is supplied, it is set in the IRP so the driver's *Cancel* routine is called if the IRP is canceled before its completion.

Drivers that do not have a *StartIo* routine cannot call **IoStartPacket**.

Callers of **IoStartPacket** must be running at IRQL <= DISPATCH_LEVEL. Usually, this routine is called from a device driver's Dispatch routine at IRQL = PASSIVE_LEVEL.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending)

[IoSetCancelRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcancelroutine)

[IoStartNextPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartnextpacket)

[IoStartNextPacketByKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartnextpacketbykey)