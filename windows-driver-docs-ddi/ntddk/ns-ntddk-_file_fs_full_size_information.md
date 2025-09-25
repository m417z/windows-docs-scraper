# _FILE_FS_FULL_SIZE_INFORMATION structure

## Description

The FILE_FS_FULL_SIZE_INFORMATION structure is used to query sector size information for a file system volume.

## Members

### `TotalAllocationUnits`

Total number of allocation units on the volume that are available to the user associated with the calling thread.

**Microsoft Windows 2000 and later:** If per-user quotas are in use, this value may be less than the total number of allocation units on the disk.

### `CallerAvailableAllocationUnits`

Total number of free allocation units on the volume that are available to the user associated with the calling thread.

**Windows 2000 and later:** If per-user quotas are in use, this value may be less than the total number of free allocation units on the disk.

### `ActualAvailableAllocationUnits`

Total number of free allocation units on the volume.

### `SectorsPerAllocationUnit`

Number of sectors in each allocation unit.

### `BytesPerSector`

Number of bytes in each sector.

## Remarks

This information can be queried in either of the following ways:

* Call [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile), passing FileFsFullSizeInformation as the value of *FileInformationClass* and passing a caller-allocated, FILE_FS_FULL_SIZE_INFORMATION-structured buffer as the value of *FileInformation*.
* Create an IRP with major function code IRP_MJ_QUERY_VOLUME_INFORMATION.

No specific access rights are required to query this information. Thus this information is available as long as the volume is accessed through an open handle to the volume itself, or to a file or directory on the volume.

The size of the buffer passed in the *FileInformation* parameter to [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile) must be at least **sizeof** (FILE_FS_FULL_SIZE_INFORMATION).

This structure must be aligned on a LONGLONG (8-byte) boundary.

## See also

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[IRP_MJ_QUERY_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information)

[ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile)