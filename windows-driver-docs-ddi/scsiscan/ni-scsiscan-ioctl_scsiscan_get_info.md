# IOCTL_SCSISCAN_GET_INFO IOCTL

## Description

The **IOCTL_SCSISCAN_GET_INFO** I/O control code returns device information.

## Parameters

### Major code

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

Pointer to a [SCSISCAN_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiscan/ns-scsiscan-_scsiscan_info) structure.

### Output buffer length

Size of output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

When the DeviceloControl function is called with the **IOCTL_SCSISCAN_GET_INFO** I/O control code, the caller must specify the address of a SCSISCAN_INFO structure as the function's lpOutbuffer parameter. The kernel-mode driver fills in the structure.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)