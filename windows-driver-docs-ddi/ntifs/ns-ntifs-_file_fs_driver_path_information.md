# _FILE_FS_DRIVER_PATH_INFORMATION structure

## Description

The FILE_FS_DRIVER_PATH_INFORMATION structure is used to query whether a given driver is in the I/O path for a file system volume.

## Members

### `DriverInPath`

Receives **TRUE** if the driver is in the I/O path for the file system volume, **FALSE** otherwise.

### `DriverNameLength`

Caller-supplied length of the driver name string.

### `DriverName`

Caller-supplied Unicode string containing the name of the driver.

## Remarks

To perform this query, call [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile), passing FileFsDriverPathInformation as the value of *FileInformationClass* and passing a caller-allocated, FILE_FS_DRIVER_PATH_INFORMATION-structured buffer as the value of *FileInformation*.

This information is file system-independent. Thus the call to [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile) does not cause an IRP to be sent to the file system.

No specific access rights are required to query this information. Thus this information is available as long as the volume is accessed through an open handle to the volume itself, or to a file or directory on the volume.

The size of the buffer passed in the *FileInformation* parameter to [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile) must be at least **sizeof** (FILE_FS_DRIVER_PATH_INFORMATION).

This structure must be aligned on a LONGLONG (8-byte) boundary.

## See also

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile)