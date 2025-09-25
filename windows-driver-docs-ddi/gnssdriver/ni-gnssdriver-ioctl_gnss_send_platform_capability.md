# IOCTL_GNSS_SEND_PLATFORM_CAPABILITY IOCTL

## Description

The **IOCTL_GNSS_SEND_PLATFORM_CAPABILITY** control code is used by the GNSS adapter to communicate the various location-specific platform capabilities. The GNSS driver can use this data in various ways. For example, if the platform does not support injection of assistance data, the GNSS driver can use the mobile operation network to seek such information. The use of the individual capability information is optional and the driver can ignore the platform capability information for its operation.

## Parameters

### Major code

### Input buffer

A pointer to a [GNSS_PLATFORM_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_platform_capability) structure.

### Input buffer length

Set to sizeof(GNSS_PLATFORM_CAPABILITY).

### Output buffer

Set to NULL.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

The driver sets one of the following NTSTATUS values to indicate result.

* **STATUS_SUCCESS**, when the driver processes the capability information successfully.
* **Failed**, when the driver does not process the capability information successfully.
* **Ignored**, when the driver ignores the capability information.

### GNSS adapter notes

This is a void fire-and-forget style call to the driver. The GNSS adapter does not do any special error handling even when the call fails.

### GNSS driver notes

The driver can record the capability information in state variables and pass on to the engine as needed. The I/O should be completed as soon as the configuration information is copied.

This should be called when the GNSS adapter is initializing the GNSS driver.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)