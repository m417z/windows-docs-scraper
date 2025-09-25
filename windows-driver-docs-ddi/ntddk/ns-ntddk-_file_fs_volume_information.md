# _FILE_FS_VOLUME_INFORMATION structure

## Description

The FILE_FS_VOLUME_INFORMATION structure is used to query information about a volume on which a file system is mounted.

## Members

### `VolumeCreationTime`

Time when the volume was created.

### `VolumeSerialNumber`

Serial number of the volume.

### `VolumeLabelLength`

Length, in bytes, of the name of the volume.

### `SupportsObjects`

**TRUE** if the file system supports object-oriented file system objects, **FALSE** otherwise.

### `VolumeLabel`

Name of the volume.

## Remarks

This information can be queried in either of the following ways:

* Call [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile), passing FileFsVolumeInformation as the value of *FileInformationClass* and passing a caller-allocated, FILE_FS_VOLUME_INFORMATION-structured buffer as the value of *FileInformation*.
* Create an IRP with major function code IRP_MJ_QUERY_VOLUME_INFORMATION.

No specific access rights are required to query this information. Thus this information is available as long as the volume is accessed through an open handle to the volume itself, or to a file or directory on the volume.

All dates and times are in absolute system-time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601.

The size of the buffer passed in the *FileInformation* parameter to [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile) must be at least **sizeof** (FILE_FS_VOLUME_INFORMATION).

This structure must be aligned on a LONGLONG (8-byte) boundary.

## See also

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[IRP_MJ_QUERY_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information)

[ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile)