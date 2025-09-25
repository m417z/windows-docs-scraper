# IOCTL_USBPRINT_GET_LPT_STATUS IOCTL

## Description

The **IOCTL_USBPRINT_GET_LPT_STATUS** request allows upper-layer software (such as a language monitor), to request and obtain the printer status byte from a USB printer.

## Parameters

### Major code

### Input buffer

Not used in this operation; set this parameter to **NULL**.

### Input buffer length

Not used in this operation; set this parameter to 0.

### Output buffer

Pointer to a DWORD containing the printer status.

### Output buffer length

sizeof(DWORD)

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Otherwise, **Status** to the appropriate error condition as an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)