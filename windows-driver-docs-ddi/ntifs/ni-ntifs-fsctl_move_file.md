## Description

The **FSCTL_MOVE_FILE** control code relocates one or more virtual clusters of a file from one logical cluster to another within the same volume.

## Parameters

### Major code

FSCTL_MOVE_FILE

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

See [FSCTL_MOVE_FILE IOCTL (winioctl.h)](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_move_file) for more information.

## See also

[**MOVE_FILE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-move_file_data)

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)