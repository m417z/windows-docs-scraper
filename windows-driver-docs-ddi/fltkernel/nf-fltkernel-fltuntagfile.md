# FltUntagFile function

## Description

**FltUntagFile** removes a reparse point from a file or directory.

## Parameters

### `InitiatingInstance` [in]

Opaque instance pointer for the minifilter driver instance that initiated this I/O request. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

Pointer to a file object for the file or directory from which the reparse point is to be removed. The file object must be opened for FILE_WRITE_DATA access. This parameter is required and cannot be **NULL**.

### `FileTag` [in]

Reparse point tag. The tag specified in this parameter must match the tag of the reparse point to be removed.

### `Guid` [in, optional]

Globally unique identifier (GUID) that uniquely identifies the type of reparse point. If *FileTag* is not a Microsoft tag, this parameter is required and cannot be **NULL**. The GUID specified in this parameter must match the GUID of the reparse point to be removed.

## Return value

**FltUntagFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_IO_REPARSE_TAG_MISMATCH** | The reparse tag specified by the caller did not match the tag of the reparse point to be deleted. This is an error code. |
| **STATUS_REPARSE_ATTRIBUTE_CONFLICT** | The reparse GUID specified by the caller did not match the GUID of the reparse point to be deleted. This is an error code. |

## Remarks

Minifilter drivers should use **FltUntagFile** instead of [FSCTL_DELETE_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-delete-reparse-point) to delete a reparse point.

A minifilter driver can set a reparse tag on a file or directory by calling [FltTagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile).

For more information about reparse points, see the Microsoft Windows SDK documentation.

## See also

[FLT_TAG_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_tag_data_buffer)

[FSCTL_DELETE_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-delete-reparse-point)

[FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-reparse-point)

[FSCTL_SET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point)

[FltTagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile)

[IsReparseTagMicrosoft](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagmicrosoft)

[IsReparseTagNameSurrogate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagnamesurrogate)