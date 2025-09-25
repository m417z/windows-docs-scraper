## Description

The **IOCTL_USBPRINT_VENDOR_SET_COMMAND** request allows upper-layer software (such as a language monitor) to issue a vendor-specific SET command to the target device.

## Parameters

### Major code

### Input buffer

A pointer to an input buffer, an array of UCHAR elements. The meaning of each array element is shown in the following table.

| Array Element | Contents |
|---|---|
| *lpInBuffer*\[0\] | Vendor request code |
| *lpInBuffer*\[1\] | Vendor request value (most significant byte) |
| *lpInBuffer*\[2\] | Vendor request value (least significant byte) |
| *lpInBuffer*\[3\], ... | Any additional data to be sent as part of the command |

### Input buffer length

The size of the input buffer, in bytes.

### Output buffer

Not used in this operation; set this parameter to **NULL**.

### Output buffer length

Not used in this operation; set this parameter to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[IOCTL_USBPRINT_VENDOR_GET_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbprint/ni-usbprint-ioctl_usbprint_vendor_get_command)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)