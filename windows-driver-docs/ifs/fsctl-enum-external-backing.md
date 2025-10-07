# FSCTL_ENUM_EXTERNAL_BACKING control code

The **FSCTL_ENUM_EXTERNAL_BACKING** control code begins or continues an enumeration of files on a volume that have a backing source. For each successful completion of the request, an identifier for the backed file is returned. All backed files are enumerated regardless of which external provider is backing it. Successive **FSCTL_ENUM_EXTERNAL_BACKING** requests are required to enumerate all the backed files on the volume.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) with the following parameters.

## Parameters

- **Instance** [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

- **FileObject** [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. The file pointer object specifying the volume to be dismounted. This parameter is required and cannot be **NULL**.

- **FileHandle** [in]: [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) only. The file handle of the volume to be dismounted. This parameter is required and cannot be **NULL**.

- **FsControlCode** [in]: Control code for the operation. Use **FSCTL_ENUM_EXTERNAL_BACKING** for this operation.

- **InputBuffer** [in]: None. Set to **NULL**.

- **InputBufferLength** [in]: Set to 0.

- **OutputBuffer** [out]: A pointer to the output buffer, which must have a size large enough to receive one or more **WOF_EXTERNAL_FILE_ID** structures.

- **OutputBufferLength** [out]: Size of the output buffer pointed to by **OutputBuffer**. **OutputBufferLength** must be >= **sizeof**(WOF_EXTERNAL_FILE_ID).

- **LengthReturned** [out]: Specifies the number of bytes written into **OutputBuffer** on successful completion.

## Status block

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) returns STATUS_SUCCESS if the operation succeeds. Otherwise, the appropriate function might return one of the following NTSTATUS values.

| Code | Meaning |
| ---- | ------- |
| STATUS_ACCESS_DENIED | The requester does not have administrative privileges. |
| STATUS_BUFFER_TOO_SMALL | The length of the output buffer pointed to by **OutputBuffer** and specified by **OutputBufferLength** is too small. |
| STATUS_NO_MORE_FILES | No more files on the volume have a backing source. |
| STATUS_INTERNAL_ERROR | The requested volume is not accessible. |
| STATUS_INVALID_DEVICE_REQUEST | The backing service is not present or not started. |

## Remarks

The **WOF_EXTERNAL_FILE_ID** structure returned in **OutputBuffer** contains unique file identifiers for backed files. The structure is defined in ntifs.h as the following.

```ManagedCPlusPlus
typedef struct _WOF_EXTERNAL_FILE_ID {
    FILE_ID_128 FileId;
} WOF_EXTERNAL_FILE_ID, *PWOF_EXTERNAL_FILE_ID;
```

A **FSCTL_ENUM_EXTERNAL_BACKING** request is issued successively to retrieve the identifiers for each file on the volume having backing source. When all the files are enumerated, the STATUS_NO_MORE_FILES status code is returned.

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Minimum supported client | Windows 8.1 Update |
| Header | *Ntifs.h* (include *Ntifs.h* or *Fltkernel.h*) |

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85))

[**FSCTL_GET_EXTERNAL_BACKING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-external-backing)