# IOCTL_SYSENV_ENUM_VARIABLES IOCTL

## Description

Returns information about system environment variables using
SysEnv device.

## Parameters

### Major code

### Input buffer

A boolean value indicating whether values should be included.

### Input buffer length

Size of BOOLEAN.

### Output buffer

A pointer to a buffer that contains the system environment variable information. If values have been requested, the buffer points to an array of [XVARIABLE_NAME_AND_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_xvariable_name_and_value) structures. Otherwise, returns an array of [XVARIABLE_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_xvariable_name) structures.

The location of the next entry is determined by **NextEntryOffset** of the [XVARIABLE_NAME_AND_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_xvariable_name_and_value) and [XVARIABLE_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_xvariable_name).

### Output buffer length

On input, the length in bytes of the output buffer. On output,
the length in bytes of the returned data. If the input buffer is
large enough, then this value indicates the amount of data copied
into output buffer. If the input buffer is too small, then it
indicates the required buffer length.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)