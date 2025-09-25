# IOCTL_GNSS_LISTEN_ERROR IOCTL

## Description

The **IOCTL_GNSS_LISTEN_ERROR**
control code is used to start listening for ERROR events from the driver.

## Parameters

### Major code

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

A pointer to a [GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event) structure.

The EventType must be set to GNSS_Event_Error and the ErrorCode, IsRecoverable and ErrorDescription members of ErrorInformation filled in.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### GNSS adapter notes

The GNSS adapter ensures that this request is always pending, so that the driver can indicate an error.

When the driver completes the I/O call, the adapter issues another IOCTL to continue waiting for further error notifications.

### GNSS driver notes

The driver can complete this call when it wants to report an error condition. The GNSS adapter will use the error data to log telemetry events.

The Error code is in HRESULT format. The driver can create codes using the **MAKE_HRESULT** macro with codes in **FACILITY_ITF**.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)