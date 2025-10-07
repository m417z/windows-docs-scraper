# FSCTL_GET_EXTERNAL_BACKING control code

The **FSCTL_GET_EXTERNAL_BACKING** control code gets the backing information for a file from an external backing provider. Backing providers include the Windows Image Format (WIM) provider or individual compressed file provider. Content for externally backed files may reside on volumes other than on the volume containing the queried file.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) with the following parameters.

## Parameters

- **Instance** [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. An opaque instance pointer for the caller. This parameter is required and cannot be NULL.

- **FileObject** [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. The file pointer object of the file for which backing information is queried. This parameter is required and cannot be NULL.

- **FileHandle** [in]: [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) only. The handle of the file for which backing information is queried. This parameter is required and cannot be NULL.

- **FsControlCode** [in]: A control code for the operation. Use **FSCTL_GET_EXTERNAL_BACKING** for this operation.

- **InputBuffer** [in]: None. Set to **NULL**.

- **InputBufferLength** [in]: Set to 0.

- **OutputBuffer** [out]: A pointer to the output buffer, which must have a size large enough to receive a [**WOF_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_info) structure followed by the provider data. For WIM backed files, **WOF_EXTERNAL_INFO** is followed by a [**WIM_PROVIDER_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wim_provider_external_info) structure. For individually compressed files, **WOF_EXTERNAL_INFO** is followed by a [**FILE_PROVIDER_EXTERNAL_INFO_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_provider_external_info_v1) structure.

- **OutputBufferLength** [out]: Size, in bytes, of the buffer pointed to by **OutputBuffer**.

- **LengthReturned** [out]: Specifies the number of bytes written into **OutputBuffer** on successful completion.

## Status block

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) returns STATUS_SUCCESS if the operation succeeds. Otherwise, the appropriate function might return one of the following NTSTATUS values.

| Code | Meaning |
| ---- | ------- |
| STATUS_OBJECT_NOT_EXTERNALLY_BACKED | The file is not externally backed. |
| STATUS_INVALID_DEVICE_REQUEST | The backing service is not present or not started. |

## Remarks

When the backing provider for the data source to update is a WIM file, the output buffer will contain a [**WOF_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_info) structure followed by a [**WIM_PROVIDER_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wim_provider_external_info) structure. The *OutputBufferLength* must be at least **sizeof**(WOF_EXTERNAL_INFO) + **sizeof**(WIM_PROVIDER_EXTERNAL_INFO). When the backing provider is an individually compressed file, the output buffer will contain a **WOF_EXTERNAL_INFO** structure followed by a [**FILE_PROVIDER_EXTERNAL_INFO_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_provider_external_info_v1) structure.

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Minimum supported client | Windows 8.1 Update |
| Header | *Ntifs.h* (include *Ntifs.h* or *Fltkernel.h*) |

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85))

[**FSCTL_SET_EXTERNAL_BACKING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-external-backing)

[**WIM_PROVIDER_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wim_provider_external_info)

[**WOF_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_info)