# FILE_SYSTEM_RECOGNITION_INFORMATION structure

## Description

Contains file system recognition information retrieved by the [FSCTL_QUERY_FILE_SYSTEM_RECOGNITION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_query_file_system_recognition) control code.

## Members

### `FileSystem`

The file system name stored on the disk. This is a null-terminated string of 8 ASCII characters that represents the nonlocalizable human-readable name of the
file system the volume is formatted with.

## See also

[FILE_SYSTEM_RECOGNITION_STRUCTURE](https://learn.microsoft.com/windows/desktop/FileIO/file-system-recognition-structure)

[FSCTL_QUERY_FILE_SYSTEM_RECOGNITION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_query_file_system_recognition)