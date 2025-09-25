# IOCTL_GNSS_GET_FIXDATA IOCTL

## Description

The **IOCTL_GNSS_GET_FIXDATA**
control code is used by the GNSS adapter to register to receive the next fix data from an active fix session. This IOCTL provides the GNSS driver with a pending I/O request, the asynchronous resolution of which notifies the adapter that data is being provided through the overlapped structures **GnssEvent** member as a data buffer. The GnssEvent member is a [GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event) structure.

## Parameters

### Major code

### Input buffer

Pointer to a DWORD value that represents the fix session ID.

### Input buffer length

Set to sizeof(DWORD).

### Output buffer

Set to NULL

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### Input

**FixSessionID**: Session ID for an active fix.

### Output

[GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event)

The **EventType** element must be set to **GNSS_Event_FixAvailable**.

The data associated with this event is of type [GNSS_FIXDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_fixdata).

### GNSS adapter notes

The GNSS adapter issues one or more get fix request after starting a fix session. This call creates a pending I/O against which the GNSS driver can return fix data when it is available from the underlying GNSS engine or cache value.

### GNSS driver notes

Whenever a fix data is ready, the driver fills the buffer and completes the I/O. The driver must ensure that the data is returned for the specified fix session ID.

Whenever fix data is ready, the driver must fill the buffer and complete the I/O request. It is the driver’s responsibility to ensure that the data is returned for the specified fix session ID. Additionally, when a fix session is stopped by the GNSS adapter issuing an [IOCTL_GNSS_STOP_FIXSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_stop_fixsession), the driver must cancel all pending get fix requests for the given fix session ID.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)