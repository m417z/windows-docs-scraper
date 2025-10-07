# FSCTL_DELETE_REPARSE_POINT control code

The FSCTL_DELETE_REPARSE_POINT control code deletes a reparse point from the specified file or directory. Using FSCTL_DELETE_REPARSE_POINT does not delete the file or directory.

To perform this operation, call [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) with the following parameters.

Minifilters should use [**FltUntagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile) instead of FSCTL_DELETE_REPARSE_POINT to delete a reparse point.

For more information about reparse points and the FSCTL_DELETE_REPARSE_POINT control code, see the Microsoft Windows SDK documentation.

## Parameters

- **FileHandle** [in]: File handle for the file or directory from which the reparse point is to be deleted. The caller must have write access to the file or directory. This parameter is required and cannot be **NULL**.

- **FsControlCode** [in]: Control code for the operation. Use FSCTL_DELETE_REPARSE_POINT for this operation.

- **InputBuffer** [in]: Pointer to a [**REPARSE_GUID_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer) or [**REPARSE_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer) structure. The tag specified in the **ReparseTag** member of this structure must match the tag of the reparse point to be deleted, and the **ReparseDataLength** member must be zero. In addition, if the reparse point is a third-party (non-Microsoft) reparse point, the GUID specified in the **ReparseGuid** member of the REPARSE_GUID_DATA_BUFFER structure must match the GUID of the reparse point to be deleted.

- **InputBufferLength** [in]: Size, in bytes, of the buffer pointed to by the **InputBuffer** parameter. For a REPARSE_GUID_DATA_BUFFER structure, this value must be exactly REPARSE_GUID_DATA_BUFFER_HEADER_SIZE. For a REPARSE_DATA_BUFFER structure, this value must be exactly REPARSE_DATA_BUFFER_HEADER_SIZE.

- **OutputBuffer** [out]: None. Set to NULL.

- **OutputBufferLength** [out]: Set to 0.

## Status block

[**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Code | Meaning |
| ---- | ------- |
| STATUS_IO_REPARSE_DATA_INVALID | One of the specified parameter values was invalid. This is an error code. |
| STATUS_IO_REPARSE_TAG_INVALID | The reparse tag specified by the caller was invalid. This is an error code. |
| STATUS_IO_REPARSE_TAG_MISMATCH | The reparse tag specified by the caller did not match the tag of the reparse point to be deleted. This is an error code. |
| STATUS_REPARSE_ATTRIBUTE_CONFLICT | The reparse point is a third-party reparse point, and the reparse GUID specified by the caller did not match the GUID of the reparse point to be deleted. This is an error code. |

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Header | *Ntifs.h* (include *Ntifs.h* or *Fltkernel.h*) |

## See also

[**FLT_PARAMETERS for IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-file-system-control)

[**FltTagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile)

[**FltUntagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile)

[**FSCTL_GET_REPARSE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-reparse-point)

[**FSCTL_SET_REPARSE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point)

[**IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-file-system-control)

[**IsReparseTagMicrosoft**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagmicrosoft)

[**IsReparseTagNameSurrogate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagnamesurrogate)

[**REPARSE_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer)

[**REPARSE_GUID_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer)

[**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85))