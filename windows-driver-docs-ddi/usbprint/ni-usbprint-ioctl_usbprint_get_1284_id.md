## Description

The **IOCTL_USBPRINT_GET_1284_ID** control code allows upper-layer software (such as a language monitor), to request and obtain the printer's IEEE 1284 device ID string.

## Parameters

### Major code

### Input buffer

Not used in this operation; set this parameter to **NULL**.

### Input buffer length

Not used in this operation; set this parameter to 0.

### Output buffer

The output buffer will contain UCHAR data. On success this buffer can hold the following: a two-byte prefix that specifies the size, in bytes, of the device's IEEE 1284 device ID; the device ID; and a null terminator. An IEEE 1284 device ID can be up to 64 KB in size. On failure, if **GetLastError** returns the error code **STATUS_BUFFER_TOO_SMALL**, the output buffer was not large enough to hold the data intended for it.

### Output buffer length

The output buffer must be large enough to contain a two-byte quantity holding the length of the device's IEEE 1284 device ID, the device ID (up to 64 KB in size), and a terminating null.

The IOCTL_USBPRINT_GET_1284_ID output buffer length is placed directly into the USB packet. On some USB print devices, using the maximum 65535 bytes can cause the call to fail with error 23. Reduce the buffer to 4094 bytes or less to resolve this issue.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)