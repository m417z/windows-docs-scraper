# IoRegisterLastChanceShutdownNotification function

## Description

The **IoRegisterLastChanceShutdownNotification** routine registers a driver to receive an [IRP_MJ_SHUTDOWN](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-shutdown) IRP when the system is shut down, after all file systems have been flushed.

## Parameters

### `DeviceObject` [in]

Pointer to the device object of the device for which the driver requests shutdown notification. The system passes this pointer to the driver's [DispatchShutdown](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch) routine.

## Return value

**IoRegisterLastChanceShutdownNotification** returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure.

## Remarks

The **IoRegisterLastChanceShutdownNotification** routine registers the driver to receive an [IRP_MJ_SHUTDOWN](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-shutdown) IRP for the specified device when the system shuts down. The driver receives one such IRP for each device it registers to receive notification for. Drivers handle **IRP_MJ_SHUTDOWN** IRPs within their [DispatchShutdown](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch) routines.

For any device that is registered with this routine, the system sends the **IRP_MJ_SHUTDOWN** IRP after all file systems are flushed. Only one driver in a device stack should register to receive shutdown notification, by calling either [IoRegisterShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistershutdownnotification) or **IoRegisterLastChanceShutdownNotification**.

If the driver ceases to require shutdown notification for that device, use [IoUnregisterShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregistershutdownnotification) to remove the driver from the shutdown notification queue.

A driver that calls **IoRegisterLastChanceShutdownNotification** must satisfy the following restrictions in its *DispatchShutdown* routine:

* The *DispatchShutdown* routine must not call any pageable routines.
* The *DispatchShutdown* routine must not access pageable memory.
* The *DispatchShutdown* routine must not perform any file I/O operations.

Most drivers that require shutdown notification should call the [IoRegisterShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistershutdownnotification) routine, which does not impose these limitations on the *DispatchShutdown* routine, and which causes the *DispatchShutdown* routine to be called before the file systems are flushed. Only drivers that must do some cleanup after the file systems are flushed, such as a driver for a mass storage device, should use **IoRegisterLastChanceShutdownNotification**.

The registered *DispatchShutdown* routine is called before the power manager sends an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) request for **PowerSystemShutdown**. The *DispatchShutdown* routine is not called for transitions to any other power states.

## See also

[DispatchShutdown](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch)

[IoRegisterShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistershutdownnotification)

[IoUnregisterShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregistershutdownnotification)