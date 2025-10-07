# FSCTL_ENUM_OVERLAY control code

The **FSCTL_ENUM_OVERLAY** control code enumerates all the data sources from a backing provider for a specified volume.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) with the following parameters.

## Parameters

- **Instance** [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

- **FileObject** [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. The file pointer object specifying the volume to be dismounted. This parameter is required and cannot be **NULL**.

- **FileHandle** [in]: [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) only. The file handle of the volume to be dismounted. This parameter is required and cannot be **NULL**.

- **FsControlCode** [in]: Control code for the operation. Use **FSCTL_REMOVE_OVERLAY** for this operation.

- **InputBuffer** [in]: A pointer to the input buffer, which must contain a [**WOF_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_info) structure.

- **InputBufferLength** [in]: Set to **sizeof**(WOF_EXTERNAL_INFO).

- **OutputBuffer** [out]: Pointer to an output buffer which will receive one or more [**WIM_PROVIDER_OVERLAY_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wim_provider_update_overlay_input) structures for data sources backing the volume.

- **OutputBufferLength** [out]: Size of the buffer pointed to by *OutputBuffer*, in bytes.

- **LengthReturned** [out]: Specifies the number of bytes written into *OutputBuffer* on successful completion.

## Status block

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) returns STATUS_SUCCESS if the operation succeeds. Otherwise, the appropriate function might return one of the following NTSTATUS values.

| Code | Meaning |
| ---- | ------- |
| STATUS_ACCESS_DENIED | The requester does not have administrative privileges. |
| STATUS_BUFFER_TOO_SMALL | The length of the output buffer pointed to by **OutputBuffer** and specified by **OutputBufferLength** is too small. |
| STATUS_INTERNAL_ERROR | The requested volume is not accessible. |
| STATUS_INVALID_DEVICE_REQUEST | The backing service is not present or not started. |

## Remarks

When enumerating the data sources for the WIM provider, the output buffer will contain an array of [**WIM_PROVIDER_OVERLAY_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wim_provider_update_overlay_input) structures. The size of the output buffer must be large enough to contain all the overlay entries or the call will return STATUS_BUFFER_TOO_SMALL.

Additional backing providers will define their own specific enumeration structures.

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Minimum supported client | Windows 8.1 Update |
| Header | *Ntifs.h* (include *Ntifs.h* or *Fltkernel.h*) |

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85))

[**FSCTL_ADD_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-add-overlay)

[**WOF_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_info)