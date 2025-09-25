# IOCTL_ATA_PASS_THROUGH IOCTL

## Description

Allows an application to send almost any ATA command to a target device, with the following restrictions:

* If a class driver for the target type of device exists, the application must send the request to the class driver. Thus, an application can send this request directly to the system port driver for a target logical unit (LU) only if there is no class driver for the type of device connected to that LU. The system port driver does not check to determine if a device has been claimed by a class driver before processing a pass-through request. Therefore, if an application bypasses a class driver that has claimed a device and sends a pass-through request for that device directly to the port driver, a conflict for control of the device can occur between the class driver and the application.
* This request cannot be used if the command requires the underlying driver to access memory directly. If the caller's command might require direct access to memory, use [IOCTL_ATA_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_ata_pass_through_direct) instead.
* Applications must not attempt to send a pass-through request asynchronously. All pass-through requests must be synchronous.
* Applications do not require administrative privileges to send a pass-through request to a device, but they must have read/write access to the device.

The calling application provides the ATA task file register contents for the intended command in the [ATA_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_ex) structure. The system double buffers all data transfers. This request is typically used for transferring small amounts of data (less than 16 KB).

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** should contain an [ATA_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_ex) structure, which includes a set of task file input registers that indicate the sort of command to be performed and its parameters. The caller must initialize all the members of this structure except for **PathId**, **TargetId**, and **Lun**, which the port driver fills in. For a data-out command, the **DataBufferOffset** member of the structure must point to a cache-aligned buffer containing the data to be written.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size in bytes of the buffer at **Irp->AssociatedIrp.SystemBuffer**. If the embedded ATA command is a write operation, the size of the input buffer should be the sum of **sizeof**([ATA_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_ex)) and the value in the **DataTransferLength** member of **ATA_PASS_THROUGH_EX**. The following pseudocode example shows how to calculate the buffer size:

```
ULONG buffsize; // size of the buffer
ATA_PASS_THROUGH_EX hdr;
hdr.DataTransferLength = size in bytes of the data transfer
buffsize = sizeof (ATA_PASS_THROUGH_EX) + hdr.DataTransferLength
```

If the embedded ATA command is a read operation or a device control operation that does not involve data transfer, **InputBufferLength** should be equal to **sizeof** (ATA_PASS_THROUGH_EX).

In either case, if **InputBufferLength** is less than **sizeof** (ATA_PASS_THROUGH_EX), the port driver fails the I/O request and returns an error.

### Output buffer

The port driver formats the return data using an [ATA_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_ex) structure and stores the data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

The port driver fills the **CurrentTaskFile** member with the values that are present in the device's output registers at the completion of the embedded ATA command. If the command was a data transfer, the port driver stores the transferred data in a cache-aligned buffer that is located at an offset of **DataBufferOffset** bytes from the beginning of the structure. The application is responsible for interpreting the contents of the output registers to determine what errors, if any, were returned by the device.

### Output buffer length

The port driver updates the **DataTransferLength** member of [ATA_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_ex) to indicate the amount of data actually transferred from the device. If the embedded ATA command is a write operation or a device control operation that does not transfer data, **OutputBufferLength** is equal to **sizeof**(ATA_PASS_THROUGH_EX). If the embedded ATA command is a read operation, **OutputBufferLength** is equal to **sizeof**(ATA_PASS_THROUGH_EX) + **DataTransferLength**.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the number of bytes returned in the output buffer at **Irp->AssociatedIrp.SystemBuffer**. The **Status** member is set to STATUS_SUCCESS or possibly to STATUS_BUFFER_TOO_SMALL or STATUS_INVALID_PARAMETER if the input **Status** value in [ATA_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_ex) is improperly set.

## See also

[ATA_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_ex)

[IOCTL_ATA_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_ata_pass_through_direct)