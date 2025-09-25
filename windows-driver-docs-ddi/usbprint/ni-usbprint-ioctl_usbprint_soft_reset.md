# IOCTL_USBPRINT_SOFT_RESET IOCTL

## Description

The **IOCTL_USBPRINT_SOFT_RESET** request allows upper-layer software (such as a language monitor), to issue a class-specific soft reset command to the printer.

## Parameters

### Major code

### Input buffer

Not used with this operation; set this parameter to **NULL**.

### Input buffer length

Not used with this operation; set this parameter to 0.

### Output buffer

Not used with this operation; set this parameter to **NULL**.

### Output buffer length

Not used with this operation; set this parameter to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)