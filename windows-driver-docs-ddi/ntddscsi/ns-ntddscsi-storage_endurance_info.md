# STORAGE_ENDURANCE_INFO structure

## Description

A miniport uses the **STORAGE_ENDURANCE_INFO** structure to report a device's endurance information.

## Members

### `ValidFields`

Bitmask that indicates which of the remaining members contain valid data. Can be any of the combination of the following bits:

| Bit | Meaning |
|-|-|
| 0 | The *GroupId* member contains valid data. |
| 1 | The *Flags* member contains valid data. |
| 2 | The *LifePercentage* member contains valid data. |
| 3 | The *BytesReadCount* member contains valid data. |
| 4 | The *ByteWriteCount* member contains valid data. |

### `GroupId`

ID number that represents a group of resources.

### `Flags`

### `Flags.Shared`

Set TRUE if the endurance information is shared with multiple disks.

### `Flags.Reserved`

Reserved; do not use.

### `LifePercentage`

Percentage of used life. This value is typically between 0-100, where a larger number indicates more life has been used.

### `BytesReadCount`

Total bytes read from the device, specified in billions. For example, a value of 1 would mean 1 billion bytes read.

### `ByteWriteCount`

Total bytes written to the device, specified in billions. For example, a value of 1 would mean 1 billion bytes written.

## Remarks

This structure is a member of [STORAGE_ENDURANCE_DATA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-storage_endurance_data_descriptor), which is the structure returned within the output buffer of an [IOCTL_SCSI_MINIPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) request with a **Signature** of [IOCTL_MINIPORT_SIGNATURE_ENDURANCE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_miniport_signature_endurance_info).

## See also

[IOCTL_MINIPORT_SIGNATURE_ENDURANCE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_miniport_signature_endurance_info)

[IOCTL_SCSI_MINIPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport)

[STORAGE_ENDURANCE_DATA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-storage_endurance_data_descriptor)

[STORAGE_HW_ENDURANCE_INFO]/ntddstor/ns-ntddstor-storage_hw_endurance_info.md)