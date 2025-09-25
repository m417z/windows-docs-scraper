## Description

The **FSCTL_MANAGE_BYPASS_IO** control code controls BypassIO operations on a given file in the filter and file system stacks.

## Parameters

### Major code

FSCTL_MANAGE_BYPASS_IO

### Input buffer

Pointer to a [**FS_BPIO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_input) structure containing information about the BypassIO request.

### Input buffer length

Size of the [**FS_BPIO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_input) structure that **InputBuffer** points to, in bytes.

### Output buffer

Pointer to a [**FS_BPIO_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_output) structure in which to return information about the BypassIO operation.

### Output buffer length

Size of the [**FS_BPIO_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_output) structure that **OutputBuffer** points to, in bytes.

### Input/output buffer

n/a

### Input/output buffer length

n/a

### Status block

Reserved for system use.

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) with the following parameters.

| Parameter | Description |
| --------- | ----------- |
| **Instance** | [in] For **FltFsControlFile** only. An opaque instance pointer for the caller. This parameter is required and cannot be NULL. |
| **FileObject** | [in] For **FltFsControlFile** only. A file object pointer for the file or directory that is the target of this BypassIO operation request. This parameter is required and cannot be NULL. |
| **FileHandle** | [in] For **ZwFsControlFile** only. File handle of the file on which the BypassIO operation is being requested. This parameter is required and cannot be NULL. |
| **FsControlCode** | [in] Set to **FSCTL_MANAGE_BYPASS_IO**. |
| **InputBuffer** | [in] Pointer to a [**FS_BPIO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_input) structure containing information about the BypassIO request. |
| **InputBufferLength** | [in] Size of the buffer that **InputBuffer** points to, in bytes. |
| **OutputBuffer** | [out] Pointer to a [**FS_BPIO_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_output) structure in which to return information about the BypassIO operation. |
| **OutputBufferLength** | [out] Size of the buffer that **OutputBuffer** points to, in bytes. |

See [BypassIO for filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio) for more information.

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**FS_BPIO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_input)

[**FS_BPIO_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_output)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)