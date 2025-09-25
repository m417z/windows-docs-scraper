# IOCTL_SYSENV_SET_VARIABLE IOCTL

## Description

Sets the value of the specified system environment variables using
SysEnv device.

## Parameters

### Major code

### Input buffer

A pointer to a [XVARIABLE_NAME_AND_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_xvariable_name_and_value) structure that contains the information to set.

### Input buffer length

The size of the [XVARIABLE_NAME_AND_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsysenv/ns-ntddsysenv-_xvariable_name_and_value) structure.

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)