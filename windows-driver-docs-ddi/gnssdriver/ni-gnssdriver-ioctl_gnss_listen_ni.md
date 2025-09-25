# IOCTL_GNSS_LISTEN_NI IOCTL

## Description

The **IOCTL_GNSS_LISTEN_NI** control code is used to start listening for a SUPL NI request.

This IOCTL effectively provides the GNSS driver with a pending I/O request that it can use to, through the overlapped structures GnssEvent member, convey the NI request to the adapter. The GnssEvent member is a [GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event) structure. The adapter ensures that this request is always pending and will issue a new request as soon as the pending one is resolved. When the I/O request is resolved the adapter will issue a corresponding [IOCTL_GNSS_RESPOND_NI](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_respond_ni).

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

The **EventType** must be set to **GNSS_Event_NI** and the **NiRequest** member filled in.

### GNSS adapter notes

The GNSS adapter ensures that this request is always pending, so that the driver can indicate there is a NI request.

When the driver completes the I/O call, the adapter issues another IOCTL to continue waiting for further NI requests. The adapter should issue the IOCTL immediately, even if the previous NI requests are held up due to user interaction.

### GNSS driver notes

Whenever the GNSS driver gets a NI request from the SUPL/CP, it completes the I/O operation.

These certificates, which are specified by the mobile operator and configured via the SUPL configuration service provider, are needed for establishing connection with the H-SLP or E-SLP. The GNSS adapter only pushes the SUPL configuration, including the certificated, to the GNSS driver. It does not install the certificates in the Windows file system. This is because different IHVs may have different implementations of the SUPL client, and some may include implementation of their own TLS stack. The GNSS adapter is agnostic to any implementation details of the SUPL client. The GNSS driver can store the certificates in registry or disk or push them directly to the SUPL client based on their usage. The SUPL client will need to take care of installing/using the certificates as needed.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)