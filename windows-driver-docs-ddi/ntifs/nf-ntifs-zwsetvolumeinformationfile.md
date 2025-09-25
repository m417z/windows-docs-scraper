# ZwSetVolumeInformationFile function

## Description

The **ZwSetVolumeInformationFile** routine modifies information about the volume associated with a given file, directory, storage device, or volume.

## Parameters

### `FileHandle` [in]

Handle to a file object for an open file, directory, storage device, or volume whose volume information is to be modified.

### `IoStatusBlock` [out]

Pointer to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the operation.

### `FsInformation` [in]

Pointer to a caller-allocated buffer containing the volume information to be modified. The structure of the information in this buffer depends on the value of *FsInformationClass*, as shown in the following table.

### `Length` [in]

Size in bytes of the buffer pointed to by *FsInformation*. The caller should set this parameter according to the given *FsInformationClass*.

### `FsInformationClass` [in]

Type of volume information to be set. One of the following:

| Value | Meaning |
| --- | --- |
| **FileFsControlInformation** | Set [FILE_FS_CONTROL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information) for the volume. |
| **FileFsLabelInformation** | Set [FILE_FS_LABEL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_label_information) for the volume. |
| **FileFsObjectIdInformation** | Set [FILE_FS_OBJECTID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information) for the volume. |

## Return value

**ZwSetVolumeInformationFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | An invalid value was specified for *Length*. This is an error code. |
| **STATUS_INSUFFICIENT_RESOURCES** | [ZwSetVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetvolumeinformationfile) encountered a pool allocation failure. This is an error code. |
| **STATUS_INVALID_INFO_CLASS** | An invalid value was specified for *FsInformationClass*. This is an error code. |

## Remarks

To query volume information, call [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile).

To change information about a file, call **ZwSetVolumeInformationFile**.

Minifilters should use [FltSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile) instead of **ZwSetVolumeInformationFile**.

**Note** If the call to the **ZwSetVolumeInformationFile**function occurs in user mode, you should use the name "[NtSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)" instead of "**ZwSetVolumeInformationFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[FILE_FS_CONTROL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information)

[FILE_FS_LABEL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_label_information)

[FILE_FS_OBJECTID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information)

[FltSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile)

[IRP_MJ_SET_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-volume-information)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)