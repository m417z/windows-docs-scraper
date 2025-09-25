## Description

The **FSCTL_ENUM_USN_DATA** control code enumerates the update sequence number (USN) data between two specified boundaries to get master file table (MFT) records.

## Parameters

### Major code

FSCTL_ENUM_USN_DATA

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

See [FSCTL_ENUM_USN_DATA IOCTL (winioctl.h)](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_enum_usn_data) for more information.

## See also

[**MFT_ENUM_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-mft_enum_data_v0)

[**USN_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v2)

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)