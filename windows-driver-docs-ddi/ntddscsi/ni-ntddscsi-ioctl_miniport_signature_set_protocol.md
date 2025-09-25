# IOCTL_MINIPORT_SIGNATURE_SET_PROTOCOL SIGNATURE

## Description

**IOCTL_MINIPORT_SIGNATURE_SET_PROTOCOL** is the system-defined signature used in conjunction with the [**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) control code to send protocol-specific data to a miniport.

## Parameters

### Major code

### Input buffer

See Remarks.

### Input buffer length

See Remarks.

### Output buffer

See Remarks.

### Output buffer length

See Remarks.

### Input/output buffer

None.

### Input/output buffer length

Not applicable.

### Status block

Not applicable.

## Remarks

For this signature, [**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) input buffer will contain an [**SRB_IO_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure with:

* The **Signature** member set to IOCTL_MINIPORT_SIGNATURE_SET_PROTOCOL.

* The **ControlCode** member set to [**IOCTL_STORAGE_SET_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_property)

If the miniport recognizes and supports the **IOCTL_MINIPORT_SIGNATURE_SET_PROTOCOL** signature, it should update its device using the protocol information specified in a [**STORAGE_PROTOCOL_DATA_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_data_descriptor)
structure. For this signature, the **STORAGE_PROTOCOL_DATA_DESCRIPTOR** structure is found in **IOCTL_SCSI_MINIPORT**'s input buffer immediately following the **SRB_IO_CONTROL** structure.

See [**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) for information on how to calculate buffer sizes.

## See also

[**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport)

[**IOCTL_STORAGE_SET_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_property)

[**STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_data_descriptor_ext)

[**STORAGE_PROTOCOL_SPECIFIC_DATA_EXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_specific_data_ext)