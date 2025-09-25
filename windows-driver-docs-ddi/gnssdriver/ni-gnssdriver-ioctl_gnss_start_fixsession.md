# IOCTL_GNSS_START_FIXSESSION IOCTL

## Description

The **IOCTL_GNSS_START_FIXSESSION** control code is used by the GNSS adapter to start a fix session.

## Parameters

### Major code

### Input buffer

A pointer to a [GNSS_FIXSESSION_PARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_fixsession_param) structure.

### Input buffer length

Set to sizeof(GNSS_FIXSESSION_PARAM).

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

* The fix session successfully started.
* A fix session of the same type is already active and the driver does not support multiple sessions.

### GNSS adapter notes

If multi-session support is not present, the GNSS adapter ensures that multiple sessions of the same fix type are multiplexed properly so that the GNSS driver sees only one session of a given type of fix. The GNSS adapter can modify the fix session parameters of an active fix session through the [IOCTL_GNSS_MODIFY_FIXSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_modify_fixsession) call.

The GNSS adapter does not start a get fix request unless the driver completes this call and returns a success status in the output.

### GNSS driver notes

If multi-session support is not present, and the GNSS adapter sends another start fix request for a fix type that is already active, the GNSS driver must fail the new session request. The driver should not replace the previous session with the new fix session details.

Multiple fix sessions of different fix types are always supported by the GNSS driver.

Once the GNSS driver accepts the fix session parameters, validates them, and kicks off the GNSS engine, it immediately completes the I/O with a success return code. Unless the start fix session returns with a success code, the GNSS adapter will not issue a get fix request. All fixes received for this specific fix session must be delivered to the GNSS adapter against a subsequent pending get fix call from the GNSS adapter that has the same session ID. If a fix becomes available and no pending get fix call is created by the adapter, the GNSS driver is required to queue the fix up to an implementation-specific timeout value, until a pending I/O is created that represents the session ID.

Once a fix session is started, it remains active unless the fix session is explicitly stopped by the GNSS adapter. This applies to all fix types.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)