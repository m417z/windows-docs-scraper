# IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT IOCTL

## Description

This I/O control code allows an application or kernel driver to send a SCSI command to a designated real LUN. The following restrictions apply to the use of this I/O control code:

* If a class driver for the pseudo LUN exists, the application must send the request to that class driver. Thus, an application can send this request directly to an MPIO only if there is no class driver for the device.
* All pass-through requests must be synchronous.
* Applications do not require administrative privileges to send a pass-through request to a device, but they must have read/write access to the device.
* The request comprises a SCSI pass-through request (in an embedded [SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct) structure) as well as certain directives.
* The SCSI pass-through structure should meet the requirements for such, as described in [SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct).
* If the request is to be sent through the DSM that claimed the real LUN, that must be indicated. In such a case, the DSM itself must indicate the same real LUN. Otherwise, the request will fail.
* The request must specify the real LUN that is comprised by the pseudo LUN in terms of the former's SCSI address or its MPIO **PathId**, but not both.

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Input buffer length

The buffer must be at least **sizeof**(MPIO_PASS_THROUGH_PATH) or, if sent by a 32-bit application in a 64-bit operating system, **sizeof**(MPIO_PASS_THROUGH_PATH32).

### Output buffer

The port driver returns any request-sense data and any data that is transferred from the device to the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

The **SenseInfoLength** and **DataTransferLength** in the embedded [SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct) structure are updated to indicate the amount of data that is transferred.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned in the output buffer at **Irp->AssociatedIrp.SystemBuffer**. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL or STATUS_INVALID_PARAMETER if the input **Length** value in the embedded [SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct) is improperly set.

## See also

[MPIO_PASS_THROUGH_PATH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_mpio_pass_through_path_direct)

[SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct)