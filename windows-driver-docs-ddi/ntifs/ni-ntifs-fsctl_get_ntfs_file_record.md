## Description

The **FSCTL_GET_NTFS_FILE_RECORD** control code retrieves a file record from an NTFS volume.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

See [**FSCTL_GET_NTFS_VOLUME_DATA**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_ntfs_file_record) for more information.

## See also

[**NTFS_FILE_RECORD_INPUT_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_file_record_input_buffer)

[**NTFS_FILE_RECORD_OUTPUT_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_file_record_output_buffer)