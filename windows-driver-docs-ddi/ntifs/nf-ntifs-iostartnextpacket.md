# IoStartNextPacket function (ntifs.h)

## Description

The **IoStartNextPacket** routine dequeues the next IRP, if any, from the given device object's associated device queue and calls the driver's [**StartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for which the IRP is to be dequeued.

### `Cancelable` [in]

Specifies whether IRPs in the device queue can be canceled.

## Remarks

If there are no IRPs currently in the device queue for the target **DeviceObject**, this routine simply returns control to the caller.

If the driver passed a pointer to a cancel routine when it called [**IoStartPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartpacket), it should pass TRUE in this routine's **Cancelable** parameter. If **Cancelable** is TRUE, the I/O manager will use the cancel spin lock to protect the device queue and the current IRP.

Drivers that do not have a **StartIo** routine cannot call **IoStartNextPacket**.

Drivers that call **IoStartNextPacket** from their **StartIo** routine should be aware of recursion issues. If a driver can call **IoStartNextPacket** on a large number of requests in succession from its **StartIo** routine (for example, when a device error occurs and the driver is clearing out it device queue), you should set the **DeferredStartIo** attribute for the device by using [**IoSetStartIoAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iosetstartioattributes) routine. This attribute ensures that the next packet will not be issued until the previous **StartIo** call returns.

Callers of **IoStartNextPacket** must be running at IRQL = DISPATCH_LEVEL. Usually, this routine is called from a device driver's [**DpcForIsr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_dpc_routine) or [**CustomDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine) routine, both of which are run at IRQL = DISPATCH_LEVEL.

## See also

[**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[**IoSetStartIoAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iosetstartioattributes)

[**IoStartNextPacketByKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartnextpacketbykey)

[**IoStartPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartpacket)