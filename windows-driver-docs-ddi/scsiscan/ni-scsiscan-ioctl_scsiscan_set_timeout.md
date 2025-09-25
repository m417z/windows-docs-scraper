# IOCTL_SCSISCAN_SET_TIMEOUT IOCTL

## Description

The **IOCTL_SCSISCAN_SET_TIMEOUT** control code modifies the time-out value used by the kernel-mode still image driver for SCSI buses when it accesses a device.

## Parameters

### Major code

### Input buffer

The location containing a time-out value, in half seconds.

### Input buffer length

Size of the input buffer

### Output buffer

Set to NULL.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

When the kernel-mode SCSI still image driver sends a SCSI command to a device, by default the driver waits 30 seconds before timing out the operation. You can change the time-out value for a device by calling the **DeviceloControl** function with the [IOCTL_SCSISCAN_CMD](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiscan/ni-scsiscan-ioctl_scsiscan_cmd) control code. The specified time-out value stays in effect until the device is closed.

Time-out values are specified in half seconds. Thus a specified value of 100 causes the driver to wait 50 seconds before timing out the device.

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).

### Code example

```cpp
ULONG timeout = 240;
fRet = DeviceIoControl( m_DeviceDataHandle,
        (DWORD)IOCTL_SCSISCAN_SET_TIMEOUT,
        &timeout,
        sizeof(ULONG),
        NULL, NULL, &dwBytesReturned, NULL);
```

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)