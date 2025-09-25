# IOCTL_GNSS_STOP_FIXSESSION IOCTL

## Description

The **IOCTL_GNSS_STOP_FIXSESSION** control code is used by the GNSS adapter to stop an active fix session.

## Parameters

### Major code

### Input buffer

A pointer to a [GNSS_STOPFIXSESSION_PARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_stopfixsession_param) structure.

### Input buffer length

Set to sizeof(GNSS_STOPFIXSESSION_PARAM).

### Output buffer

Set to NULL.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

The driver sets an NTSTATUS value to indicate one of the following results.

* The fix session successfully stopped.
* The fix session is already stopped or is not active.

### GNSS adapter notes

The GNSS adapter always issues a stop fix for every successful start fix. If multi-session support is not present, the GNSS adapter stops any active fix session of the same type before issuing a new start fix request.

### GNSS driver notes

The GNSS driver must cancel/stop all pending fix requests and then complete the I/O so that when this call returns, the adapter does not receive any fix data pertaining to the stopped session.

If no other fix sessions are active, the GNSS driver should keep the GNSS engine in a cold state.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)