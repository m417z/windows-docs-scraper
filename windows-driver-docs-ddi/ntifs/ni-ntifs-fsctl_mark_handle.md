## Description

The **FSCTL_MARK_HANDLE** control code marks a specified file or directory and its change journal record with information about changes to that file or directory.

## Parameters

### Major code

FSCTL_MARK_HANDLE

### Input buffer

Pointer to a [**MARK_HANDLE_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-mark_handle_info) structure containing the information to use to mark a specified file or directory, and its update sequence number (USN) change journal record with data about changes.

### Input buffer length

Size of the [**MARK_HANDLE_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-mark_handle_info) structure that **InputBuffer** points to, in bytes.

### Output buffer

Set to NULL.

### Output buffer length

n/a (ignored)

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
| **FileObject** | [in] For **FltFsControlFile** only. A file object pointer for the file or directory that is the target of this request. This parameter is required and cannot be NULL. |
| **FileHandle** | [in] For **ZwFsControlFile** only. File handle of the file or directory that is the target of this request. This parameter is required and cannot be NULL. |
| **FsControlCode** | [in] Set to **FSCTL_MARK_HANDLE**. |
| **InputBuffer** | [in] Pointer to a [**MARK_HANDLE_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-mark_handle_info) structure containing the information to use to mark a specified file or directory, and its update sequence number (USN) change journal record with data about changes. |
| **InputBufferLength** | [in] Size of the buffer that **InputBuffer** points to, in bytes. |
| **OutputBuffer** | [out] Set to NULL for this FSCTL. |
| **OutputBufferLength** | [in] Ignored when **OutputBuffer** is NULL. |
| **LengthReturned** | [out] Set to NULL. |

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)