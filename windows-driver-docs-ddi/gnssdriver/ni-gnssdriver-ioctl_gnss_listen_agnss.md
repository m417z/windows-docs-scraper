# IOCTL_GNSS_LISTEN_AGNSS IOCTL

## Description

The **IOCTL_GNSS_LISTEN_AGNSS** control code is used by the GNSS adapter to start listening for AGNSS requests issued by the GNSS driver. This IOCTL effectively provides the GNSS driver with a pending I/O request, the asynchronous resolution of which notifies the adapter, through the overlapped structures GnssEvent member, that the driver requires an AGNSS injection. The GnssEvent member is a [GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event) structure. The GNSS adapter ensures that this request is always pending and will issue a new request as soon as the pending one is resolved. When the I/O request is resolved the GNSS adapter will issue a corresponding [IOCTL_GNSS_INJECT_AGNSS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_inject_agnss) with the appropriate injection data.

## Parameters

### Major code

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

Set to NULL.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### Output

[GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event)

The EventType must be set to **GNSS_Event_RequireAGNSS** and the **AGNSSRequest** member filled in.

### GNSS adapter notes

The GNSS adapter ensures that this request is always pending, so that the driver can indicate that it requires AGNSS injection.

When the driver completes the I/O call, the adapter issues another IOCTL to continue waiting for further AGNSS requests.

Depending on the **AGNSSRequest.RequestType** element, the driver issues [IOCTL_GNSS_INJECT_AGNSS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_inject_agnss) with the appropriate injection data.

### GNSS driver notes

Whenever the GNSS driver requires assistance data, it completes the I/O operation to seek injection data from the adapter

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)