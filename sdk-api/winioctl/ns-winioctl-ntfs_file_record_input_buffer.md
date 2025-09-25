# NTFS_FILE_RECORD_INPUT_BUFFER structure

## Description

Contains data for the
[FSCTL_GET_NTFS_FILE_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_file_record) control code.

## Members

### `FileReferenceNumber`

The file identifier of the file record to be retrieved. This is not necessarily the file identifier returned in the **FileReferenceNumber** member of the
[NTFS_FILE_RECORD_OUTPUT_BUFFER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-ntfs_file_record_output_buffer) structure. Refer to the Remarks section of the reference page for
[FSCTL_GET_NTFS_FILE_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_file_record) for more information.

## Remarks

Pass this structure as input to the
[FSCTL_GET_NTFS_FILE_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_file_record) control code.

## See also

[FSCTL_GET_NTFS_FILE_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_file_record)

[NTFS_FILE_RECORD_OUTPUT_BUFFER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-ntfs_file_record_output_buffer)