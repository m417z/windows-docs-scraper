## Description

**FSCTL_SHUFFLE_FILE** adds or removes allocation from within the specified file.

## Parameters

### Major code

### Input buffer

Pointer to a [**SHUFFLE_FILE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-shuffle_file_data) structure that describes the allocation to be shuffled.

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

**FSCTL_SHUFFLE_FILE** returns STATUS_SUCCESS upon successful completion; otherwise it returns an NTSTATUS code such as one of the following.

| Return code | Meaning |
| ----------- | ------- |
| STATUS_ACCESS_DENIED | For various reasons, including only kernel-mode calls are allowed, or the volume is locked. |
| STATUS_BUFFER_TOO_SMALL | The specified input buffer length is smaller than sizeof(SHUFFLE_FILE_DATA). |
| STATUS_MEDIA_WRITE_PROTECTED | Shuffling is not allowed on a read-only volume. |

## Remarks

This control code will cause data to shift within the file. The caller is responsible for protecting/erasing the random data within the added allocation.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) with the following parameters.

| Parameter | Description |
| --------- | ----------- |
| **Instance** | [in] For **FltFsControlFile** only. An opaque instance pointer for the caller. This parameter is required and cannot be NULL. |
| **FileObject** | [in] For **FltFsControlFile** only. A file object pointer for the file or directory that is the target of this request. This parameter is required and cannot be NULL. |
| **FileHandle** | [in] For **ZwFsControlFile** only. File handle of the file or directory that is the target of this request. This parameter is required and cannot be NULL. |
| **IoStatusBlock** | [out] For **ZwFsControlFile** only. Pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that contains the final status of the request. |
| **FsControlCode** | [in] Set to **FSCTL_SHUFFLE_FILE**. |
| **InputBuffer** | [in] See IOCTL parameters. |
| **InputBufferLength** | [in] See IOCTL parameters. |

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**FSCTL_REARRANGE_FILE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_rearrange_file)

[**SHUFFLE_FILE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-shuffle_file_data)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)