# FSCTL_SET_PERSISTENT_VOLUME_STATE control code

The **FSCTL_SET_PERSISTENT_VOLUME_STATE** control code sets persistent settings for a file system volume. Persistent settings remain on a file system volume between reboots of the computer.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) with the following parameters.

## Parameters

- **FileObject** [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. A file object pointer for the file system volume. This parameter is required and cannot be **NULL**.

- **FileHandle** [in]: [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) only. A file handle for the file system volume. This parameter is required and cannot be **NULL**.

- **FsControlCode** [in]: The control code for the operation. Use **FSCTL_SET_PERSISTENT_VOLUME_STATE** for this operation.

- **InputBuffer** [in]: A pointer to a caller-allocated [**FILE_FS_PERSISTENT_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_persistent_volume_information) structure that contains the persistent settings for a file system volume.

- **InputBufferLength** [in]: The size, in bytes, of the buffer pointed to by the *InputBuffer* parameter.

- **OutputBuffer** [out]: Not used with this operation; set to **NULL**.

- **OutputBufferLength** [out]: Not used with this operation; set to zero.

## Status block

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Code | Meaning |
| ---- | ------- |
| STATUS_NOT_SUPPORTED | The requested registry setting is not per volume, or the caller specified an incorrect version number in the **Version** member of [**FILE_FS_PERSISTENT_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_persistent_volume_information). |
| STATUS_INVALID_PARAMETER | The file system volume is not an open user volume, or the caller specified an invalid flag in the **FlagMask** member of **FILE_FS_PERSISTENT_VOLUME_INFORMATION**. |
| STATUS_BUFFER_TOO_SMALL | The buffer that the **InputBuffer** parameter points to is not large enough to hold the persistent-settings data. In this case, no persistent-settings data is set. This is an error code. |
| STATUS_ACCESS_DENIED | The caller cannot access the file system volume. |
| STATUS_VOLUME_DISMOUNTED | The file system volume is dismounted. |
| STATUS_TOO_LATE | The file system volume is shut down. |
| STATUS_MEDIA_WRITE_PROTECTED | The file system volume is read only. |

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Minimum supported client | Windows 7 |
| Header | *Ntifs.h* (include *Ntifs.h*) |

## See also

[**FILE_FS_PERSISTENT_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_persistent_volume_information)

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85))