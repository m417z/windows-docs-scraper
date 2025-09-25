# LBA_FILTER_TABLE structure

## Description

The **LBA_FILTER_TABLE** structure contains the LBA ranges whose access is controlled by a silo driver. The LBA filter entries in the table define bands on a storage device that are managed by a silo driver. A silo drivers send the LBA filter table to the enhanced storage class driver in an [**IOCTL_EHSTOR_DRIVER_UPDATE_LBA_FILTER_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_update_lba_filter_table) request.

## Members

### `StructSize`

The size of this structure. This is set to ```sizeof(LBA_FILTER_TABLE)```.

### `GlobalReadLock`

If TRUE, LBAs not included in the filter table are not readable. Otherwise unfiltered LBAs are readable if FALSE.

### `Reserved1`

Reserved.

### `GlobalWriteLock`

If TRUE, LBAs not included in the filter table are not writeable. Otherwise unfiltered LBAs are writeable if FALSE.

### `Reserved2`

Reserved.

### `LbaFilterCount`

The number of filter entries in the filter table.

### `LbaFilterSize`

The size in bytes of a filter table entry. This must be set to **sizeof**(LBA_FILTER_TABLE_ENTRY).

### `LbaFiltersOffset`

The offset of the LBA filter table from the beginning of this structure. This will typically be ```sizeof(LBA_FILTER_TABLE)```.

## Remarks

LBA ranges not included in any filter table entries are considered part of the global band for the device. These ranges are managed independently by the Enhanced Storage Class driver. Access for these ranges is determined by the settings in **GlobalReadLock** and **GlobalWriteLock**.

Following the **LBA_FILTER_TABLE** structure is an array of 0 or more [**LBA_FILTER_TABLE_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_lba_filter_table_entry) structures. Each **LBA_FILTER_TABLE_ENTRY** defines an individual band whose access is controlled by the silo driver through the direction of band management requests forwarded by the Enhanced Storage Class driver. **LBA_FILTER_TABLE_ENTRY** structures can occur in any order, however, an LBA range in a table entry must not overlap with an LBA range from another table entry.

## See also

[**IOCTL_EHSTOR_DRIVER_UPDATE_LBA_FILTER_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_update_lba_filter_table)

[**LBA_FILTER_TABLE_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_lba_filter_table_entry)