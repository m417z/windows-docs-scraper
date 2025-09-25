# IoRegisterShutdownNotification function

## Description

The **IoRegisterShutdownNotification** routine registers the driver to receive an [IRP_MJ_SHUTDOWN](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-shutdown) IRP when the system is shut down.

## Parameters

### `DeviceObject` [in]

Pointer to the device object of the device for which the driver requests shutdown notification. The system passes this pointer to the driver's [DispatchShutdown](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch) routine.

## Return value

**IoRegisterShutdownNotification** returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure.

## Remarks

The **IoRegisterShutdownNotification** routine registers the driver to receive an [IRP_MJ_SHUTDOWN](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-shutdown) IRP for the specified device when the system shuts down. The driver receives one such IRP for each device it registers to receive notification for. Drivers handle **IRP_MJ_SHUTDOWN** IRPs within their [DispatchShutdown](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch) routines.

If the driver ceases to require shutdown notification for the device, use [IoUnregisterShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregistershutdownnotification) to remove the driver from the shutdown notification queue.

Only one driver in a device stack should register to receive shutdown notification.

The system sends the driver the **IRP_MJ_SHUTDOWN** request before it flushes the file systems. Some drivers, such as drivers for mass storage devices, can require shutdown notification after the system flushes the file systems. To receive shutdown notification for a device after the file systems are flushed, use the [IoRegisterLastChanceShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterlastchanceshutdownnotification) routine instead.

The registered *DispatchShutdown* routine is called before the power manager sends an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) request for **PowerSystemShutdown**. The *DispatchShutdown* routine is not called for transitions to any other power states.

A driver writer can make no assumptions about the order in which the driver's *DispatchShutdown* routine will be called in relation to other such routines or to other shutdown activities.

A PnP driver might register a shutdown routine to perform certain tasks before system shutdown starts, such as locking down code.

## See also

[DispatchShutdown](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch)

[IoRegisterLastChanceShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterlastchanceshutdownnotification)

[IoUnregisterShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregistershutdownnotification)