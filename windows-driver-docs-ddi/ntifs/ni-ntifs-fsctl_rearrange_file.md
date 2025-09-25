## Description

**FSCTL_REARRANGE_FILE** rearranges allocation within the file, moving clusters from a requested contiguous source range within a file to another location within the same file.

## Parameters

### Major code

### Input buffer

Pointer to a [**REARRANGE_FILE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-rearrange_file_data) structure that describes the allocation to be rearranged. (For 32-bit callers, the input buffer is a pointer to a **REARRANGE_FILE_DATA32** structure.)

### Input buffer length

Size in bytes of the input buffer.

### Output buffer

None; set to NULL.

### Output buffer length

Set to zero.

### Input/output buffer

### Input/output buffer length

### Status block

## Return values

**FSCTL_REARRANGE_FILE** returns STATUS_SUCCESS upon successful completion; otherwise it returns an NTSTATUS code such as one of the following.

| Return code | Meaning |
| ----------- | ------- |
| STATUS_ACCESS_DENIED | Only kernel-mode calls are allowed. |
| STATUS_BUFFER_TOO_SMALL | The specified input buffer length is smaller than sizeof(REARRANGE_FILE_DATA). |
| STATUS_PENDING | Operation completion is pending. |

## Remarks

[Request parameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-rearrange_file_data) contain source and target file byte offsets, and length in bytes of the source region to move, all of which must be cluster-aligned.

* If moving clusters down, the target file offset indicates the point at which the lower boundary of the moving source range should be aligned.
* If moving clusters up, the target file offset indicates the point at which the source range's upper boundary should be aligned.

In both cases, the target offset indicates that the source range should be inserted before the cluster that begins at the target offset, the distinction being forced by the constraint that the allocation size remains fixed.

Unlike [**FSCTL_SHUFFLE_FILE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_shuffle_file), **FSCTL_REARRANGE_FILE** doesn't allow adding allocations containing random data.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) with the following parameters.

| Parameter | Description |
| --------- | ----------- |
| **Instance** | [in] For **FltFsControlFile** only. An opaque instance pointer for the caller. This parameter is required and cannot be NULL. |
| **FileObject** | [in] For **FltFsControlFile** only. A file object pointer for the file or directory that is the target of this request. This parameter is required and cannot be NULL. |
| **FileHandle** | [in] For **ZwFsControlFile** only. File handle of the file or directory that is the target of this request. This parameter is required and cannot be NULL. |
| **IoStatusBlock** | [out] For **ZwFsControlFile** only. Pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that contains the final status of the request. |
| **FsControlCode** | [in] Set to **FSCTL_REARRANGE_FILE**. |
| **InputBuffer** | [in] See IOCTL parameters. |
| **InputBufferLength** | [in] See IOCTL parameters. |

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**FSCTL_SHUFFLE_FILE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_shuffle_file)

[**REARRANGE_FILE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-rearrange_file_data)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)