# _FILE_FS_FULL_SIZE_INFORMATION_EX structure

## Description

Used in a request to query sector size information for a file system volume.

## Members

### `ActualTotalAllocationUnits`

Total space (in clusters) on the volume without considering the quota setting.

### `ActualAvailableAllocationUnits`

Total space available (in clusters) on the volume (in clusters) without considering the quota setting.

### `ActualPoolUnavailableAllocationUnits`

Total unavailable space (in clusters) for the volume due to insufficient free pool space indicated by **PoolAvailableAllocationUnits**.

### `CallerTotalAllocationUnits`

Total space (in clusters) on the volume including available, unavailable, used, and reserved space.

### `CallerAvailableAllocationUnits`

Total space (in clusters) on the volume that is available to the user associated with the calling thread.

### `CallerPoolUnavailableAllocationUnits`

Total space (in clusters) that is the unavailable space for the volume due to insufficient free pool space.

### `UsedAllocationUnits`

Total used space (in clusters) on the volume.

### `TotalReservedAllocationUnits`

Total reserved space (in clusters) on the volume.

### `VolumeStorageReserveAllocationUnits`

A special type of reserved space (in clusters) for per-volume storage reserve. This value is included in **TotalReservedAllocationUnits**.

### `AvailableCommittedAllocationUnits`

Total space (in clusters) that has been committed by storage pool but has not been allocated by file system.

### `PoolAvailableAllocationUnits`

Total available space (in clusters) in corresponding storage pool. If the volume is not a spaces volume, the **PoolAvailableAllocationUnits** is set to zero.

### `SectorsPerAllocationUnit`

Number of sectors in each allocation unit.

### `BytesPerSector`

Number of bytes in each sector.

## Remarks

This information can be queried in either of the following ways:

- Call [**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryvolumeinformationfile), passing FileFsFullSizeInformationEx as the value of _FileInformationClass_ and passing a caller-allocated, **FILE_FS_FULL_SIZE_INFORMATION_EX**-structured buffer as the value of FileInformation.

- Create an IRP with major function code IRP_MJ_QUERY_VOLUME_INFORMATION.

No specific access rights are required to query this information. Thus this information is available as long as the volume is accessed through an open handle to the volume itself, or to a file or directory on the volume.

The size of the buffer passed in the _FileInformation_ parameter to [**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryvolumeinformationfile) must be at least sizeof (FILE_FS_FULL_SIZE_INFORMATION_EX).

This structure must be aligned on a LONGLONG (8-byte) boundary.

## See also

[**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryvolumeinformationfile)