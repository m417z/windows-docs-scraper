# IOCTL_GNSS_LISTEN_BREADCRUMBING_ALERT IOCTL

## Description

The **IOCTL_GNSS_LISTEN_BREADCRUMBING_ALERT** control code is used to request alert information from [GNSS_BREADCRUMBING_ALERT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_breadcrumbing_alert_data) when the breadcrumbing buffer has reached a level at which OS read operations should be performed.

## Parameters

### Major code

### Input buffer

Pointer to the input buffer.

### Input buffer length

Size of the input buffer.

### Output buffer

Pointer to the output buffer.

### Output buffer length

Size of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

**IOCTL_GNSS_LISTEN_BREADCRUMBING_ALERT** is defined as follows in the gnssdriver.h header file:

```cpp
#define IOCTL_GNSS_LISTEN_BREADCRUMBING_ALERT \
    CTL_CODE( FILE_DEVICE_UNKNOWN, 0x072, METHOD_BUFFERED, FILE_ANY_ACCESS )
```

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)