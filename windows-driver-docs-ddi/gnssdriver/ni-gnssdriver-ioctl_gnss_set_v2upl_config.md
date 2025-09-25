# IOCTL_GNSS_SET_V2UPL_CONFIG IOCTL

## Description

The **IOCTL_GNSS_SET_V2UPL_CONFIG** control code is used by the GNSS adapter to set configuration for v2 user plane location for CDMA, which consist of the MPC address, and in testing mode, potentially the PDE address.

## Parameters

### Major code

### Input buffer

A pointer to a [GNSS_V2UPL_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_v2upl_config) structure.

### Input buffer length

Set to sizeof(GNSS_V2UPL_CONFIG).

### Output buffer

Set to NULL.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

The driver sets one of the following NTSTATUS values to indicate the result.

* **STATUS_SUCCESS**, when the driver processes the V2UPL information successfully.
* **Failed**, when the driver does not process the V2UPL information successfully.
* **Ignored**, when the driver ignores the V2UPL information.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)