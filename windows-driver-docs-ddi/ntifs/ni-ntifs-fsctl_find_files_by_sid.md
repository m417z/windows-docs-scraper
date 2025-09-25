## Description

The **FSCTL_FIND_FILES_BY_SID** control code searches a directory for a file whose creator owner matches the specified security identifier (SID).

## Parameters

### Major code

FSCTL_FIND_FILES_BY_SID

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

See [FSCTL_FIND_FILES_BY_SID IOCTL (winioctl.h)](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_find_files_by_sid).

## See also

[**FIND_BY_SID_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-find_by_sid_data)

[**FIND_BY_SID_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-find_by_sid_output)

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)