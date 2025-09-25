# IOCTL_SCSI_MINIPORT IOCTL

## Description

Sends a special control function to a host bus adapter-specific (HBA) miniport driver. Results vary, depending on the particular miniport driver to which this request is forwarded. If the caller specifies a nonzero **Length**, either the input or output buffer must be at least (**sizeof**(SRB_IO_CONTROL) + *DataBufferLength*)).

The prescribed way to open the HBA is use the [SetupDi*Xxx* APIs](https://learn.microsoft.com/windows-hardware/drivers/install/using-device-installation-functions#ddk-setupdi-setup-class-functions-dg) to get all the ScsiAdapter class devices that are running. Get the properties of each for their device instance name and open the HBA directly. SCSI%d (for example, \\\\.\Scsi0:) is a symbolic link and not ALL storage drivers create the link.

> [!NOTE]
> The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** must contain an [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the buffer, which must be at least **sizeof**(SRB_IO_CONTROL), with additional storage for data if the **Length** field is nonzero.

### Output buffer

An updated [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure is returned to the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

The length of the [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure.

### Input/output buffer

None.

### Input/output buffer length

Not applicable.

### Status block

The **Information** field contains the number of bytes returned in the output buffer. The **Status** field indicates the results of the operation.

## See also

[SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control)