# IOCTL_GNSS_LISTEN_DRIVER_REQUEST IOCTL

## Description

The **IOCTL_GNSS_LISTEN_DRIVER_REQUEST** control code is used by the GNSS driver to get data from the HLOS.

## Parameters

### Major code

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

A pointer to a [GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event) structure.

The **EventType** must be set to **GNSS_Event_DriverRequest** and the **DriverRequestedData** member filled in.

### Output buffer length

Set to sizeof(GNSS_EVENT).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### GNSS adapter notes

The GNSS adapter keeps a pending request all the time.

When the driver completes the I/O call, the adapter issues another IOCTL to receive the next driver request.

### GNSS driver notes

There will be a pending IOCTL all the time. Whenever there is a need to request data from HLOS the I/O operation should be completed. The GNSS driver should fill out the required data requested by filling the [GNSS_DRIVER_REQUEST_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_driver_request_data) structure.

The driver should use this IOCTL to get data in only rare circumstances and not during normal operations. On possible use case would be to request SUPL configuration if somehow the configuration is lost.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)