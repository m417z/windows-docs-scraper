# IOCTL_GNSS_LISTEN_NMEA IOCTL

## Description

The **IOCTL_GNSS_LISTEN_NMEA** control code is used to start listening for NMEA events from the driver.

## Parameters

### Major code

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

A pointer to a [GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event) structure.

### Output buffer length

Set to sizeof(GNSS_EVENT).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

The **EventType** must be set to **GNSS_Event_NmeaData**.

### GNSS adapter notes

The GNSS adapter does not use this IOCTL.

### GNSS driver notes

The driver can complete this call when it has NMEA data to send to the calling client. This calling client will typically be a test tool created by the OEM.

The calling client that wishes to receive NMEA data needs to do the following tasks:

* Ensure that NMEA logging is active.
* Ensures that this request is always pending, so that the driver can return NMEA data when available.

When the driver completes the I/O call, the calling client will need to issue another IOCTL to continue waiting for further NMEA data.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)