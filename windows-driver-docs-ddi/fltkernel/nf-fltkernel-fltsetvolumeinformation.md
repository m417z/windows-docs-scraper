# FltSetVolumeInformation function

## Description

**FltSetVolumeInformation** changes various kinds of information about the volume that the given instance is attached to.

## Parameters

### `Instance` [in]

Opaque instance pointer for a minifilter driver instance that is attached to the volume.

### `Iosb` [out]

Pointer to an IO_STATUS_BLOCK structure that receives the final completion status and information about the operation.

### `FsInformation` [out]

Pointer to a caller-allocated buffer containing the values to be set for the volume. The structure of the information contained in the buffer is defined by the *FsInformationClass* parameter.

### `Length` [in]

Size in bytes of the buffer that *FsInformation* points to. The caller should set this parameter according to the given *FsInformationClass*. For example, if the value of *FsInformationClass* is FileFsControlInformation, *Length* must be at least **sizeof(**FILE_FS_CONTROL_INFORMATION**)**.

### `FsInformationClass` [in]

Type of information to be set for the volume. One of the following.

| Value | Meaning |
| --- | --- |
| **FileFsControlInformation** | Set [FILE_FS_CONTROL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information) for the volume. |
| **FileFsLabelInformation** | Set [FILE_FS_LABEL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_label_information) for the volume. |
| **FileFsObjectIdInformation** | Set [FILE_FS_OBJECTID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information) for the volume. |

## Return value

**FltSetVolumeInformation** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | An invalid value was specified for *Length*. This is an error code. |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltSetVolumeInformation** encountered a pool allocation failure. This is an error code. |
| **STATUS_INVALID_INFO_CLASS** | An invalid value was specified for *FsInformationClass*. This is an error code. |
| **STATUS_INVALID_PARAMETER** | The *Instance* is attached to a network volume. **FltSetVolumeInformation** cannot be used to set network volume information. This is an error code. |

## Remarks

To query information about a volume, call [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation).

## See also

[FILE_FS_CONTROL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information)

[FILE_FS_LABEL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_label_information)

[FILE_FS_OBJECTID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information)

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)