## Description

The **NTFS_FILE_RECORD_INPUT_BUFFER** structure is used with the [**FSCTL_GET_NTFS_FILE_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_ntfs_file_record) control code.

## Members

### `FileReferenceNumber`

The file identifier of the file record to be retrieved. This is not necessarily the file identifier returned in the **FileReferenceNumber** member of the [**NTFS_FILE_RECORD_OUTPUT_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_file_record_output_buffer) structure.

## See also

[**FSCTL_GET_NTFS_FILE_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_ntfs_file_record)

[**NTFS_FILE_RECORD_OUTPUT_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_file_record_output_buffer)