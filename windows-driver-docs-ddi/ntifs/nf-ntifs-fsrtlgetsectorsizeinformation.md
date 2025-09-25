# FsRtlGetSectorSizeInformation function

## Description

The **FsRtlGetSectorSizeInformation** routine retrieves the physical and logical sector size information for a storage volume.

## Parameters

### `DeviceObject`

The target device object for a storage device.

### `SectorSizeInfo` [out]

A pointer to a caller supplied [FILE_FS_SECTOR_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_sector_size_information) structure.

## Return value

**FsRtlGetSectorSizeInformation** returns **STATUS_SUCCESS** if the sector size information is returned in *SectorSizeInfo*. Otherwise, another appropriate **NTSTATUS** value is returned such as the following.

| Return code | Description |
| --- | --- |
| **STATUS_BAD_DEVICE_TYPE** | The storage device reported an invalid sector size. |

## Remarks

This routine is used by file system drivers to retrieve sector size information from the storage device containing the volume. A file system driver typically maintains the device object sent in *RealDevice* in its volume parameter block (VPD) for the storage volume.

Drivers other than file system drivers, can query sector size information using the [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile) routines, or by sending an [IRP_MJ_QUERY_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information) request and specifying **FileFsSectorSizeInformation** as the file system information class.

## See also

[FILE_FS_SECTOR_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_sector_size_information)

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[IRP_MJ_QUERY_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information)

[ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile)