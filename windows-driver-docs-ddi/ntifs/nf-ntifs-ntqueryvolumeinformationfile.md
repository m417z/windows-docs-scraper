# NtQueryVolumeInformationFile function

## Description

The **NtQueryVolumeInformationFile** routine retrieves information about the volume associated with a given file, directory, storage device, or volume.

## Parameters

### `FileHandle` [in]

A handle to a file object returned by [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) or [**NtOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile) for an open file, directory, storage device, or volume for which volume information is being requested.

### `IoStatusBlock` [out]

A pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the query operation. For successful calls that return data, the number of bytes written to the **FsInformation** buffer is returned in the structure's **Information** member.

### `FsInformation` [out]

A pointer to a caller-allocated buffer that receives the desired information about the volume. The structure of the information returned in the buffer is defined by the **FsInformationClass** parameter.

### `Length` [in]

Size in bytes of the buffer pointed to by **FsInformation**. The caller should set this parameter according to the given **FsInformationClass**.

### `FsInformationClass` [in]

Type of information to be returned about the volume. Set this member to one of the following [**FS_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_fsinfoclass) enumeration values.

| Value | Meaning |
| ----- | ------- |
| **FileFsAttributeInformation** | Return a [**FILE_FS_ATTRIBUTE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information) structure containing attribute information about the file system responsible for the volume. |
| **FileFsControlInformation** | Return a [**FILE_FS_CONTROL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information) structure containing file system control information about the volume. |
| **FileFsDeviceInformation** | Return a [**FILE_FS_DEVICE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_fs_device_information) structure containing device information for the volume. |
| **FileFsDriverPathInformation** | Return a [**FILE_FS_DRIVER_PATH_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_driver_path_information) structure containing information about whether a specified driver is in the I/O path for the volume. The caller must store the name of the driver into the **FILE_FS_DRIVER_PATH_INFORMATION** structure before calling **NtQueryVolumeInformationFile**. |
| **FileFsFullSizeInformation** | Return a [**FILE_FS_FULL_SIZE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_full_size_information) structure containing information about the total amount of space available on the volume. |
| **FileFsObjectIdInformation** | Return a [**FILE_FS_OBJECTID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information) structure containing file system-specific object ID information for the volume. Note that this is not the same as the (GUID-based) unique volume name assigned by the operating system. |
| **FileFsSizeInformation** | Return a [**FILE_FS_SIZE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_size_information) structure containing information about the amount of space on the volume that is available to the user associated with the calling thread. |
| **FileFsVolumeInformation** | Return a [**FILE_FS_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_volume_information) containing information about the volume such as the volume label, serial number, and creation time. |
| **FileFsSectorSizeInformation** | Return a [**FILE_FS_SECTOR_SIZE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_sector_size_information) structure that contains information about the physical and logical sector sizes of a volume. |

## Return value

**NtQueryVolumeInformationFile** returns STATUS_SUCCESS or an appropriate error status.

## Remarks

**NtQueryVolumeInformationFile** retrieves information about the volume associated with a given file, directory, storage device, or volume.

If the **FileHandle** represents a direct device open, only **FileFsDeviceInformation** can be specified as the value of **FsInformationClass**.

**NtQueryVolumeInformationFile** returns zero in any member of a **FILE_**XXX**_INFORMATION** structure that is not supported by the file system.

For information about other file information query routines, see [File Objects](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#file-objects).

Minifilters should use [**FltQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformationfile) instead of **NtQueryVolumeInformationFile**.

Callers of **NtQueryVolumeInformationFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

> [!NOTE]
> If the call to the **NtQueryVolumeInformationFile** function occurs in user mode, you should use the name "**NtQueryVolumeInformationFile**" instead of "**ZwQueryVolumeInformationFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**FILE_FS_ATTRIBUTE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information)

[**FILE_FS_CONTROL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information)

[**FILE_FS_DEVICE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_fs_device_information)

[**FILE_FS_DRIVER_PATH_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_driver_path_information)

[**FILE_FS_FULL_SIZE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_full_size_information)

[**FILE_FS_OBJECTID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information)

[**FILE_FS_SIZE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_size_information)

[**FILE_FS_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_volume_information)

[**FltQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformationfile)

[**IRP_MJ_QUERY_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information)

[**IRP_MJ_SET_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-volume-information)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[**NtOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile)

[**NtQueryDirectoryFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntquerydirectoryfile)

[**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[**NtSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)

[**ZwSetVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetvolumeinformationfile)