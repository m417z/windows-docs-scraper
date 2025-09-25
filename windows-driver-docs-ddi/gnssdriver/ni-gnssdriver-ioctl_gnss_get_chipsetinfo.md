# IOCTL_GNSS_GET_CHIPSETINFO IOCTL

## Description

The **IOCTL_GNSS_GET_CHIPSETINFO**
control code is used by the GNSS manufacturing test application to get information about the GNSS chipset. This information may be used by the test applications to decide which sets of tests should be executed, in which order, and map the response codes from the self tests into error conditions specific to the manufacturer or the chipset.

## Parameters

### Major code

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

A pointer to a [GNSS_CHIPSETINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_chipsetinfo) structure.

### Output buffer length

Set to sizeof(GNSS_CHIPSETINFO).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### GNSS test application notes

The GNSS test application must wait for the response from the GNSS driver and be resilient to the GNSS driver not responding.

### GNSS driver notes

The GNSS driver must respond with the information about the GNSS chipset.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)