# FSCTL_GET_REPARSE_POINT control code

The FSCTL_GET_REPARSE_POINT control code retrieves the reparse point data associated with the specified file or directory.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) with the following parameters.

For more information about reparse points and the FSCTL_GET_REPARSE_POINT control code, see the Microsoft Windows SDK documentation.

## Parameters

- **FileObject** [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. File object pointer for the file or directory from which to retrieve the reparse point data. This parameter is required and cannot be **NULL**.

- **FileHandle** [in]: [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) only. File handle for the file or directory from which to retrieve the reparse point data. This parameter is required and cannot be **NULL**.

- **FsControlCode** [in]: A control code for the operation. Use **FSCTL_GET_REPARSE_POINT** for this operation.

- **InputBuffer** [in]: Not used with this operation; set to **NULL**.

- **InputBufferLength** [in]: Not used with this operation; set to zero.

- **OutputBuffer** [out]: Pointer to a caller-allocated [**REPARSE_GUID_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer) or [**REPARSE_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer) structure that receives the reparse point data.

- **OutputBufferLength** [out]: Size, in bytes, of the buffer pointed to by the **OutputBuffer** parameter. The number of bytes is calculated as follows:

 | Structure | OutputBufferLength |
| --------- | ------------------ |
| **REPARSE_GUID_DATA_BUFFER** | Must be at least REPARSE_GUID_DATA_BUFFER_HEADER_SIZE plus the size of the expected user-defined data; and must be less than or equal to MAXIMUM_REPARSE_DATA_BUFFER_SIZE. |
| **REPARSE_DATA_BUFFER** | Must be at least REPARSE_DATA_BUFFER_HEADER_SIZE plus the size of the expected user-defined data; and must be less than or equal to MAXIMUM_REPARSE_DATA_BUFFER_SIZE. |

## Status block

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Code | Meaning |
| ---- | ------- |
| STATUS_BUFFER_OVERFLOW | The buffer that the **OutputBuffer** parameter points to is large enough to hold the fixed portion of the REPARSE_GUID_DATA_BUFFER or REPARSE_DATA_BUFFER structure but not the user-defined data. In this case, only **OutputBufferLength** bytes are returned in the **OutputBuffer** buffer. The **LengthReturned** parameter to [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) receives the actual length, in bytes, of data returned. This is a warning code. |
| STATUS_BUFFER_TOO_SMALL | The buffer that **OutputBuffer** points to is less than ```sizeof(REPARSE_GUID_DATA_BUFFER)``` and is not large enough to hold the reparse point data. The **LengthReturned** parameter to [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) (or the **Information** member of the **IoStatus** parameter to [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85))) receives the required buffer size. In this case, no reparse point data is returned. This is an error code. |
| STATUS_IO_REPARSE_DATA_INVALID | One of the specified parameter values was invalid. This is an error code. |
| STATUS_NOT_A_REPARSE_POINT | The file or directory is not a reparse point. This is an error code. |

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Header | *Ntifs.h* (include *Ntifs.h* or *Fltkernel.h*) |

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_PARAMETERS for IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-file-system-control)

[**FLT_TAG_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_tag_data_buffer)

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**FltTagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile)

[**FltUntagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile)

[**FSCTL_DELETE_REPARSE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-delete-reparse-point)

[**FSCTL_SET_REPARSE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point)

[**IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-file-system-control)

[**IsReparseTagMicrosoft**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagmicrosoft)

[**IsReparseTagNameSurrogate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagnamesurrogate)

[**REPARSE_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer)

[**REPARSE_GUID_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer)

[**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85))