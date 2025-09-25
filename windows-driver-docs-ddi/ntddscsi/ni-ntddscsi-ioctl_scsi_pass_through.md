# IOCTL_SCSI_PASS_THROUGH IOCTL

## Description

Allows an application to send almost any SCSI command to a target device, with the following restrictions:

* Multitarget commands, such as COPY, are not allowed.
* Bidirectional data transfer operations are not supported.
* If a class driver for the target type of device exists, the request must be sent to that class driver. Thus, an application can send this request directly to the system port driver for a target logical unit (LU) only if there is no class driver for the type of device that is connected to that LU. The system port driver does not check to determine if a device has been claimed by a class driver before it processes a pass-through request. Therefore, if an application bypasses a class driver that has claimed a device and sends a pass-through request for that device directly to the port driver, a conflict for control of the device can occur between the class driver and the application. If a pass-through request is sent to an adapter device object and if it originates from user mode and targets an LU that is claimed by a class driver, Storport fails the request with STATUS_INVALID_DEVICE_REQUEST. If the request is sent to an LU device object, originates in kernel mode, or targets an unclaimed LU, it is passed to the miniport driver.
* This request cannot be used if the CDB might require the underlying miniport driver to access memory directly. If the caller's CDB might require direct access to memory, use [IOCTL_SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct) instead.
* Applications must not attempt to send a pass-through request asynchronously. All pass-through requests must be synchronous.
* Applications do not require administrative privileges to send a pass-through request to a device, but they must have read/write access to the device.

The calling application creates the SCSI command descriptor block, which can include a request for request-sense data if a CHECK CONDITION occurs.

**IOCTL_SCSI_PASS_THROUGH** is a buffered device control request. To bypass buffering in system memory, callers should use [IOCTL_SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct). When handling an **IOCTL_SCSI_PASS_THROUGH_DIRECT** request, the system locks down the buffer in user memory and the device accesses this memory directly.

This request is typically used for transferring small amounts of data (<16K).

Applications can send this request by means of an [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control) request.

Storage class drivers set the minor IRP number to IRP_MN_SCSI_CLASS to indicate that the request has been processed by a storage class driver.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### Major code

### Input buffer

This structure includes a SCSI CDB, which must be initialized by the caller except for the path, target ID, and logical unit number (LUN), which are filled in by the port driver. For a data-out command, the data to be transferred is included in the buffer at **Irp->AssociatedIrp.SystemBuffer** at **DataBufferOffset** in the **SCSI_PASS_THROUGH** structure. However, the caller must allocate additional storage, immediately following **SCSI_PASS_THROUGH**, if the caller asks for request-sense data.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be at least (*sense data size* + **sizeof**(SCSI_PASS_THROUGH)). The size of the [SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through) structure varies, depending on its **DataTransferLength** specification.

### Output buffer

The port driver returns any request-sense data and any data transferred from the device to the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

The **SenseInfoLength** and **DataTransferLength** in the [SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through) structure are updated to indicate the amount of data transferred.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned in the output buffer at **Irp->AssociatedIrp.SystemBuffer**. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL or STATUS_INVALID_PARAMETER if the input **Length** value in [SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through) is improperly set.

## See also

[SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through)