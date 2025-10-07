# FSCTL_ADD_OVERLAY control code

The **FSCTL_ADD_OVERLAY** control code adds a new external backing source to a volume’s namespace. This backing source can be a Windows Image Format (WIM) file.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) with the following parameters.

## Parameters

- **Instance** [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. An opaque instance pointer for the caller. This parameter is required and cannot be NULL.

- **FileObject**: [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. The file pointer object of the volume for which the overlay is added to. This parameter is required and cannot be NULL.

- **FileHandle** [in]: [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) only. The handle of the volume for which the overlay is added to. This parameter is required and cannot be NULL.

- **FsControlCode** [in]: The control code for the operation. Use **FSCTL_ADD_OVERLAY** for this operation.

- **InputBuffer** [in]: A pointer to the input buffer, which must contain a [**WOF_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_info) structure. When required, additional provider specific data is included immediately after **WOF_EXTERNAL_INFO**.

- **InputBufferLength** [in]: Set to sizeof([**WOF_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_info)) plus the size of any additional provider input data.

- **OutputBuffer** [out]: A pointer to the output buffer, which contains any resultant information from the add operation.

- **OutputBufferLength** [out]: Size of the buffer pointed to by **OutputBuffer**.

## Status block

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) returns STATUS_SUCCESS if the operation succeeds. Otherwise, the appropriate function might return one of the following NTSTATUS values.

| Code | Meaning |
| ---- | ------- |
| STATUS_ACCESS_DENIED | The requester does not have administrative privileges. |
| STATUS_BUFFER_TOO_SMALL | The length of the output buffer pointed to by **OutputBuffer**, and specified by **OutputBufferLength**, is too small. |
| STATUS_INTERNAL_ERROR | The requested volume is not accessible. |
| STATUS_INVALID_DEVICE_REQUEST | The backing service is not present or not started. |

## Remarks

When the backing source added is a Windows Imaging Format (WIM) file, the input buffer will contain a [**WOF_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_info) structure followed by a [**WIM_PROVIDER_ADD_OVERLAY_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wim_provider_add_overlay_input) structure. The **InputBufferLength** in this case will be **sizeof**(**WOF_EXTERNAL_INFO**) + **sizeof**(**WIM_PROVIDER_ADD_OVERLAY_INPUT**). On completion of the request, the data pointed to by **OutputBuffer** contains a single LARGE_INTEGER value which is the new data source identifier for the WIM file.

Other backing providers will define their own specific input parameter structures and output data types.

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Minimum supported client | Windows 8.1 Update |
| Header | *Ntifs.h* (include *Ntifs.h* or *Fltkernel.h*) |

## See also

[**FSCTL_REMOVE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-remove-overlay)

[**FSCTL_SUSPEND_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-suspend-overlay)

[**FSCTL_UPDATE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-update-overlay)

[**FSCTL_GET_EXTERNAL_BACKING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-external-backing)

[**FSCTL_SET_EXTERNAL_BACKING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-external-backing)