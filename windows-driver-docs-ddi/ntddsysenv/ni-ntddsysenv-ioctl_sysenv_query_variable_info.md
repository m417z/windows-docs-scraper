# IOCTL_SYSENV_QUERY_VARIABLE_INFO IOCTL

## Description

Returns information about system environment variables using
SysEnv device.

## Parameters

### Major code

### Input buffer

A pointer to a ULONG variable that contains the attributes of the system environment variable.

### Input buffer length

Size of ULONG.

### Output buffer

A pointer to a [SYSENV_VARIABLE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_sysenv_variable_info) structure that contains variable information.

### Output buffer length

The size of the [SYSENV_VARIABLE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_sysenv_variable_info) structure.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)