# FltQueryVolumeInformationFile function

## Description

**FltQueryVolumeInformationFile** retrieves volume information for a given file, directory, storage device, or volume.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for an open file, directory, storage device, or volume. This parameter is required and cannot be **NULL**.

### `FsInformation` [out]

Pointer to a caller-allocated buffer that receives information about the file. The *FsInformationClass* parameter specifies the type of information. This parameter is required and cannot be **NULL**.

### `Length` [in]

Size, in bytes, of the *FsInformation* buffer.

### `FsInformationClass` [in]

Type of volume information to be returned. One of the following:

| Value | Meaning |
| --- | --- |
| **FileFsAttributeInformation** | Return a [FILE_FS_ATTRIBUTE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information) structure that contains attribute information about the file system responsible for the volume. |
| **FileFsControlInformation** | Return a [FILE_FS_CONTROL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information) structure that contains file system control information about the volume. |
| **FileFsDeviceInformation** | Return a [FILE_FS_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_fs_device_information) structure that contains device information for the volume. |
| **FileFsDriverPathInformation** | Return a [FILE_FS_DRIVER_PATH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_driver_path_information) structure that contains information about whether a specified driver is in the I/O path for the volume. The caller must store the name of the driver into the **FILE_FS_DRIVER_PATH_INFORMATION** structure before calling **FltQueryVolumeInformationFile**. |
| **FileFsFullSizeInformation** | Return a [FILE_FS_FULL_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_full_size_information) structure that contains information about the total amount of space available on the volume. |
| **FileFsObjectIdInformation** | Return a [FILE_FS_OBJECTID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information) structure that contains file-system-specific object ID information for the volume. Note that this is not the same as the (GUID-based) unique volume name that is assigned by the operating system. |
| **FileFsSizeInformation** | Return a [FILE_FS_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_size_information) structure containing information about the amount of space on the volume that is available to the user that is associated with the calling thread. |
| **FileFsVolumeInformation** | Return a [FILE_FS_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_volume_information) that contains information about the volume such as the volume label, serial number, and creation time. |
| **FileFsSectorSizeInformation** | Return a [FILE_FS_SECTOR_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_sector_size_information) structure that contains information about the physical and logical sector sizes of a volume. |

### `LengthReturned` [out, optional]

Pointer to a caller-allocated variable that receives the size, in bytes, of the information returned in the *FsInformation* buffer. This parameter is optional and can be **NULL**.

## Return value

**FltQueryVolumeInformationFile** returns **STATUS_SUCCESS** or an appropriate **NTSTATUS** value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_VOLUME_DISMOUNTED** | The volume is not currently mounted. This is an error code. |

## Remarks

**FltQueryVolumeInformationFile** retrieves volume information for a given file, directory, storage device, or volume.

If the *FileObject* represents a direct device open, only *FileFsDeviceInformation* can be specified as the value of *FsInformationClass*.

**FltQueryVolumeInformationFile** returns zero in any member of a FILE_FS_*XXX*_INFORMATION structure that is not supported by a particular file system.

## See also

[FILE_FS_ATTRIBUTE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information)

[FILE_FS_CONTROL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information)

[FILE_FS_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_fs_device_information)

[FILE_FS_DRIVER_PATH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_driver_path_information)

[FILE_FS_FULL_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_full_size_information)

[FILE_FS_OBJECTID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information)

**FILE_FS_SECTOR_SIZE_INFORMATION**

[FILE_FS_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_size_information)

[FILE_FS_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_volume_information)

[FltSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile)