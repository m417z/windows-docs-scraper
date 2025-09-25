# IOCTL_SYSENV_GET_VARIABLE IOCTL

## Description

Gets the value of the specified system environment variables using
SysEnv device.

## Parameters

### Major code

### Input buffer

A pointer to a [SYSENV_VARIABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_sysenv_variable) structure that specifies the variable..

### Input buffer length

The size of the [SYSENV_VARIABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_sysenv_variable) structure.

### Output buffer

A pointer to a [SYSENV_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_sysenv_value) structure that receives the value of the variable.

### Output buffer length

The size of the [SYSENV_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_sysenv_value) structure.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)