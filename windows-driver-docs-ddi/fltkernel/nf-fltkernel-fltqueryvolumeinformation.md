# FltQueryVolumeInformation function

## Description

The **FltQueryVolumeInformation** routine retrieves information about the volume that the given instance is attached to.

## Parameters

### `Instance` [in]

An opaque instance pointer for a minifilter driver instance that is attached to the volume.

### `Iosb` [out]

A pointer to caller-allocated IO_STATUS_BLOCK structure that receives the final completion status and information about the query operation. For successful calls that return data, the number of bytes written to the *FsInformation* buffer is returned in the structure's **Information** member.

### `FsInformation` [out]

A pointer to a caller-allocated buffer that receives the desired information about the volume. The structure of the information returned in the buffer is defined by the *FsInformationClass* parameter.

### `Length` [in]

The size in bytes of the buffer that *FsInformation* points to. The caller should set this parameter according to the given *FsInformationClass*. For example, if the value of *FsInformationClass* is FileFsControlInformation, *Length* must be at least **sizeof**(FILE_FS_CONTROL_INFORMATION).

### `FsInformationClass` [in]

The type of information requested. One of the following value.

| Value | Meaning |
| --- | --- |
| **FileFsAttributeInformation** | Return a [FILE_FS_ATTRIBUTE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information) structure containing attribute information about the file system responsible for the volume. |
| **FileFsControlInformation** | Return a [FILE_FS_CONTROL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information) structure containing file system control information about the volume. |
| **FileFsDeviceInformation** | Return a [FILE_FS_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_fs_device_information) structure containing device information for the volume. |
| **FileFsDriverPathInformation** | Return a [FILE_FS_DRIVER_PATH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_driver_path_information) structure containing information about whether a specified driver is in the I/O path for the volume. The caller must store the name of the driver into the **FILE_FS_DRIVER_PATH_INFORMATION** structure before calling **FltQueryVolumeInformation**. |
| **FileFsFullSizeInformation** | Return a [FILE_FS_FULL_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_full_size_information) structure containing information about the total amount of space available on the volume. |
| **FileFsObjectIdInformation** | Return a [FILE_FS_OBJECTID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information) structure containing file system-specific object ID information for the volume. Be aware that this is not the same as the (GUID-based) unique volume name assigned by the operating system.<br><br>**Note** This value is not valid for snapshot volumes. |
| **FileFsSizeInformation** | Return a [FILE_FS_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_size_information) structure containing information about the amount of space on the volume that is available to the user associated with the calling thread. |
| **FileFsVolumeInformation** | Return a [FILE_FS_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_volume_information) containing information about the volume such as the volume label, serial number, and creation time. |
| **FileFsSectorSizeInformation** | Return a [FILE_FS_SECTOR_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_sector_size_information) structure that contains information about the physical and logical sector sizes of a volume. |

## Return value

The **FltQueryVolumeInformation** routine returns **STATUS_SUCCESS** or an appropriate **NTSTATUS** value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) encountered a pool allocation failure. This is an error code. |
| **STATUS_INVALID_INFO_CLASS** | An invalid value was specified for *FsInformationClass*. This is an error code. |
| **STATUS_INVALID_PARAMETER** | The *Instance* is attached to a network volume. [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) cannot be used to query network volume information. This is an error code. |

## Remarks

Fields in the FILE_*XXX*_INFORMATION structure that are not supported by the underlying file system are set to zero.

To change information about a volume, call [FltSetVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation).

To get volume property information for the given volume, call [FltGetVolumeProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeproperties).

To get the volume name for a given volume, call [FltGetVolumeName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumename).

To get the volume GUID name for a given volume, call [FltGetVolumeGuidName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeguidname).

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

[FltGetVolumeGuidName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeguidname)

[FltGetVolumeName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumename)

[FltGetVolumeProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeproperties)

[FltSetVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation)