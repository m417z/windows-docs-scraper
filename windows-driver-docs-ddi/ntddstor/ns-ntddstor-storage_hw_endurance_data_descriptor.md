# STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR structure

## Description

A storage port driver uses the STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR structure to report a device's endurance information.

## Members

### `Version`

Version of this structure. Set this to be **sizeof**(STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR).

### `Size`

Size, in bytes, of the buffer containing the endurance information. Set this to be **sizeof**(STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR).

### `EnduranceInfo`

A [STORAGE_HW_ENDURANCE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_hw_endurance_info) structure in which to store the device's endurance information.

## Remarks

A storage port driver uses this structure when communicating with its miniport for an [IOCTL_SCSI_MINIPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) request that has an [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure with a **Signature** of [IOCTL_MINIPORT_SIGNATURE_ENDURANCE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_miniport_signature_endurance_info), and a **ControlCode** of[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) with a **PropertyId** of StorageDeviceEnduranceProperty and a **QueryType** of PropertyStandardQuery.

The miniport uses [STORAGE_ENDURANCE_DATA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-storage_endurance_data_descriptor), which is defined in *ntddscsi.h*. STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR and STORAGE_ENDURANCE_DATA_DESCRIPTOR are identical in size, so the storage port driver and miniport should cast the structure they receive accordingly when communicating with each other.

## See also

[IOCTL_MINIPORT_SIGNATURE_ENDURANCE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_miniport_signature_endurance_info)

[IOCTL_SCSI_MINIPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control)

[STORAGE_ENDURANCE_DATA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-storage_endurance_data_descriptor)

[STORAGE_HW_ENDURANCE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_hw_endurance_info)