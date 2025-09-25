## Description

The PARTITION\_STYLE enumeration type indicates the type of partition table for a disk.

## Constants

### `PARTITION_STYLE_MBR`

Specifies the traditional, AT-style Master Boot Record, type of partition table.

### `PARTITION_STYLE_GPT`

Specifies the GUID Partition Table type of partition table.

### `PARTITION_STYLE_RAW`

The partition is not formatted in either of the recognized formats — MBR or GPT.

## Remarks

The GUID Partition Table format conforms to the Extensible Firmware Interface (EFI) standard developed by Intel. For further information, see Intel's *Extensible Firmware Interface* specification.

## See also

[**CREATE\_DISK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk)

[**DISK\_PARTITION\_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_partition_info)

[**PARTITION\_INFORMATION\_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_ex)