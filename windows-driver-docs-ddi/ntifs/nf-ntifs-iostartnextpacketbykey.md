# IoStartNextPacketByKey function (ntifs.h)

## Description

The **IoStartNextPacketByKey** routine dequeues the next I/O request packet from the specified device object's associated device queue according to a specified sort-key value and calls the driver's [**StartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine with that IRP.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for which the IRP is to be dequeued.

### `Cancelable` [in]

Specifies whether IRPs in the device queue can be canceled.

### `Key` [in]

Specifies the sort key that determines which entry to remove from the queue.

## Remarks

If there are no IRPs currently in the device queue for the target device object, this routine simply returns control to the caller.

If the driver passed a pointer to a cancel routine when it called [**IoStartPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartpacket), it should pass TRUE in this routine's **Cancelable** parameter. If **Cancelable** is TRUE, the I/O manager will use the cancel spin lock to protect the device queue and the current IRP.

Drivers that do not have a **StartIo** routine cannot call **IoStartNextPacketByKey**.

Callers of **IoStartNextPacketByKey** must be running at IRQL <= DISPATCH_LEVEL. Usually, this routine is called from a device driver's [**DpcForIsr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_dpc_routine) or [**CustomDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine) routine, both of which are run at IRQL = DISPATCH_LEVEL.

## See also

[**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[**IoStartNextPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartnextpacket)

[**IoStartPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartpacket)