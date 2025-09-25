# IOCTL_GNSS_INJECT_AGNSS IOCTL

## Description

The **IOCTL_GNSS_INJECT_AGNSS** control code is used by the GNSS adapter to inject AGNSS data into the driver. This IOCTL is sent as a result of the driver previously responding to a pending [IOCTL_GNSS_LISTEN_AGNSS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_listen_agnss) request.

## Parameters

### Major code

### Input buffer

A pointer to a [GNSS_AGNSS_INJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_agnss_inject) structure.

### Input buffer length

Set to sizeof(GNSS_AGNSS_INJECT).

### Output buffer

Set to **NULL**.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### Input

[GNSS_AGNSS_INJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_agnss_inject)

Depending on the InjectionType element, the appropriate data element is filled.

### Output

NTSTATUS with the following indications:

* Success: AGNSS data injection was accepted.
* Failed: AGNSS data injection failed.

### GNSS adapter notes

When the GNSS adapter fails to get time for injection, it sets the InjectionStatus element. The driver must check that this element indicates success, before actually using the element data.

In case of failure in gathering injection data, the adapter does not automatically retry. It is up to the driver to retry the same request sequent.

This is a fire-and-forget IOCTL. The GNSS adapter does not handle error even if the driver returns a failure indicating that the injection data was not used.

### GNSS driver notes

The GNSS driver completes the I/O request after consuming the injection data.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)