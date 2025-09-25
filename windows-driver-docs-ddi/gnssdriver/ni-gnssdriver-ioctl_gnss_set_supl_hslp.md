# IOCTL_GNSS_SET_SUPL_HSLP IOCTL

## Description

The **IOCTL_GNSS_SET_SUPL_HSLP** control code is used by the GNSS adapter to set the SUPL H-SLP address.

## Parameters

### Major code

### Input buffer

A pointer to a [GNSS_SUPL_HSLP_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_supl_hslp_config) structure.

### Input buffer length

Set to sizeof(GNSS_SUPL_HSLP_CONFIG).

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

* **STATUS_SUCCESS**, when the driver processes the SUPL H-SLP information successfully.
* **Failed**, when the driver does not process the SUPL H-SLP information successfully.
* **Ignored**, when the driver ignores the SUPL H-SLP information.

### GNSS driver notes

The GNSS driver must pass the H-SLP information, contained in the input structure, to the SUPL component which should connect to the server address specified by the H-SLP.

If the certificate with the same name is injected again, the GNSS driver should overwrite the previous certificate with the same name.

The H-SLP address is always in the form of a FQDN.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)