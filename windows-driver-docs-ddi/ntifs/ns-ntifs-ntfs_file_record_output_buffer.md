## Description

The **NTFS_FILE_RECORD_OUTPUT_BUFFER** structure receives the output data from the [**FSCTL_GET_NTFS_FILE_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_ntfs_file_record) control code.

## Members

### `FileReferenceNumber`

The file identifier of the returned file record. This is not necessarily the file identifier specified in the FileReferenceNumber member of the [**NTFS_FILE_RECORD_INPUT_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_file_record_input_buffer) structure.

### `FileRecordLength`

Length of the file record, in bytes.

### `FileRecordBuffer[1]`

The starting location of the buffer for the returned file record.

## See also

[**FSCTL_GET_NTFS_FILE_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_ntfs_file_record)

[**NTFS_FILE_RECORD_INPUT_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_file_record_input_buffer)