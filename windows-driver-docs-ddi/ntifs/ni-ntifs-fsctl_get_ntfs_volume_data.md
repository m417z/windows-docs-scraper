## Description

The **FSCTL_GET_NTFS_VOLUME_DATA** control code retrieves information about the specified NTFS volume.

## Parameters

### Major code

FSCTL_GET_NTFS_VOLUME_DATA

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

See [FSCTL_GET_NTFS_VOLUME_DATA IOCTL (winioctl.h)](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data) for more information.

## See also

[**NTFS_VOLUME_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_volume_data_buffer)

[**NTFS_EXTENDED_VOLUME_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_extended_volume_data)

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)