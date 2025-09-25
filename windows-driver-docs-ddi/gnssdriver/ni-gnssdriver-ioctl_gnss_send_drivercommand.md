# IOCTL_GNSS_SEND_DRIVERCOMMAND IOCTL

## Description

The **IOCTL_GNSS_SEND_DRIVERCOMMAND** control code is used by the GNSS adapter to execute well-defined commands on the driver and also to set driver configuration parameters. Each call specifies a certain command type, and the associated data for the command (if one is applicable) through the [GNSS_DRIVERCOMMAND_PARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_drivercommand_param) structure.

## Parameters

### Major code

### Input buffer

A pointer to a [GNSS_DRIVERCOMMAND_PARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_drivercommand_param) structure.

### Input buffer length

Set to sizeof(GNSS_DRIVERCOMMAND_PARAM).

### Output buffer

Set to NULL.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

The driver sets one of the following NTSTATUS values to indicate the result.

* STATUS_SUCCESS
* Command Not Supported
* Command Not Executed
* Command Deferred
* Command Failed

### GNSS adapter notes

With the exception of a few commands, the GNSS adapter generally ignores any failures encountered in executing a specific command.

### GNSS driver notes

If the GNSS driver does not support a specific command, it indicates so. Drivers are not required to support all commands defined in this protocol. The driver should complete the I/O only after finishing executing of the command.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)