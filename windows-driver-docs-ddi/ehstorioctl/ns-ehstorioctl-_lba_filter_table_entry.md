# _LBA_FILTER_TABLE_ENTRY structure

## Description

The **LBA_FILTER_TABLE_ENTRY** structure contains an individual LBA range for the [LBA_FILTER_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_lba_filter_table) sent in an [IOCTL_EHSTOR_DRIVER_UPDATE_LBA_FILTER_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_update_lba_filter_table) request.

## Members

### `StartLba`

The starting LBA of the LBA range for this entry.

### `LbaCount`

The number of LBAs in the LBA range.

### `ReadLock`

Set to TRUE if the LBA range in this entry is not readable. Otherwise, this member is FALSE and the LBA range is readable.

### `WriteLock`

Set to TRUE if the LBA range in this entry is not writeable. Otherwise, this member is FALSE and the LBA range is writable

## Remarks

An LBA range is valid only if LbaCount is > 0 and it is not overlapping with another entry in [LBA_FILTER_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_lba_filter_table).

## See also

[IOCTL_EHSTOR_DRIVER_UPDATE_LBA_FILTER_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_update_lba_filter_table)

[LBA_FILTER_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_lba_filter_table)