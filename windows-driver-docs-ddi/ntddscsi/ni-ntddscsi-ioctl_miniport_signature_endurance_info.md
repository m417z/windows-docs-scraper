# IOCTL_MINIPORT_SIGNATURE_ENDURANCE_INFO SIGNATURE

## Description

**IOCTL_MINIPORT_SIGNATURE_ENDURANCE_INFO** is the system-defined *signature* used in conjunction with the [**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) control code to request that a miniport return a target device's endurance information.

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

For this signature, [**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport)'s input buffer will contain an [**SRB_IO_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure with:

* The **Signature** member is set to IOCTL_MINIPORT_SIGNATURE_ENDURANCE_INFO.

* The **ControlCode** member is set to [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property).

If the miniport recognizes and supports the **IOCTL_MINIPORT_SIGNATURE_ENDURANCE_INFO** signature, it should return its device's endurance data in a [**STORAGE_ENDURANCE_DATA_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-storage_endurance_data_descriptor) structure. Specifically, **IOCTL_SCSI_MINIPORT**'s output buffer will contain an **SRB_IO_CONTROL** structure, followed immediately by a **STORAGE_ENDURANCE_DATA_DESCRIPTOR** structure that contains the endurance data.

See [**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) for information on how to calculate buffer sizes.

## See also

[**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport)

[**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE_ENDURANCE_DATA_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-storage_endurance_data_descriptor)