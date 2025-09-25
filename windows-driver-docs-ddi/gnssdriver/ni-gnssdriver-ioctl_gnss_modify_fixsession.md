# IOCTL_GNSS_MODIFY_FIXSESSION IOCTL

## Description

The **IOCTL_GNSS_MODIFY_FIXSESSION** control code is used by the GNSS adapter to modify the fix session parameters of an active fix session. This is only required when the GNSS driver does not support multiple fix session of the same fix type, for example, when the **SupportMultipleFixSession** capability of the driver is FALSE.

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

* The fix session was successfully modified.
* The fix session is currently stopped or not active.
* The fix session parameter could not be modified.

### GNSS adapter notes

The GNSS adapter uses this IOCTL to change the fix session parameters of an active fix session to accommodate new fix requests from the LBS applications.

If the call fails, the GNSS adapter will not multiplex the new fix request into the existing active session. Instead it will continue expecting that the active fix session has remained unchanged.

If the call succeeds, the GNSS adapter will expect the subsequent fix data to adhere to the newly specified session parameters.

### GNSS driver notes

If multi-session support is not present, the GNSS driver must support this IOCTL and change the fix session parameters on the fly for the active session.

Once the GNSS driver accepts the fix session parameters, validates them, and sends them to the GNSS engine, it should immediately complete the I/O request with a success return code.

Upon successful completion, the GNSS driver should return all fix data according to the new fix session parameters. However, fix data that’s already in the process of being provided to the GNSS adapter should still be made available and should not be discarded.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)