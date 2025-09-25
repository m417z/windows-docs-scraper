# FltTagFile function

## Description

**FltTagFile** sets a reparse tag on a file or directory.

## Parameters

### `InitiatingInstance` [in]

Opaque instance pointer for the minifilter driver instance that initiated this I/O request. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

Pointer to a file object for the file or directory on which to set a reparse point. The file object must be opened for FILE_WRITE_DATA access. This parameter is required and cannot be **NULL**.

### `FileTag` [in]

Reparse point tag. If an existing reparse tag is being modified, the tag specified in this parameter must match the tag of the reparse point to be modified.

### `Guid` [in, optional]

GUID that uniquely identifies the type of reparse point. If *FileTag* is not a Microsoft tag, this parameter is required and cannot be **NULL**. If an existing reparse tag is being modified, the GUID specified in this parameter must match the GUID of the reparse point to be modified.

### `DataBuffer` [in]

Pointer to a buffer that contains user-defined data for the reparse point.

### `DataBufferLength` [in]

Size, in bytes, of the buffer that *DataBuffer* points to.

## Return value

**FltTagFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltTagFileEx** encountered a pool allocation failure. This is an error code. |
| **STATUS_INVALID_DEVICE_REQUEST** | The file system does not support reparse points. This is an error code. |
| **STATUS_INVALID_PARAMETER** | *FileTag* is not a Microsoft tag, and **NULL** was specified for *Guid*. This is an error code. |
| **STATUS_IO_REPARSE_TAG_MISMATCH** | The reparse tag specified by the caller did not match the tag of the reparse point to be modified. This is an error code. |
| **STATUS_REPARSE_ATTRIBUTE_CONFLICT** | The reparse GUID specified by the caller did not match the GUID of the reparse point to be modified. This is an error code. |

## Remarks

Minifilter drivers should use **FltTagFile** instead of [FSCTL_SET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point) to set a reparse point.

Not all file systems support reparse points. The NTFS file system supports them; the FAT file system does not. Minifilter drivers can determine whether a file system supports reparse points by calling [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation), specifying FileFsAttributeInformation for the *FsInformation* parameter, and examining the FILE_SUPPORTS_REPARSE_POINTS bit flag in the returned [FILE_FS_ATTRIBUTE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information) structure.

To remove an existing reparse point, call [FltUntagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile).

For more information about reparse points, see the Microsoft Windows SDK documentation.

## See also

[FILE_FS_ATTRIBUTE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information)

[FLT_TAG_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_tag_data_buffer)

[FSCTL_DELETE_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-delete-reparse-point)

[FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-reparse-point)

[FSCTL_SET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point)

[FltFsControlFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[FltTagFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfileex)

[FltUntagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile)

[IsReparseTagMicrosoft](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagmicrosoft)

[IsReparseTagNameSurrogate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagnamesurrogate)

[REPARSE_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer)

[REPARSE_GUID_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer)