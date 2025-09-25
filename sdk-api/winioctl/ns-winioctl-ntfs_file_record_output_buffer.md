# NTFS_FILE_RECORD_OUTPUT_BUFFER structure

## Description

Receives output data from the
[FSCTL_GET_NTFS_FILE_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_file_record) control code.

## Members

### `FileReferenceNumber`

The file identifier of the returned file record. This is not necessarily the file identifier specified in the **FileReferenceNumber** member of the
[NTFS_FILE_RECORD_INPUT_BUFFER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-ntfs_file_record_input_buffer) structure. Refer to the Remarks section of the reference page for
[FSCTL_GET_NTFS_FILE_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_file_record) for more information.

### `FileRecordLength`

The length of the returned file record, in bytes.

### `FileRecordBuffer`

The starting location of the buffer for the returned file record.

## Remarks

To retrieve data to fill in this structure, use the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)
[FSCTL_GET_NTFS_FILE_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_file_record) control code.

## See also

[FSCTL_GET_NTFS_FILE_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_file_record)

[NTFS_FILE_RECORD_INPUT_BUFFER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-ntfs_file_record_input_buffer)