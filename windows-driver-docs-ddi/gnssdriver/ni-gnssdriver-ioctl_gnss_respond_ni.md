# IOCTL_GNSS_RESPOND_NI IOCTL

## Description

The **IOCTL_GNSS_RESPOND_NI** control code is used by the GNSS adapter to respond to an NI request that was asynchronously communicated to it by the GNSS driver through the resolution of an [IOCTL_GNSS_LISTEN_NI](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_listen_ni) request.

## Parameters

### Major code

### Input buffer

A pointer to a [GNSS_NI_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_ni_response) structure.

### Input buffer length

Set to sizeof(GNSS_NI_RESPONSE).

### Output buffer

Set to NULL.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

The driver sets one of the following NTSTATUS values to indicate result.

* **STATUS_SUCCESS**, when the driver processed the users NI response information successfully.
* **Failed**, when the driver does not process the users NI response information successfully.
* **Ignored**, when the driver ignored the users NI response information.

### GNSS driver notes

It is the GNSS driver’s responsibility to pass the user’s response, contained in the **GNSS_NI_RESPONSE** input structure to the NI. If the response is **GNSS_Ni_UserResponseTimeout**, the driver should determine the appropriate default response after time-out and send it to the SUPL server.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)