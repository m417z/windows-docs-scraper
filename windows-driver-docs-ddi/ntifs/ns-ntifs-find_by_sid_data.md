## Description

The **FIND_BY_SID_DATA** structure contains data for the [**FSCTL_FIND_FILES_BY_SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_find_files_by_sid) control code.

## Members

### `Restart`

Indicates whether to restart the search. This member should be 1 on first call, so the search will start from the root. For subsequent calls, this member should be zero so the search will resume at the point where it stopped.

### `Sid`

A [**SID**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-sid) structure that specifies the desired creator owner.

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

See [FSCTL_FIND_FILES_BY_SID IOCTL (winioctl.h)](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_find_files_by_sid).

## See also

[**FSCTL_FIND_FILES_BY_SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_find_files_by_sid)