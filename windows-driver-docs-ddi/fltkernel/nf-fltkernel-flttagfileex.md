# FltTagFileEx function

## Description

**FltTagFileEx** sets a reparse point on a file or directory.

## Parameters

### `InitiatingInstance`

Opaque pointer to the minifilter driver instance that initiated this I/O request. This parameter is required and cannot be **NULL**.

### `FileObject`

Pointer to the file object for the file or directory on which to set a reparse point. The file object must be opened for FILE_WRITE_DATA access. This parameter is required and cannot be **NULL**.

### `FileTag`

Reparse point tag. Can be one of the **IO_REPARSE_TAG_*XXX*** values defined in *ntifs.h*.

### `Guid`

GUID that uniquely identifies the reparse point. If *FileTag* is a non-Microsoft tag, this parameter is required and cannot be **NULL**. If an existing reparse tag is being modified, the GUID specified in this parameter must match the GUID of the reparse point to be modified.

### `DataBuffer`

Pointer to a buffer that contains user-defined data for the reparse point.

### `DataBufferLength`

Size, in bytes, of the buffer to which *DataBuffer* points.

### `ExistingFileTag`

Existing tag on the file if the tag has to be replaced. This parameter must be set to zero to set a reparse tag on a file that doesn't already have one.

### `ExistingGuid`

GUID that uniquely identifies an existing reparse point. If *ExistingFileTag* is a non-Microsoft tag and is non-zero, this parameter must not be **NULL**.

### `Flags`

Specifies the REPARSE_DATA_BUFFER_EX_*XXX* flags defined in *ntifs.h*.

## Return value

This function returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return Code | Description |
| ----------- | ----------- |
| STATUS_IO_REPARSE_TAG_MISMATCH | The tag value specified in *ExistingFileTag* does not match that of the existing tag value. |
| STATUS_REPARSE_ATTRIBUTE_CONFLICT | For an existing reparse point with a non-Microsoft tag, *ExistingFileTag* matches the existing tag value, but the *Guid* does not match the existing Guid. |

## Remarks

Minifilter drivers should use **FltTagFileEx** instead of FSCTL_SET_REPARSE_POINT_EX to set a reparse point.

Not all file systems support reparse points; for example, the NTFS and ReFS file systems supports them, but the FAT file system does not. Minifilter drivers can determine whether a file system supports reparse points by calling [**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation), specifying FileFsAttributeInformation for the *FsInformation* parameter, and examining the FILE_SUPPORTS_REPARSE_POINTS bit flag in the returned [FILE_FS_ATTRIBUTE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information) structure.

To remove an existing reparse point, call [**FltUntagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile).

For more information about reparse points, see the Microsoft Windows SDK documentation.

## See also

[FILE_FS_ATTRIBUTE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information)

[FLT_TAG_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_tag_data_buffer)

[FSCTL_DELETE_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-delete-reparse-point)

[FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-reparse-point)

[FSCTL_SET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point)

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[**FltTagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile)

[**FltUntagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile)

[**IsReparseTagMicrosoft**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagmicrosoft)

[**IsReparseTagNameSurrogate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagnamesurrogate)

[REPARSE_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer)

[REPARSE_GUID_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer)