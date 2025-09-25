## Description

Given a file handle, the **FSCTL_GET_RETRIEVAL_POINTERS** control code retrieves a data structure that describes the allocation and location on disk of a specified file; or, given a volume handle, it retrieves the locations of bad clusters on the volume.

## Parameters

### Major code

FSCTL_GET_RETRIEVAL_POINTERS

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

See [FSCTL_GET_RETRIEVAL_POINTERS IOCTL (winioctl.h)](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_retrieval_pointers) for more information.

## See also

[RETRIEVAL_POINTERS_BUFFER structure (winioctl.h)](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-retrieval_pointers_buffer)