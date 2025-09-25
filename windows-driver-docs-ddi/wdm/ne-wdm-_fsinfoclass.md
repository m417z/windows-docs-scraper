# _FSINFOCLASS enumeration

## Description

 The **FS_INFORMATION_CLASS** enumeration contains the information class constants that specify what type of information structure is present for a set or a query operation.

## Constants

### `FileFsVolumeInformation`

Return a [**FILE_FS_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_volume_information) structure that contains information about the volume such as the volume label, serial number, and creation time.

### `FileFsLabelInformation`

Use a [**FILE_FS_LABEL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_label_information) structure to set information a volume label.

### `FileFsSizeInformation`

Return a [**FILE_FS_SIZE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_size_information) structure containing information about the amount of space on the volume that is available to the user that is associated with the calling thread.

### `FileFsDeviceInformation`

Return a [**FILE_FS_DEVICE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_fs_device_information) structure that contains device information for the volume.

### `FileFsAttributeInformation`

Return a [**FILE_FS_ATTRIBUTE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information) structure that contains attribute information about the file system responsible for the volume.

### `FileFsControlInformation`

Return a [**FILE_FS_CONTROL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information) structure that contains file system control information about the volume.

### `FileFsFullSizeInformation`

Return a [**FILE_FS_FULL_SIZE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_full_size_information) structure that contains information about the total amount of space available on the volume.

### `FileFsObjectIdInformation`

Return a [**FILE_FS_OBJECTID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information) structure that contains file-system-specific object ID information for the volume. Note that this is not the same as the (GUID-based) unique volume name that is assigned by the operating system.

### `FileFsDriverPathInformation`

Return a [**FILE_FS_DRIVER_PATH_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_driver_path_information) structure that contains information about whether a specified driver is in the I/O path for the volume. The originator of the IRP_MJ_QUERY_VOLUME_INFORMATION request must store the name of the driver into the FILE_FS_DRIVER_PATH_INFORMATION structure before sending the IRP to the file system volume device stack.

### `FileFsVolumeFlagsInformation`

Use a **FILE_FS_VOLUME_FLAGS_INFORMATION** structure to set the flags for a volume.

### `FileFsSectorSizeInformation`

Return a [**FILE_FS_SECTOR_SIZE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_sector_size_information) structure that contains information about the physical and logical sector sizes of a volume.

### `FileFsDataCopyInformation`

Returns a **FILE_FS_DATA_COPY_INFORMATION** structure that contains the number of data copies.

### `FileFsMetadataSizeInformation`

Returns a **FILE_FS_METADATA_SIZE_INFORMATION** structure that contains the metadata size information.

### `FileFsFullSizeInformationEx`

Returns a [**FILE_FS_FULL_SIZE_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_full_size_information_ex) structure that contains information about the total amount of space available on the volume.

### `FileFsGuidInformation`

Returns a **FILE_FS_GUID_INFORMATION** structure that contains the GUID information.

### `FileFsMaximumInformation`

End of this enumeration.