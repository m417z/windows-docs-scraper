# IOCTL_ACPI_GET_DEVICE_SPECIFIC_DATA IOCTL

## Description

The **IOCTL_ACPI_GET_DEVICE_SPECIFIC_DATA** control code is used to get device specific data.

## Parameters

### Major code

### Input buffer

An input buffer structure that depends on the type of input arguments to be passed to the control method.

### Input buffer length

The size, in bytes, of the input buffer.

### Output buffer

An output buffer structure that contains the output arguments from the control method.

### Output buffer length

The size, in bytes, of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)